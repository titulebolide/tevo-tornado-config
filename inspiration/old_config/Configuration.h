/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Basé sur Sprinter et grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * Ce programme est un logiciel libre: vous pouvez le redistribuer et /
 * ou le modifier selon les termes de la licence publique générale GNU
 * telle que publiée par la Free Software Foundation, soit la version 3 de
 * la licence, soit (à votre choix) toute version ultérieure.
 *
 * Ce programme est distribué dans l'espoir qu'il sera utile, mais SANS
 * AUCUNE GARANTIE; sans même la garantie implicite de QUALITÉ
 * MARCHANDE ou d'ADÉQUATION À UN USAGE PARTICULIER. Voir la
 * licence publique générale GNU pour plus de détails.
 *
 * Vous devriez avoir reçu une copie de la licence publique
 * générale GNU avec ce programme. Si non, voir <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Configuration.h
 *
 * Paramètres de base tels que:
 *
 * - Type d'électronique
 * - Type de capteur de température
 * - Géométrie de l'imprimante
 * - Configuration des fin de course
 * - Contrôleur LCD
 * - Fonctionnalités supplémentaires
 *
 * Les paramètres avancés peuvent être trouvés dans Configuration_adv.h
 *
 */
#define CONFIGURATION_H_VERSION 020000

//===========================================================================
//============================= Getting Started =============================
//===========================================================================

/**
 * Voici quelques liens standard pour le calibrage de votre machine:
 *
 * http://reprap.org/wiki/Calibration
 * http://youtu.be/wAL9d7FgInk
 * http://calculator.josefprusa.cz
 * http://reprap.org/wiki/Triffid_Hunter%27s_Calibration_Guide
 * http://www.thingiverse.com/thing:5573
 * https://sites.google.com/site/repraplogphase/calibration-of-your-reprap
 * http://www.thingiverse.com/thing:298812
 * en Français: https://www.youtube.com/watch?v=qotADlrrvUw ; https://www.youtube.com/watch?v=ghw-okeJd6Y&t=52s
 * Pour les Deltas: https://www.youtube.com/watch?v=Wndp7lTkD3c
 */

//===========================================================================
//=========================== Imprimante DELTA ==============================
//===========================================================================
// Pour une imprimante Delta, démarrez l’un des fichiers de configuration du répertoire
// config / examples / delta et personnalisez-le en fonction de votre machine.
//

//===========================================================================
//======================== Imprimante CARTESIENNE ===========================
//===========================================================================
// Pour une imprimante CARTESIENNE, commencez par les fichiers de configuration de
// config / examples / SCARA et personnalisez-les en fonction de votre machine.
//

// @section info

// Les informations de version spécifiées par l'utilisateur de cette version à afficher dans la fenêtre du terminal
// [Pronterface, etc.] lors du démarrage. Mise en œuvre d'une idée par le professeur Braino pour informer  l'utilisateur que
// toutes les modifications apportées à  cette version par l'utilisateur ont été téléchargées avec succès dans le micrologiciel.
#define STRING_CONFIG_H_AUTHOR "Titus Senez" // Qui a fait les changements.
#define SHOW_BOOTSCREEN
#define STRING_SPLASH_LINE1 SHORT_BUILD_VERSION // sera affiché lors du démarrage en ligne 1
#define STRING_SPLASH_LINE2 WEBSITE_URL         // sera affiché lors du démarrage en ligne 2

/**
 * *** LES VENDEURS VEUILLEZ LIRE ***
 *
 * Marlin vous permet d'ajouter une image de démarrage personnalisée pour les écrans LCD graphiques.
 * Avec cette option, Marlin affiche d'abord votre écran personnalisé, suivi
 * du logo Marlin standard avec le numéro de version et l'adresse Web.
 *
 * Nous vous encourageons à tirer parti de cette nouvelle fonctionnalité et nous vous demandons également
 * respectueusement de conserver l'écran de démarrage Marlin non modifié.
 */

// Activer pour afficher le bitmap dans Marlin / _Bootscreen.h au démarrage.
//#define SHOW_CUSTOM_BOOTSCREEN

// Activer pour afficher le bitmap dans Marlin / _Statusscreen.h sur l'écran d'état.
#define CUSTOM_STATUS_SCREEN_IMAGEPID


// @section machine

/**
 * Sélectionnez le port série de la carte à utiliser pour la communication avec l'hôte.
 * Cela permet de connecter des adaptateurs sans fil (par exemple) à des broches de port autres que celles par défaut.
 * Remarque: le premier port série (-1 ou 0) sera toujours utilisé par le chargeur de démarrage Arduino.
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
#define SERIAL_PORT 0

/**
 * Sélectionnez un port série secondaire sur la carte à utiliser pour la communication avec l'hôte.
 * Cela permet de connecter des adaptateurs sans fil (par exemple) à des broches de port autres que celles par défaut.
 * Le port série -1 est le port série émulé par USB, s'il est disponible.
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
//#define SERIAL_PORT_2 -1

/**
 * Ce paramètre détermine la vitesse de communication de l'imprimante.
 *
 * 250000 fonctionne dans la plupart des cas, mais vous pouvez essayer
 * une vitesse inférieure si vous rencontrez fréquemment des abandons lors de l'impression
 * hôte. Vous pouvez essayer jusqu’à 1000000 pour accélérer le transfert de fichiers SD.
 *
 * :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
 */
#define BAUDRATE 250000

// Activer l'interface série Bluetooth sur les périphériques AT90USB
//#define BLUETOOTH

// Choisissez le nom de boards.h qui correspond à votre configuration
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_MKS_BASE
#endif

// Nom affiché dans le message "Prêt" de l'écran LCD et dans le menu Info
#define CUSTOM_MACHINE_NAME "TEVO TORNADO"

// Identifiant unique de l'imprimante, utilisé par certains programmes pour différencier les machines.
// Choisissez le vôtre ou utilisez un service comme http://www.uuidgenerator.net/version4
//#define MACHINE_UUID "00000000-0000-0000-0000-000000000000"

// @section extruder

// Ceci définit le nombre d'extrudeurs
// :[1, 2, 3, 4, 5, 6]
#define EXTRUDERS 1

// Diamètre de filament généralement attendu (1,75, 2,85, 3,0, ...). Utilisé pour les capteurs volumétriques, de largeur de filament, etc.
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

// Pour Cyclops ou tout "multi-extrudeur" partageant une seule buse.
//#define SINGLENOZZLE

/**
 * Průša MK2 Multiplexeur à plusieurs matériaux à une buse et variantes.
 *
 * Ce dispositif permet à un pilote pas à pas sur une carte de
 * commande de commander deux à huit moteurs pas à pas, un à la
 * fois, d’une manière adaptée aux extrudeurs.
 *
 * Cette option permet uniquement au multiplexeur d'activer le changement d'outil.
 * Des options supplémentaires pour configurer les déplacements E personnalisés sont en attente.
 */
//#define MK2_MULTIPLEXER
#if ENABLED(MK2_MULTIPLEXER)
  // Remplacez les broches de sélection DIO par défaut ici, si nécessaire.
  // Certains fichiers de broches peuvent fournir des valeurs par défaut pour ces broches.
  //#define E_MUX0_PIN 40  // Toujours requis
  //#define E_MUX1_PIN 42  // Nécessaire pour 3 à 8 entrées
  //#define E_MUX2_PIN 44  // Nécessaire pour 5 à 8 entrées
#endif

/**
 * Unité multi-matériaux Prusa v2
 *
 * Requiert NOZZLE_PARK_FEATURE pour garer la tête d'impression en cas de défaillance de l'unité MMU.
 * Requiert EXTRUDEURS = 5
 *
 * Pour une configuration supplémentaire, voir Configuration_adv.h
 */
//#define PRUSA_MMU2

// Une extrudeuse double utilisant un seul moteur pas à pas
//#define SWITCHING_EXTRUDER
#if ENABLED(SWITCHING_EXTRUDER)
  #define SWITCHING_EXTRUDER_SERVO_NR 0
  #define SWITCHING_EXTRUDER_SERVO_ANGLES { 0, 90 } // Angles pour E0, E1 [, E2, E3]
  #if EXTRUDERS > 3
    #define SWITCHING_EXTRUDER_E23_SERVO_NR 1
  #endif
#endif

// Double buse utilisant un servomoteur pour élever / abaisser l'une des buses (ou les deux)
//#define SWITCHING_NOZZLE
#if ENABLED(SWITCHING_NOZZLE)
  #define SWITCHING_NOZZLE_SERVO_NR 0
  //#define SWITCHING_NOZZLE_E1_SERVO_NR 1          // Si deux servos sont utilisés, l'index du second
  #define SWITCHING_NOZZLE_SERVO_ANGLES { 0, 90 }   // Angles pour E0, E1 (simple servo) ou abaissés / surélevés (double servo)
#endif

/**
 * Deux chariots X séparés avec des extrudeuses qui se connectent à une pièce mobile
 * via un mécanisme d'accouplement à solénoïde. Nécessite SOL1_PIN et SOL2_PIN.
 */
//#define PARKING_EXTRUDER

/**
 * Deux chariots en X séparés avec des extrudeuses qui se connectent à une pièce en
 * mouvement via un mécanisme d'amarrage magnétique utilisant des mouvements et sans solénoïde
 *
 * projet   : https://www.thingiverse.com/thing:3080893
 * mouvements : https://youtu.be/0xCEiG9VS3k
 *             https://youtu.be/Bqbcs0CU2FE
 */
//#define MAGNETIC_PARKING_EXTRUDER

#if EITHER(PARKING_EXTRUDER, MAGNETIC_PARKING_EXTRUDER)

  #define PARKING_EXTRUDER_PARKING_X { -78, 184 }     // positions X pour garer les extrudeuses
  #define PARKING_EXTRUDER_GRAB_DISTANCE 1            // (mm) Distance à parcourir au-delà du point de stationnement pour saisir l'extrudeuse
  //#define MANUAL_SOLENOID_CONTROL                   // Contrôle manuel des solénoïdes d'amarrage avec M380 S / M381

  #if ENABLED(PARKING_EXTRUDER)

    #define PARKING_EXTRUDER_SOLENOIDS_INVERT           // Si activé, le solénoïde n'est PAS magnétisé avec une tension appliquée
    #define PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE LOW  // Le signal de broche LOW ou HIGH active la bobine
    #define PARKING_EXTRUDER_SOLENOIDS_DELAY 250        // (ms) Délai pour le champ magnétique. Aucun délai si 0 ou non défini.
    //#define MANUAL_SOLENOID_CONTROL                   // Contrôle manuel des solénoïdes d'amarrage avec M380 S / M381

  #elif ENABLED(MAGNETIC_PARKING_EXTRUDER)

    #define MPE_FAST_SPEED      9000      // (mm / m) Vitesse de déplacement avant le dernier point de distance
    #define MPE_SLOW_SPEED      4500      // (mm / m) Vitesse pour le dernier trajet parcouru jusqu'au parc et au couple
    #define MPE_TRAVEL_DISTANCE   10      // (mm) Dernier point de distance
    #define MPE_COMPENSATION       0      // Compensation de décalage -1, 0, 1 (multiplicateur) uniquement pour le couplage

  #endif

#endif

/**
 * Tête de commutation
 *
 * Prise en charge des têtes d’outil échangeables et ancrables, telles
 * que le changeur d’outil E3D.Les têtes d'outils sont verrouillées avec un servo.
 */
//#define SWITCHING_TOOLHEAD

/**
 * Tête d'outil à commutation magnétique
 *
 * Prend en charge les têtes d’outil échangeables et ancrables avec un mécanisme
 * d’arrimage magnétique utilisant le mouvement et aucun servo.
 */
//#define MAGNETIC_SWITCHING_TOOLHEAD

/**
 * Tête d'outil de commutation électromagnétique
 *
 * Parking pour la cinématique CoreXY / HBot.
 * Les têtes d'outils sont garées sur un bord et maintenues avec un électroaimant.
 * Prend en charge plus de 2 têtes d’outils. Voir https://youtu.be/JolbsAKTKf4
 */
//#define ELECTROMAGNETIC_SWITCHING_TOOLHEAD

