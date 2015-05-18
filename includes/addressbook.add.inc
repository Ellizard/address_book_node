<?php

function addressbook_add(&$form, &$form_state, $contact_id = FALSE) {

//  $db_select =  db_select('adressbook_table', 'n')
//    ->fields('n')
//    ->condition('n.addressbook_id', arg(3))
//    ->execute()
//    ->fetchAll();

  $form['addressbook_firstname'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter your first name'),
    '#description' => 'First name',
    '#required' => TRUE,
    '#default_value' => '',
  );

  $form['addressbook_lastname'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter you Last name'),
    '#description' => 'Last name',
    '#required' => TRUE,
    '#defailt_value' => '',
  );

  $form['addressbook_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter your email'),
    '#description' => 'Email',
    '#required' => TRUE,
    '#defailt_value' => '',
  );

  $form['addressbook_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter your phone number'),
    '#description' => 'Phone',
    '#required' => TRUE,
    '#defailt_value' => '',
  );

  $form['addressbook_photo'] = array(
    '#type' => 'managed_file',
    '#title' => t('Photo'),
    '#required' => TRUE,
    '#description' => t('Allowed extensions: gif, png, jpg, jpeg'),
    '#upload_location' => 'public://addressbook/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
      'file_validate_size' => array(0.3 * 1024 * 1024),
      'file_validate_image_resolution' => array('400x400'),
    ),
    '#default_value' => '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    //'#validate' => array('addressbook_validate'),
  );
  return $form;
}


function addressbook_add_validate(&$form, &$form_state) {

}

function addressbook_add_submit(&$form, &$form_state) {
  dsm($form);
  return db_insert('adressbook_table')
    ->fields(array(
      'addressbook_name' => $form['addressbook_firstname']['#value'],
      'addressbook_lastname' => $form['addressbook_lastname']['#value'],
      'addressbook_email' => $form['addressbook_email']['#value'],
      'addressbook_photo' => $form['addressbook_photo']['#value']['fid'],
      'addressbook_phone' => $form['addressbook_phone']['#value'],
    ))
    ->execute();
}