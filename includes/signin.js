/**
 * User sign-in overriden from the drush casperjs defaults.
 *
 * The default in the drush casperjs's casperjs/includes/session.js file,
 * and makes no provision for a CAS-based login option.
 *
 * @param Object user
 *   The user object to sign in as.
 */
casper.drupalSignIn = function(user) {
  casper.thenOpen('user', function () {
    if (this.exists('.uncas-link a')) {
      this.log('Switching to the non-CAS login form', 'info');
      this.click('.uncas-link a');
    } else {
      this.log('Assuming the normal login form is already available.', 'info');
    }
  });

  casper.then(function () {
    this.log('Submitting the login form for user name' + user.name, 'info');
    this.fill('form#user-login', {
      "name": user.name,
      "pass": user.pass
    }, true);
  });

  casper.waitForSelector('body.logged-in', function() {
    this.log('Logged in as ' + user.label, 'info');
  }, function timeout() {
    this.test.fail('Unable to log in as ' + user.label);
  });
};