#if ANY(SWITCHING_TOOLHEAD, MAGNETIC_SWITCHING_TOOLHEAD, ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
  #define SWITCHING_TOOLHEAD_Y_POS          235         // (mm) position Y du dock de la tête d’outil
  #define SWITCHING_TOOLHEAD_Y_SECURITY      10         // (mm) Distance de sécurité axe Y
  #define SWITCHING_TOOLHEAD_Y_CLEAR         60         // (mm) Distance minimale du support pour un axe X non obstrué
  #define SWITCHING_TOOLHEAD_X_POS          { 215, 0 }  // (mm) positions X pour garer les extrudeurs
  #if ENABLED(SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_SERVO_NR       2         // Index du servo connecteur
    #define SWITCHING_TOOLHEAD_SERVO_ANGLES { 0, 180 }  // (degrés) Angles pour verrouiller, déverrouiller
  #elif ENABLED(MAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Y_RELEASE      5         // (mm) Distance de sécurité axe Y
    #define SWITCHING_TOOLHEAD_X_SECURITY   { 90, 150 } // (mm) Distance de sécurité axe X (T0, T1)
    //#define PRIME_BEFORE_REMOVE                       // Amorcez la buse avant de quitter le support
    #if ENABLED(PRIME_BEFORE_REMOVE)
      #define SWITCHING_TOOLHEAD_PRIME_MM           20  // (mm)   Longueur de la première extrusion (amorçage)
      #define SWITCHING_TOOLHEAD_RETRACT_MM         10  // (mm)   Rétracter après la longueur d'amorçage
      #define SWITCHING_TOOLHEAD_PRIME_FEEDRATE    300  // (mm/m) Vitesse de la première extrusion (amorçage)
      #define SWITCHING_TOOLHEAD_RETRACT_FEEDRATE 2400  // (mm/m) Vitesse de rétraction
    #endif
  #elif ENABLED(ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Z_HOP          2         // (mm) distance Z pour la commutation
  #endif
#endif

/**
 * "Mixing Extruder"
 *   - Ajoute les codes G M163 et M164 pour définir et "valider" les facteurs de mixage actuels.
 *   - Étend les routines de progression pour déplacer plusieurs steppes proportionnellement au mixage.
 *   - Prise en charge optionnelle des outils virtuels prenant en charge 'M164 S <index>' de Repetier Firmware.
 *   - Cette mise en œuvre prend en charge jusqu'à deux extrudeuses de mélange.
 *   - Activez DIRECT_MIXING_IN_G1 pour M165 et mélangez dans G1 (à partir de l'implémentation de référence de Pia Taubert).
 */
//#define MIXING_EXTRUDER
#if ENABLED(MIXING_EXTRUDER)
  #define MIXING_STEPPERS 2        // Nombre de steppers dans votre extrudere de mélange
  #define MIXING_VIRTUAL_TOOLS 16  // Utilisez la méthode de l'outil virtuel avec M163 et M164
  //#define DIRECT_MIXING_IN_G1    // Autoriser les facteurs de mélange ABCDHI dans les commandes de mouvement G1
  //#define GRADIENT_MIX           // Prise en charge du mélange dégradé avec le M166 et l'écran LCD
  #if ENABLED(GRADIENT_MIX)
    //#define GRADIENT_VTOOL       // Ajouter M166 T pour utiliser un index V-tool comme alias de dégradé
  #endif
#endif

// Décalage des extrudeurs (décommentez si vous en utilisez plusieurs et comptez sur le firmware pour le positionner lors du changement).
// Le décalage doit être X = 0, Y = 0 pour l'extrudeur 0 hotend (extrudeur par défaut).
// Pour les autres hotends, c'est leur distance par rapport à l'extrudeuse 0 hotend.
//#define HOTEND_OFFSET_X { 0.0, 20.00 } // (mm) décalage X relatif pour chaque buse
//#define HOTEND_OFFSET_Y { 0.0, 5.00 }  // (mm) décalage Y relatif pour chaque buse
//#define HOTEND_OFFSET_Z { 0.0, 0.00 }  // (mm) décalage Z relatif pour chaque buse

// @section machine

/**
 * Contrôle de l'alimentation
 *
 * Activez et connectez l’alimentation au PS_ON_PIN.
 * Spécifiez si l'alimentation est active en HIGH ou active en LOW.
 */
//#define PSU_CONTROL
//#define PSU_NAME "Alimentation"

#if ENABLED(PSU_CONTROL)
  #define PSU_ACTIVE_HIGH false // Définissez 'false' pour ATX (1), 'true' pour X-Box (2)

  //#define PS_DEFAULT_OFF      // Gardez le courant coupé jusqu'à ce qu'il soit activé directement avec M80

  //#define AUTO_POWER_CONTROL  // Activer le contrôle automatique de la broche PS_ON
  #if ENABLED(AUTO_POWER_CONTROL)
    #define AUTO_POWER_FANS           // Allumez le bloc d'alimentation si les ventilateurs ont besoin d'énergie
    #define AUTO_POWER_E_FANS
    #define AUTO_POWER_CONTROLLERFAN
    #define AUTO_POWER_CHAMBER_FAN
    //#define AUTO_POWER_E_TEMP        50 // (°C) Allumer le PSU au dessus de cette température
    //#define AUTO_POWER_CHAMBER_TEMP  30 // (°C) Allumer le PSU au dessus de cette température
    #define POWER_TIMEOUT 30
  #endif
#endif

// @section temperature

//===========================================================================
//=========================== Réglages thermiques ===========================
//===========================================================================

/**
 * --NORMAL IS 4.7kohm PULLUP!-- 1kohm pullup peut être utilisé sur le capteur hotend, en utilisant la résistance et le tableau appropriés
 *
 * Temperature sensors available:
 *
 *    -4 : thermocouple avec AD8495
 *    -3 : thermocouple avec MAX31855 (uniquement pour le capteur 0)
 *    -2 : thermocouple avec MAX6675 (uniquement pour le capteur 0)
 *    -1 : thermocouple avec AD595
 *     0 : non utilisé
 *     1 : Thermistance 100k - le meilleur choix pour EPCOS 100k (4,7k pullup)
 *     2 : Thermistance 200k - ATC Semitec 204GT-2 (4,7k pullup)
 *     3 : Thermistance de Mendel-Parts (4,7k pullup)
 *     4 : Thermistance 10k !! ne l'utilisez pas pour un hotend. Cela donne une mauvaise résolution à haute température. !!
 *     5 : Thermistance 100K - ATC Semitec 104GT-2 / 104NT-4-R025H42G (utilisé dans ParCan et J-Head) (4,7k pull-up)
 *   501 : Thermistance Zonestar (Tronxy X3A) 100K
 *   512 : Thermistance hotend 100W RPW-Ultra (4,7k pullup)
 *     6 : 100k EPCOS - Pas aussi précis que le tableau 1 (créé à l'aide d'un thermocouple Fluke) (4.7k pullup)
 *     7 : Thermistance Honeywell 100 000 135-104LAG-J01 (4.7k pullup)
 *    71 : Thermistance Honeywell 100 000 135-104LAF-J01 (4.7k pullup)
 *     8 : 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup)
 *     9 : 100k GE Sensing AL03006-58.2K-97-G1 (4.7k pullup)
 *    10 : Thermistance de 100k RS 198-961(4.7k pullup)
 *    11 : thermistance 100k beta 3950 1% (4.7k pullup)
 *    12 : 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup) (calibré pour lit chauffé Makibox)
 *    13 : 100k Hisens 3950 1% jusqu'à 300 ° C pour hotend "Simple ONE" et "Hotend" All In ONE "
 *    15 : Étalonnage de thermistance 100k pour JGAurora A5 hotend
 *    18 : ATC Semitec 204GT-2 (4,7 Ko extensible) Dagoma.Fr - MKS_Base_DKU001327
 *    20 : le circuit PT100 présent dans l'Ultimainboard V2.x
 *    60 : Thermomètre de lit Kapton bêta = 3950 de 100k Maker's Tool Works
 *    61 : 100k Formbot / Vivedino 3950 350C thermistor 4.7k pullup
 *    66 : Thermistance 4,7 M haute température de Dyze Design
 *    67 : Thermistance 450C de SliceEngineering
 *    70 : la thermistance 100K trouvée dans le bq Hephestos 2
 *    75 : Thermopompe en silicium générique 100k avec thermistance NTC 100K MGB18-104F39050L32
 *
 *       Tables de tirage de 1 000 ohms - Ceci est atypique et nécessite de changer la résistance de 4,7k pour 1k.
 *                              (mais donne une plus grande précision et un PID plus stable)
 *    51 : Thermistance 100k - EPCOS(1k pullup)
 *    52 : Thermistance 200k - ATC Semitec 204GT-2 (1k pullup)
 *    55 : Thermistance 100k - ATC Semitec 104GT-2 (utilisé dans ParCan et J-Head)(1k pullup)
 *
 *  1047 : Pt1000 avec 4k7 pullup
 *  1010 : Pt1000 avec 1k pullup (non standard)
 *   147 : Pt1000 avec 4k7 pullup
 *   110 : Pt1000 avec 1k pullup (non standard)
 *
 *  1000 : Personnalisé - Spécifiez les paramètres dans Configuration_adv.h
 *
 *         Utilisez-les à des fins de test ou de développement. JAMAIS pour la machine de production.
 *   998 : Tableau factice qui indique TOUJOURS 25 ° C ou la température définie ci-dessous.
 *   999 : Tableau factice qui indique TOUJOURS 100 ° C ou la température définie ci-dessous.
 *
 * :{ '0':"Not used", '1':"100k / 4.7k - EPCOS", '2':"200k / 4.7k - ATC Semitec 204GT-2", '3':"Mendel-parts / 4.7k", '4':"10k !! do not use for a hotend. Bad resolution at high temp. !!", '5':"100K / 4.7k - ATC Semitec 104GT-2 (Used in ParCan & J-Head)", '501':"100K Zonestar (Tronxy X3A)", '512':"100k RPW-Ultra hotend thermistor", '6':"100k / 4.7k EPCOS - Not as accurate as Table 1", '7':"100k / 4.7k Honeywell 135-104LAG-J01", '8':"100k / 4.7k 0603 SMD Vishay NTCS0603E3104FXT", '9':"100k / 4.7k GE Sensing AL03006-58.2K-97-G1", '10':"100k / 4.7k RS 198-961", '11':"100k / 4.7k beta 3950 1%", '12':"100k / 4.7k 0603 SMD Vishay NTCS0603E3104FXT (calibrated for Makibox hot bed)", '13':"100k Hisens 3950  1% up to 300°C for hotend 'Simple ONE ' & hotend 'All In ONE'", '18':"ATC Semitec 204GT-2 (4.7k pullup) Dagoma.Fr - MKS_Base_DKU001327" '20':"PT100 (Ultimainboard V2.x)", '51':"100k / 1k - EPCOS", '52':"200k / 1k - ATC Semitec 204GT-2", '55':"100k / 1k - ATC Semitec 104GT-2 (Used in ParCan & J-Head)", '60':"100k Maker's Tool Works Kapton Bed Thermistor beta=3950", '61':"100k Formbot / Vivedino 3950 350C thermistor 4.7k pullup", '66':"Dyze Design 4.7M High Temperature thermistor", '67':"Slice Engineering 450C High Temperature thermistor", '70':"the 100K thermistor found in the bq Hephestos 2", '71':"100k / 4.7k Honeywell 135-104LAF-J01", '147':"Pt100 / 4.7k", '1047':"Pt1000 / 4.7k", '110':"Pt100 / 1k (non-standard)", '1010':"Pt1000 / 1k (non standard)", '-4':"Thermocouple + AD8495", '-3':"Thermocouple + MAX31855 (only for sensor 0)", '-2':"Thermocouple + MAX6675 (only for sensor 0)", '-1':"Thermocouple + AD595", '998':"Dummy 1", '999':"Dummy 2", '1000':"Custom thermistor params" }
 */
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_CHAMBER 0

// Lectures de température constante de la thermistance factice, à utiliser avec les modèles 998 et 999
#define DUMMY_THERMISTOR_998_VALUE 25
#define DUMMY_THERMISTOR_999_VALUE 100

// Utilisez le capteur de température 1 comme capteur redondant avec le capteur 0.
// Si les lectures des deux capteurs diffèrent trop, l'impression sera annulée.
//#define TEMP_SENSOR_1_AS_REDUNDANT
#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

#define TEMP_RESIDENCY_TIME     5  // (secondes) est le temps d'attendre que hotend se "stabilise" dans M109
#define TEMP_WINDOW              1  // (°C) Proximité de la température pour la temporisation "température atteinte"
#define TEMP_HYSTERESIS          3  // (°C) Différznce de température considérée "assez proche" de la cible

#define TEMP_BED_RESIDENCY_TIME 5  // (seconds) est le temps d'attendre que le lit se "stabilise" dans M190
#define TEMP_BED_WINDOW          1  // (°C) Proximité de la température pour la temporisation "température atteinte"
#define TEMP_BED_HYSTERESIS      3  // (°C) Différance de température considérée "assez proche" de la cible

// En dessous de cette température, le chauffage sera éteint
// car il indique probablement un fil de thermistance cassé.
#define HEATER_0_MINTEMP   5
#define HEATER_1_MINTEMP   5
#define HEATER_2_MINTEMP   5
#define HEATER_3_MINTEMP   5
#define HEATER_4_MINTEMP   5
#define HEATER_5_MINTEMP   5
#define BED_MINTEMP        5

// Au-dessus de cette température, le chauffage sera éteint.
// Cela peut protéger les composants contre la surchauffe, mais PAS contre les courts-circuits et les défaillances.
// (Utilisez MINTEMP pour la protection contre les courts-circuits / défaillances des thermistances.)
#define HEATER_0_MAXTEMP 300
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define HEATER_5_MAXTEMP 275
#define BED_MAXTEMP      150

