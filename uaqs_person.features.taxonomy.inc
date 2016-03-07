<?php
/**
 * @file
 * uaqs_person.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function uaqs_person_taxonomy_default_vocabularies() {
  return array(
    'uaqs_people_category' => array(
      'name' => 'People Categories',
      'machine_name' => 'uaqs_people_category',
      'description' => 'Taxonomy for categorizing people',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
