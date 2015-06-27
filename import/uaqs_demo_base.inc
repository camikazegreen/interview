<?php

/**
 * @file
 * Provides common base classes that the migrations for features can extend.
 */

/**
 * Establishes conventions for file handling.
 *
 * The default conventions for finding demo content associate local JSON files
 * with each migration, naming each file from the lowercased version of the
 * machine name of the migration. All the JSON files are in the data
 * subdirectory of the directory holding the migration PHP code, and any
 * additional files (PDF documents, JPEG and PNG images) are in a parallel
 * images subdirectory.
 */
abstract class UaDemoLocalfileMigration extends Migration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments for the parent constructor (Migration standard behavior).
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
  }

  /**
   * Hard-codes the name for the subdirectory within this module's directory.
   *
   * @return string
   *   The path of our directory relative to DRUPAL_ROOT.
   */
  public function importRoot() {
    return drupal_get_path('module', 'ua_demo') . '/import';
  }

  /**
   * Gives the path of the directory holding the JSON demo data files.
   *
   * @return string
   *   The path relative to DRUPAL_ROOT.
   */
  public function dataPath() {
    return $this->importRoot() . '/data';
  }

  /**
   * Gives the path of the directory holding the image and attachment files.
   *
   * @return string
   *   The path relative to DRUPAL_ROOT.
   */
  public function imagePath() {
    return $this->importRoot() . '/images';
  }

  /**
   * Turns a class machine name into the default JSON data file path.
   *
   * @return string
   *   The relative path to the JSON data file.
   */
  public function jsonFilePath() {
    return $this->dataPath() . '/' . drupal_strtolower($this->machineName) . '.json';
  }

}