//===========================================================================
//============================ Paramètres PID ===============================
//===========================================================================
// Guide de réglage PID ici: http://reprap.org/wiki/PID_Tuning
// en Français: https://www.youtube.com/watch?v=_2TSIjD6CBM

// Commentez la ligne suivante pour désactiver PID et activer bang-bang.
#define PIDTEMP
#define BANG_MAX 255     // Limite le courant à la buse en mode bang-bang; 255 = courant maximum
#define PID_MAX BANG_MAX // Limite le courant à la buse lorsque le PID est actif (voir PID_FUNCTIONAL_RANGE ci-dessous); 255 = courant maximum
#define PID_K1 0.95      // Facteur de lissage dans une boucle PID
#if ENABLED(PIDTEMP)
  #define PID_EDIT_MENU         // Ajoutez le réglage PID au menu "Paramètres avancés". (~ 700 octets de PROGMEM)
  #define PID_AUTOTUNE_MENU     // Ajoutez le réglage automatique du PID au menu "Paramètres avancés". (~ 250 octets de PROGMEM)
  //#define PID_DEBUG             // Envoie les données de débogage au port série.
  //#define PID_OPENLOOP 1        // Met le PID en boucle ouverte. M104 / M140 définit la puissance de sortie de 0 à PID_MAX
  //#define SLOW_PWM_HEATERS      // PWM avec très basse fréquence (environ 0,125 Hz = 8 s) et temps d'état minimal d'environ 1 s utile pour les appareils de chauffage alimentés par un relais
  //#define PID_PARAMS_PER_HOTEND // Utilise des paramètres PID distincts pour chaque extrudeur (utile pour les extrudeurs incompatibles)
                                  // Définir / obtenir avec gcode: M301 E [numéro d'extrudeuse, 0-2]
  #define PID_FUNCTIONAL_RANGE 10 // Si la différence de température entre la température cible et la température réelle est
                                  // supérieure à PID_FUNCTIONAL_RANGE, le PID est désactivé et le chauffage est réglé sur min / max.
// Hotend E3DV6

// PID à 235°C
  //#define  DEFAULT_Kp 17.02
  //#define  DEFAULT_Ki 1.19
  //#define  DEFAULT_Kd 60.65

      // PID TORNADO BUSE
  #define  DEFAULT_Kp 20.37
  #define  DEFAULT_Ki 1.50
  #define  DEFAULT_Kd 69.26

    // PID à 210°C
  //#define  DEFAULT_Kp 13.99
  //#define  DEFAULT_Ki 0.88
  //#define  DEFAULT_Kd 55.86

  // Si vous utilisez un hotend préconfiguré, vous pouvez utiliser l'un des ensembles de valeurs en le supprimant.

  // Ultimaker
  //#define DEFAULT_Kp 22.2
  //#define DEFAULT_Ki 1.08
  //#define DEFAULT_Kd 114

  // MakerGear
  //#define DEFAULT_Kp 7.0
  //#define DEFAULT_Ki 0.1
  //#define DEFAULT_Kd 12

  // Mendel Parts V9 on 12V
  //#define DEFAULT_Kp 63.0
  //#define DEFAULT_Ki 2.25
  //#define DEFAULT_Kd 440

#endif // PIDTEMP

//===========================================================================
//================= PID > Contrôle de la température du lit =================
//===========================================================================

/**
 * Chauffage de lit PID
 *
 * Si cette option est activée, définissez les constantes PID ci-dessous.
 * Si cette option est désactivée, bang-bang sera utilisé et BED_LIMIT_SWITCHING activera l'hystérésis.
 *
 * La fréquence PID sera la même que celle de l'extrudeur PWM.
 * Si PID_dT est la valeur par défaut et corrige le matériel / la configuration, cela signifie 7,689 Hz, ce qui convient parfaitement
 * pour entraîner une onde carrée dans une charge résistive et n’a pas d’impact significatif sur le chauffage FET. Cela fonctionne
 * également très bien sur un relais à semi-conducteurs Fotek SSR-10DA dans un appareil de chauffage de 250W. Si votre
 * configuration est sensiblement différente et que vous ne comprenez pas les problèmes en jeu, n'utilisez pas de PID de lit tant que
 * personne n'a vérifié que votre matériel fonctionne.
 */
#define PIDTEMPBED

//#define BED_LIMIT_SWITCHING

/**
 * Puissance maximale du lit
 * S'applique à toutes les formes de contrôle de lit (PID, bang bang et bang bang avec hystérésis).
 * Lorsqu'elle est définie sur une valeur inférieure à 255, active une forme de PWM sur le lit qui agit comme un diviseur. Ne l'utilisez donc
 * pas sauf si vous voulez activer PWM sur votre lit. (Voir le commentaire sur l'activation de PIDTEMPBED)
 */
#define MAX_BED_POWER 255 // limite le cycle de service au lit; 255 = courant maximum

#if ENABLED(PIDTEMPBED)
  #define MIN_BED_POWER 0
  //#define PID_BED_DEBUG // Envoie les données de débogage au port série.

   // Plateau d'origine Tornado

   // PID Plateu TORNADO REX
  #define  DEFAULT_bedKp 14.81
  #define  DEFAULT_bedKi 2.87
  #define  DEFAULT_bedKd 19.11


  //120V 250W Réchauffeur en silicone sous borosilicate de 4 mm (MendelMax 1.5+)
  //from FOPDT model - kp=.39 Tp=405 Tdead=66, Tc set to 79.2, facteur agressif de .15 (vs .1, 1, 10)
  //#define DEFAULT_bedKp 10.00
  //#define DEFAULT_bedKi .023
  //#define DEFAULT_bedKd 305.4

  //120V 250W Réchauffeur en silicone sous borosilicate de 4 mm (MendelMax 1.5+)
  //from pidautotune
  //#define DEFAULT_bedKp 97.1
  //#define DEFAULT_bedKi 1.41
  //#define DEFAULT_bedKd 1675.16

  // TROUVEZ VOTRE PROPRE: "M303 E-1 C8 S90" pour exécuter le réglage automatique sur le lit à 90 degrés pendant 8 cycles.
#endif // PIDTEMPBED

// @section extrudeur

/**
 * Empêcher l'extrusion si la température est inférieure à EXTRUDE_MINTEMP.
 * Ajoutez M302 pour définir la température d'extrusion minimale et /
 * ou activez et désactivez la prévention d'extrusion à froid.
 *
 * *** IL EST FORTEMENT RECOMMANDÉ DE LAISSER CETTE OPTION ACTIVÉE! ***
 */
#define PREVENT_COLD_EXTRUSION  // MODIFIE pour permettre de charger le filament pendant que la buse chauffe
#define EXTRUDE_MINTEMP 165

/**
 * Empêcher une seule extrusion plus longue que EXTRUDE_MAXLENGTH.
 * Remarque: pour les extrudeuses Bowden, faites-le suffisamment grand pour permettre le chargement / déchargement.
 */
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 300

//===========================================================================
//========================== Protection thermique  ==========================
//===========================================================================

/**
 * La protection thermique offre une protection supplémentaire à votre imprimante contre les
 * dommages et le feu. Marlin inclut toujours des plages de température minimum et maximum
 * sûres qui protègent contre les fils de thermistance cassés ou déconnectés
 *
 * Le problème: si une thermistance venait à tomber, elle signalera la
 * température beaucoup plus basse que l'air dans la pièce et le
 * micrologiciel maintiendra le chauffage en marche.
 *
 * Si vous obtenez des erreurs "Runaway thermique" ou "Chauffage
 * échoué", vous pouvez régler les détails dans Configuration_adv.h
 */

#define THERMAL_PROTECTION_HOTENDS // Activer la protection thermique pour tous les extrudeurs
#define THERMAL_PROTECTION_BED     // Activer la protection thermique pour le plateau chauffant
//#define THERMAL_PROTECTION_CHAMBER // Activer la protection thermique de la chambre chauffée

//===========================================================================
//============================= Réglages mécaniques =========================
//===========================================================================

// @section machine

// Supprimez la mise en commentaire de l'une de ces options pour activer la cinématique
// CoreXY, CoreXZ ou CoreYZ dans l'ordre habituel ou inversé
//#define COREXY
//#define COREXZ
//#define COREYZ
//#define COREYX
//#define COREZX
//#define COREZY

//===========================================================================
//======================== Paramètres de fin de course ======================
//===========================================================================

// @section homing

// Spécifiez ici tous les connecteurs d’arrêt final connectés à un switch quelconque ou à une sonde.
// Presque toutes les imprimantes en utiliseront un par axe. Les sondes utiliseront un ou plusieurs
// des connecteurs supplémentaires. Laissez indéfini toute valeur utilisée pour des objectifs sans switch ni sonde.
#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG
//#define USE_XMAX_PLUG
//#define USE_YMAX_PLUG
//#define USE_ZMAX_PLUG

// Activer le pull-up pour tous les arrêts pour empêcher un état flottant
#define ENDSTOPPULLUPS
#if DISABLED(ENDSTOPPULLUPS)
  // Désactiver ENDSTOPPULLUPS pour définir les PULLUPS individuellement
  //#define ENDSTOPPULLUP_XMAX
  //#define ENDSTOPPULLUP_YMAX
  //#define ENDSTOPPULLUP_ZMAX
  //#define ENDSTOPPULLUP_XMIN
  //#define ENDSTOPPULLUP_YMIN
  //#define ENDSTOPPULLUP_ZMIN
  //#define ENDSTOPPULLUP_ZMIN_PROBE
#endif

// Activer le pulldown pour tous les arrêts pour empêcher un état flottant
//#define ENDSTOPPULLDOWNS
#if DISABLED(ENDSTOPPULLDOWNS)
  // Désactiver ENDSTOPPULLDOWNS pour définir les pulldowns individuellement
  //#define ENDSTOPPULLDOWN_XMAX
  //#define ENDSTOPPULLDOWN_YMAX
  //#define ENDSTOPPULLDOWN_ZMAX
  //#define ENDSTOPPULLDOWN_XMIN
  //#define ENDSTOPPULLDOWN_YMIN
  //#define ENDSTOPPULLDOWN_ZMIN
  //#define ENDSTOPPULLDOWN_ZMIN_PROBE
#endif

// La butée mécanique avec COM à la masse et NC à Signal utilise ici "faux" (configuration la plus courante).
#define X_MIN_ENDSTOP_INVERTING true // Défini sur true pour inverser la logique du fin de course.
#define Y_MIN_ENDSTOP_INVERTING true // Défini sur true pour inverser la logique du fin de course.
#define Z_MIN_ENDSTOP_INVERTING true // Défini sur true pour inverser la logique du fin de course.
#define X_MAX_ENDSTOP_INVERTING false // Défini sur true pour inverser la logique du fin de course.
#define Y_MAX_ENDSTOP_INVERTING false // Défini sur true pour inverser la logique du fin de course.
#define Z_MAX_ENDSTOP_INVERTING false // Défini sur true pour inverser la logique du fin de course.
#define Z_MIN_PROBE_ENDSTOP_INVERTING false // Défini sur true pour inverser la logique de la sonde

/**
 * Pilotes pas à pas
 *
 * Ces paramètres permettent à Marlin d’ajuster le minutage du pilote pas à pas et des options avancées pour les pilotes pas à pas qui les
 * prennent en charge. Vous pouvez également remplacer les options de minutage dans Configuration_adv.h.
 *
 * A4988 est supposé pour les pilotes non spécifiés.
 *
 * Options: A4988, A5984, DRV8825, LV8729, L6470, TB6560, TB6600, TMC2100,
 *          TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
 *          TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
 *          TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
 *          TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
 * :['A4988', 'A5984', 'DRV8825', 'LV8729', 'L6470', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC26X', 'TMC26X_STANDALONE', 'TMC2660', 'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
 */
//#define X_DRIVER_TYPE  A4988
//#define Y_DRIVER_TYPE  A4988
//#define Z_DRIVER_TYPE  A4988
//#define X2_DRIVER_TYPE A4988
//#define Y2_DRIVER_TYPE A4988
//#define Z2_DRIVER_TYPE A4988
//#define E0_DRIVER_TYPE A4988
//#define E1_DRIVER_TYPE A4988
//#define E2_DRIVER_TYPE A4988
//#define E3_DRIVER_TYPE A4988
//#define E4_DRIVER_TYPE A4988
//#define E5_DRIVER_TYPE A4988

// Activez cette fonctionnalité si toutes les broches de fin de course activées sont capables d’interrompre le mouvement.
// Cela éliminera le besoin d'interroger les broches d'interruption, économisant ainsi de nombreux cycles de processeur.
//#define ENDSTOP_INTERRUPTS_FEATURE

/**
 * Filtre de bruit de fin de course
 *
 * Activer si votre sonde ou vos terminaux se déclenchent par erreur à cause de parasites.
 *
 * - Des valeurs plus élevées peuvent affecter la répétabilité ou la précision de certaines sondes de lit.
 * - Pour réparer le bruit, installez un condensateur en céramique 100nF sur la ligne avec le commutateur.
 * - Cette fonctionnalité n'est pas requise pour les micro-commutateurs courants montés sur des
 *   circuits imprimés basés sur la conception Makerbot, qui possèdent déjà le condensateur 100 nF.
 *
 * :[2,3,4,5,6,7]
 */
//#define ENDSTOP_NOISE_THRESHOLD 2

//=============================================================================
//=========================== Paramètres de mouvement =========================
//=============================================================================
// @section mouvement

/**
 * Paramètres par défaut
 *
 * Ces paramètres peuvent être réinitialisés par M502
 *
 * Notez que si EEPROM est activé, les valeurs enregistrées les remplaceront.
 */

/**
 * Avec cette option, chaque stepper E peut avoir ses propres facteurs pour
 * les réglages de mouvement suivants. Si moins de facteurs sont fournis que
 * le nombre total d'extrudeuses, la dernière valeur s'applique au reste.

 */
#define DISTINCT_E_FACTORS

/**
 * Pas d'axe par défaut par unité (pas / mm)
 * Modifiable avec M92
 *                                      X, Y, Z, E0 [, E1[, E2[, E3[, E4[, E5]]]]]
 */
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 79.76, 79.76, 399.2901, 400 }

/**
 * Débit d'alimentation maximum par défaut (mm / s)
 * Modifiable avec M203
 *                                      X, Y, Z, E0 [, E1[, E2[, E3[, E4[, E5]]]]]
 */
#define DEFAULT_MAX_FEEDRATE          { 250, 250, 30, 55 }

/**
 * Accélération maximale par défaut (changement / changement) = mm / s
 * (Vitesse maximale de départ pour les mouvements accélérés)
 * Modifiable avec M201
 *                                      X, Y, Z, E0 [, E1[, E2[, E3[, E4[, E5]]]]]
 */
#define DEFAULT_MAX_ACCELERATION      { 800, 800, 120, 10000 }

/**
 * Accélération par défaut (change/s) change = mm/s
 * Modifiable avec M204
 *
 *   M204 P    Accélération
 *   M204 R    Accélération pour la rétraction
 *   M204 T    Accélération pour le déplacement
 */
#define DEFAULT_ACCELERATION          800    // Accélération X, Y, Z et E pour les impression
#define DEFAULT_RETRACT_ACCELERATION  10000    // E accélération pour la rétraction
#define DEFAULT_TRAVEL_ACCELERATION   1500    // X, Y, Z accélération pour les déplacements (pas d'impression)

/**
 * Déviation de jonction
 *
 * Utilisez la déviation de jonction au lieu de la limitation de secousse traditionnelle (Jerk)
 *
 * Voir:
 *   https://reprap.org/forum/read.php?1,739819
 *   http://blog.kyneticcnc.com/2018/10/computing-junction-deviation-for-marlin.html
 */
//#define JUNCTION_DEVIATION
#if ENABLED(JUNCTION_DEVIATION)
  #define JUNCTION_DEVIATION_MM 0.02  // (mm) Distance du bord de jonction réel
#endif

/**
 * Jerk par défaut (mm / s)
 * Modifiable avec M205 X Y Z E
 *
 * "Jerk" spécifie le changement de vitesse minimum nécessitant une accélération.
 * Lors du changement de vitesse et de direction, si la différence est
 * inférieure à la valeur définie ici, cela peut se produire instantanément.
 */
#if DISABLED(JUNCTION_DEVIATION)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK  0.4
#endif

#define DEFAULT_EJERK    5.0  // Peut être utilisé par Linear Advance

/**
 * Accélération de la courbe en S
 *
 * Cette option élimine les vibrations pendant l’impression en ajustant une courbe de Bézier
 * pour l’accélération, ce qui produit des changements de direction beaucoup plus lisses.
 *
 * Voir https://github.com/synthetos/TinyG/wiki/Jerk-Controlled-Motion-Explained
 */
#define S_CURVE_ACCELERATION

//===========================================================================
//=========================== Options de sonde Z ============================
//===========================================================================
// @section sonde

//
// Voir http://marlinfw.org/docs/configuration/probes.html
//

/**
 * Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
 *
 * Activez cette option pour une sonde connectée à la broche de butée Z Min.
 */
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

/**
 * Z_MIN_PROBE_PIN
 *
 * Définissez cette broche si la sonde n'est pas connectée à Z_MIN_PIN.
 * Si non défini, la broche par défaut pour la carte mère sélectionnée sera utilisée
 * La plupart du temps, la valeur par défaut correspond à ce que vous souhaitez.
 *
 *  - L'option la plus simple consiste à utiliser un connecteur d'extrémité libre.
 *  - Utilisez 5V pour les capteurs alimentés (généralement inductifs).
 *
 *  - Les cartes RAMPS 1.3 / 1.4 peuvent utiliser les broches 5V, GND et Aux4-> D32:
 *    - Pour des commutateurs simples, connectez ...
 *      - commutateurs normalement fermés à GND et D32.
 *      - commutateurs normalement ouverts sur 5V et D32.
 *
 */
//#define Z_MIN_PROBE_PIN 32 // La broche 32 est la valeur par défaut sur la carte RAMPS

/**
 * Type de sonde
 *
 * Sondes à clé Allen, servo-sondes, sondes Z-Sled, FIX_MOUNTED_PROBE, etc.
 * Activez l'une de ces options pour utiliser le nivellement automatique du lit ci-dessous.
 */

/**
 * La "sonde manuelle" fournit un moyen d'effectuer le nivellement "automatique" du lit sans sonde.
 * Utilisez G29 à plusieurs reprises, en ajustant la hauteur en Z en chaque point avec
 * des commandes de mouvement ou (avec LCD_BED_LEVELING) le contrôleur LCD.
 */
//#define PROBE_MANUALLY
//#define MANUAL_PROBE_START_Z 0.2

/**
 * Une sonde à montage fixe ne se déploie pas ou nécessite un déploiement manuel.
 *   (par exemple, une sonde inductive ou un commutateur de sonde basé sur une buse.)
 */
//#define FIX_MOUNTED_PROBE

/**
 * Z Servo-sonde, comme un interrupteur de fin de course sur un bras rotatif.
 */
//#define Z_PROBE_SERVO_NR 0       // Defaults to SERVO 0 connector.
//#define Z_SERVO_ANGLES { 70, 0 } // Z Servo Deploy and Stow angles

/**
 * La sonde BLTouch utilise un capteur à effet Hall et émule un servo.
 */
//#define BLTOUCH

/**
 * Sonde Touch-MI par hotends.fr
 *
 * Cette sonde est déployée et activée en déplaçant l'axe X sur un aimant situé au bord du lit.
 * Par défaut, l'aimant est supposé être à gauche et activé par un "home"
 * Si l'aimant est à droite, activez et définissez TOUCH_MI_DEPLOY_XPOS sur la position de déploiement.
 *
 * Nécessite également: BABYSTEPPING, BABYSTEP_ZPROBE_OFFSET, Z_SAFE_HOMING,
 *                et un minimum de Z_HOMING_HEIGHT de 10.
 */
//#define TOUCH_MI_PROBE
#if ENABLED(TOUCH_MI_PROBE)
  #define TOUCH_MI_RETRACT_Z 4                  // Hauteur à laquelle la sonde se rétracte
  //#define TOUCH_MI_DEPLOY_XPOS (X_MAX_BED + 2)  // Pour un aimant sur le côté droit du lit
  //#define TOUCH_MI_MANUAL_DEPLOY                // Pour un déploiement manuel (menu LCD)
#endif

// Une sonde qui est déployée et rangée avec une broche solénoïde (SOL1_PIN)
//#define SOLENOID_PROBE

// Une sonde sur traîneau comme celles conçues par Charles Bell.
//#define Z_PROBE_SLED
//#define SLED_DOCKING_OFFSET 5  // La distance supplémentaire que l’axe X doit parcourir pour ramasser le traîneau.
                                 // 0 devrait aller bien mais vous pouvez le pousser plus loin si vous le souhaitez.

// Une sonde déployée en déplaçant l'axe des abscisses, telle que la sonde à crémaillère du Wilson II conçue par Marty Rice.
//#define RACK_AND_PINION_PROBE
#if ENABLED(RACK_AND_PINION_PROBE)
  #define Z_PROBE_DEPLOY_X  X_MIN_POS
  #define Z_PROBE_RETRACT_X X_MAX_POS
#endif

//
// Pour Z_PROBE_ALLEN_KEY, voir les exemples de configuration Delta.
//

/**
 * Décalage de la sonde à la buse (X, Y,Z), par rapport à (0, 0).
 * Les décalages X et Y doivent être des entiers.
 *
 * Dans l'exemple suivant, les décalages X et Y sont positifs:
 * #define X_PROBE_OFFSET_FROM_EXTRUDER 10
 * #define Y_PROBE_OFFSET_FROM_EXTRUDER 10
 *
 *     +-- BACK ---+
 *     |           |
 *   L |    (+) P  | R <-- sonde (20,20)
 *   E |           | I
 *   F | (-) N (+) | G <-- buse (10,10)
 *   T |           | H
 *     |    (-)    | T
 *     |           |
 *     O-- FRONT --+
 *   (0,0)
 */
#define X_PROBE_OFFSET_FROM_EXTRUDER 10  // Décalage X: - gauche + droite [de la buse]
#define Y_PROBE_OFFSET_FROM_EXTRUDER 10  // Décalage Y: - avant + derrière [la buse]
#define Z_PROBE_OFFSET_FROM_EXTRUDER 0   // Z offset: - dessous + dessus [la buse]

// Je laisse le décalage en Z à 0 et je le règle avec le Zoffset (à l'écran ou avec M851 Z...)

// Certains types de sondes doivent rester à l'écart des bords
#define MIN_PROBE_EDGE 0

// Vitesse de déplacement des axes X et Y (mm / m) entre les sondes
#define XY_PROBE_SPEED 8000

// Avance (mm / m) pour la première approche en double palpage (MULTIPLE_PROBING == 2)
#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z

// Avance (mm / m) pour la sonde "précise" de chaque point
#define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 2)

/**
 * Sondage Multiple
 *
 * Vous pouvez obtenir de meilleurs résultats en sondant 2 fois ou plus.
 * Avec EXTRA_PROBING, les lectures les plus atypiques seront ignorées.
 *
 * Un total de 2 sondes rapides / lentes avec une moyenne pondérée.
 * Un total de 3 ou plus ajoute des sondes plus lentes, et calcul la moyenne.
 */
#define MULTIPLE_PROBING 2
//#define EXTRA_PROBING    1

/**
 * Les sondes Z nécessitent un dégagement lors du déploiement, de l'arrimage et
 * du déplacement entre les points de la sonde pour éviter de heurter le lit et d'autres matériels.
 * Les sondes servo-montées nécessitent un espace supplémentaire pour la rotation du bras.
 * Les sondes inductives ont besoin d'espace pour ne pas se déclencher trop tôt.
 *
 * Utilisez ces paramètres pour spécifier la distance (mm) à laquelle soulever la
 * sonde (ou abaisser le lit). Les valeurs définies ici s’appliquent au-delà de tout décalage (négatif)
 * de la sonde Z défini avec Z_PROBE_OFFSET_FROM_EXTRUDER, M851 ou l’écran LCD.
 * Seules les valeurs entières> = 1 sont valables ici.
 *
 * Exemple: `M851 Z-5` avec un jeu de 4 => 9 mm du lit à la buse.
 *     Mais: `M851 Z + 1` avec un jeu de 2 => 2mm du lit à la buse.
 */
#define Z_CLEARANCE_DEPLOY_PROBE   10 // Dégagement Z pour le déploiement / stockage
#define Z_CLEARANCE_BETWEEN_PROBES  5 // Z Distance entre les points de sonde
#define Z_CLEARANCE_MULTI_PROBE     5 // Z Distance entre plusieurs sondes
//#define Z_AFTER_PROBING           5  // Position Z après avoir terminé le sondage

#define Z_PROBE_LOW_POINT          -2 // Plus grande distance en dessous du point de déclenchement à parcourir avant de s’arrêter

// Pour M851, donnez une plage de réglage du décalage de la sonde Z
#define Z_PROBE_OFFSET_RANGE_MIN -20
#define Z_PROBE_OFFSET_RANGE_MAX 20

// Activer le test de répétabilité M48 pour tester la précision de la sonde
//#define Z_MIN_PROBE_REPEATABILITY_TEST

// Avant le déploiement/l'arrimage, pause pour la confirmation de l'utilisateur
//#define PAUSE_BEFORE_DEPLOY_STOW
#if ENABLED(PAUSE_BEFORE_DEPLOY_STOW)
  //#define PAUSE_PROBE_DEPLOY_WHEN_TRIGGERED // Pour le déploiement manuel de la sonde Allenkey
#endif

/**
 * Activez un ou plusieurs des éléments suivants si l'analyse semble peu fiable.
 * Les chauffages et / ou les ventilateurs peuvent être désactivés pendant le sondage afin de minimiser
 * les perturbations électrique. Un délai peut également être ajouté pour permettre au bruit et aux vibrations de s'atténuer.
 * Ces options sont très utiles pour la sonde BLTouch, mais peuvent également
 * améliorer les lectures avec des sondes inductives et des capteurs piézo.
 */
//#define PROBING_HEATERS_OFF       // Éteignez les appareils de chauffage lors du sondage
#if ENABLED(PROBING_HEATERS_OFF)
  //#define WAIT_FOR_BED_HEATER     // Attendre que le lit se réchauffe entre les sondes (pour améliorer la précision)
#endif
//#define PROBING_FANS_OFF          // Éteignez les fans lors de la vérification
//#define PROBING_STEPPERS_OFF      // Désactivez les steppers (sauf si vous devez rester en position) lors du sondage
//#define DELAY_BEFORE_PROBING 200  // (ms) Pour empêcher les vibrations de déclencher des capteurs piézo

// Pour inverser les broches d'activation de pas à pas (actif Low), utilisez 0, sinon utilisez (actif High) 1
// :{ 0:'Low', 1:'High' }
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // Pour toutes les extrudeurs

// Désactive le moteur d'axe immédiatement lorsqu'il n'est pas utilisé.
// AVERTISSEMENT: lorsque les moteurs sont éteints, il y a un risque de perte de précision de la position!
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

// Avertir sur l'affichage de la précision éventuellement réduite
//#define DISABLE_REDUCED_ACCURACY_WARNING

// @section extrudeur

#define DISABLE_E false             // Pour tous les extrudeurs
#define DISABLE_INACTIVE_EXTRUDER  true // Ne garder que l'extrudeur actif activé

// @section machine

// Inverser la direction du moteur. Changer (ou inverser le connecteur du moteur) si un axe tourne dans le mauvais sens.
#define INVERT_X_DIR false
#define INVERT_Y_DIR false
#define INVERT_Z_DIR true

// @section extruder

// Pour l'extrudeur à entraînement direct v9 définie sur true, pour l'extrudeur à engrenage définie sur false.
#define INVERT_E0_DIR true
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false

// @section homing

//#define NO_MOTION_BEFORE_HOMING  // Interdire le mouvement jusqu'à ce que tous les axes aient été mis en "home"

//#define UNKNOWN_Z_NO_RAISE // Ne soulevez pas Z (abaissez le lit) si Z est "inconnu". Pour les lits qui tombent lorsque Z est éteint.

#define Z_HOMING_HEIGHT 20  // (mm) Hauteur minimale en Z avant le référencement (G28) pour le dégagement en Z au-dessus du lit, des pinces, ...
                             // Assurez-vous d’avoir cette distance sur votre Z_MAX_POS au cas où.

// Direction des fins de course lors de la prise d'origine. 1 = MAX, -1 = MIN
// :[-1,1]
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

// @section machine

// La taille du lit d'impression
#define X_BED_SIZE 320
#define Y_BED_SIZE 300

// Limites de déplacement (mm) après le référencement, correspondant aux positions de fin de course.
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 400

/**
 * Fins de course logiciel
 *
 * - Empêcher les déplacements en dehors des limites définies de la machine.
 * - Si vous le souhaitez, vous pouvez désactiver des axes individuelement.
 * - X et Y s'appliquent uniquement aux imprimantes cartésiennes.
 * - Utilisez 'M211' pour activer / désactiver les arrêts logiciels ou pour signaler l'état actuel
 */

// Les fins de course logicielles restreignent le mouvement dans les limites des coordonnées minimales
#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
#endif

// Les extrémités logicielles maximales limitent le mouvement dans les limites des coordonnées maximales
#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif

#if EITHER(MIN_SOFTWARE_ENDSTOPS, MAX_SOFTWARE_ENDSTOPS)
  #define SOFT_ENDSTOPS_MENU_ITEM  // Activer / Désactiver les terminaux logiciels à partir de l'écran LCD
#endif

/**
 * Capteurs de fin de filament
 * Des capteurs mécaniques ou optique sont utilisées pour vérifier la présence de filament.
 *
 * Les cartes basées sur RAMPS utilisent SERVO3_PIN pour le premier capteur de fin de filament.
 * Pour les autres cartes, vous devrez peut-être définir FIL_RUNOUT_PIN, FIL_RUNOUT2_PIN, etc.
 * Par défaut, le micrologiciel suppose HIGH = FILAMENT PRESENT.
 */
//#define FILAMENT_RUNOUT_SENSOR
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define NUM_RUNOUT_SENSORS   1     // Nombre de capteurs, jusqu'à un par extrudeur. Définissez un FIL_RUNOUT # _PIN pour chacun.
  #define FIL_RUNOUT_INVERTING false // Défini sur true pour inverser la logique du capteur.
  #define FIL_RUNOUT_PIN 19          // définie sur Z+ pour E0
  #define FIL_RUNOUT_PULLUP          // Utilisez un pull-up interne pour les capteurs de fin de filament.
  //#define FIL_RUNOUT_PULLDOWN      // Utilisez le pulldown interne pour les broches des capteurs de fin de filament.

  // Définissez une ou plusieurs commandes à exécuter en cas de fin de filament.
  // (Après «M412 H», Marlin demandera à l'hôte de gérer le processus.)
  #define FILAMENT_RUNOUT_SCRIPT "M600"

  // Après la détection du manque de filament, continuez d’imprimer cette longueur de filament
  // avant d’exécuter le script d’exécution. Utile pour un capteur au bout d'un tube d'alimentation
  // Requiert une SRAM de 4 octets par capteur, plus une surcharge de 4 octets.
  //#define FILAMENT_RUNOUT_DISTANCE_MM 25

  #ifdef FILAMENT_RUNOUT_DISTANCE_MM
    // Activez cette option pour utiliser un disque codeur (détecteur d'avancer de filament)
    // qui bascule la broche de sortie lorsque le filament se déplace. (Veillez à définir
    // FILAMENT_RUNOUT_DISTANCE_MM suffisamment grand pour éviter les faux positifs.)
    //#define FILAMENT_MOTION_SENSOR
  #endif
#endif

//===========================================================================
//=============================== Bed Leveling ==============================
//===========================================================================
// @section calibrage

/**
 * Choisissez l’une des options ci-dessous pour activer le nivellement de lit G29.
 * Les paramètres et le comportement de G29 changeront en fonction de votre sélection.
 *
 *  Si vous utilisez une sonde pour Z Homing, activez également Z_SAFE_HOMING!
 *
 * - AUTO_BED_LEVELING_3POINT
 *   Sonde 3 points arbitraires sur le lit (qui ne sont pas colinéaires)
 *   Vous spécifiez les coordonnées XY des 3 points.
 *   Le résultat est un seul plan incliné. Idéal pour un lit plat.
 *
 * - AUTO_BED_LEVELING_LINEAR
 *   Sondez plusieurs points dans une grille.
 *   Vous spécifiez le rectangle et la densité des points d'échantillonnage.
 *   Le résultat est un seul plan incliné. Idéal pour un lit plat.
 *
 * - AUTO_BED_LEVELING_BILINEAR
 *   Sondez plusieurs points dans une grille.
 *   Vous spécifiez le rectangle et la densité des points d'échantillonnage.
 *   Le résultat est un treillis, idéal pour les lits larges ou inégaux.
 *
 * - AUTO_BED_LEVELING_UBL (Nivellement de lit unifié)
 *   Un système complet de mise à niveau des lits combinant les caractéristiques
 *   et les avantages des autres systèmes. UBL comprend également des systèmes intégrés
 *   de génération de maillage, de validation de maillage et d'édition de maillage.
 *
 * - MESH_BED_LEVELING
 *   Sonder une grille manuellement
 *   Le résultat est un maillage, adapté aux lits de grande taille ou inégaux. (Voir BILINÉAIRE.)
 *   Pour les machines sans sonde, le maillage de lit fournit une méthode pour effectuer le nivellement
 *   par étapes afin que vous puissiez ajuster manuellement la hauteur en Z à chaque point de la grille.
 *   Avec un contrôleur LCD, le processus est guidé pas à pas.
 */
//#define AUTO_BED_LEVELING_3POINT
//#define AUTO_BED_LEVELING_LINEAR
//#define AUTO_BED_LEVELING_BILINEAR
//#define AUTO_BED_LEVELING_UBL
//#define MESH_BED_LEVELING

/**
 * Normalement, G28 laisse le nivellement désactivé à la fin. Activez
 * cette option pour que G28 restaure l'état de mise à niveau précédent.
 */
//#define RESTORE_LEVELING_AFTER_G28

/**
 * Activer la journalisation détaillée de G28, G29, M48, etc.
 * Activez avec la commande 'M111 S32'.
 * NOTE: Nécessite beaucoup de PROGMEM!
 */
//#define DEBUG_LEVELING_FEATURE

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_UBL)
  // Réduisez progressivement la correction de mise à niveau jusqu'à atteindre une hauteur définie,
  // point auquel le mouvement sera de niveau par rapport au plan XY de la machine.
  // La hauteur peut être réglée avec M420 Z <hauteur>
  #define ENABLE_LEVELING_FADE_HEIGHT

  // Pour les machines cartésiennes, au lieu de diviser les déplacements en limites de maillage, les
  // mouvements de fractionnement se divisent en petits segments, comme un triangle. Cela suit les
  // contours du lit de plus près que les mouvements rectilignes d'un bord à l'autre.
  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Longueur de tous les segments (sauf le dernier)

  /**
   * Activez l’outil Modèle de validation de maillage G26.
   */
  //#define G26_MESH_VALIDATION
  #if ENABLED(G26_MESH_VALIDATION)
    #define MESH_TEST_NOZZLE_SIZE    0.4  // (mm) Diamètre de la buse primaire.
    #define MESH_TEST_LAYER_HEIGHT   0.2  // (mm) Hauteur de couche par défaut pour l'outil de validation de maillage G26.
    #define MESH_TEST_HOTEND_TEMP  205    // (°C) Température de buse par défaut pour l'outil de validation de maillage G26.
    #define MESH_TEST_BED_TEMP      60    // (°C) Température de lit par défaut pour l'outil de validation de maillage G26.
    #define G26_XY_FEEDRATE         20    // (mm/s) vitesse de déplacement XY pour l'outil de validation de maillage G26.
  #endif

#endif

#if EITHER(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR)

  // Définissez le nombre de points de la grille par dimension.
  #define GRID_MAX_POINTS_X 5
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  // Définissez les limites du sondage (où la sonde peut atteindre).
  //#define LEFT_PROBE_BED_POSITION 0
  //#define RIGHT_PROBE_BED_POSITION 265
  //#define FRONT_PROBE_BED_POSITION 0
  //#define BACK_PROBE_BED_POSITION 300

  // Sonde le long de l'axe des Y, en avançant X après chaque colonne
  //#define PROBE_Y_FIRST

  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)

    // Au-delà de la grille sondée, continuez l'inclinaison implicite?
    // La valeur par défaut est de maintenir la hauteur du bord le plus proche.
    //#define EXTRAPOLATE_BEYOND_GRID

    //
    // Subdivision expérimentale de la grille par la méthode de Catmull-Rom.
    // Synthétise les points intermédiaires pour produire un maillage plus détaillé.
    //
    //#define ABL_BILINEAR_SUBDIVISION
    #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      // Nombre de subdivisions entre les points de sonde
      #define BILINEAR_SUBDIVISIONS 3
    #endif

  #endif

#elif ENABLED(AUTO_BED_LEVELING_UBL)

  //===========================================================================
  //========================= Unified Bed Leveling ============================
  //===========================================================================

  //#define MESH_EDIT_GFX_OVERLAY   // Afficher une superposition graphique lors de l'édition du maillage

  #define MESH_INSET 1              // Définir les limites du maillage comme une partie du lit
  #define GRID_MAX_POINTS_X 10      // Ne pas utiliser plus de 15 points par axe, implémentation limitée.
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  #define UBL_MESH_EDIT_MOVES_Z     // Les utilisateurs confirmés préfèrent aucun mouvement de buse
  #define UBL_SAVE_ACTIVE_ON_M500   // Enregistrer le maillage actuellement actif dans l'emplacement actuel avec M500

  //#define UBL_Z_RAISE_WHEN_OFF_MESH 2.5 // Lorsque la buse est hors du maillage, cette valeur est utilisée
                                          // comme valeur de correction de hauteur Z.

#elif ENABLED(MESH_BED_LEVELING)

  //===========================================================================
  //=================================== Mesh ==================================
  //===========================================================================

  #define MESH_INSET 10          // Définir les limites du maillage comme une partie du lit
  #define GRID_MAX_POINTS_X 3    // N'utilisez pas plus de 7 points par axe, implémentation limitée.
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  //#define MESH_G28_REST_ORIGIN // Après le référencement de tous les axes ('G28' ou 'G28 XYZ'), reposez Z sur Z_MIN_POS.

#endif // BED_LEVELING

/**
 * Points à explorer pour toutes les procédures de nivellement à 3 points.
 * Ignorez si les points sélectionnés automatiquement sont inadéquats.
 */
#if EITHER(AUTO_BED_LEVELING_3POINT, AUTO_BED_LEVELING_UBL)
  //#define PROBE_PT_1_X 15
  //#define PROBE_PT_1_Y 180
  //#define PROBE_PT_2_X 15
  //#define PROBE_PT_2_Y 20
  //#define PROBE_PT_3_X 170
  //#define PROBE_PT_3_Y 20
#endif

/**
 * Ajoutez un sous-menu de nivellement de lit pour ABL ou MBL.
 * Incluez une procédure guidée si la sonde manuelle est activée.
 */
//#define LCD_BED_LEVELING

#if ENABLED(LCD_BED_LEVELING)
  #define MESH_EDIT_Z_STEP  0.025 // (mm) Taille de pas tout en sondant manuellement l'axe Z.
  #define LCD_PROBE_Z_RANGE 4     // (mm) Plage Z centrée sur Z_MIN_POS pour le réglage Z de l'écran LCD
  //#define MESH_EDIT_MENU        // Ajouter un menu pour éditer des points de maillage
#endif

// Ajoutez un élément de menu pour vous déplacer entre les coins du lit pour un nivellement manuel du lit
#define LEVEL_BED_CORNERS

#if ENABLED(LEVEL_BED_CORNERS)
  #define LEVEL_CORNERS_INSET 30    // (mm) Un encart pour le nivellement des coins
  #define LEVEL_CORNERS_Z_HOP  4.0  // (mm) Déplacez la buse vers le haut avant de vous déplacer entre les coins
  #define LEVEL_CORNERS_HEIGHT 0.0  // (mm) Z hauteur de la buse aux points de nivellement
  #define LEVEL_CENTER_TOO        // Déplacer vers le centre après le dernier coin
#endif

/**
 * Commandes à exécuter à la fin du sondage G29.
 * Utile pour rétracter ou déplacer la sonde Z hors du chemin.
 */
//#define Z_PROBE_END_SCRIPT "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10"


// @section homing

// Le centre du lit est à (X = 0, Y = 0)
//#define BED_CENTER_AT_0_0

// Définissez manuellement la position initiale. Laissez indéfinis pour des réglages automatiques.
// Pour DELTA, il s’agit du centre haut du volume d’impression cartésien.
//#define MANUAL_X_HOME_POS 0
//#define MANUAL_Y_HOME_POS 0
//#define MANUAL_Z_HOME_POS 0

// Utilisez "Z Safe Homing" pour éviter le référencement avec une sonde Z en dehors de la zone du lit.
//
// Avec cette fonctionnalité activée:
//
// - Autorisez la prise d'origine Z uniquement après que les contacts de prise d'origine X et Y ET les moteurs pas à pas aient été activés.
// - Si les pilotes pas à pas sont désactivés, il faudra de nouveau X et Y avant Z.
// - Déplacez la sonde Z (ou la buse) sur un point XY défini avant le palpage d'origine lorsque tous les axes sont orientés (G28).
// - Empêchez le palpage lorsque la sonde Z est en dehors du lit.
//
//#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT ((X_BED_SIZE) / 2)    // Point X pour la prise d'origine Z lors de la prise d'origine tous les axes (G28).
  #define Z_SAFE_HOMING_Y_POINT ((Y_BED_SIZE) / 2)    // Point Y pour la prise d'origine Z lors de la prise d'origine tous les axes (G28).
#endif

// Homing speeds (mm/m)
#define HOMING_FEEDRATE_XY (60*60)
#define HOMING_FEEDRATE_Z  (15*60)

// Valider que les fins de course sont déclenchées sur les déplacements de prise d'origine
#define VALIDATE_HOMING_ENDSTOPS

// @section calibrage

/**
 * Compensation du lit en biais
 *
 * Cette fonction corrige les défauts d’alignement dans les axes XYZ.
 *
 * Suivez les étapes suivantes pour que le lit soit incliné dans le plan XY:
 *  1. Imprimer un carré de test (e.g., https://www.thingiverse.com/thing:2563185)
 *  2. Pour XY_DIAG_AC, mesurez la diagonale A à C
 *  3. Pour XY_DIAG_BD, mesurez la diagonale B vers D
 *  4. Pour XY_SIDE_AD, mesurez l’arête A à D
 *
 * Marlin calcule automatiquement les facteurs d'inclinaison à partir de ces mesures.
 * Les facteurs d'inclinaison peuvent également être calculés et définis manuellement:
 *
 *  - Calculer AB     : SQRT(2*AC*AC+2*BD*BD-4*AD*AD)/2
 *  - XY_SKEW_FACTOR : TAN(PI/2-ACOS((AC*AC-AB*AB-AD*AD)/(2*AB*AD)))
 *
 * Si vous le souhaitez, suivez la même procédure pour XZ et YZ.
 * Utilisez ces diagrammes pour référence:
 *
 *    Y                     Z                     Z
 *    ^     B-------C       ^     B-------C       ^     B-------C
 *    |    /       /        |    /       /        |    /       /
 *    |   /       /         |   /       /         |   /       /
 *    |  A-------D          |  A-------D          |  A-------D
 *    +-------------->X     +-------------->X     +-------------->Y
 *     XY_SKEW_FACTOR        XZ_SKEW_FACTOR        YZ_SKEW_FACTOR
 */
//#define SKEW_CORRECTION

#if ENABLED(SKEW_CORRECTION)
  // Entrez toutes les mesures de longueur ici:
  #define XY_DIAG_AC 282.8427124746
  #define XY_DIAG_BD 282.8427124746
  #define XY_SIDE_AD 200

  // Ou définissez les facteurs d'inclinaison par défaut directement ici
  // en remplaçant les mesures ci-dessus:
  #define XY_SKEW_FACTOR 0.0

  //#define SKEW_CORRECTION_FOR_Z
  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 282.8427124746
    #define XZ_DIAG_BD 282.8427124746
    #define YZ_DIAG_AC 282.8427124746
    #define YZ_DIAG_BD 282.8427124746
    #define YZ_SIDE_AD 200
    #define XZ_SKEW_FACTOR 0.0
    #define YZ_SKEW_FACTOR 0.0
  #endif

  // Activer cette option pour M852 pour définir l'inclinaison au moment de l'exécution
  //#define SKEW_CORRECTION_GCODE
#endif

//=============================================================================
//====================== Caractéristiques supplémentaires =====================
//=============================================================================

// @section extras

/**
 * EEPROM
 *
 * Stockage persistant pour conserver les paramètres configurables lors des redémarrages.
 *
 *   M500 - Stocker les paramètres sur EEPROM.
 *   M501 - Lire les paramètres de l'EEPROM. (c'est-à-dire, jeter les modifications non enregistrées)
 *   M502 - Rétablir les paramètres par défaut aux paramètres d'usine. (Suivez avec M500 pour lancer la mémoire EEPROM.)
 */
#define EEPROM_SETTINGS       // Stockage permanent avec M500 et M501
//#define DISABLE_M503        // Enregistre environ 2700 octets de PROGMEM. Désactiver pour la libération!
#define EEPROM_CHITCHAT       // Donner des commentaires sur les commandes EEPROM. Désactiver pour sauvegarder PROGMEM.
#if ENABLED(EEPROM_SETTINGS)
  //#define EEPROM_AUTO_INIT  // Init EEPROM automatiquement sur les erreurs.
#endif

//
// Host Keepalive
//
// Lorsqu'il est activé, Marlin enverra un message d'état "occupé" à l'hôte.
// toutes les deux secondes quand il ne peut pas accepter les commandes.
//
#define HOST_KEEPALIVE_FEATURE        // Désactivez cette option si votre hôte n'aime pas les messages keepalive
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Nombre de secondes entre les messages "occupé". Réglé avec M113.
#define BUSY_WHILE_HEATING            // Certains hôtes exigent des messages "occupé" même pendant le chauffage

//
// Observateur de mémoire libre M100
//
//#define M100_FREE_MEMORY_WATCHER    // Ajouter M100 (Free Memory Watcher) pour déboguer l'utilisation de la mémoire

//
// G20/G21 Prise en charge du mode pouces
//
//#define INCH_MODE_SUPPORT

//
// M149 Prise en charge des unités de température
//
//#define TEMPERATURE_UNITS_SUPPORT

// @section temperature

// Preheat Constants
#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 200
#define PREHEAT_1_TEMP_BED     60
#define PREHEAT_1_FAN_SPEED     0 // Valeur de 0 to 255

#define PREHEAT_2_LABEL       "PETG"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_FAN_SPEED     0 // Valeur de 0 to 255

/**
 * Nozzle Park
 *
 * Garez la buse à la position XYZ indiquée "inactif" ou à G27.
 *
 * Le paramètre "P" contrôle l'action appliquée sur l'axe Z:
 *
 *    P0  (Par défaut) Si Z est en dessous du "parc", Z relevez la buse.
 *    P1  Soulevez toujours la buse à la hauteur du Z-Park.
 *    P2  Soulevez la buse par quantité Z-park, limitée à Z_MAX_POS.
 */
#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  // Spécifiez une position de parcage sous la forme {X, Y, Z_raise}
  #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
  #define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) Avance des axes X et Y (également utilisée pour l'axe Z delta)
  #define NOZZLE_PARK_Z_FEEDRATE 5     // (mm/s) Avance sur l'axe Z (non utilisée pour les imprimantes delta)
#endif

/**
 * Fonction de buse propre - EXPÉRIMENTAL
 *
 * Ajoute la commande G12 pour effectuer un processus de nettoyage des buses.
 *
 * Paramètres:
 *   P  Modèle
 *   S  Coups / répétitions
 *   T  Triangles (P1 seulement)
 *
 * Modèles:
 *   P0  Ligne droite (par défaut). Ce processus nécessite un matériau de type éponge à un
 *       emplacement de lit fixe. "S" spécifie des traits (c'est-à-dire des mouvements
 *       de va-et-vient) entre les points de départ et d'arrivée

 *
 *   P1  Motif en zig-zag compris entre (X0, Y0) et (X1, Y1), "T" spécifie le
 *       nombre de trianglesen zig-zag à effectuer. "S" définit le nombre de coups.
 *       Les zigzags sont effectués selon la dimension la plus étroite.
 *       Par exemple, "G12 P1 S1 T3" sera exécutera:
 *
 *          --
 *         |  (X0, Y1) |     /\        /\        /\     | (X1, Y1)
 *         |           |    /  \      /  \      /  \    |
 *       A |           |   /    \    /    \    /    \   |
 *         |           |  /      \  /      \  /      \  |
 *         |  (X0, Y0) | /        \/        \/        \ | (X1, Y0)
 *          --         +--------------------------------+
 *                       |________|_________|_________|
 *                           T1        T2        T3
 *
 *   P2  Motif circulaire avec milieu à NOZZLE_CLEAN_CIRCLE_MIDDLE.
 *       "R" spécifie le rayon. "S" spécifie le nombre de coups.
 *       Avant de commencer, la buse passe à NOZZLE_CLEAN_START_POINT.
 *
 *   Mises en garde: le Z final doit être identique au début de Z.
 * Aattention: EXPÉRIMENTAL. Les arguments de Gcode peuvent changer.
 *
 */
//#define NOZZLE_CLEAN_FEATURE

#if ENABLED(NOZZLE_CLEAN_FEATURE)
  // Nombre de répétitions de motifs par défaut
  #define NOZZLE_CLEAN_STROKES  12

  // Nombre de triangles par défaut
  #define NOZZLE_CLEAN_TRIANGLES  3

  // Spécifiez les positions comme {X, Y, Z}
  #define NOZZLE_CLEAN_START_POINT { 30, 30, (Z_MIN_POS + 1)}
  #define NOZZLE_CLEAN_END_POINT   { 100, 60, (Z_MIN_POS + 1) }

  // Rayon de motif circulaire
  #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5
  // Nombre de fragments de cercle de motif circulaire
  #define NOZZLE_CLEAN_CIRCLE_FN 10
  // Point milieu du cercle
  #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT

  // Déplacez la buse dans la position initiale après le nettoyage
  #define NOZZLE_CLEAN_GOBACK

  // Activer pour une station de purge / nettoyage toujours à la hauteur du portique (donc pas de mouvement en Z)
  //#define NOZZLE_CLEAN_NO_Z
#endif

/**
 * Minuterie d'impression
 *
 * Démarrez et arrêtez automatiquement le minuteur de travail d'impression sur M104 / M109 / M190.
 *
 *   M104 (hotend, pas d'attente) - Température haute = aucun                , basse température = arrêter la minuterie
 *   M109 (hotend, attente)       - Température haute = démarrer la minuterie, basse température = arrêter la minuterie
 *   M190 (bed, attente)          - Température haute = démarrer la minuterie, basse température = aucun
 *
 * La minuterie peut également être contrôlée avec les commandes suivantes:
 *
 *   M75 - Démarrer le minuteur du travail d'impression
 *   M76 - Suspendre le minuteur du travail d'impression
 *   M77 - Arrêter le minuteur du travail d'impression
 */
#define PRINTJOB_TIMER_AUTOSTART

/**
 * Compteur d'impression
 *
 * Suivre des données statistiques telles que:
 *
 *  - Total des travaux d'impression
 *  - Total des travaux d'impression réussis
 *  - Total des travaux d'impression ayant échoué
 *  - Temps total d'impression
 *
 * Affichez les statistiques actuelles avec M78.
 */
//#define PRINTCOUNTER

//=============================================================================
//============================= Support LCD et SD =============================
//=============================================================================

// @section lcd

/**
 * LANGUE LCD
 *
 * Sélectionnez la langue à afficher sur l'écran LCD. Ces langues sont disponibles:
 *
 *    en, an, bg, ca, cz, da, de, el, el-gr, es, eu, fi, fr, gl, hr, it,
 *    jp-kana, ko_KR, nl, pl, pt, pt-br, ru, sk, tr, uk, zh_CN, zh_TW, test
 *
 * :{ 'en':'English', 'an':'Aragonese', 'bg':'Bulgarian', 'ca':'Catalan', 'cz':'Czech', 'da':'Danish', 'de':'German', 'el':'Greek', 'el-gr':'Greek (Greece)', 'es':'Spanish', 'eu':'Basque-Euskera', 'fi':'Finnish', 'fr':'French', 'gl':'Galician', 'hr':'Croatian', 'it':'Italian', 'jp-kana':'Japanese', 'ko_KR':'Korean (South Korea)', 'nl':'Dutch', 'pl':'Polish', 'pt':'Portuguese', 'pt-br':'Portuguese (Brazilian)', 'ru':'Russian', 'sk':'Slovak', 'tr':'Turkish', 'uk':'Ukrainian', 'zh_CN':'Chinese (Simplified)', 'zh_TW':'Chinese (Traditional)', 'test':'TEST' }
 */
#define LCD_LANGUAGE fr

/**
 * Jeu de caractères LCD
 *
 * Remarque: cette option n'est PAS applicable aux affichages graphiques.
 *
 * Tous les écrans à cristaux liquides basés sur les caractères
 * fournissent l'ASCII plus une de ces extensions de langue:
 *
 *  - JAPANESE ... le plus commun
 *  - WESTERN  ... avec plus de caractères accentués
 *  - CYRILLIC ... pour la langue russe
 *
 * Pour déterminer l’extension linguistique installée sur votre contrôleur:
 *
 *  - Compilez et téléchargez avec LCD_LANGUAGE défini sur 'test'
 *  - Cliquez sur le contrôleur pour afficher le menu LCD
 *  - L’écran LCD affichera du texte japonais, occidental ou cyrillique
 *
 * Voir http://marlinfw.org/docs/development/lcd_language.html
 *
 * :['JAPANESE', 'WESTERN', 'CYRILLIC']
 */
#define DISPLAY_CHARSET_HD44780 JAPANESE

/**
 * Style d'écran d'information (0: Classique, 1: Prusa)
 */
#define LCD_INFO_SCREEN_STYLE 0

/**
 * CARTE SD
 *
 * La prise en charge de la carte SD est désactivée par défaut. Si votre contrôleur possède
 * un emplacement SD, vous devez dé-commenter la ligne suivante, sinon cela ne fonctionnera pas.
 *
 */
#define SDSUPPORT

/**
 * SD CARD: SPI SPEED
 *
 * Activez l'un des éléments suivants pour une vitesse de transfert SPI plus lente.
 * Cela peut être nécessaire pour résoudre les erreurs "volume init".
 */
//#define SPI_SPEED SPI_HALF_SPEED
//#define SPI_SPEED SPI_QUARTER_SPEED
//#define SPI_SPEED SPI_EIGHTH_SPEED

/**
 * CARTE SD: ACTIVER LE CRC
 *
 * Utilisez les contrôles et les tentatives CRC sur la communication SD.
 */
//#define SD_CHECK_AND_RETRY

/**
 * Éléments de menu LCD
 *
 * Désactivez tous les menus et n’affiche que l’écran d’état, ou supprimez
 * simplement des éléments de menu superflus pour récupérer de l’espace.
 */
//#define NO_LCD_MENUS
//#define SLIM_LCD_MENUS

//
// PARAMETRES DU CODEUR (roue codeuse ou touches)
//
// Cette option annule le nombre par défaut d'impulsions de codeur nécessaires pour
// produire une étape. Devra être augmenté pour les encodeurs haute résolution.
//
#define ENCODER_PULSES_PER_STEP 4

//
// Utilisez cette option pour remplacer le nombre de signaux de pas
// nécessaires pour passer d'un élément de menu suivant à un autre.
//
#define ENCODER_STEPS_PER_MENU_ITEM 1

/**
 * Options de direction du codeur
 *
 * Testez d'abord le comportement de votre encodeur avec les deux options désactivées.
 *
 *  Valeur inversée Menu et navigation dans le menu? Activer REVERSE_ENCODER_DIRECTION.
 *  Menu inversé uniquement? Activez REVERSE_MENU_DIRECTION.
 *  Valeur inversée Modification uniquement? Activer les deux options.
 */

//
// Cette option inverse le sens du codeur partout.
//
//  Définissez cette option si une rotation dans le sens horaire entraîne une diminution des valeurs
//
#define REVERSE_ENCODER_DIRECTION

//
// Cette option inverse le sens du codeur pour la navigation dans les menus LCD.
//
//  Si une rotation dans le sens horaire doit faire diminuer la valeur, cela la fait monter.
//  Si une rotation dans le sens horaire doit faire augmenter la valeur, cela la fait descendre.
//
//#define REVERSE_MENU_DIRECTION

//
// Cette option inverse le sens du codeur pour Sélectionner l’écran.
//
//  Si une rotation dans le sens horaire doit faire déplacer à GAUCHE, cela le fait aller à DROITE.
//  Si une rotation dans le sens horaire doit faire déplacer à DROITE, cela le fait aller à GAUCHE.
//
//#define REVERSE_SELECT_DIRECTION

//
// Homing des axes individualisé
//
// Ajoutez des éléments de référencement d'axe individuels (Accueil X, Accueil Y et Accueil Z) au menu LCD.
//
#define INDIVIDUAL_AXIS_HOMING_MENU

//
// SPEAKER/BUZZER
//
// Si vous avez un haut-parleur capable de produire des sons, activez-le ici.
// Par défaut, Marlin suppose que vous avez une sonnerie à fréquence fixe.
//
//#define SPEAKER

//
// La durée et la fréquence du son de retour de l'interface utilisateur.
// Définissez-les sur 0 pour désactiver le retour audio dans les menus de l'écran LCD.
//
// Remarque: Testez la sortie audio avec le Gcode:
//  M300 S<fréquence Hz> P<durée ms>
//
//#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2
//#define LCD_FEEDBACK_FREQUENCY_HZ 5000

//=============================================================================
//======================== LCD / Controller Selection =========================
//========================   (Character-based LCDs)   =========================
//=============================================================================

//
// Contrôleur intelligent RepRapDiscount.
// http://reprap.org/wiki/RepRapDiscount_Smart_Controller
//
// Remarque: généralement vendu avec un circuit imprimé blanc.
//
//#define REPRAP_DISCOUNT_SMART_CONTROLLER

//
// Ecran LCD RADDS original + Encodeur + Lecteur de carte SD
// http://doku.radds.org/dokumentation/lcd-display/
//
//#define RADDS_DISPLAY

//
// Contrôleur ULTIMAKER.
//
//#define ULTIMAKERCONTROLLER

//
// ULTIPANEL tel que vu dans Thingiverse.
//
//#define ULTIPANEL

//
// PanelOne à partir de T3P3 (via RAMPS 1.4 AUX2 / AUX3)
// http://reprap.org/wiki/PanelOne
//
//#define PANEL_ONE

//
// Contrôleur LCD / SD GADGETS3D G3D
// http://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
//
// Remarque: généralement vendu avec un circuit imprimé bleu.
//
//#define G3D_PANEL

//
// RigidBot Panel V1.0
// http://www.inventapart.com/
//
//#define RIGIDBOT_PANEL

//
// Makeboard 3D Printer Pièces Contrôleur Mini Printer Imprimante 3D Mini Contrôleur 1602
// https://www.aliexpress.com/item/Micromake-Makeboard-3D-Printer-Parts-3D-Printer-Mini-Display-1602-Mini-Controller-Compatible-with-Ramps-1/32765887917.html
//
//#define MAKEBOARD_MINI_2_LINE_DISPLAY_1602

//
// Contrôleur ANET et Tronxy 20x4
//
//#define ZONESTAR_LCD            // Requiert que ADC_KEYPAD_PIN soit affecté à une broche analogique.
                                  // Cet écran LCD est connu pour être sujet à des interférences électriques
                                  // qui brouillent l'affichage. Appuyez sur n’importe quel bouton pour l’effacer.
                                  // Ceci est un écran LCD2004 avec 5 boutons analogiques.

//
// Écran LCD générique à base de caractères 16x2, 16x4, 20x2 ou 20x4.
//
//#define ULTRA_LCD

//=============================================================================
//======================== LCD / Controller Selection =========================
//=====================   (I2C and Shift-Register LCDs)   =====================
//=============================================================================

//
// Contrôleur TYPE: I2C
//
// Remarque: Ces contrôleurs nécessitent l’installation du logiciel LiquidCrystal_I2C d’Arduino.
// Pour plus d'informations: https://github.com/kiyoshigawa/LiquidCrystal_I2C
//

//
// Panneau de configuration Elefu RA Board
// http://www.elefu.com/index.php?route=product/product&product_id=53
//
//#define RA_CONTROL_PANEL

//
// Sainsmart (YwRobot) Écrans LCD
//
// Ceux-ci nécessitent la bibliothèque LiquidCrystal_I2C de F.Malpartida
// https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home
//
//#define LCD_SAINSMART_I2C_1602
//#define LCD_SAINSMART_I2C_2004

//
// Adaptateur LCD LCM1602 générique
//
//#define LCM1602

//
// PANELOLU2 LCD avec voyants d'état,
// séparez le codeur et cliquez sur les entrées.
//
// Remarque: Ce contrôleur requiert la bibliothèque LiquidTWI2 v1.2.3 ou ultérieure d'Arduino.
// Pour plus d'informations: https://github.com/lincomatic/LiquidTWI2
//
// Remarque: le poussoir de l'encodeur PANELOLU2 peut être soit directement connectée à une
// broche (si BTN_ENC est définie sur! = -1), soit lue via I2C (lorsque BTN_ENC == -1).
//
//#define LCD_I2C_PANELOLU2

//
// Panucatt VIKI LCD avec voyants d'état,
// boutons intégrés click & L / R / U / D, entrées codeur séparées.
//
//#define LCD_I2C_VIKI

//
// CONTRÔLEUR DE TYPE : Panneaux de registre à décalage
//

//
// LCD SR à 2 fils non verrouillable à partir de https://goo.gl/aJJ4sH
// Configuration de l'écran LCD: http://reprap.org/wiki/SAV_3D_LCD
//
//#define SAV_3DLCD

//
// LCD SR à 3 fils avec stroboscope utilisant 74HC4094
// https://github.com/mikeshub/SailfishLCD
// Utilise le code directement à partir de Sailfish
//
//#define FF_INTERFACEBOARD

//=============================================================================
//=======================   LCD / Controller Selection  =======================
//=========================      (Graphical LCDs)      ========================
//=============================================================================

//
// TYPE DE CONTROLEUR: Graphique 128x64 (DOGM)
//
// IMPORTANT: La bibliothèque U8glib est requise pour l'affichage graphique!
//            https://github.com/olikraus/U8glib_Arduino
//

//
// RepRapDiscount FULL GRAPHIC Smart Controller
// http://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
//
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

//
// LCD graphique ReprapWorld
// https://reprapworld.com/?products_details&products_id/1218
//
//#define REPRAPWORLD_GRAPHICAL_LCD

//
// Activez l’un d’eux si vous avez un appareil Panucatt
// Viki 2.0 ou mini Viki avec LCD graphique
// http://panucatt.com
//
//#define VIKI2
//#define miniVIKI

//
// MakerLab Mini Panel avec graphique
// controller and SD support - http://reprap.org/wiki/Mini_panel
//
//#define MINIPANEL

//
// MaKr3d Makr-Panel avec contrôleur graphique et support SD.
// http://reprap.org/wiki/MaKr3d_MaKrPanel
//
//#define MAKRPANEL

//
// Contrôleur graphique complet Adafruit ST7565.
// https://github.com/eboston/Adafruit-ST7565-Full-Graphic-Controller/
//
//#define ELB_FULL_GRAPHIC_CONTROLLER

//
// Le contrôleur intelligent LCD BQ est livré par
// défaut avec le BQ Hephestos 2 et la Witbox 2.
//
//#define BQ_LCD_SMART_CONTROLLER

//
// Cartesio UI
// http://mauk.cc/webshop/cartesio-shop/electronics/user-interface
//
//#define CARTESIO_UI

//
// LCD pour Melzi Card avec LCD graphique
//
//#define LCD_FOR_MELZI

//
// Ulticontroller original de l'imprimante Ultimaker 2 avec écran SSD1309 I2C et encodeur
// https://github.com/Ultimaker/Ultimaker2/tree/master/1249_Ulticontroller_Board_(x1)
//
//#define ULTI_CONTROLLER

//
// MKS MINI12864 avec contrôleur graphique et support SD
// https://reprap.org/wiki/MKS_MINI_12864
//
//#define MKS_MINI_12864

//
// Variante FYSETC du contrôleur graphique MINI12864 avec prise en charge SD
// https://wiki.fysetc.com/Mini12864_Panel/
//
//#define FYSETC_MINI_12864_X_X  // Type C / D / E / F. Pas de rétroéclairage RVB ajustable par défaut
//#define FYSETC_MINI_12864_1_2  // Type C / D / E / F. Rétro-éclairage RVB simple (toujours allumé)
//#define FYSETC_MINI_12864_2_0  // Type A/B. Rétroéclairage RVB discret
//#define FYSETC_MINI_12864_2_1  // Type A/B. Rétro-éclairage RVB Neopixel

//
// Affichage d'usine pour Creality CR-10
// https://www.aliexpress.com/item/Universal-LCD-12864-3D-Printer-Display-Screen-With-Encoder-For-CR-10-CR-7-Model/32833148327.html
//
// Ceci est compatible avec RAMPS en utilisant un seul connecteur à 10 broches.
// (Pour les propriétaires de CR-10 qui souhaitent remplacer le tableau Melzi Creality mais conservent l'affichage)
//
//#define CR10_STOCKDISPLAY

//
// ANET et contrôleur graphique Tronxy
//
// Ecran LCD graphique complet Anet 128x64 avec encodeur rotatif utilisé sur Anet A6
// Un clone de l'affichage graphique complet RepRapDiscount
// mais avec des broches / câblage différents (voir pins_ANET_10.h).
//
//#define ANET_FULL_GRAPHICS_LCD

//
// AZSMZ 12864 LCD avec SD
// https://www.aliexpress.com/store/product/3D-printer-smart-controller-SMART-RAMPS-OR-RAMPS-1-4-LCD-12864-LCD-control-panel-green/2179173_32213636460.html
//
//#define AZSMZ_12864

//
// Contrôleur Silvergate GLCD
// http://github.com/android444/Silvergate
//
//#define SILVER_GATE_GLCD_CONTROLLER

//=============================================================================
//=============================  Afficheurs OLED  =============================
//=============================================================================

//
// SSD1306 Affichage générique graphique complet OLED
//
//#define U8GLIB_SSD1306

//
// Prise en charge des modules LCD SAV OLEd à l'aide de modules LCD basés sur SSD1306 ou SH1106
//
//#define SAV_3DGLCD
#if ENABLED(SAV_3DGLCD)
  #define U8GLIB_SSD1306
  //#define U8GLIB_SH1106
#endif

//
// TinyBoy2 Panneau OLED / encodeur 128x64
//
//#define OLED_PANEL_TINYBOY2

//
// CONTRÔLEUR FULL GRAPHICS MKS OLED 1.3 "128 × 64
// http://reprap.org/wiki/MKS_12864OLED
//
// Écran OLED minuscule mais très net
//
//#define MKS_12864OLED          // Utilise le contrôleur SH1106 (par défaut)
//#define MKS_12864OLED_SSD1306  // Utilise le contrôleur SSD1306

//
// Einstart S OLED SSD1306
//
//#define U8GLIB_SH1106_EINSTART

//
// Afficheur / contrôleur Overlord OLED avec buzzer i2c et voyants
//
//#define OVERLORD_OLED

//=============================================================================
//============== Affichages d'interface utilisateur extensibles ===============
//=============================================================================

//
// Écran tactile DGUS avec DWIN OS
//
//#define DGUS_LCD

//
// LCD à écran tactile pour imprimantes Malyan M200
//
//#define MALYAN_LCD

//
// Interfaces de contrôleur tierces ou personnalisées par le fournisseur.
// Les sources doivent être installées dans 'src / lcd / extensible_ui'.
//
//#define EXTENSIBLE_UI

//=============================================================================
//=============================== TFT graphiques ==============================
//=============================================================================

//
// Écran FSMC (MKS Robin, Alfawise U20, JGAurora A5S, A1, etc.)
//
//#define FSMC_GRAPHICAL_TFT

//=============================================================================
//===========================  Autres contrôleurs  ============================
//=============================================================================

//
// ADS7843/XPT2046 ADC Écran tactile tel que ILI9341 2.8
//
//#define TOUCH_BUTTONS
#if ENABLED(TOUCH_BUTTONS)
  #define XPT2046_X_CALIBRATION   12316
  #define XPT2046_Y_CALIBRATION  -8981
  #define XPT2046_X_OFFSET       -43
  #define XPT2046_Y_OFFSET        257
#endif

//
// RepRapWorld REPRAPWORLD_KEYPAD v1.1
// http://reprapworld.com/?products_details&products_id=202&cPath=1591_1626
//
// REPRAPWORLD_KEYPAD_MOVE_STEP définit le déplacement de l'imprimante
// lorsqu'une touche est enfoncée. Une valeur de 10.0 signifie 10 mm par clic.
//
//#define REPRAPWORLD_KEYPAD
//#define REPRAPWORLD_KEYPAD_MOVE_STEP 10.0

//=============================================================================
//====================== Fonctionnalités supplémentaires ======================
//=============================================================================

// @section extras

// Augmentez la fréquence FAN PWM. Supprime le bruit PWM mais augmente le chauffage dans le FET / Arduino
//#define FAST_PWM_FAN

// Utilisez le logiciel PWM pour piloter le ventilateur, comme pour les chauffages. Ceci utilise
// une très basse fréquence qui n'est pas aussi bruillante qu'avec le PWM matériel. D'autre part,
// si cette fréquence est trop basse, vous devez également incrémenter SOFT_PWM_SCALE.
//#define FAN_SOFT_PWM

// L'incrémentation de 1 double la fréquence logicielle PWM, ce qui
// affecte les chauffages et le ventilateur si FAN_SOFT_PWM est activé.
// Cependant, la résolution de contrôle sera divisée par deux pour
// chaque incrément. à zéro, il y a 128 positions de contrôle effectives.
// :[0,1,2,3,4,5,6,7]
#define SOFT_PWM_SCALE 0

// Si SOFT_PWM_SCALE est défini sur une valeur supérieure à 0, le
// dithering peut être utilisé pour atténuer la perte de résolution
// associée. Si cette option est activée, certains des cycles PWM sont
// étirés afin que le cycle de travail souhaité soit atteint en moyenne.
//#define SOFT_PWM_DITHER

// LED d’état de la température qui affichent la température de la buse et du lit. Si tous
// les points chauds, la température du lit et la température cible sont inférieurs à 54 ° C
// le voyant BLEU est allumé. Sinon, la led ROUGE est allumée. (Hystérésis 1C)
//#define TEMP_STAT_LEDS

// SkeinForge sends the wrong arc g-codes when using Arc Point as fillet procedure
// ~~SkeinForge envoie les codes d'erreur d'arc incorrects lorsque vous utilisez Arc Point comme procédure de congé~~
//#define SF_ARC_FIX

// Prise en charge de l'extrudeuse de pâte BariCUDA
//#define BARICUDA

// Prise en charge de BlinkM / CyzRgb
//#define BLINKM

// Prise en charge du pilote PCA9632 PWM LED
//#define PCA9632

// Prise en charge du pilote de LED PWM PCA9533
// https://github.com/mikeshub/SailfishRGB_LED
//#define PCA9533

/**
 * Contrôle de bande RVB LED / LED
 *
 * Activer la prise en charge d'une LED RVB connectée à des broches numériques 5V ou
 * d'une bande RGB connectée à des transistors MOSFET contrôlés par des broches numériques.
 *
 * Ajoute la commande M150 pour définir la couleur des voyants (ou des bandes de voyants).
 * Si les broches sont compatibles PWM (par exemple 4, 5, 6, 11),
 * une plage de valeurs de luminance peut être définie entre 0 et 255.
 * Pour "Neopixel LED", un paramètre de luminosité globale est également disponible.
 *
 * *** MISE EN GARDE ***
 *  Les bandes de LED nécessitent un MOSFET entre les lignes PWM
 *  et les LED, car Arduino ne peut pas gérer le courant requis par les LED.
 *  Ne pas suivre cette précaution peut détruire votre carte électronique!
 *  REMARQUE: une alimentation séparée de 5 V est requise! La LED Neopixel
 *  a besoin de plus de courant que le régulateur linéaire Arduino 5V ne peut en produire.
 * *** MISE EN GARDE ***
 *
 * Type de LED. N'activez qu'une des deux options suivantes.
 *
 */
//#define RGB_LED
//#define RGBW_LED

#if EITHER(RGB_LED, RGBW_LED)
  //#define RGB_LED_R_PIN 34
  //#define RGB_LED_G_PIN 43
  //#define RGB_LED_B_PIN 35
  //#define RGB_LED_W_PIN -1
#endif

// Prise en charge du pilote Adafruit Neopixel LED
//#define NEOPIXEL_LED
#if ENABLED(NEOPIXEL_LED)
  #define NEOPIXEL_TYPE   NEO_GRB // NEO_GRBW / NEO_GRB - type de pilote quatre / trois canaux (défini dans Adafruit_NeoPixel.h)
  #define NEOPIXEL_PIN     4       // Pin de pilotage de LED
  //#define NEOPIXEL2_TYPE NEOPIXEL_TYPE
  //#define NEOPIXEL2_PIN    5
  #define NEOPIXEL_PIXELS 8       // Nombre de LED dans la bande, plus grand que 2 bandes si 2 bandes néopixel sont utilisées
  #define NEOPIXEL_IS_SEQUENTIAL   // Affichage séquentiel pour le changement de température - LED par LED. Désactiver pour changer tous les voyants à la fois.
  #define NEOPIXEL_BRIGHTNESS 10  // Luminosité initiale (0-255)
  #define NEOPIXEL_STARTUP_TEST  // Faire défiler les couleurs au démarrage

  // Utilisez une seule LED Neopixel pour un éclairage statique (arrière-plan)
  //#define NEOPIXEL_BKGD_LED_INDEX  0               // Index de la LED à utiliser
  //#define NEOPIXEL_BKGD_COLOR { 255, 255, 255, 0 } // R, G, B, W
#endif

/**
 * Visuels d'événement de l'imprimante
 *
 * Pendant l’impression, les voyants reflètent l’état de l’imprimante:
 *
 *  - Passez progressivement du bleu au violet lorsque le lit chauffant atteint la température cible
 *  - Passe graduellement du violet au rouge au fur et à mesure que la buse se réchauffe
 *  - Changer en blanc pour éclairer la surface de travail
 *  - Changer en vert une fois l'impression terminée
 *  - Eteindre lorsque l'impression est terminée et que l'utilisateur a appuyé sur un bouton
 */
#if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
  #define PRINTER_EVENT_LEDS
#endif

/**
 * Support R / C SERVO
 * Sponsorisé par TrinityLabs, retravaillé par codexmas
 */

/**
 * Nombre de servos
 *
 * Pour certaines options liées au servo, NUM_SERVOS sera défini automatiquement.
 * Réglez ceci manuellement s'il y a des servos supplémentaires nécessitant un contrôle manuel.
 * Laissez indéfini ou mis à 0 pour désactiver complètement le sous-système servo.
 */
//#define NUM_SERVOS 3 // L'index servo commence par 0 pour la commande M280

// Délai (en millisecondes) avant que le prochain mouvement ne commence, pour donner au servo le temps d'atteindre son angle cible.
// 300ms est une bonne valeur mais vous pouvez essayer moins de retard.
// Si le servo ne peut pas atteindre la position demandée, augmentez-la.
#define SERVO_DELAY { 300 }

// N'alimentez les servos que pendant le mouvement, sinon laissez-les éteints pour éviter les tremblements
//#define DEACTIVATE_SERVOS_AFTER_MOVE

// Permettre à l’angle du servo d’être édité et sauvegardé sur EEPROM
//#define EDITABLE_SERVO_ANGLES
