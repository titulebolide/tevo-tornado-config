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
 * Configuration_adv.h
 *
 * Réglages avancés.
 * Ne les changez que si vous savez exactement ce que vous faites.
 * Certains de ces paramètres peuvent endommager votre imprimante s’ils ne sont pas correctement configurés!
 *
 * Les paramètres de base peuvent être trouvés dans Configuration.h
 *
 */
#define CONFIGURATION_ADV_H_VERSION 020000

// @section temperature

//===========================================================================
//===========================Réglages thermiques  ===========================
//===========================================================================

//
// Paramètres personnalisés du Thermistor 1000
//
#if TEMP_SENSOR_0 == 1000
  #define HOTEND0_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND0_RESISTANCE_25C_OHMS  100000  // Résistance à 25C°
  #define HOTEND0_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_1 == 1000
  #define HOTEND1_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND1_RESISTANCE_25C_OHMS  100000  // Résistance à 25C°
  #define HOTEND1_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_2 == 1000
  #define HOTEND2_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND2_RESISTANCE_25C_OHMS  100000  // Résistance à 25C°
  #define HOTEND2_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_3 == 1000
  #define HOTEND3_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND3_RESISTANCE_25C_OHMS  100000  // Résistance à 25C°
  #define HOTEND3_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_4 == 1000
  #define HOTEND4_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND4_RESISTANCE_25C_OHMS  100000  // Résistance à 25C°
  #define HOTEND4_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_5 == 1000
  #define HOTEND5_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND5_RESISTANCE_25C_OHMS  100000  // Résistance à 25C°
  #define HOTEND5_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_BED == 1000
  #define BED_PULLUP_RESISTOR_OHMS     4700    // Résistance pullup
  #define BED_RESISTANCE_25C_OHMS      100000  // Résistance à 25C°
  #define BED_BETA                     3950    // Valeur bêta
#endif

#if TEMP_SENSOR_CHAMBER == 1000
  #define CHAMBER_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define CHAMBER_RESISTANCE_25C_OHMS  100000  // Résistance à 25C°
  #define CHAMBER_BETA                 3950    // Valeur bêta
#endif

//
// Kit d'amélioration de lit chauffant Hephestos 2 24V.
// https://store.bq.com/en/heated-bed-kit-hephestos2
//
//#define HEPHESTOS2_HEATED_BED_KIT
#if ENABLED(HEPHESTOS2_HEATED_BED_KIT)
  #undef TEMP_SENSOR_BED
  #define TEMP_SENSOR_BED 70
  #define HEATER_BED_INVERTING true
#endif

/**
 * Paramètres de la "chambre chauffée"
 */
#if TEMP_SENSOR_CHAMBER
  #define CHAMBER_MINTEMP             5
  #define CHAMBER_MAXTEMP            60
  #define TEMP_CHAMBER_HYSTERESIS     1   // (°C) Proximité de la température considérée "assez proche" de la cible
  //#define CHAMBER_LIMIT_SWITCHING
  //#define HEATER_CHAMBER_PIN       44   // Broche marche / arrêt de la chambre de chauffage
  //#define HEATER_CHAMBER_INVERTING false
#endif

#if DISABLED(PIDTEMPBED)
  #define BED_CHECK_INTERVAL 5000 // ms entre les vérifications dans le contrôle bang bang
  #if ENABLED(BED_LIMIT_SWITCHING)
    #define BED_HYSTERESIS 2 // Désactiver le chauffage uniquement si T> target + BED_HYSTERESIS et activer le chauffage si T> target-BED_HYSTERESIS
  #endif
#endif

/**
 * La protection thermique offre une protection supplémentaire à votre imprimante contre les
 * dommages et le feu. Marlin inclut toujours des plages de température minimum et
 * maximum sécuritaires qui protègent contre les fils de thermistance cassés ou déconnectés.
 *
 * Le problème: si une thermistance venait à tomber, elle signalera la
 * température beaucoup plus basse de l'air dans la pièce et le
 * micrologiciel maintiendra le chauffage en marche.
 *
 * La solution: dès que la température atteint la cible, commencez à observer.
 * Si la température reste trop longtemps en dessous de la cible (hystérésis) pendant
 * trop longtemps (période), le micrologiciel arrêtera la machine par mesure de sécurité.
 *
 * Si vous obtenez des faux positifs pour "Emballement thermique", augmentez
 * THERMAL_PROTECTION_HYSTERESIS and/or THERMAL_PROTECTION_PERIOD
 */
#if ENABLED(THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD 40        // Secondes
  #define THERMAL_PROTECTION_HYSTERESIS 4     // Degrés Celsius

  //#define ADAPTIVE_FAN_SLOWING              // Ventilateur de refroidissement lent si la température baisse
  #if BOTH(ADAPTIVE_FAN_SLOWING, PIDTEMP)
    //#define NO_FAN_SLOWING_IN_PID_TUNING    // Ne ralentissez pas la vitesse du ventilateur pendant le M303
  #endif

  /**
   * Chaque fois qu'un M104, M109 ou M303 augmente la température
   * cible, le micrologiciel attendra l'expiration de WATCH_TEMP_PERIOD.
   * Si la température n'a pas augmenté de WATCH_TEMP_INCREASE, la machine est arrêtée et
   * nécessite une réinitialisation matérielle. Ce test redémarre avec n'importe quel M104 / M109 / M303,
   * mais uniquement si la température actuelle est suffisamment éloignée
   * de la cible pour permettre un test fiable.
   *
   * Si vous obtenez des faux positifs pour "Échec du chauffage", augmentez
   * WATCH_TEMP_PERIOD et / ou diminuez WATCH_TEMP_INCREASE.
   * WATCH_TEMP_INCREASE ne doit pas être défini en dessous de 2.
   */
  #define WATCH_TEMP_PERIOD 20                   // Secondes
  #define WATCH_TEMP_INCREASE 2                  // Degrés Celsius
#endif

/**
 * Les paramètres de protection thermique du lit sont identiques à ceux décrits ci-dessus pour les hotends.
 */
#if ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD 20       // Secondes
  #define THERMAL_PROTECTION_BED_HYSTERESIS 2    // Degrés Celsius

  /**
   * Comme décrit ci-dessus, sauf pour le lit (M140 / M190 / M303).
   */
  #define WATCH_BED_TEMP_PERIOD 60                // Secondes
  #define WATCH_BED_TEMP_INCREASE 2               // Degrés Celsius
#endif

/**
 * Paramètres de protection thermique pour la chambre chauffée.
 */
#if ENABLED(THERMAL_PROTECTION_CHAMBER)
  #define THERMAL_PROTECTION_CHAMBER_PERIOD 20    // Secondes
  #define THERMAL_PROTECTION_CHAMBER_HYSTERESIS 2 // Degrés Celsius

  /**
   * Réglages de la surveillance à chambre chauffée (M141 / M191).
   */
  #define WATCH_CHAMBER_TEMP_PERIOD 60            // Secondes
  #define WATCH_CHAMBER_TEMP_INCREASE 2           // Degrés Celsius
#endif

#if ENABLED(PIDTEMP)
  // Ajoutez un terme supplémentaire expérimental à la puissance de chauffage, proportionnel à la vitesse d'extrusion.
  // Une valeur de Kc bien choisie devrait ajouter juste assez de puissance pour faire fondre le volume accru de matériau.
  //#define PID_EXTRUSION_SCALING
  #if ENABLED(PID_EXTRUSION_SCALING)
    #define DEFAULT_Kc (100) //puissance de chauffage = Kc * (vitesse du E)
    #define LPQ_MAX_LEN 50
  #endif
#endif

/**
 * Température automatique:
 * La température cible de la buse est calculée par toutes les lignes de gcode mises en mémoire tampon.
 * Le nombre maximum de step/s du moteur de l’extrudeuse est appelé "se".
 * Lancer le mode temp automatique avec M109 S <mintemp> B <maxtemp> F <facteur>
 * La température cible est définie sur mintemp + factor * se [pas / s] et est
 * limitée par mintemp et maxtemp. Désactivez cette option en exécutant M109 sans F *
 * De plus, si la température est réglée sur une valeur inférieure à mintemp, elle ne sera pas modifiée par autotemp.
 * Sur un Ultimaker, certains tests initiaux ont fonctionné avec M109 S215 B260 F1 dans le code de démarrage
 */
#define AUTOTEMP
#if ENABLED(AUTOTEMP)
  #define AUTOTEMP_OLDWEIGHT 0.98
#endif

// Afficher les informations de position supplémentaires dans M114
//#define M114_DETAIL

// Afficher la valeur de la température ADC
// Activez M105 pour inclure les valeurs ADC lues par les capteurs de température.
//#define SHOW_TEMP_ADC_VALUES

/**
 * Support de thermistance à haute température
 * Les thermistances capables de supporter des températures élevées
 * ont tendance à avoir du mal à obtenir de bonnes lectures à la
 * température ambiante et à basses températures. Cela signifie que
 * HEATER_X_RAW_LO_TEMP sera probablement intercepté lors de la
 * première activation de l'élément chauffant pendant le processus de préchauffage, ce qui
 * déclenchera une erreur min_temp_error par mesure de sécurité et forcera tout à arrêter.
 * Pour contourner cette limitation, nous autorisons un temps de
 * préchauffage (pendant lequel min_temp_error ne sera pas déclenché)
 * et ajoutons un tampon min_temp pour gérer les lectures aberrantes.
 *
 * Si vous souhaitez activer cette fonction pour que votre thermistance hotend
 * ne décommente pas et définisse des valeurs> 0 dans les constantes ci-dessous
 */

// Nombre d'erreurs consécutives à basse température pouvant survenir avant
// le déclenchement d'une erreur min_temp_error. (Ne devrait pas excéder 10.)
//#define MAX_CONSECUTIVE_LOW_TEMPERATURE_ERROR_ALLOWED 0

// Le nombre de millisecondes pendant lesquelles la buse va chauffer avant de commencer à
// vérifier la température. Cette valeur NE DOIT PAS être définie sur le temps nécessaire
// à l'extrémité chaude pour atteindre la température cible, mais au temps nécessaire
// pour atteindre la température minimale que votre thermistance peut lire
// Plus bas, mieux c'est / plus sûr. Cela ne devrait pas nécessiter plus de 30 secondes (30000)
//#define MILLISECONDS_PREHEAT_TIME 0

// @section extruder

// Extruusion préventive.
// Si la machine est inactive et que la température dépasse MINTEMP,
// extrudez du filament par couple de SECONDES.
//#define EXTRUDER_RUNOUT_PREVENT
#if ENABLED(EXTRUDER_RUNOUT_PREVENT)
  #define EXTRUDER_RUNOUT_MINTEMP 190
  #define EXTRUDER_RUNOUT_SECONDS 30
  #define EXTRUDER_RUNOUT_SPEED 1500  // (mm/m)
  #define EXTRUDER_RUNOUT_EXTRUDE 5   // (mm)
#endif

// @section temperature

// Calibrage du capteur AD595 / AD8495 pour ajuster les mesures de température.
// La température finale est calculée comme suit: (T° MESURÉE * GAIN) + OFFSET.
#define TEMP_SENSOR_AD595_OFFSET  0.0
#define TEMP_SENSOR_AD595_GAIN    1.0
#define TEMP_SENSOR_AD8495_OFFSET 0.0
#define TEMP_SENSOR_AD8495_GAIN   1.0

/**
 * Ventilateur du contrôleur
 * Pour refroidir les drivers pas à pas et les MOSFET.
 *
 * Le ventilateur se mettra automatiquement en marche chaque fois qu'un stepper est
 * activé et s'éteindra après une période définie après la désactivation de tous les steppers.
 */
//#define USE_CONTROLLER_FAN
#if ENABLED(USE_CONTROLLER_FAN)
  //#define CONTROLLER_FAN_PIN -1        // Définir une broche personnalisée pour le ventilateur du contrôleur
  #define CONTROLLERFAN_SECS 60          // Durée en secondes pour que le ventilateur fonctionne après la désactivation de tous les moteurs
  #define CONTROLLERFAN_SPEED 255        // 255 == pleine vitesse
#endif

// Lorsque vous démarrez le ventilateur principal pour la première fois, faites-le
// tourner à pleine vitesse pendant le nombre de millisecondes indiqué. Le ventilateur tourne de manière fiable avant de définir
// une valeur PWM. (Ne fonctionne pas avec le logiciel PWM for fan sur Sanguinololu)
//#define FAN_KICKSTART_TIME 100

/**
 * Mise à l'échelle du ventilateur PWM
 *
 * Définissez les vitesses min / max pour les ventilateurs PWM (comme défini avec M106).
 *
 * Avec ces options, la plage de valeurs M106 0-255 est réduite à un sous-ensemble pour garantir
 * que le ventilateur dispose de suffisamment de puissance pour tourner ou pour faire fonctionner
 * des ventilateurs à courant réduit avec un courant supérieur. (par exemple
 * ventilateurs 5V / 12V avec 12V / 24V) La valeur 0 éteint toujours le ventilateur.
 *
 * Définissez un ou les deux pour remplacer la plage par défaut de 0 à 255.
 */
//#define FAN_MIN_PWM 50
//#define FAN_MAX_PWM 128

/**
 * Paramètres FAST PWM FAN
 *
 * Utilisez pour changer la fréquence FAST FAN PWM (si activé dans Configuration.h)
 * Des combinaisons de modes PWM, de valeurs de pré-échelle et de résolutions TOP sont utilisées
 * en interne pour produire une fréquence aussi proche que possible de la fréquence souhaitée.
 *
 * FAST_PWM_FAN_FREQUENCY [indéfini par défaut]
 *   Réglez-le sur la fréquence souhaitée.
 *   Si laissé non défini, la valeur par défaut est F = F_CPU / (2 * 255 * 1)
 *   Soit F = 31,4 kHz sur des microcontrôleurs à 16 MHz ou F = 39,2 KHz sur des microcontrôleurs à 20 MHz
 *   Ces valeurs par défaut sont identiques à celles de l'ancienne implémentation FAST_PWM_FAN - aucune migration n'est requise.
 *   REMARQUE: Le réglage de très basses fréquences (<10 Hz) peut entraîner un comportement inattendu de la minuterie.
 *
 * USE_OCR2A_AS_TOP [undefined by default]
 *   Boards that use TIMER2 for PWM have limitations resulting in only a few possible frequencies on TIMER2:
 *   16MHz MCUs: [62.5KHz, 31.4KHz (default), 7.8KHz, 3.92KHz, 1.95KHz, 977Hz, 488Hz, 244Hz, 60Hz, 122Hz, 30Hz]
 *   20MHz MCUs: [78.1KHz, 39.2KHz (default), 9.77KHz, 4.9KHz, 2.44KHz, 1.22KHz, 610Hz, 305Hz, 153Hz, 76Hz, 38Hz]
 *   A greater range can be achieved by enabling USE_OCR2A_AS_TOP. But note that this option blocks the use of
 *   PWM on pin OC2A. Only use this option if you don't need PWM on 0C2A. (Check your schematic.)
 *   USE_OCR2A_AS_TOP sacrifices duty cycle control resolution to achieve this broader range of frequencies.
 */
#if ENABLED(FAST_PWM_FAN)
  //#define FAST_PWM_FAN_FREQUENCY 31400
  //#define USE_OCR2A_AS_TOP
#endif

// @section extruder

/**
 * Ventilateurs des extrudeurs (ventilateur de refroidissement de la tête d'impression)
 *
 * Les ventilateurs automatiques d'extrudeuses s'allument automatiquement lorsque
 * la température de leurs extrudeuses dépasse EXTRUDER_AUTO_FAN_TEMPERATURE.
 *
 * Spécifiez Les Pins à utiliser sur la carte de votre imprimantes.
 * Remplacez les ici ou définissez le sur -1 pour le désactiver complètement.
 *
 * Plusieurs têtes peuvent être affectées à la même broche, auquel cas le ventilateur
 * se mettra en marche lorsque la tête sélectionnée sera au-dessus du seuil.
 */
#define E0_AUTO_FAN_PIN 7
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1
#define E5_AUTO_FAN_PIN -1
#define CHAMBER_AUTO_FAN_PIN -1

#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED 255   // 255 == pleine vitesse
#define CHAMBER_AUTO_FAN_TEMPERATURE 30
#define CHAMBER_AUTO_FAN_SPEED 255

/**
 * Multiplexeur de ventilateur de refroidissement partiel
 *
 * Cette fonction vous permet de multiplexer numériquement la sortie du ventilateur.
 * Le multiplexeur est automatiquement commuté au changement d’outil.
 * Définissez FANMUX [012] _PIN ci-dessous pour un maximum de 2, 4 ou 8 ventilateurs multiplexés.
 */
#define FANMUX0_PIN -1
#define FANMUX1_PIN -1
#define FANMUX2_PIN -1

/**
 * M355 Eclairage de caisson on-off / luminosité
 */
//#define CASE_LIGHT_ENABLE
#if ENABLED(CASE_LIGHT_ENABLE)
  //#define CASE_LIGHT_PIN 4                  // Remplacer la broche par défaut si nécessaire
  #define INVERT_CASE_LIGHT false             // Défini sur true si Case Light est allumé lorsque la broche est LOW
  #define CASE_LIGHT_DEFAULT_ON true          // Définir l'état de démarrage par défaut
  #define CASE_LIGHT_DEFAULT_BRIGHTNESS 105   // Définir la luminosité par défaut à la mise sous tension (0-255, requiert une broche PWM)
  //#define CASE_LIGHT_MENU                   // Ajouter des options Case Light au menu LCD
  //#define CASE_LIGHT_NO_BRIGHTNESS          // Désactiver le contrôle de la luminosité. Activer pour un éclairage non-PWM.
  //#define CASE_LIGHT_USE_NEOPIXEL           // Utilisez Neopixel LED comme boîtier, nécessite des NEOPIXEL_LED.
  #if ENABLED(CASE_LIGHT_USE_NEOPIXEL)
    #define CASE_LIGHT_NEOPIXEL_COLOR { 255, 255, 255, 255 } // { Rouge, vert, bleu, blanc }
  #endif
#endif

// @section homing

// Si vous voulez que les fins de course restent activées (par défaut), activez cette
// option même si vous ne l'utilisez pas Ignorez à tout moment avec M120, M121.
//#define ENDSTOPS_ALWAYS_ON_DEFAULT

// @section extras

//#define Z_LATE_ENABLE // Activer Z au dernier moment. Nécessaire si votre pilote Z surchauffe.

// Employer un contrôleur de boucle fermée externe. Remplacer les broches ici si nécessaire.
//#define EXTERNAL_CLOSED_LOOP_CONTROLLER
#if ENABLED(EXTERNAL_CLOSED_LOOP_CONTROLLER)
  //#define CLOSED_LOOP_ENABLE_PIN        -1
  //#define CLOSED_LOOP_MOVE_COMPLETE_PIN -1
#endif

/**
 * Dual Steppers / Dual Endstops
 *
 * Cette section vous permettra d'utiliser des pilotes E supplémentaires pour piloter un deuxième moteur pour les axes X, Y ou Z.
 *
 * Par exemple, définissez le paramètre X_DUAL_STEPPER_DRIVERS pour utiliser un deuxième moteur sur l'axe X. Si les moteurs doivent tourner
 * dans des directions opposées, définissez INVERT_X2_VS_X_DIR. Si le deuxième moteur a besoin de son propre endstop,
 * X_DUAL_ENDSTOPS. Cela peut s'ajuster pour "racking". Utilisez X2_USE_ENDSTOP pour définir le connecteur à utiliser pout
 * pour le deuxième le endstop. Des endstop supplémentaires apparaîtront dans la sortie de 'M119'.
 *
 * Utilisez X_DUAL_ENDSTOP_ADJUSTMENT pour ajuster les imperfections mécaniques. Après le référencement des deux
 * moteurs, ce décalage est appliqué au moteur X2. Pour trouver le décalage l'axe X et mesurer l'erreur dans X2. Les
 * décalages de fin de course doubles peuvent être définis au moment de l'exécution avec l'option 'M666 X <offset> Y <offset> Z <offset>'.
 */

//#define X_DUAL_STEPPER_DRIVERS
#if ENABLED(X_DUAL_STEPPER_DRIVERS)
  #define INVERT_X2_VS_X_DIR true   // Définissez 'true' si les moteurs X doivent tourner dans des directions opposées
  //#define X_DUAL_ENDSTOPS
  #if ENABLED(X_DUAL_ENDSTOPS)
    #define X2_USE_ENDSTOP _XMAX_
    #define X_DUAL_ENDSTOPS_ADJUSTMENT  0
  #endif
#endif

//#define Y_DUAL_STEPPER_DRIVERS
#if ENABLED(Y_DUAL_STEPPER_DRIVERS)
  #define INVERT_Y2_VS_Y_DIR true   // Définissez 'true' si les moteurs Y doivent tourner dans des directions opposées
  //#define Y_DUAL_ENDSTOPS
  #if ENABLED(Y_DUAL_ENDSTOPS)
    #define Y2_USE_ENDSTOP _YMAX_
    #define Y_DUAL_ENDSTOPS_ADJUSTMENT  0
  #endif
#endif

//#define Z_DUAL_STEPPER_DRIVERS
#if ENABLED(Z_DUAL_STEPPER_DRIVERS)
  //#define Z_DUAL_ENDSTOPS
  #if ENABLED(Z_DUAL_ENDSTOPS)
    #define Z2_USE_ENDSTOP _XMAX_
    #define Z_DUAL_ENDSTOPS_ADJUSTMENT  0
  #endif
#endif

//#define Z_TRIPLE_STEPPER_DRIVERS
#if ENABLED(Z_TRIPLE_STEPPER_DRIVERS)
  //#define Z_TRIPLE_ENDSTOPS
  #if ENABLED(Z_TRIPLE_ENDSTOPS)
    #define Z2_USE_ENDSTOP _XMAX_
    #define Z3_USE_ENDSTOP _YMAX_
    #define Z_TRIPLE_ENDSTOPS_ADJUSTMENT2  0
    #define Z_TRIPLE_ENDSTOPS_ADJUSTMENT3  0
  #endif
#endif

/**
 * Dual X Carriage
 *
 * Cette configuration comprend deux chariots X pouvant se déplacer indépendamment, chacun avec son propre hotend.
 * Les chariots peuvent être utilisés pour imprimer un objet avec deux couleurs ou matériaux,
 * ou en "mode de duplication", il peut imprimer simultanément deux objets identiques ou en miroir.
 * Le chariot inactif est garé automatiquement pour empêcher le suintement.
 * X1 est le chariot de gauche, X2 le droit. Ils se garent et rentrent "chez eux" aux extrémités opposées de l'axe X.
 * Par défaut, le stepper X2 est affecté au premier connecteur E non utilisé de la carte.
 *
 * Les modes de transport Dual X suivants peuvent être sélectionnés avec le M605 S <mode>:
 *
 *   0 : (FULL_CONTROL) La trancheuse contrôle parfaitement les deux chariots X et peut obtenir
 *       des résultats de déplacement optimaux tant qu'elle prend en charge les chariots X doubles. (M605 S0)
 *
 *   1 : (AUTO_PARK) Le micrologiciel stationne et annule automatiquement les chariots X lors du
 *       changement d'outil, de sorte qu'un support de trancheur supplémentaire n'est pas nécessaire. (M605 S1)
 *
 *   2 : (DUPLICATION) Le micrologiciel déplace le deuxième chariot X et l'extrudeur en synchronisation
 *       avec le premier chariot X et l'extrudeur, afin d'imprimer deux copies du même
 *       objet en même temps. Réglez le décalage X constant et la différence de température
 *       avec M605 S2 X [offs] R [deg] et suivez avec M605 S2 pour lancer le mouvement dupliqué.
 *
 *   3 : Mode miroir (inspiré de Formbot / Vivedino) dans lequel la deuxième tête duplique le
 *       mouvement de la première, sauf que le movement de la deuxième tête est inversée sur l'axe X.
 *       Réglez le décalage initial X et la différence de température avec M605 S2 X [offs] R [deg],
 *       puis suivez avec M605 S3 pour lancer le mouvement en miroir.
 */
//#define DUAL_X_CARRIAGE
#if ENABLED(DUAL_X_CARRIAGE)
  #define X1_MIN_POS X_MIN_POS   // Définir X_MIN_POS
  #define X1_MAX_POS X_BED_SIZE  // Fixer un maximum pour que le premier chariot X ne puisse pas atteindre le deuxième chariot X stationné
  #define X2_MIN_POS    80       // Définissez un minimum pour vous assurer que le deuxième chariot X ne peut pas atteindre le premier chariot X stationné
  #define X2_MAX_POS   353       // Définissez ceci sur la distance entre les têtes d'outils lorsque les deux têtes sont reliées
  #define X2_HOME_DIR    1       // Réglé sur 1. Le deuxième chariot X se déplace toujours à la position maximale de fin de course
  #define X2_HOME_POS X2_MAX_POS // Position d'origine X2 par défaut. Définissez sur X2_MAX_POS.
                      // Cependant: Dans ce mode, la valeur HOTEND_OFFSET_X pour la deuxième tête fournit une
                      // substitution de logiciel pour  X2_HOME_POS. Cela permet également de recalibrer la
                      // distance entre les deux extrémités sans modifier le firmware (via la commande "M218 T1 X ???").
                      // N'oubliez pas: vous devez définir le x-offset dela deuxième tête  sur 0 dans votre slicer.

  // C'est le mode de mise en marche par défaut qui peut être utilisé ultérieurement avec M605.
  #define DEFAULT_DUAL_X_CARRIAGE_MODE DXC_AUTO_PARK_MODE

  // Décalage x par défaut en mode de duplication (généralement défini sur la moitié de la largeur du lit d'impression)
  #define DEFAULT_DUPLICATION_X_OFFSET 100

#endif // DUAL_X_CARRIAGE

// Activer un solénoïde sur la tête active avec M380. Désactiver tout avec M381.
// Définissez SOL0_PIN, SOL1_PIN, etc. pour chaque tête équipée d’un solénoïde.
//#define EXT_SOLENOID

// @section homing

// Le rapatriement touche chaque endstop, se rétracte sur ces distances, puis revient au contact du endstop
#define X_HOME_BUMP_MM 5
#define Y_HOME_BUMP_MM 5
#define Z_HOME_BUMP_MM 2
#define HOMING_BUMP_DIVISOR { 2, 2, 4 }  // Diviseur de vitesse de deuxième contact (divise la vitesse de retour)
//#define QUICK_HOME                     // Si le référencement inclut X et Y, effectuez un mouvement diagonal au début
//#define HOMING_BACKOFF_MM { 2, 2, 2 }  // (mm) Éloignez-vous des endstop après le référencement
// Lorsque G28 est appelé, cette option amènera Y à l'origine avant X
//#define HOME_Y_BEFORE_X

// Activez cette option si X ou Y ne peuvent pas revenir à l'origine sans avoir au préalable orienté l'autre axe vers le centre.
//#define CODEPENDENT_XY_HOMING

#if ENABLED(BLTOUCH)
  /**
   * Soit: Utilisez les valeurs par défaut (recommandé) ou: A des fins spéciales, utilisez les options DEFINES suivantes
   * N'activez pas les paramètres que la sonde pourrait ne pas comprendre.
   * Les clones peuvent mal comprendre les commandes avancées.
   *
   * Remarque: Si la sonde ne se déploie pas, vérifiez les paramètres "Cmd: Réinitialiser" et "Cmd: Autotest",
   *       puis vérifiez le câblage des fils MARRON, ROUGE et ORANGE.
   *
   * Remarque: Si le signal de déclenchement de votre sonde n’est pas reconnu, c’est très souvent dû au fait
   *       que les fils NOIR et BLANC devaient être permutés. Ils ne sont pas "interchangeables" comme ils
   *       le seraient avec un véritable interrupteur. Alors s'il vous plaît vérifier le câblage en premier.
   *
   * Paramètres pour toutes les sondes BLTouch et clone:
   */

  // Sécurité: La sonde a besoin de temps pour reconnaître la commande.
  //         Délai de commande minimal (ms). Activer et augmenter si nécessaire.
  #define BLTOUCH_DELAY 375

  /**
   * Paramètres de BLTOUCH Classic 1.2, 1.3 ou BLTouch Smart 1.0, 2.0, 2.2, 3.0, 3.1 et la plupart des clones:
   */

  // Fonctionnalité: Basculer en mode SW après un déploiement. Cela rend l'impulsion de sortie plus longue.
  //          Peut être utile dans des cas particuliers, tels que des configurations d'entrée bruitées ou filtrées.
  //#define BLTOUCH_FORCE_SW_MODE

  /**
   * Paramètres de BLTouch Smart 3.0 et 3.1
   * Résumé:
   *   - Modes de tension: modes de sortie 5V et OD (drain ouvert - "sans tension logique")
   *   - Mode haute vitesse
   *   - Désactiver les options de tension de l'écran LCD
   */

  /**
   * Danger: N'activez le mode 5V que s'il est connecté à un contrôleur tolérant le 5V!
   * V3.0 ou 3.1: définissez le mode par défaut sur 5V au démarrage de Marlin.
   * S'il est désactivé, le mode OD est la valeur par défaut codée en dur sur la version 3.0.
   * Au démarrage, Marlin comparera son eeprom à cette valeur. Si le mode
   * sélectionné diffère, une écriture eeprom définie sera complétée à l’initialisation.
   * Utilisez l'option ci-dessous pour forcer une écriture eeprom sur une sonde V3.1, indépendamment de votre choix.
   */
  //#define BLTOUCH_SET_5V_MODE

  /**
   * Sécurité: Activer si vous connectez une sonde avec un mode de tension inconnu.
   * V3.0: Définissez une sonde dans le mode sélectionné ci-dessus au démarrage de Marlin. Requis pour le mode 5V sur 3.0
   * V3.1: Forcer une sonde de mode inconnu en mode sélectionné au démarrage de Marlin (= écriture de la sonde EEPROM)
   * Pour préserver la durée de vie de la sonde, utilisez-la une fois, éteignez-la et répétez le flash
   */
  //#define BLTOUCH_FORCE_MODE_SET

  /**
   * Utilisez le mode "HIGH SPEED" pour le sondage.
   * Danger: Désactivez si votre sonde échoue parfois. Convient uniquement aux systèmes stables bien ajustés.
   * Cette fonctionnalité a été conçue pour les modèles Delta avec mouvements Z rapides, mais des cartes à vitesse plus élevée peuvent
   * fonctionner Si la machine ne peut pas relever la sonde assez rapidement après un déclenchement, elle peut passer en état d'erreur.
   */
  //#define BLTOUCH_HS_MODE

  // Safety: Enable voltage mode settings in the LCD menu.
  //#define BLTOUCH_LCD_VOLTAGE_MENU

#endif // BLTOUCH

/**
 * Z Auto-Alignement Steppers
 * Ajoutez la commande G34 pour aligner plusieurs steppers Z à l'aide d'une sonde de lit.
 */
//#define Z_STEPPER_AUTO_ALIGN
#if ENABLED(Z_STEPPER_AUTO_ALIGN)
  // Définir les positions X et Y des sondes pour Z1, Z2 [, Z3]
  #define Z_STEPPER_ALIGN_X { 10, 150, 290 }
  #define Z_STEPPER_ALIGN_Y { 290, 10, 290 }
  // Définir le nombre d'itérations à aligner
  #define Z_STEPPER_ALIGN_ITERATIONS 3
  // Activer pour restaurer la configuration de mise à niveau après l'opération
  #define RESTORE_LEVELING_AFTER_G34

  // Sur un lit de 300 mm, une note de 5% donnerait un désalignement d'environ 1,5 cm
  #define G34_MAX_GRADE  5  // (%)Inclinaison maximale que G34 gérera

  // Utilisez le facteur d'amplification pour augmenter / diminuer l'étape de correction.
  // Si la position du moteur pas à pas (broche) est plus éloignée que le point de test,
  // utilisez une valeur> 1. REMARQUE: Ceci peut provoquer une instabilité.
  #define Z_STEPPER_ALIGN_AMP 1.0
  // Critère d'arrêt. Si la précision est meilleure que cela, arrêtez de itérer plus tôt
  #define Z_STEPPER_ALIGN_ACC 0.02
#endif

// @section machine

#define AXIS_RELATIVE_MODES { false, false, false, false }

// Ajouter une option de duplication pour les buses jointes bien séparées
//#define MULTI_NOZZLE_DUPLICATION

// Par défaut, les drivers d'étape pololu nécessitent un signal haut actif. Cependant, certains pilotes de forte puissance nécessitent un signal bas actif.
#define INVERT_X_STEP_PIN false
#define INVERT_Y_STEP_PIN false
#define INVERT_Z_STEP_PIN false
#define INVERT_E_STEP_PIN false

// Libération par défaut du stepper si inactif. Réglez sur 0 pour désactiver.
// Les steppers vont fermer DEFAULT_STEPPER_DEACTIVE_TIME quelques secondes après le dernier déplacement, lorsque DISABLE_INACTIVE_? est true.
// Le temps peut être réglé par M18 et M84.
#define DEFAULT_STEPPER_DEACTIVE_TIME 120
#define DISABLE_INACTIVE_X true
#define DISABLE_INACTIVE_Y true
#define DISABLE_INACTIVE_Z true  // Définissez la valeur false si la buse tombe sur votre pièce imprimée une fois l'impression terminée.
#define DISABLE_INACTIVE_E true

#define DEFAULT_MINIMUMFEEDRATE       0.0     // avance minimale
#define DEFAULT_MINTRAVELFEEDRATE     0.0

//#define HOME_AFTER_DEACTIVATE  // Exiger le rapatriement aus origines après la désactivation des steppers

// @section lcd

#if EITHER(ULTIPANEL, EXTENSIBLE_UI)
  #define MANUAL_FEEDRATE { 50*60, 50*60, 4*60, 60 } // Les avances pour les déplacements manuels le long des panneaux X, Y, Z, E
  #define SHORT_MANUAL_Z_MOVE 0.025 // (mm) Plus petit mouvement manuel en Z (<0.1mm)
  #if ENABLED(ULTIPANEL)
    #define MANUAL_E_MOVES_RELATIVE // Afficher la distance de déplacement de l'extrudeuse plutôt que la "position"
    #define ULTIPANEL_FEEDMULTIPLY  // Le codeur définit le multiplicateur d'avance sur l'écran d'état
  #endif
#endif

// @section extras

// Temps minimum, en microsecondes, qu'un mouvement doit prendre si le tampon est vidé.
#define DEFAULT_MINSEGMENTTIME        20000

// Si défini, les mouvements ralentissent lorsque le tampon d'anticipation est à moitié plein
#define SLOWDOWN

// Fréquence limite
// Voir le blog de nophead pour plus d'informations
// Ne fonctionne pas O
//#define XY_FREQUENCY_LIMIT  15

// Vitesse minimale de jonction du planificateur. Définit la vitesse minimale par défaut prévue par le planificateur à la fin du tampon et
// de tous les arrêts. Cela ne devrait pas être beaucoup plus grand que zéro et ne devrait être changé que si un comportement indésirable
// est observé sur la machine d'un utilisateur lorsqu'il tourne à très basse vitesse.
#define MINIMUM_PLANNER_SPEED 0.05 // (mm/s)

//
// Compensation de Backlash
// Ajoute un mouvement supplémentaire aux axes sur les changements de direction pour prendre en compte le jeu.
//
//#define BACKLASH_COMPENSATION
#if ENABLED(BACKLASH_COMPENSATION)
  // Définissez les valeurs de distance de jeu et de correction.
  // Si BACKLASH_GCODE est activé, ces valeurs sont les valeurs par défaut.
  #define BACKLASH_DISTANCE_MM { 0, 0, 0 } // (mm)
  #define BACKLASH_CORRECTION    0.0       // 0,0 = pas de correction; 1,0 = correction totale

  // Définissez BACKLASH_SMOOTHING_MM pour répartir la correction du jeu sur plusieurs segments
  // afin de réduire les artefacts d'impression. (Activer cela coûte cher en mémoire et en calcul!)
  //#define BACKLASH_SMOOTHING_MM 3 // (mm)

  // Ajout de la configuration d'exécution et du réglage des valeurs de jeu (M425)
  //#define BACKLASH_GCODE

  #if ENABLED(BACKLASH_GCODE)
    // Mesurer le jeu en Z lors du palpage (G29) et régler avec "M425 Z"
    #define MEASURE_BACKLASH_WHEN_PROBING

    #if ENABLED(MEASURE_BACKLASH_WHEN_PROBING)
      // Lors de la mesure, la sonde se déplacera jusqu'à BACKLASH_MEASUREMENT_LIMIT
      // en mm du point de contact dans les incréments de BACKLASH_MEASUREMENT_RESOLUTION
      // tout en vérifiant si le contact est rompu.
      #define BACKLASH_MEASUREMENT_LIMIT       0.5   // (mm)
      #define BACKLASH_MEASUREMENT_RESOLUTION  0.005 // (mm)
      #define BACKLASH_MEASUREMENT_FEEDRATE    Z_PROBE_SPEED_SLOW // (mm/m)
    #endif
  #endif
#endif

/**
 * Étalonnage automatique du jeu, de la position et du décalage à chaud
 *
 * Activez G425 pour exécuter un étalonnage automatique à l'aide d'un cube,
 * d'un boulon ou d'une rondelle électriquement conducteur monté sur le lit.
 *
 * Le G425 utilise la sonde pour toucher le dessus et les côtés de l'objet
 * à étalonner sur le lit et mesurer et / ou corriger les décalages de
 * position, le décalage de l'axe et les décalages de tête chaude.
 *
 * Remarque: HOTEND_OFFSET et CALIBRATION_OBJECT_CENTER doivent
 *       être définis sur ± 5 mm des valeurs vraies pour que G425 réussisse.
 */
//#define CALIBRATION_GCODE
#if ENABLED(CALIBRATION_GCODE)

  #define CALIBRATION_MEASUREMENT_RESOLUTION     0.01 // mm

  #define CALIBRATION_FEEDRATE_SLOW             60    // mm/m
  #define CALIBRATION_FEEDRATE_FAST           1200    // mm/m
  #define CALIBRATION_FEEDRATE_TRAVEL         3000    // mm/m

  // Les paramètres suivants se rapportent à la section conique de la pointe de buse.
  #define CALIBRATION_NOZZLE_TIP_HEIGHT          1.0  // mm
  #define CALIBRATION_NOZZLE_OUTER_DIAMETER      2.0  // mm

  // Ne commentez pas l'activation du rapport (requis pour "G425 V", mais utilise PROGMEM).
  //#define CALIBRATION_REPORTING

  // Le véritable emplacement et la dimension du cube / boulon / rondelle sur le lit.
  #define CALIBRATION_OBJECT_CENTER     { 264.0, -22.0,  -2.0} // mm
  #define CALIBRATION_OBJECT_DIMENSIONS {  10.0,  10.0,  10.0} // mm

  // Mettez en commentaire les côtés inaccessibles par la sonde. Pour de
  // meilleurs résultats d'auto-étalonnage, tous les côtés doivent être accessibles.
  #define CALIBRATION_MEASURE_RIGHT
  #define CALIBRATION_MEASURE_FRONT
  #define CALIBRATION_MEASURE_LEFT
  #define CALIBRATION_MEASURE_BACK

  // Le fait de sonder exactement au centre ne fonctionne que si le centre est plat
  // Si vous sondez sur une tête de vis ou une rondelle creuse, sondez près des bords.
  //#define CALIBRATION_MEASURE_AT_TOP_EDGES

  // Définir la broche lue lors de l'étalonnage
  #ifndef CALIBRATION_PIN
    #define CALIBRATION_PIN -1 // Remplacer dans pins.h ou mettre à -1 pour utiliser votre butée Z
    #define CALIBRATION_PIN_INVERTING false // Défini sur true pour inverser la broche
    //#define CALIBRATION_PIN_PULLDOWN
    #define CALIBRATION_PIN_PULLUP
  #endif
#endif

/**
 * Le lissage adaptatif des pas augmente la résolution des déplacements multi-axes, en particulier
 * pour les fréquences inférieures à 1 kHz (pour AVR) ou 10kHz (pour ARM), où le repliement entre
 * axes dans les déplacements multi-axes provoque des vibrations audibles et des artefacts de surface.
 * L'algorithme s'adapte pour fournir le meilleur lissage possible des pas aux fréquences les plus basses.
 */
#define ADAPTIVE_STEP_SMOOTHING

/**
 * Custom Microstepping
 * Remplacez selon les besoins pour votre configuration. Jusqu'à 3 broches MS sont prises en charge.
 */
//#define MICROSTEP1 LOW,LOW,LOW
//#define MICROSTEP2 HIGH,LOW,LOW
//#define MICROSTEP4 LOW,HIGH,LOW
//#define MICROSTEP8 HIGH,HIGH,LOW
//#define MICROSTEP16 LOW,LOW,HIGH
//#define MICROSTEP32 HIGH,LOW,HIGH

// Paramètre Microstep (Fonctionne uniquement lorsque les broches micropas du pilote pas à pas sont connectées à la MCU.
#define MICROSTEP_MODES { 16, 16, 16, 16, 16, 16 } // [1,2,4,8,16]

/**
 *  @section courant des moteurs pas à pas
 *
 *  Certaines cartes permettent de régler le courant du moteur pas à pas via un micrologiciel.
 *
 *  Les courants du moteur sont définis par:
 *    PWM_MOTOR_CURRENT - utilisé par MINIRAMBO & ULTIMAIN_2
 *                         puces compatibles connues: A4982
 *    DIGIPOT_MOTOR_CURRENT - utilisé par BQ_ZUM_MEGA_3D, RAMBO & SCOOVO_X9H
 *                         puces compatibles connues: AD5206
 *    DAC_MOTOR_CURRENT_DEFAULT - utilisé par PRINTRBOARD_REVF & RIGIDBOARD_V2
 *                        puces compatibles connues: MCP4728
 *    DIGIPOT_I2C_MOTOR_CURRENTS - utilisé par 5DPRINT, AZTEEG_X3_PRO, AZTEEG_X5_MINI_WIFI, MIGHTYBOARD_REVE
 *                         puces compatibles connues: MCP4451, MCP4018
 *
 *  Les courants du moteur peuvent également être réglés par M907 - M910 et par l’écran LCD.
 *    M907 - s'applique à tous.
 *    M908 - BQ_ZUM_MEGA_3D, RAMBO, PRINTRBOARD_REVF, RIGIDBOARD_V2 & SCOOVO_X9H
 *    M909, M910 et LCD - uniquement PRINTRBOARD_REVF & RIGIDBOARD_V2
 */
//#define PWM_MOTOR_CURRENT { 1300, 1300, 1250 }          // Valeurs en milliampères
//#define DIGIPOT_MOTOR_CURRENT { 135,135,135,135,135 }   // Valeurs 0-255 (RAMBO 135 = ~ 0,75A, 185 = ~ 1A)
//#define DAC_MOTOR_CURRENT_DEFAULT { 70, 80, 90, 80 }    // Pourcentage de valeur par défaut - Axe X, Y, Z, E

// Utilisez un DIGIPOT basé sur I2C (par exemple, Azteeg X3 Pro)
//#define DIGIPOT_I2C
#if ENABLED(DIGIPOT_I2C) && !defined(DIGIPOT_I2C_ADDRESS_A)
  /**
   * Adresses d'esclaves communes:
   *
   *                        A   (A shifted)   B   (B shifted)  IC
   * Smoothie              0x2C (0x58)       0x2D (0x5A)       MCP4451
   * AZTEEG_X3_PRO         0x2C (0x58)       0x2E (0x5C)       MCP4451
   * AZTEEG_X5_MINI        0x2C (0x58)       0x2E (0x5C)       MCP4451
   * AZTEEG_X5_MINI_WIFI         0x58              0x5C        MCP4451
   * MIGHTYBOARD_REVE      0x2F (0x5E)                         MCP4018
   */
  #define DIGIPOT_I2C_ADDRESS_A 0x2C  // adresse d'esclave non décalé pour le premier DIGIPOT
  #define DIGIPOT_I2C_ADDRESS_B 0x2D  // adresse d'esclave non décalé pour le deuxième DIGIPOT
#endif

//#define DIGIPOT_MCP4018          // Requiert une bibliothèque à l'adresse https://github.com/stawel/SlowSoftI2CMaster.
#define DIGIPOT_I2C_NUM_CHANNELS 8 // 5DPRINT: 4     AZTEEG_X3_PRO: 8     MKS SBASE: 5
// Courants réels du moteur en ampères. Le nombre d'entrées doit correspondre à DIGIPOT_I2C_NUM_CHANNELS.
// Ceux-ci correspondent aux conducteurs physiques, alors soyez attentif si l'ordre est modifié.
#define DIGIPOT_I2C_MOTOR_CURRENTS { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }  //  AZTEEG_X3_PRO

//===========================================================================
//======================Caractéristiques supplémentaires=====================
//===========================================================================

// @section lcd

// Changer les valeurs plus rapidement lorsque le codeur tourne plus rapidement
#define ENCODER_RATE_MULTIPLIER
#if ENABLED(ENCODER_RATE_MULTIPLIER)
  #define ENCODER_10X_STEPS_PER_SEC   30  // (pas / s) Taux d'encodeur pour une vitesse 10x
  #define ENCODER_100X_STEPS_PER_SEC  80  // (pas / s) Taux d'encodeur pour une vitesse 100x
#endif

// Émettre un bip lorsque l’avance est modifiée à partir de l’écran d’état
//#define BEEP_ON_FEEDRATE_CHANGE
#if ENABLED(BEEP_ON_FEEDRATE_CHANGE)
  #define FEEDRATE_CHANGE_BEEP_DURATION   10
  #define FEEDRATE_CHANGE_BEEP_FREQUENCY 440
#endif

// Inclure une page d'informations sur l'imprimante dans le menu principal de l'écran LCD
//#define LCD_INFO_MENU
#if ENABLED(LCD_INFO_MENU)
  #define LCD_PRINTER_INFO_IS_BOOTSCREEN // Afficher les écrans de démarrage au lieu des pages d'informations sur l'imprimante
#endif

// Faire défiler un message d'état plus long sur l'écran
#define STATUS_MESSAGE_SCROLLING

// Sur l'écran d'information, affichez XY avec une décimale lorsque cela est possible
//#define LCD_DECIMAL_SMALL_XY

// Le délai d'attente (en ms) pour revenir à l'écran d'état à partir de sous-menus
//#define LCD_TIMEOUT_TO_STATUS 15000

// Ajoutez un Gcode 'M73' pour définir le pourcentage actuel
//#define LCD_SET_PROGRESS_MANUALLY

#if HAS_CHARACTER_LCD && HAS_PRINT_PROGRESS
  //#define LCD_PROGRESS_BAR              // Afficher une barre de progression sur les écrans LCD HD44780 pour l'impression SD
  #if ENABLED(LCD_PROGRESS_BAR)
    #define PROGRESS_BAR_BAR_TIME 2000    // (ms) Durée d'affichage de la barre
    #define PROGRESS_BAR_MSG_TIME 3000    // (ms) Durée d'affichage du message d'état
    #define PROGRESS_MSG_EXPIRE   0       // (ms) Durée de conservation du message d'état (0 = pour toujours)
    //#define PROGRESS_MSG_ONCE           // Afficher le message pour MSG_TIME puis l'effacer
    //#define LCD_PROGRESS_BAR_TEST       // Ajouter un élément de menu pour tester la barre de progression
  #endif
#endif

/**
 * Menu de contrôle LED
 * Activer cette fonction pour ajouter LED Control au menu LCD
 */
//#define LED_CONTROL_MENU
#if ENABLED(LED_CONTROL_MENU)
  #define LED_COLOR_PRESETS                 // Activer l'option de menu Couleur prédéfinie
  #if ENABLED(LED_COLOR_PRESETS)
    #define LED_USER_PRESET_RED        255  // Valeur ROUGE définie par l'utilisateur
    #define LED_USER_PRESET_GREEN      255  // Valeur VERT définie par l'utilisateur
    #define LED_USER_PRESET_BLUE       255  // Valeur BLEU définie par l'utilisateur
    #define LED_USER_PRESET_WHITE      255  // Valeur BLANC définie par l'utilisateur
    #define LED_USER_PRESET_BRIGHTNESS 10  // Intensité définie par l'utilisateur
    #define LED_USER_PRESET_STARTUP       // Demandez à l'imprimante d'afficher la couleur prédéfinie par l'utilisateur au démarrage
  #endif
#endif // LED_CONTROL_MENU

#if ENABLED(SDSUPPORT)

  // Certaines RAMPS et d’autres cartes ne détectent pas le moment où une carte SD est insérée.
  // Vous pouvez contourner ce problème en connectant un bouton poussoir ou un commutateur à portée unique
  // à la broche définie en tant que SD_DETECT_PIN dans les définitions des broches de votre carte.
  // Ce paramètre doit être désactivé sauf si vous utilisez un bouton-poussoir pour mettre la pin au 0v.
  // Remarque: Ceci est toujours désactivé pour ULTIPANEL (sauf ELB_FULL_GRAPHIC_CONTROLLER).
  #define SD_DETECT_INVERTED

  #define SD_FINISHED_STEPPERRELEASE true          // Désactiver les steppers lorsque l'impression SD est terminée
  #define SD_FINISHED_RELEASECOMMAND "M84 X Y Z E" // Vous voudrez peut-être garder le Z activé pour que votre lit reste en place.

  // Triez le format SD pour afficher d’abord les fichiers "plus récents", en fonction de la FAT de la carte.
  // SDCARD_SORT_ALPHA est recommandé si le FAT ne fonctionne pas.
  #define SDCARD_RATHERRECENTFIRST

  #define SD_MENU_CONFIRM_START             // Confirmez le fichier SD sélectionné avant l'impression

  //#define MENU_ADDAUTOSTART               // Ajouter une option de menu pour exécuter les fichiers auto # .g

  #define EVENT_GCODE_SD_STOP "G28XY"       // Code G à exécuter sur Stop Print ("G28XY" ou "G27", par exemple)

  /**
   * Reprise après coupure de courant (Creality3D)
   *
   * Stockez l’état actuel sur la carte SD au début de chaque couche
   * pendant l’impression SD. Si le fichier de récupération est trouvé au
   * démarrage, présentez une option sur l'écran LCD pour continuer
   * l'impression à partir du dernier point connu du fichier.
   */
  //#define POWER_LOSS_RECOVERY
  #if ENABLED(POWER_LOSS_RECOVERY)
    //#define POWER_LOSS_PIN         44 // Pin pour détecter la perte d'alimentation
    //#define POWER_LOSS_STATE     HIGH // Etat de la broche indiquant une perte de puissance
    //#define POWER_LOSS_PURGE_LEN   20 // (mm) Longueur du filament à purger à la reprise
    //#define POWER_LOSS_RETRACT_LEN 10 // (mm) Longueur du filament à rétracter en cas d'échec. Nécessite une alimentation secourue.

    // Sans POWER_LOSS_PIN, l'option suivante permet de réduire l'usure de la carte SD, notamment
    // avec l'impression "en mode vase". Réglez trop haut et les vases ne peuvent pas être poursuivis.
    #define POWER_LOSS_MIN_Z_CHANGE 0.05 // (mm) Modification minimale de Z avant la sauvegarde des données de perte de puissance
  #endif

  /**
   * Triez les listes de fichiers SD par ordre alphabétique.
   *
   * Lorsque cette option est activée, les éléments des
   * cartes SD seront triés par nom pour faciliter la navigation.
   *
   * Par défaut...
   *
   *  - Utilisez la méthode de tri la plus lente mais la plus sûre.
   *  - Les dossiers sont affichés en haut.
   *  - La clé de tri est allouée de manière statique.
   *  - Pas de support ajouté pour le code G (M34).
   *  - Limite de tri de 40 articles. (Les articles après les 40 premiers sont non triés.)
   *
   * Le tri SD utilise une allocation statique (définie par SDSORT_LIMIT), ce qui
   * permet au compilateur de calculer l'utilisation dans le cas le plus défavorable
   * et d'envoyer une erreur si la limite de SRAM est dépassée.
   *
   *  - SDSORT_USES_RAM permet un tri plus rapide via un tampon de répertoire statique.
   *  - SDSORT_USES_STACK fait la même chose, mais utilise un tampon local basé sur une pile.
   *  - SDSORT_CACHE_NAMES conservera la liste des fichiers triés dans la RAM. (Coûteux en mémoire!)
   *  - SDSORT_DYNAMIC_RAM utilise la RAM uniquement lorsque le menu SD est visible. (Utiliser avec précaution!)
   */
  //#define SDCARD_SORT_ALPHA

  // Options de tri de la carte SD
  #if ENABLED(SDCARD_SORT_ALPHA)
    #define SDSORT_LIMIT       40     // Nombre maximum d'éléments triés (10-256). Coûte 27 octets chacun.
    #define FOLDER_SORTING     -1     // -1 = supérieur à    0 = aucun    1 = inférieur à
    #define SDSORT_GCODE       false  // Permet d'activer / de désactiver le tri avec les écrans LCD et M34 g-code.
    #define SDSORT_USES_RAM    false  // Pré-allouez un tableau statique pour un tri plus rapide.
    #define SDSORT_USES_STACK  false  // Préférez la pile pour le tri préalable afin de restituer de la mémoire SRAM. (Refusé par les 2 prochaines options.)
    #define SDSORT_CACHE_NAMES false  // Conservez les éléments triés dans la RAM plus longtemps pour des performances rapides. Option la plus couteuse en mémoire.
    #define SDSORT_DYNAMIC_RAM false  // Utiliser l'allocation dynamique (dans les menus SD). Option la moins coûteuse. Définissez SDSORT_LIMIT avant utilisation!
    #define SDSORT_CACHE_VFATS 2      // Nombre maximal d'entrées VFAT de 13 octets à utiliser pour le tri.
                                      // Remarque: affecte uniquement SCROLL_LONG_FILENAMES avec SDSORT_CACHE_NAMES mais pas SDSORT_DYNAMIC_RAM.
  #endif

  // Cela permet aux hôtes de demander des noms longs pour les fichiers et les dossiers avec M33.
  #define LONG_FILENAME_HOST_SUPPORT

  // Activer cette option pour faire défiler les noms de fichiers longs dans le menu de la carte SD
  #define SCROLL_LONG_FILENAMES

  // Laissez les appareils de chauffage allumés après Stop Print (non recommandé!)
  //#define SD_ABORT_NO_COOLDOWN

  /**
   * Cette option vous permet d’interrompre l’impression SD lorsqu’un endstop quelconque est déclenché.
   * Cette fonction doit être activée avec "M540 S1" ou depuis le menu LCD.
   * Pour avoir un effet quelconque, les end stop doivent être activés lors de l’impression SD.
   */
  //#define SD_ABORT_ON_ENDSTOP_HIT

  /**
   * Cette option facilite l’impression du même fichier de carte SD.
   * Une fois l'impression terminée, le menu LCD s'ouvre sur le fichier sélectionné.
   * Vous pouvez simplement cliquer pour lancer l'impression ou naviguer ailleurs.
   */
  //#define SD_REPRINT_LAST_SELECTED_FILE

  /**
   * Signaler automatiquement l'état de la carte SD avec M27 S <secondes>
   */
  //#define AUTO_REPORT_SD_STATUS

  /**
   * Prise en charge des clés USB utilisant un Arduino USB Host Shield ou
   * une carte opto-isolée MAX3421E équivalente. La clé USB apparaîtra
   * à Marlin comme une carte SD.
   *
   * Le MAX3421E doit se voir attribuer les mêmes broches que
   * le lecteur de carte SD, avec le mappage des broches suivant:
   *
   *    SCLK, MOSI, MISO --> SCLK, MOSI, MISO
   *    INT              --> SD_DETECT_PIN
   *    SS               --> SDSS
   */
  //#define USB_FLASH_DRIVE_SUPPORT
  #if ENABLED(USB_FLASH_DRIVE_SUPPORT)
    #define USB_CS_PIN         SDSS
    #define USB_INTR_PIN       SD_DETECT_PIN
  #endif

  /**
   * Si vous utilisez un chargeur de démarrage prenant en charge SD-Firmware-Flashing
   * ajoutez un élément de menu pour activer SD-FW-Update au prochain redémarrage.
   *
   * Requiert ATMEGA2560 (Arduino Mega)
   *
   * Testé avec ce chargeur de démarrage:
   *   https://github.com/FleetProbe/MicroBridge-Arduino-ATMega2560
   */
  //#define SD_FIRMWARE_UPDATE
  #if ENABLED(SD_FIRMWARE_UPDATE)
    #define SD_FIRMWARE_UPDATE_EEPROM_ADDR    0x1FF
    #define SD_FIRMWARE_UPDATE_ACTIVE_VALUE   0xF0
    #define SD_FIRMWARE_UPDATE_INACTIVE_VALUE 0xFF
  #endif

  // Ajouter un mode de transfert de fichier binaire optimisé, initié avec 'M28 B1'
  //#define BINARY_FILE_TRANSFER

  #if HAS_SDCARD_CONNECTION
    /**
     * Définissez cette option sur l’une des options suivantes (ou les valeurs par défaut de la carte s’appliquent):
     *
     *           LCD - Utilisez le lecteur SD du contrôleur LCD externe.
     *       ONBOARD - Utilisez le lecteur SD sur le tableau de commande. (Pas de SD_DETECT_PIN. M21 à init.)
     *  CUSTOM_CABLE - Utilisez un câble personnalisé pour accéder à la SD (comme défini dans un fichier de broches).
     *
     * :[ 'LCD', 'ONBOARD', 'CUSTOM_CABLE' ]
     */
    //#define SDCARD_CONNECTION LCD
  #endif

#endif // SDSUPPORT

/**
 * Par défaut, un lecteur de carte SD intégré peut être partagé en tant que
 * périphérique de stockage de masse USB. Cette option masque la carte SD du PC hôte.
 */
//#define NO_SD_HOST_DRIVE   // Désactiver l'accès à la carte SD via USB (pour des raisons de sécurité).

/**
 * Options supplémentaires pour les affichages graphiques
 *
 * Utilisez les optimisations ici pour améliorer les performances
 * d'impression, qui peuvent être affectées par le dessin sur écran
 * graphique, en particulier lorsque vous effectuez plusieurs déplacements
 * courts et lorsque vous imprimez sur des machines DELTA et SCARA.
 *
 * Certaines de ces options peuvent entraîner un décalage de l'affichage
 * par rapport aux événements du contrôleur, car il existe un compromis
 * entre des performances d'impression fiables et des mises à jour rapides de l'affichage.
 */
#if HAS_GRAPHICAL_LCD
  // Afficher le pourcentage SD à côté de la barre de progression
  //#define DOGM_SD_PERCENT

  // Activer l'enregistrement de nombreux cycles en traçant un cadre vide sur l'écran d'informations
  #define XYZ_HOLLOW_FRAME

  // Activer l'enregistrement de nombreux cycles en traçant un cadre vide sur les écrans de menu
  #define MENU_HOLLOW_FRAME

  // Une police plus grande est disponible pour les éléments de modification. Coûte 3 120 octets de PROGMEM.
  // Western uniquement. Non disponible pour le cyrillique, le kana, le turc, le grec et le chinois.
  //#define USE_BIG_EDIT_FONT

  // Une police plus petite peut être utilisée sur l'écran d'information. Coûte 2300 octets de PROGMEM.
  // Western uniquement. Non disponible pour le cyrillique, le kana, le turc, le grec et le chinois.
  //#define USE_SMALL_INFOFONT

  // Activez cette option et réduisez la valeur pour optimiser les mises à jour de l'écran.
  // Le délai normal est de 10µs. Utilisez la valeur la plus basse qui donne toujours un affichage fiable.
  //#define DOGM_SPI_DELAY_US 5

  // Permutez les indicateurs CW / CCW dans la superposition graphique
  //#define OVERLAY_GFX_REVERSE

  /**
   * Les écrans LCD basés sur ST7920 peuvent émuler un affichage de 16 x 4 caractères
   * à l'aide du générateur de caractères ST7920 pour des mises à jour d'écran très rapides.
   * Activez LIGHTWEIGHT_UI pour utiliser ce mode d’affichage spécial.
   *
   * Etant donné que LIGHTWEIGHT_UI a un espace limité, les messages de position
   * et d’état occupent la même ligne. Définissez STATUS_EXPIRE_SECONDS
   * sur la durée d'affichage du message d'état avant l'effacement.
   *
   * Définissez STATUS_EXPIRE_SECONDS sur zéro pour ne jamais effacer le statut.
   * Cela empêchera l'affichage des mises à jour de position.
   */
  #if ENABLED(U8GLIB_ST7920)
    //#define LIGHTWEIGHT_UI
    #if ENABLED(LIGHTWEIGHT_UI)
      #define STATUS_EXPIRE_SECONDS 20
    #endif
  #endif

  /**
   * Statut (Info) personnalisations d'écran
   * Ces options peuvent affecter la taille du code et le temps de rendu de l'écran.
   * Les écrans d'état personnalisés peuvent forcer le remplacement de ces paramètres.
   */
  //#define STATUS_COMBINE_HEATERS    // Utilisez des images de chauffage combinées au lieu d'images séparées
  //#define STATUS_HOTEND_NUMBERLESS  // Utilisez des icônes de hotend simples au lieu d’icônes numérotées (avec 2 hotends)
  #define STATUS_HOTEND_INVERTED      // Afficher les images bitmap de buses solides lors du chauffage (Requiert STATUS_HOTEND_ANIM)
  #define STATUS_HOTEND_ANIM          // Utilisez un deuxième bitmap pour indiquer que tête chauffe
  #define STATUS_BED_ANIM             // Utilisez un deuxième bitmap pour indiquer le chauffage du lit
  #define STATUS_CHAMBER_ANIM         // Utilisez un deuxième bitmap pour indiquer le chauffage de la chambre
  //#define STATUS_ALT_BED_BITMAP     // Utilisez le bitmap alternatif pour le lit
  //#define STATUS_ALT_FAN_BITMAP     // Utiliser le bitmap de ventilateur alternatif
  //#define STATUS_FAN_FRAMES 3       // :[0,1,2,3,4] Nombre d'images d'animation de ventilateur
  //#define STATUS_HEAT_PERCENT       // Afficher le chauffage dans une barre de progression
  //#define BOOT_MARLIN_LOGO_SMALL    // Afficher un logo Marlin plus petit sur l'écran de démarrage (économie de 399 octets de mémoire flash)

  // Frivolous Game Options
  //#define MARLIN_BRICKOUT
  //#define MARLIN_INVADERS
  //#define MARLIN_SNAKE
  //#define GAMES_EASTER_EGG          // Ajouter des lignes vides supplémentaires au-dessus du sous-menu "Jeux"

#endif // HAS_GRAPHICAL_LCD

// @section sécurité

/**
 * Le temporisateur matériel du chien de garde effectuera une réinitialisation et désactivera
 * toutes les sorties si le micrologiciel est trop surchargé pour lire les capteurs de température.
 *
 * Si vous constatez que le redémarrage du chien de garde entraîne le blocage définitif de votre carte
 * AVR, activez WATCHDOG_RESET_MANUAL pour utiliser un minuteur personnalisé à la place de WDTO.
 * REMARQUE: cette méthode est moins fiable car elle ne peut que
 * rattraper les interruptions lorsque les interruptions sont activées.
 */
#define USE_WATCHDOG
#if ENABLED(USE_WATCHDOG)
  //#define WATCHDOG_RESET_MANUAL
#endif

// @section lcd

/**
 * Babystepping permet de déplacer les axes par petits incréments sans
 * changer les valeurs de la position actuelle. Cette fonctionnalité est principalement
 * utilisée pour ajuster l'axe Z de la première couche d'une impression en temps réel.
 *
 * Attention: ne respecte pas les butées de fin de course!
 */
//#define BABYSTEPPING
#if ENABLED(BABYSTEPPING)
  //#define BABYSTEP_WITHOUT_HOMING
  //#define BABYSTEP_XY                     // Activez également le Babystepping X / Y. Non pris en charge sur DELTA!
  #define BABYSTEP_INVERT_Z false           // Changer si Z babysteps devrait aller dans l'autre sens
  #define BABYSTEP_MULTIPLICATOR  1         // Les babysteps sont très petites. Augmenter pour un mouvement plus rapide.

  #define DOUBLECLICK_FOR_Z_BABYSTEPPING  // Double-cliquez sur l'écran d'état pour Z Babystepping.
  #if ENABLED(DOUBLECLICK_FOR_Z_BABYSTEPPING)
    #define DOUBLECLICK_MAX_INTERVAL 1250   // Intervalle maximal entre les clics, en millisecondes.
                                            // Remarque: Un délai supplémentaire peut être ajouté pour atténuer la latence du contrôleur.
    //#define BABYSTEP_ALWAYS_AVAILABLE     // Autoriser les babystes en tout temps (pas seulement pendant le mouvement).
    //#define MOVE_Z_WHEN_IDLE              // Passez au menu de déplacement Z lors d’un double clic lorsque l’imprimante est inactive.
    #if ENABLED(MOVE_Z_WHEN_IDLE)
      #define MOVE_Z_IDLE_MULTIPLICATOR 1   // Multipliez 1mm par ce facteur pour la taille de l'étape de déplacement.
    #endif
  #endif

  //#define BABYSTEP_DISPLAY_TOTAL          // Afficher le nombre total de babysps depuis le dernier G28

  #define BABYSTEP_ZPROBE_OFFSET          // Combinez M851 Z et Babystepping
  #if ENABLED(BABYSTEP_ZPROBE_OFFSET)
    //#define BABYSTEP_HOTEND_Z_OFFSET      // Pour les écarts multiples, compenser les z relatifs de Babystep
    //#define BABYSTEP_ZPROBE_GFX_OVERLAY   // Activer la superposition graphique sur l'éditeur Z-offset
  #endif
#endif

// @section extrudeur

/**
 * Contrôle de pression linéaire v1.5
 *
 * Hypothèse: avance [pas] = k * (vitesse delta [pas / s])
 * K = 0 signifie avance désactivée.
 *
 * NOTE: Les valeurs K pour LIN_ADVANCE 1.5 diffèrent des versions précédentes!
 *
 * Réglez K autour de 0,22 pour 3mm PLA Direct Drive avec ~ 6,5cm entre le pignon d’entraînement et le heatbreak.
 * Des valeurs de K plus grandes seront nécessaires pour un filament flexible et des distances plus grandes.
 * Si cet algorithme produit un décalage de vitesse supérieur à celui que l'extrudeur peut gérer (par rapport à E jerk),
 * l'accélération d'impression sera réduite pendant les déplacements affectés pour rester dans les limites.
 *
 * voir http://marlinfw.org/docs/features/lin_advance.html pour des instructions complètes.
 * Tuto en français: https://www.youtube.com/watch?v=f6fzJTsnpds
 * Mentionnez @ Sebastianv650 sur GitHub pour alerter l'auteur de tout problème.
 */
//#define LIN_ADVANCE
#if ENABLED(LIN_ADVANCE)
  //#define EXTRA_LIN_ADVANCE_K // Activer pour les deuxièmes constantes d'avance linéaire
  #define LIN_ADVANCE_K 0.22    // Unité: compression en mm par vitesse d'extrudeuse de 1 mm / s
  //#define LA_DEBUG            // Si activé, cela générera une sortie d'informations de débogage sur USB.
#endif

// @section nivellement

#if EITHER(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL)
  // Remplacer la zone de maillage si la zone automatique (max) est trop grande
  //#define MESH_MIN_X MESH_INSET
  //#define MESH_MIN_Y MESH_INSET
  //#define MESH_MAX_X X_BED_SIZE - (MESH_INSET)
  //#define MESH_MAX_Y Y_BED_SIZE - (MESH_INSET)
#endif

/**
 * Essayez à plusieurs reprises de niveler G29 jusqu'à ce qu'il réussisse.
 * Arrêtez après les tentatives de G29_MAX_RETRIES.
 */
//#define G29_RETRY_AND_RECOVER
#if ENABLED(G29_RETRY_AND_RECOVER)
  #define G29_MAX_RETRIES 3
  #define G29_HALT_ON_FAILURE
  /**
   * Spécifiez les commandes GCODE à exécuter en cas de réussite de la mise à
   * niveau, entre les tentatives et après le nombre maximal de tentatives.
   */
  #define G29_SUCCESS_COMMANDS "M117 Nivellement du lit terminé."
  #define G29_RECOVER_COMMANDS "M117 La sonde a échoué. Rewiping. \ NG28 \ G12 P0 S12 T0"
  #define G29_FAILURE_COMMANDS "M117 Échec de la mise à niveau du lit G0 Z10 M300 P25 S880 M300 P50 S0 M300 P25 S880 M300 P50 S0 M300 P25 S880 M300 P50 S0 G4 S1"

#endif

// @section extras

//
// G2/G3 Arc Support
//
#define ARC_SUPPORT               // Désactiver cette fonctionnalité pour économiser ~ 3226 octets
#if ENABLED(ARC_SUPPORT)
  #define MM_PER_ARC_SEGMENT  1   // Longueur de chaque segment d'arc
  #define MIN_ARC_SEGMENTS   24   // Nombre minimum de segments dans un cercle complet
  #define N_ARC_CORRECTION   25   // Nombre de segments interpolés entre les corrections
  //#define ARC_P_CIRCLES         // Activer le paramètre 'P' pour spécifier des cercles complets
  //#define CNC_WORKSPACE_PLANES  // Permettre aux G2 / G3 de fonctionner dans les avions XY, ZX ou YZ
#endif

// Prise en charge de G5 avec destination XYZE et compensations IJPQ. Nécessite environ 2666 octets.
//#define BEZIER_CURVE_SUPPORT

/**
 * Cible de sonde G38
 *
 * Cette option ajoute G38.2 et G38.3 (sonde vers la cible) et
 * éventuellement G38.4 et G38.5 (sonde éloignée de la cible).
 * Définissez MULTIPLE_PROBING pour G38 pour qu’il teste plusieurs fois.
 */
//#define G38_PROBE_TARGET
#if ENABLED(G38_PROBE_TARGET)
  //#define G38_PROBE_AWAY        // Inclure G38.4 et G38.5 pour s’éloigner de la cible
  #define G38_MINIMUM_MOVE 0.0275 // (mm) Distance minimale qui produira un mouvement.
#endif

// Les déplacements (ou segments) comportant moins d'étapes que celles-ci seront joints au prochain déplacement
#define MIN_STEPS_PER_SEGMENT 6

/**
 * Minimum delay after setting the stepper DIR (in ns)
 *     0 : Aucun délai (attendez au moins 10 µS car un ISR Stepper doit transpirer)
 *    20 : Minimum pour les pilotes TMC2xxx
 *   200 : Minimum pour les pilotes A4988
 *   400 : Minimum pour les pilotes A5984
 *   500 : Minimum pour les pilotes LV8729 (suppose, aucune information dans la fiche technique)
 *   650 : Minimum pour les pilotes DRV8825
 *  1500 : Minimum pour les pilotes TB6600 (suppose, aucune information dans la fiche technique)
 * 15000 : Minimum pour les pilotes TB6560 (suppose, aucune information dans la fiche technique)
 *
 * Remplacez la valeur par défaut en fonction du type de pilote défini dans Configuration.h.
 */
//#define MINIMUM_STEPPER_DIR_DELAY 650

/**
 * Largeur d'impulsion minimale du conducteur pas à pas (en µs)
 *   0 : La plus petite largeur que le MCU peut produire est compatible avec les pilotes TMC2xxx
 *   0 : 500ns minimum pour LV8729, ajusté en stepper.h
 *   1 : Minimum pour les pilotes pas à pas A4988 et A5984
 *   2 : Minimum pour les pilotes pas à pas DRV8825
 *   3 : Minimum pour les pilotes pas à pas TB6600
 *  30 : Minimum pour les pilotes pas à pas TB6560
 *
 * Remplacez la valeur par défaut en fonction du type de pilote défini dans Configuration.h.
 */
//#define MINIMUM_STEPPER_PULSE 2

/**
 * Taux de progression maximum (en Hz) autorisé par le pilote pas à pas
 *  Si non défini, la valeur par défaut est 1 MHz / (2 * MINIMUM_STEPPER_PULSE).
 *  500000 : Maximum pour le pilote pas à pas A4988
 *  400000 : Maximum pour les pilotes pas à pas TMC2xxx
 *  250000 : Maximum pour le pilote pas à pas DRV8825
 *  200000 : Maximum pour pilote pas à pas LV8729
 *  150000 : Maximum pour le pilote pas à pas TB6600
 *   15000 : Maximum pour le pilote pas à pas TB6560
 *
 * Remplacez la valeur par défaut en fonction du type de pilote défini dans Configuration.h.
 */
//#define MAXIMUM_STEPPER_RATE 250000

// @section temperature

// Contrôler le chauffage 0 et le chauffage 1 en parallèle.
//#define HEATERS_PARALLEL

//===========================================================================
//================================= Buffers =================================
//===========================================================================

// @section cachée

// Le nombre de mouvements linéaires pouvant figurer dans le plan à tout moment.
// BLOCK_BUFFER_SIZE DOIT ÊTRE UN MULTIPLE DE 2 (par exemple 8, 16, 32), car les décalages et les "ors" sont utilisés pour effectuer la mise en mémoire tampon.
#if ENABLED(SDSUPPORT)
  #define BLOCK_BUFFER_SIZE 16 // SD, LCD, les boutons prennent plus de mémoire, le tampon de bloc doit être plus petit
#else
  #define BLOCK_BUFFER_SIZE 16 // maximiser le tampon de bloc
#endif

// @section serial

// Tampon ASCII pour l'entrée série
#define MAX_CMD_SIZE 96
#define BUFSIZE 4

// Transmission de taille de la mémoire tampon de l'hôte
// Pour enregistrer 386 octets de PROGMEM (et TX_BUFFER_SIZE + 3 octets de RAM), définissez la valeur sur 0.
// Pour mettre en mémoire tampon un simple "ok", vous avez besoin de 4 octets.
// Pour ADVANCED_OK (M105), vous avez besoin de 32 octets.
// Pour debug-echo: 128 octets pour la vitesse optimale.
// Les autres sorties n'ont pas besoin d'être aussi rapides.
// :[0, 2, 4, 8, 16, 32, 64, 128, 256]
#define TX_BUFFER_SIZE 0

// Taille de la mémoire tampon de réception de l'hôte
// Sans contrôle de flux XON / XOFF (voir SERIAL_XON_XOFF ci-dessous), 32 octets devraient suffire.
// Pour utiliser le contrôle de flux, définissez cette taille de tampon sur au moins 1024 octets.
// :[0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048]
//#define RX_BUFFER_SIZE 1024

#if RX_BUFFER_SIZE >= 1024
  // Activer pour que le contrôleur envoie des caractères de contrôle
  // XON / XOFF à l'hôte pour signaler que le tampon RX est saturé.
  //#define SERIAL_XON_XOFF
#endif

// Ajoutez le code G M575 pour modifier le débit en bauds
//#define BAUD_RATE_GCODE

#if ENABLED(SDSUPPORT)
  // Activez cette option pour collecter et afficher l'utilisation maximale
  // de la file d'attente RX après le transfert d'un fichier vers SD.
  //#define SERIAL_STATS_MAX_RX_QUEUED

  // Activez cette option pour collecter et afficher le nombre
  // d'octets supprimés après un transfert de fichier vers SD.
  //#define SERIAL_STATS_DROPPED_RX
#endif

// Activez un analyseur de commandes d'urgence pour intercepter certaines commandes lorsqu'elles
// entrent dans le tampon de réception série afin qu'elles ne puissent pas être bloquées.
// Gère actuellement M108, M112, M410
// Ne fonctionne pas sur les cartes utilisant des processeurs AT90USB (USBCON)!
//#define EMERGENCY_PARSER

// De mauvaises connexions série peuvent manquer une commande reçue en envoyant un 'ok'
// Par conséquent, certains clients abandonnent après 30 secondes d’expiration.
// Certains autres clients commencent à envoyer des commandes tout en recevant une "attente".
// Cette "attente" n'est envoyée que lorsque le tampon est vide. 1 seconde est une bonne valeur ici.
//#define NO_TIMEOUTS 1000 // Milliseconds

// Certains clients auront bientôt cette fonctionnalité. Cela pourrait rendre inutile NO_TIMEOUTS.
//#define ADVANCED_OK

// Printrun peut avoir des difficultés à recevoir de longues chaînes en même temps.
// Cette option insère des délais courts entre les lignes de la sortie série.
#define SERIAL_OVERRUN_PROTECTION

// @section extras

/**
 * Vitesse du ventilateur supplémentaire
 * Ajoute une vitesse de ventilateur secondaire pour chaque ventilateur de refroidissement d’impression.
 *   'M106 P<fan> T3-255' : Définir une vitesse secondaire pour <ventilateur>
 *   'M106 P<fan> T2'     : Utiliser la vitesse secondaire réglée
 *   'M106 P<fan> T1'     : Restaurer la vitesse du ventilateur précédent
 */
//#define EXTRA_FAN_SPEED

/**
 * Basé sur le micrologiciel et rétraction contrôlée par LCD
 *
 * Ajoutez des commandes G10 / G11 pour un retrait / rétablissement automatique basé sur un microprogramme.
 * Utilisez M207 et M208 pour définir les paramètres de retrait / récupération.
 *
 * Utilisez M209 pour activer ou désactiver le retrait automatique.
 * Lorsque le retrait automatique est activé, tous les mouvements G1 E dans la plage
 * définie seront convertis en mouvements de retrait / récupération basés sur le microprogramme.
 *
 * Assurez-vous de désactiver l'auto-rétractation lors du changement de filament.
 *
 * Notez que les paramètres M207 / M208 / M209 sont enregistrés sur EEPROM.
 *
 */
//#define FWRETRACT
#if ENABLED(FWRETRACT)
  #define FWRETRACT_AUTORETRACT           // coûte ~ 500 octets de PROGMEM
  #if ENABLED(FWRETRACT_AUTORETRACT)
    #define MIN_AUTORETRACT 0.1           // Lorsque l'auto-rétractation est activée, E se déplace de cette longueur et plus
    #define MAX_AUTORETRACT 10.0          // Limite supérieure pour la conversion par rétraction automatique
  #endif
  #define RETRACT_LENGTH 3                // Longueur de retrait par défaut (mm positif)
  #define RETRACT_LENGTH_SWAP 13          // Longueur de retrait par défaut de l'échange (positif mm), pour le changement d'extrudeur
  #define RETRACT_FEEDRATE 45             // Avance par défaut pour la rétraction (mm / s)
  #define RETRACT_ZRAISE 0                // Retract Z-raise par défaut (mm)
  #define RETRACT_RECOVER_LENGTH 0        // Longueur de récupération supplémentaire par défaut (mm, ajoutée pour rétracter la longueur lors de la récupération)
  #define RETRACT_RECOVER_LENGTH_SWAP 0   // Longueur par défaut de récupération d'échange supplémentaire (mm, ajoutée pour rétracter la longueur lors de la récupération du changement d'extrudeur)
  #define RETRACT_RECOVER_FEEDRATE 8      // Avance par défaut pour la récupération de la rétraction (mm / s)
  #define RETRACT_RECOVER_FEEDRATE_SWAP 8 // Avance par défaut pour la récupération de la rétraction du swap (mm / s)
  #if ENABLED(MIXING_EXTRUDER)
    //#define RETRACT_SYNC_MIXING         // Rétracter et restaurer tous les steppers de mélange simultanément
  #endif
#endif

/**
 * Paramètres de changement d'outil universel.
 * S'applique à tous les types d'extrudeurs, sauf mention explicite.
 */
#if EXTRUDERS > 1
  // augmenter la distance Z pour le changement d'outil, si nécessaire pour certaines extrudeuses
  #define TOOLCHANGE_ZRAISE     2  // (mm)
  //#define TOOLCHANGE_NO_RETURN   // Ne jamais revenir à la position précédente sur le changement d'outil

  // Rétracter et amorcer le filament lors du changement d'outil
  //#define TOOLCHANGE_FILAMENT_SWAP
  #if ENABLED(TOOLCHANGE_FILAMENT_SWAP)
    #define TOOLCHANGE_FIL_SWAP_LENGTH          12  // (mm)
    #define TOOLCHANGE_FIL_EXTRA_PRIME           2  // (mm)
    #define TOOLCHANGE_FIL_SWAP_RETRACT_SPEED 3600  // (mm/m)
    #define TOOLCHANGE_FIL_SWAP_PRIME_SPEED   3600  // (mm/m)
  #endif

  /**
   * Position ou ranger la tête lors du changement d'outil.
   * Ne s'applique pas à SWITCHING_TOOLHEAD, DUAL_X_CARRIAGE ou PARKING_EXTRUDER
   */
  //#define TOOLCHANGE_PARK
  #if ENABLED(TOOLCHANGE_PARK)
    #define TOOLCHANGE_PARK_XY    { X_MIN_POS + 10, Y_MIN_POS + 10 }
    #define TOOLCHANGE_PARK_XY_FEEDRATE 6000  // (mm/m)
  #endif
#endif

/**
 * Advanced Pause (Pause avancée)
 * Fonction expérimentale pour le support de changement de filament et pour le stationnement de la buse en pause.
 * Ajoute le GCode M600 pour initier le changement de filament.
 * Si l'option PARK_HEAD_ON_PAUSE est activée, ajoute le GCode M125 pour suspendre l'impression et garer la buse.
 *
 * Nécessite un écran LCD.
 * Nécessite NOZZLE_PARK_FEATURE.
 * Cette fonctionnalité est requise pour le paramètre par défaut FILAMENT_RUNOUT_SCRIPT.
 */
#define ADVANCED_PAUSE_FEATURE
#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #define PAUSE_PARK_RETRACT_FEEDRATE         60  // (mm/s) Vitesse de retrait initiale.
  #define PAUSE_PARK_RETRACT_LENGTH            2  // (mm) Retrait initial.
                                                  // Ce court retrait se fait immédiatement, avant de garer la buse.
  #define FILAMENT_CHANGE_UNLOAD_FEEDRATE     10  // (mm/s) Vitesse de déchargement du filament. Cela peut être assez rapide.
  #define FILAMENT_CHANGE_UNLOAD_ACCEL        25  // (mm/s^2) Une accélération plus faible peut permettre une avance plus rapide.
  #define FILAMENT_CHANGE_UNLOAD_LENGTH      0  // (mm) La longueur du filament pour un déchargement complet.
                                                  //   Pour Bowden, toute la longueur du tube et de la buse.
                                                  //   Pour un entraînement direct, toute la longueur de la buse.
                                                  //   Définissez la valeur sur 0 pour le déchargement manuel.
  #define FILAMENT_CHANGE_SLOW_LOAD_FEEDRATE   6  // (mm/s) Mouvement lent au démarrage du chargement.
  #define FILAMENT_CHANGE_SLOW_LOAD_LENGTH     0  // (mm) Longueur lente, pour laisser le temps d'insérer le matériau.
                                                  //  0 pour désactiver le chargement initial et passer au chargement rapide uniquement
  #define FILAMENT_CHANGE_FAST_LOAD_FEEDRATE   6  // (mm/s) Vitesse de chargement du filament. Cela peut être assez rapide.
  #define FILAMENT_CHANGE_FAST_LOAD_ACCEL     25  // (mm/s^2) Une accélération plus faible peut permettre une avance plus rapide.
  #define FILAMENT_CHANGE_FAST_LOAD_LENGTH     0  // (mm) Longueur de charge du filament, de l'engrenage de l'extrudeur à la buse.
                                                  //   Pour Bowden, toute la longueur du tube et de la buse.
                                                  //   Pour un entraînement direct, toute la longueur de la buse.
  //#define ADVANCED_PAUSE_CONTINUOUS_PURGE       // Purger continuellement jusqu'à la longueur de purge demandée.
  #define ADVANCED_PAUSE_PURGE_FEEDRATE        3  // (mm/s) Vitesse de purge (après le chargement). Devrait être plus lent que la vitesse de chargement.
  #define ADVANCED_PAUSE_PURGE_LENGTH         0  // (mm) Longueur à extruder après le chargement.
                                                  //   Réglez sur 0 pour l'extrusion manuelle.
                                                  //   Le filament peut être extrudé à plusieurs reprises à partir du menu Changement
                                                  //   de filament jusqu'à ce que l'extrusion soit cohérente et pour purger l'ancien filament.
  #define ADVANCED_PAUSE_RESUME_PRIME          0  // (mm) Distance supplémentaire pour amorcer la buse après le retour de la position "rangement".
  //#define ADVANCED_PAUSE_FANS_PAUSE             // Éteignez les ventilateurs de refroidissement d’impression lorsque la machine est en pause.

                                                  // Le déchargement de filament effectue d'abord une rétraction, un délai et une purge:
  #define FILAMENT_UNLOAD_RETRACT_LENGTH      13  // (mm) Décharger la longueur de retrait initiale.
  #define FILAMENT_UNLOAD_DELAY             5000  // (ms) Délais pour que le filament refroidisse après rétraction.
  #define FILAMENT_UNLOAD_PURGE_LENGTH         0  // (mm) Un retrait est fait, puis cette longueur est purgée.

  #define PAUSE_PARK_NOZZLE_TIMEOUT           45  // (secondes) Délai avant que la buse soit éteinte pour des raisons de sécurité.
  #define FILAMENT_CHANGE_ALERT_BEEPS         10  // Nombre de bips d'alerte à jouer lorsqu'une réponse est nécessaire.
  #define PAUSE_PARK_NO_STEPPER_TIMEOUT           // Laisser activer les steppers XYZ pendant le changement de filament.

  #define PARK_HEAD_ON_PAUSE                    // Garez la buse pendant la pause et le changement de filament.
  #define HOME_BEFORE_FILAMENT_CHANGE           // S'assurer que le retour à l'origine est terminé avant de changer de filament

  #define FILAMENT_LOAD_UNLOAD_GCODES           // Ajoutez les Gcodes Charger / Décharger M701 / M702, dans le menu Préparer LCD.
  #define FILAMENT_UNLOAD_ALL_EXTRUDERS         // Autoriser M702 à décharger lorsque la buse est à une température supérieurs à la température cible minimale (définie par M302)
#endif

// @section tmc

/**
 * Options du pilote pas à pas TMC26X
 *
 * La bibliothèque TMC26X Stepper est requise pour ce pilote pas à pas.
 * https://github.com/trinamic/TMC26XStepper
 */
#if HAS_DRIVER(TMC26X)

  #if AXIS_DRIVER_TYPE_X(TMC26X)
    #define X_MAX_CURRENT     1000  // (mA)
    #define X_SENSE_RESISTOR    91  // (mOhms)
    #define X_MICROSTEPS        16  // Nombre de micropas
  #endif

  #if AXIS_DRIVER_TYPE_X2(TMC26X)
    #define X2_MAX_CURRENT    1000
    #define X2_SENSE_RESISTOR   91
    #define X2_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_Y(TMC26X)
    #define Y_MAX_CURRENT     1000
    #define Y_SENSE_RESISTOR    91
    #define Y_MICROSTEPS        16
  #endif

  #if AXIS_DRIVER_TYPE_Y2(TMC26X)
    #define Y2_MAX_CURRENT    1000
    #define Y2_SENSE_RESISTOR   91
    #define Y2_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_Z(TMC26X)
    #define Z_MAX_CURRENT     1000
    #define Z_SENSE_RESISTOR    91
    #define Z_MICROSTEPS        16
  #endif

  #if AXIS_DRIVER_TYPE_Z2(TMC26X)
    #define Z2_MAX_CURRENT    1000
    #define Z2_SENSE_RESISTOR   91
    #define Z2_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_Z3(TMC26X)
    #define Z3_MAX_CURRENT    1000
    #define Z3_SENSE_RESISTOR   91
    #define Z3_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E0(TMC26X)
    #define E0_MAX_CURRENT    1000
    #define E0_SENSE_RESISTOR   91
    #define E0_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E1(TMC26X)
    #define E1_MAX_CURRENT    1000
    #define E1_SENSE_RESISTOR   91
    #define E1_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E2(TMC26X)
    #define E2_MAX_CURRENT    1000
    #define E2_SENSE_RESISTOR   91
    #define E2_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E3(TMC26X)
    #define E3_MAX_CURRENT    1000
    #define E3_SENSE_RESISTOR   91
    #define E3_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E4(TMC26X)
    #define E4_MAX_CURRENT    1000
    #define E4_SENSE_RESISTOR   91
    #define E4_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E5(TMC26X)
    #define E5_MAX_CURRENT    1000
    #define E5_SENSE_RESISTOR   91
    #define E5_MICROSTEPS       16
  #endif

#endif // TMC26X

// @section tmc_smart

/**
 * Pour utiliser les pilotes pas à pas TMC2130, TMC2160, TMC2660, TMC5130, TMC5160
 * en mode SPI, connectez vos broches SPI à l'interface SPI matérielle de votre carte
 * et définissez les broches CS requises dans votre fichier `pins_MYBOARD.h`. (Par exemple,
 * RAMPS 1.4 utilise les broches AUX3 `X_CS_PIN 53`,` Y_CS_PIN 49`, etc.).
 * Vous pouvez également utiliser le logiciel SPI si vous souhaitez utiliser des broches IO à usage général.
 *
 * Pour utiliser les pilotes de moteur pas à pas configurables UMC TMC2208 pour stepper
 * connectez #_SERIAL_TX_PIN à la broche PDN_UART du côté du pilote avec une résistance de 1K.
 * Pour utiliser les capacités de lecture, connectez également
 * #_SERIAL_RX_PIN à PDN_UART sans résistance.
 * Les pilotes peuvent également être utilisés avec le port série.
 *
 * La bibliothèque TMCStepper est requise pour utiliser les pilotes stepper TMC.
 * https://github.com/teemuatlut/TMCStepper
 */
#if HAS_TRINAMIC

  #define HOLD_MULTIPLIER    0.5  // Echelle de réduction du courant de maintien vis à vis du courant d'exécution
  #define INTERPOLATE       true  // Interpoler X / Y / Z_MICROSTEPS à 256

  #if AXIS_IS_TMC(X)
    #define X_CURRENT     800  // (mA) Courant RMS. Multipliez par 1,414 pour le courant de pointe.
    #define X_MICROSTEPS   16  // 0..256
    #define X_RSENSE     0.11
  #endif

  #if AXIS_IS_TMC(X2)
    #define X2_CURRENT    800
    #define X2_MICROSTEPS  16
    #define X2_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(Y)
    #define Y_CURRENT     800
    #define Y_MICROSTEPS   16
    #define Y_RSENSE     0.11
  #endif

  #if AXIS_IS_TMC(Y2)
    #define Y2_CURRENT    800
    #define Y2_MICROSTEPS  16
    #define Y2_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(Z)
    #define Z_CURRENT     800
    #define Z_MICROSTEPS   16
    #define Z_RSENSE     0.11
  #endif

  #if AXIS_IS_TMC(Z2)
    #define Z2_CURRENT    800
    #define Z2_MICROSTEPS  16
    #define Z2_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(Z3)
    #define Z3_CURRENT    800
    #define Z3_MICROSTEPS  16
    #define Z3_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E0)
    #define E0_CURRENT    800
    #define E0_MICROSTEPS  16
    #define E0_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E1)
    #define E1_CURRENT    800
    #define E1_MICROSTEPS  16
    #define E1_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E2)
    #define E2_CURRENT    800
    #define E2_MICROSTEPS  16
    #define E2_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E3)
    #define E3_CURRENT    800
    #define E3_MICROSTEPS  16
    #define E3_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E4)
    #define E4_CURRENT    800
    #define E4_MICROSTEPS  16
    #define E4_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E5)
    #define E5_CURRENT    800
    #define E5_MICROSTEPS  16
    #define E5_RSENSE    0.11
  #endif

  /**
   * Remplacez ici les broches SPI par défaut des pilotes TMC2130, TMC2160, TMC2660, TMC5130 et TMC5160.
   * Les broches par défaut se trouvent dans le fichier de broches de votre carte.
   */
  //#define X_CS_PIN          -1
  //#define Y_CS_PIN          -1
  //#define Z_CS_PIN          -1
  //#define X2_CS_PIN         -1
  //#define Y2_CS_PIN         -1
  //#define Z2_CS_PIN         -1
  //#define Z3_CS_PIN         -1
  //#define E0_CS_PIN         -1
  //#define E1_CS_PIN         -1
  //#define E2_CS_PIN         -1
  //#define E3_CS_PIN         -1
  //#define E4_CS_PIN         -1
  //#define E5_CS_PIN         -1

  /**
   * Option logicielle pour les pilotes pilotés par SPI (TMC2130, TMC2160, TMC2660, TMC5130 et TMC5160).
   * Les broches SWI SPI par défaut sont définies pour les fichiers de
   * broches respectifs, mais vous pouvez les remplacer ou les définir ici.
   */
  //#define TMC_USE_SW_SPI
  //#define TMC_SW_MOSI       -1
  //#define TMC_SW_MISO       -1
  //#define TMC_SW_SCK        -1

  /**
   * Quatre pilotes TMC2209 peuvent utiliser le même port série HW / SW avec des adresses configurées matériellement.
   * Définissez l'adresse à l'aide de cavaliers sur les broches MS1 et MS2.
   * Address | MS1  | MS2
   *       0 | LOW  | LOW
   *       1 | HIGH | LOW
   *       2 | LOW  | HIGH
   *       3 | HIGH | HIGH
   *
   * Définissez * _SERIAL_TX_PIN et * _SERIAL_RX_PIN pour qu'ils correspondent
   * à tous les pilotes du même port série, ici ou dans le fichier Pins de votre carte.
   */
  #define  X_SLAVE_ADDRESS 0
  #define  Y_SLAVE_ADDRESS 0
  #define  Z_SLAVE_ADDRESS 0
  #define X2_SLAVE_ADDRESS 0
  #define Y2_SLAVE_ADDRESS 0
  #define Z2_SLAVE_ADDRESS 0
  #define Z3_SLAVE_ADDRESS 0
  #define E0_SLAVE_ADDRESS 0
  #define E1_SLAVE_ADDRESS 0
  #define E2_SLAVE_ADDRESS 0
  #define E3_SLAVE_ADDRESS 0
  #define E4_SLAVE_ADDRESS 0
  #define E5_SLAVE_ADDRESS 0

  /**
   * Activation logiciel
   *
   * À utiliser pour les pilotes qui n'utilisent pas de broche d'activation dédiée, mais
   * gèrent plutôt la même fonction via une ligne de communication telle que SPI ou UART.
   */
  //#define SOFTWARE_DRIVER_ENABLE

  /**
   * TMC2130, TMC2160, TMC2208, TMC2209, TMC5130 et TMC5160
   * uniquement Utilisez le mode pas à pas ultra silencieux de Trinamic.

   * Lorsqu'il est désactivé, Marlin utilisera le mode pas à pas spreadCycle.
   */
  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z
  #define STEALTHCHOP_E

  /**
   * Optimisez les paramètres du réducteur spreadCycle à l'aide d'ensembles
   * de paramètres prédéfinis ou à l'aide d'un exemple inclus dans la bibliothèque.
   * Les jeux de paramètres fournis sont
   * CHOPPER_DEFAULT_12V
   * CHOPPER_DEFAULT_19V
   * CHOPPER_DEFAULT_24V
   * CHOPPER_DEFAULT_36V
   * CHOPPER_PRUSAMK3_24V // Paramètres importés depuis le firmware officiel Prusa pour MK3 (24V)
   * CHOPPER_MARLIN_119   // Anciennes valeurs par défaut de Marlin v1.1.9
   *
   * Définissez votre propriété avec
   * { <off_time[1..15]>, <hysteresis_end[-3..12]>, hysteresis_start[1..8] }
   */
  #define CHOPPER_TIMING CHOPPER_DEFAULT_12V

  /**
   * Surveillez les pilotes Trinamic pour détecter les conditions d'erreur,
   * telles qu'une température excessive ou un court-circuit à la terre.
   * En cas de surchauffe, Marlin peut diminuer le courant du driver jusqu'à ce que la condition d'erreur disparaisse.
   * D'autres conditions détectées peuvent être utilisées pour arrêter l'impression en cours.
   * G-codes pertinents:
   * M906 - Réglez ou obtenez le courant du moteur en milliampères à l'aide des codes d'axe X, Y, Z, E. Indiquez les valeurs si aucun code d'axe n'est donné.
   * M911 - Signaler la condition de préavertissement de surchauffe du conducteur pas à pas.
   * M912 - Désactivez l'indicateur de condition de pré-alerte de surchauffe du conducteur pas à pas
   * M122 - Rapporter les paramètres du pilote (requiert TMC_DEBUG)
   */
  //#define MONITOR_DRIVER_STATUS

  #if ENABLED(MONITOR_DRIVER_STATUS)
    #define CURRENT_STEP_DOWN     50  // [mA]
    #define REPORT_CURRENT_CHANGE
    #define STOP_ON_ERROR
  #endif

  /**
   * TMC2130, TMC2160, TMC2208, TMC2209, TMC5130 et TMC5160 uniquement
   * Le pilote passera à spreadCycle lorsque la vitesse du stepper est supérieure à HYBRID_THRESHOLD.
   * Ce mode permet des mouvements plus rapides aux dépens de niveaux de bruit plus élevés.
   * STEALTHCHOP_ (XY | Z | E) doit être activé pour pouvoir utiliser HYBRID_THRESHOLD.
   * M913 X / Y / Z / E pour modifier en direct le réglage
   */
  //#define HYBRID_THRESHOLD

  #define X_HYBRID_THRESHOLD     100  // [mm/s]
  #define X2_HYBRID_THRESHOLD    100
  #define Y_HYBRID_THRESHOLD     100
  #define Y2_HYBRID_THRESHOLD    100
  #define Z_HYBRID_THRESHOLD       3
  #define Z2_HYBRID_THRESHOLD      3
  #define Z3_HYBRID_THRESHOLD      3
  #define E0_HYBRID_THRESHOLD     30
  #define E1_HYBRID_THRESHOLD     30
  #define E2_HYBRID_THRESHOLD     30
  #define E3_HYBRID_THRESHOLD     30
  #define E4_HYBRID_THRESHOLD     30
  #define E5_HYBRID_THRESHOLD     30

  /**
   * TMC2130, TMC2160, TMC2209, TMC2660, TMC5130 et TMC5160 uniquement
   * Utilisez StallGuard2 pour détecter un obstacle et déclencher une butée.
   * Connectez la broche DIAG1 du pilote pas à pas à la broche X / Y de butée.
   * Le référencement X, Y et Z sera toujours effectué en mode spreadCycle.
   *
   * X / Y / Z_STALL_SENSITIVITY est utilisé pour régler la sensibilité du déclencheur.
   * Des valeurs plus élevées rendent le système MOINS sensible.
   * Une valeur inférieure rend le système PLUS sensible.
   * Des valeurs trop basses peuvent entraîner des résultats faussement positifs, tandis que des
   * valeurs trop élevées risquent de heurter l'axe sans se déclencher.
   * Il est conseillé de définir X / Y / Z_HOME_BUMP_MM sur 0.
   * M914 X/Y/Z pour modifier en direct le réglage
   */
  //#define SENSORLESS_HOMING // StallGuard capable drivers only

  /**
   * Use StallGuard2 to probe the bed with the nozzle.
   *
   * CAUTION: This could cause damage to machines that use a lead screw or threaded rod
   *          to move the Z axis. Take extreme care when attempting to enable this feature.
   */
  //#define SENSORLESS_PROBING // Pilotes compatibles StallGuard uniquement

  #if EITHER(SENSORLESS_HOMING, SENSORLESS_PROBING)
    // TMC2209: 0...255. TMC2130: -64...63
    #define X_STALL_SENSITIVITY  8
    #define Y_STALL_SENSITIVITY  8
    //#define Z_STALL_SENSITIVITY  8
  #endif

  /**
   * Fonctionnalité bêta!
   * Créez une impulsion de pas à onde carrée 50/50 optimale pour les conducteurs pas à pas.
   */
  //#define SQUARE_WAVE_STEPPING

  /**
   * Activer la commande de débogage M122 pour les pilotes pas à pas TMC.
   * M122 S0 / 1 permettra un rapports continus.
   */
  //#define TMC_DEBUG

  /**
   * Vous pouvez définir vos propres paramètres avancés en remplissant des fonctions prédéfinies.
   * Une liste des fonctions disponibles est consultable sur la page de la bibliothèque github
   * https://github.com/teemuatlut/TMCStepper
   *
   * Exemple:
   * #define TMC_ADV() { \
   *   stepperX.diag0_temp_prewarn(1); \
   *   stepperY.interpolate(0); \
   * }
   */
  #define TMC_ADV() {  }

#endif // HAS_TRINAMIC

// @section L6470

/**
 * Options du pilote pas à pas L6470
 *
 * La bibliothèque Arduino-L6470 (0.7.0 ou supérieure) est requise pour ce pilote pas à pas.
 * https://github.com/ameyer/Arduino-L6470
 *
 * Nécessite de définir les éléments suivants dans votre fichier pins_YOUR_BOARD
 *     L6470_CHAIN_SCK_PIN
 *     L6470_CHAIN_MISO_PIN
 *     L6470_CHAIN_MOSI_PIN
 *     L6470_CHAIN_SS_PIN
 *     L6470_RESET_CHAIN_PIN  (optionnel)
 */
#if HAS_DRIVER(L6470)

  //#define L6470_CHITCHAT        // Afficher des informations d'état supplémentaires

  #if AXIS_DRIVER_TYPE_X(L6470)
    #define X_MICROSTEPS     128  // Nombre de micropas (VALIDE: 1, 2, 4, 8, 16, 32, 128)
    #define X_OVERCURRENT   2000  // (mA) Courant où le conducteur détecte une surintensité (VALID: 375 x (1 - 16) - 6A max - arrondi à la baisse)
    #define X_STALLCURRENT  1500  // (mA) Courant où le conducteur détecte un décrochage (VALID: 31.25 * (1-128) - 4A max - arrondit à la baisse)
    #define X_MAX_VOLTAGE    127  // 0-255, Tension efficace maximale vue par le stepper
    #define X_CHAIN_POS        0  // Position dans la chaîne SPI, 0 = pas dans la chaîne, 1 = MOSI le plus proche
  #endif

  #if AXIS_DRIVER_TYPE_X2(L6470)
    #define X2_MICROSTEPS      128
    #define X2_OVERCURRENT    2000
    #define X2_STALLCURRENT   1500
    #define X2_MAX_VOLTAGE     127
    #define X2_CHAIN_POS         0
  #endif

  #if AXIS_DRIVER_TYPE_Y(L6470)
    #define Y_MICROSTEPS       128
    #define Y_OVERCURRENT     2000
    #define Y_STALLCURRENT    1500
    #define Y_MAX_VOLTAGE      127
    #define Y_CHAIN_POS          0
  #endif

  #if AXIS_DRIVER_TYPE_Y2(L6470)
    #define Y2_MICROSTEPS      128
    #define Y2_OVERCURRENT    2000
    #define Y2_STALLCURRENT   1500
    #define Y2_MAX_VOLTAGE     127
    #define Y2_CHAIN_POS         0
  #endif

  #if AXIS_DRIVER_TYPE_Z(L6470)
    #define Z_MICROSTEPS       128
    #define Z_OVERCURRENT     2000
    #define Z_STALLCURRENT    1500
    #define Z_MAX_VOLTAGE      127
    #define Z_CHAIN_POS          0
  #endif

  #if AXIS_DRIVER_TYPE_Z2(L6470)
    #define Z2_MICROSTEPS      128
    #define Z2_OVERCURRENT    2000
    #define Z2_STALLCURRENT   1500
    #define Z2_MAX_VOLTAGE     127
    #define Z2_CHAIN_POS         0
  #endif

  #if AXIS_DRIVER_TYPE_Z3(L6470)
    #define Z3_MICROSTEPS      128
    #define Z3_OVERCURRENT    2000
    #define Z3_STALLCURRENT   1500
    #define Z3_MAX_VOLTAGE     127
    #define Z3_CHAIN_POS         0
  #endif

  #if AXIS_DRIVER_TYPE_E0(L6470)
    #define E0_MICROSTEPS      128
    #define E0_OVERCURRENT    2000
    #define E0_STALLCURRENT   1500
    #define E0_MAX_VOLTAGE     127
    #define E0_CHAIN_POS         0
  #endif

  #if AXIS_DRIVER_TYPE_E1(L6470)
    #define E1_MICROSTEPS      128
    #define E1_OVERCURRENT    2000
    #define E1_STALLCURRENT   1500
    #define E1_MAX_VOLTAGE     127
    #define E1_CHAIN_POS         0
  #endif

  #if AXIS_DRIVER_TYPE_E2(L6470)
    #define E2_MICROSTEPS      128
    #define E2_OVERCURRENT    2000
    #define E2_STALLCURRENT   1500
    #define E2_MAX_VOLTAGE     127
    #define E2_CHAIN_POS         0
  #endif

  #if AXIS_DRIVER_TYPE_E3(L6470)
    #define E3_MICROSTEPS      128
    #define E3_OVERCURRENT    2000
    #define E3_STALLCURRENT   1500
    #define E3_MAX_VOLTAGE     127
    #define E3_CHAIN_POS         0
  #endif

  #if AXIS_DRIVER_TYPE_E4(L6470)
    #define E4_MICROSTEPS      128
    #define E4_OVERCURRENT    2000
    #define E4_STALLCURRENT   1500
    #define E4_MAX_VOLTAGE     127
    #define E4_CHAIN_POS         0
  #endif

  #if AXIS_DRIVER_TYPE_E5(L6470)
    #define E5_MICROSTEPS      128
    #define E5_OVERCURRENT    2000
    #define E5_STALLCURRENT   1500
    #define E5_MAX_VOLTAGE     127
    #define E5_CHAIN_POS         0
  #endif

  /**
   * Surveiller les pilotes L6470 pour les conditions d'erreur telles que surchauffe et surintensité.
   * En cas de surchauffe, Marlin peut diminuer l'entraînement jusqu'à ce que la condition d'erreur disparaisse.
   * D'autres conditions détectées peuvent être utilisées pour arrêter l'impression en cours.
   * G-codes pertinents:
   * M906 - I1/2/3/4/5  Définissez ou obtenez le niveau d'entraînement du moteur à l'aide des codes d'axe X, Y, Z, E. Indiquez les valeurs si aucun code d'axe n'est fourni.
   *         I non presente or I0 or I1 - X, Y, Z or E0
   *         I2 - X2, Y2, Z2 or E1
   *         I3 - Z3 or E3
   *         I4 - E4
   *         I5 - E5
   * M916 - Augmenter le niveau de conduite jusqu'à l'avertissement thermique
   * M917 - Trouver les seuils de courant minimum
   * M918 - Augmenter la vitesse jusqu'à max ou erreur
   * M122 S0/1 - Signaler les paramètres du pilote
   */
  //#define MONITOR_L6470_DRIVER_STATUS

  #if ENABLED(MONITOR_L6470_DRIVER_STATUS)
    #define KVAL_HOLD_STEP_DOWN     1
    //#define L6470_STOP_ON_ERROR
  #endif

#endif // L6470

/**
 * TWI/I2C BUS
 *
 * Cette fonctionnalité est une fonctionnalité EXPERIMENTALE, elle ne doit donc pas
 * être utilisée sur des machines de production. Activer cette option vous permettra
 * d’envoyer et de recevoir des données I2C de périphériques esclaves sur le bus.
 *
 * ; Exemple #1
 * ; Cette macro envoie la chaîne "Marlin" au périphérique esclave d’adresse 0x63 (99).
 * ; Il utilise plusieurs commandes M260 avec un seul argument B <base 10>
 * M260 A99  ; Adresse de l'esclave cible
 * M260 B77  ; M
 * M260 B97  ; a
 * M260 B114 ; r
 * M260 B108 ; l
 * M260 B105 ; i
 * M260 B110 ; n
 * M260 S1   ; Envoyer le tampon actuel
 *
 * ; Exemple #2
 * ; Demander 6 octets à un périphérique esclave avec l'adresse 0x63 (99)
 * M261 A99 B5
 *
 * ; Exemple #3
 * ; Exemple de sortie en série d'une requête M261
 * echo: i2c-reply: de: 99 octets: 5 données: bonjour
 */

// @section i2cbus

//#define EXPERIMENTAL_I2CBUS
#define I2C_SLAVE_ADDRESS  0 // Définissez une valeur de 8 à 127 pour agir en tant qu'esclave

// @section extras

/**
 * G-code Photo
 * Ajoutez le code M240 G pour prendre une photo.
 * La photo peut être déclenchée par une Pin numérique ou un mouvement physique.
 */
//#define PHOTO_GCODE
#if ENABLED(PHOTO_GCODE)
  // A position to move to (and raise Z) before taking the photo
  //#define PHOTO_POSITION { X_MAX_POS - 5, Y_MAX_POS, 0 }  // { xpos, ypos, zraise } (M240 X Y Z)
  //#define PHOTO_DELAY_MS   100                            // (ms) Durée de la pause avant de revenir en arrière (M240 P)
  //#define PHOTO_RETRACT_MM   6.5                          // (mm) E retirer / récupérer pour le mouvement photo (M240 R S)

  // Déclencheur d'appareil photo numérique Canon RC-1 ou homebrew
  // Data from: http://www.doc-diy.net/photo/rc-1_hacked/
  //#define PHOTOGRAPH_PIN 23

  // Kit de développement Canon Hack
  // http://captain-slow.dk/2014/03/09/3d-printing-timelapses/
  //#define CHDK_PIN        4

  // Deuxième mouvement optionnel avec retard pour déclencher l'obturateur de la caméra
  //#define PHOTO_SWITCH_POSITION { X_MAX_POS, Y_MAX_POS }  // { xpos, ypos } (M240 I J)

  // Durée nécessaire pour maintenir le commutateur ou maintenir CHDK_PIN à l'état HIGH
  //#define PHOTO_SWITCH_MS   50 // (ms) (M240 D)
#endif

/**
 * Contrôle de la fraise et du laser
 *
 * Ajoutez les commandes M3, M4 et M5 pour allumer et éteindre la fraise / laser
 * et pour régler la vitesse de la fraise, la direction de la fraise et la puissance du laser.
 *
 * SuperPid est un contrôleur de vitesse de routeur / fraise utilisé dans la communauté de fraisage CNC.
 * Marlin peut être utilisé pour allumer et éteindre la fraise. Il peut également
 * être utilisé pour régler la vitesse de rotation de la fraise de 5 000 à 30 000 tr / min.
 *
 * Vous devrez sélectionner une Pin pour la fonction ON / OFF et éventuellement une
 * Pin PWM matérielle 0-5V pour le contrôle de la vitesse et une Pin pour le sens de rotation.
 *
 * Voir http://marlinfw.org/docs/configuration/laser_spindle.html pour plus de détails de configuration.
 */
//#define SPINDLE_FEATURE
//#define LASER_FEATURE
#if EITHER(SPINDLE_FEATURE, LASER_FEATURE)
  #define SPINDLE_LASER_ACTIVE_HIGH     false  // Réglez sur "true" si la fonction on / off est active HIGH
  #define SPINDLE_LASER_PWM             true   // Réglez sur "true" si votre contrôleur prend en charge le réglage de la vitesse / puissance
  #define SPINDLE_LASER_PWM_INVERT      true   // Réglez sur "true" si la vitesse / la puissance augmente lorsque vous souhaitez ralentir
  #define SPINDLE_LASER_POWERUP_DELAY   5000   // (ms) Délai pour permettre à la fraise / au laser de monter en vitesse / puissance
  #define SPINDLE_LASER_POWERDOWN_DELAY 5000   // (ms) Délai pour permettre à la fraise de s’arrêter

  #if ENABLED(SPINDLE_FEATURE)
    //#define SPINDLE_CHANGE_DIR               // Activer si votre contrôleur de fraise peut changer le sens de rotation de la fraise
    #define SPINDLE_CHANGE_DIR_STOP            // Activer si la fraise doit s'arrêter avant de changer le sens de rotation
    #define SPINDLE_INVERT_DIR          false  // Régler sur "true" si le sens de rotation est inversé
    /**
     *  Les commandes M3 et M4 utilisent l’équation suivante pour convertir le rapport cyclique PWM en vitesse / puissance
     *
     *  SPEED / POWER = cycle de travail PWM * SPEED_POWER_SLOPE + SPEED_POWER_INTERCEPT
     *    où le cycle de travail PWM varie de 0 à 255
     *
     *  définissez les paramètres suivants pour votre contrôleur (TOUT DOIT ÊTRE RÉGLÉ)
     */
    #define SPEED_POWER_SLOPE    118.4
    #define SPEED_POWER_INTERCEPT  0
    #define SPEED_POWER_MIN     5000
    #define SPEED_POWER_MAX    30000    // Contrôleur de routeur SuperPID 0 - 30 000 tr / min
  #else
    #define SPEED_POWER_SLOPE      0.3922
    #define SPEED_POWER_INTERCEPT  0
    #define SPEED_POWER_MIN       10
    #define SPEED_POWER_MAX      100    // 0-100%
  #endif
#endif

/**
 * Contrôle du refroidissement liquide
 *
 * Ajoutez les commandes M7, M8 et M9 pour activer et désactiver la brumisation ou le refroidissement liquide.
 *
 * Remarque: COOLANT_MIST_PIN et / ou COOLANT_FLOOD_PIN doivent également être définis.
 */
//#define COOLANT_CONTROL
#if ENABLED(COOLANT_CONTROL)
  #define COOLANT_MIST                // Activer si un refroidissement par brumisation est présent
  #define COOLANT_FLOOD               // Activer si refroidissement liquide est présent
  #define COOLANT_MIST_INVERT  false  // Définissez "true" si la fonction marche / arrêt est inversée
  #define COOLANT_FLOOD_INVERT false  // Définissez "true" si la fonction marche / arrêt est inversée
#endif

/**
 * Capteur de largeur de filament
 *
 * Mesure la largeur du filament en temps
 * réel et ajuste le débit pour compenser les irrégularités.
 *
 * Permet également au diamètre de filament
 * mesuré de régler le débit d'extrusion, de sorte que
 * le trancheur doit uniquement spécifier le volume.
 *
 * Un seul extrudeur est pris en charge pour le moment.
 *
 *  34 RAMPS_14    : Entrée analogique 5 sur le connecteur AUX2
 *  81 PRINTRBOARD : Entrée analogique 2 sur le connecteur Exp1 (version B, C, D, E)
 * 301 RAMBO       : Entrée analogique 3
 *
 * Remarque: Il peut être nécessaire de définir des Pins analogiques pour d’autres cartes.
 */
//#define FILAMENT_WIDTH_SENSOR

#if ENABLED(FILAMENT_WIDTH_SENSOR)
  #define FILAMENT_SENSOR_EXTRUDER_NUM 0    // Index de l'extrudeur qui a le capteur de filament. : [0,1,2,3,4]
  #define MEASUREMENT_DELAY_CM        14    // (cm) La distance du capteur de filament à la chambre de fusion

  #define FILWIDTH_ERROR_MARGIN        1.0  // (mm) Si une mesure diffère trop de la largeur nominale, ignorez-la
  #define MAX_MEASUREMENT_DELAY       20    // (octets) Taille de la mémoire tampon pour les mesures stockées (1 octet par cm). Doit être plus grand que MEASUREMENT_DELAY_CM.

  #define DEFAULT_MEASURED_FILAMENT_DIA DEFAULT_NOMINAL_FILAMENT_DIA // Différence entre le diamètre mesuré et le diamètre initial (réglé dans configuration.h)

  // Diafficher la largeur du filament sur la ligne d'état de l'écran LCD. Les messages d'état expirent après 5 secondes.
  //#define FILAMENT_LCD_DISPLAY
#endif

/**
 * Systèmes de coordonnées CNC
 *
 * Permet aux commandes G53 et G54-G59.3 de sélectionner des systèmes de coordonnées
 * et à G92.1 de réinitialiser l’espace de travail en espace machine natif.
 */
//#define CNC_COORDINATE_SYSTEMS

/**
 * Rapport automatique des températures avec M155 S <secondes>
 */
#define AUTO_REPORT_TEMPERATURES

/**
 * Inclure des fonctionnalités dans la sortie M115
 */
#define EXTENDED_CAPABILITIES_REPORT

/**
 * Désactiver toutes les options d'extrusion volumétrique
 */
//#define NO_VOLUMETRICS

#if DISABLED(NO_VOLUMETRICS)
  /**
   * Etat par défaut de l'extrusion volumétrique
   * Activez cette option pour que l'extrusion volumétrique soit la méthode par
   * défaut, avec DEFAULT_NOMINAL_FILAMENT_DIA comme diamètre par défaut.
   *
   * M200 D0 pour désactiver, M200 Dn pour définir un nouveau diamètre.
   */
  //#define VOLUMETRIC_DEFAULT_ON
#endif

/**
 * Activez cette option pour une version plus légère de Marlin qui supprime tous les décalages
 * d’espace de travail, simplifie les transformations de coordonnées, le nivellement, etc.
 *
 *  - M206 et M428 sont désactivés.
 *  - G92 reviendra à son comportement à partir de Marlin 1.0.
 */
//#define NO_WORKSPACE_OFFSETS

/**
 * Définissez le nombre d'espaces de police proportionnels requis pour remplir un espace de caractère typique.
 * Cela peut aider à mieux aligner la sortie de commandes telles que `G29 O` Mesh Output.
 *
 * Pour les clients qui utilisent une police à largeur fixe (telle que OctoPrint), laissez ce paramètre à 1.0.
 * Sinon, ajustez en fonction de votre client et de la police.
 */
#define PROPORTIONAL_FONT_RATIO 1.0

/**
 * Consommez 28 octets de mémoire SRAM pour optimiser l'analyseur de GCode
 */
#define FASTER_GCODE_PARSER

/**
 * Options de Gcode CNC
 * Prise en charge des dialectes de Gcode de type CNC utilisés par les découpeuses au laser, les cames de machine à dessiner, etc.
 * Notez que les vitesses G0 doivent être utilisées avec précaution pour l’impression 3D (le cas échéant).
 * Des vitesses d'alimentation élevées peuvent provoquer des résonnances et nuire à la qualité d'impression.
 */
//#define PAREN_COMMENTS      // Prise en charge des commentaires délimités par des parenthèses
//#define GCODE_MOTION_MODES  // Rappelez-vous le mode de mouvement (G0 G1 G2 G3 G5 G38.X) et appliquez-le pour X Y Z E F, etc.

// Activer et définir une vitesse d'avance (par défaut) pour tous les déplacements G0
//#define G0_FEEDRATE 3000 // (mm/m)
#ifdef G0_FEEDRATE
  //#define VARIABLE_G0_FEEDRATE // La vitesse de G0 est définie par F en mode de mouvement G0
#endif

/**
 * G-code Macros
 *
 * Ajoutez des Gcodes M810-M819 pour définir et exécuter des macros G-code.
 * Les macros ne sont pas enregistrées dans l'EEPROM.
 */
//#define GCODE_MACROS
#if ENABLED(GCODE_MACROS)
  #define GCODE_MACROS_SLOTS       5  // un maximum de 10 macros peuvent être utilisés
  #define GCODE_MACROS_SLOT_SIZE  50  // Longueur maximale d'une seule macro
#endif

/**
 * Éléments de menu définis par l'utilisateur qui exécutent un GCode personnalisé
 */
//#define CUSTOM_USER_MENUS
#if ENABLED(CUSTOM_USER_MENUS)
  #define CUSTOM_USER_MENU_TITLE "niv. manuel"
  #define USER_SCRIPT_DONE "niv. manuel OK"


  #define USER_DESC_1 "Home"
  #define USER_GCODE_1 "G28"

  #define USER_DESC_2 "AV. Gauche"
  #define USER_GCODE_2 "G1 Z10 F5000\nG1 X20 Y20\nG1 Z0"

  #define USER_DESC_3 "AV. Droit"
  #define USER_GCODE_3 "G1 Z10 F5000\nG1 X280 Y20\nG1 Z0"

  #define USER_DESC_4 "AR. Droit"
  #define USER_GCODE_4 "G1 Z10 F5000\nG1 X280 Y280\nG1 Z0"

  #define USER_DESC_5 "AR. Gauche"
  #define USER_GCODE_5 "G1 Z10 F5000\nG1 X20 Y280\nG1 Z0"

  #define USER_DESC_6 "Nettoyage du Bed"
  #define USER_GCODE_6 "G1 X150 Y300 Z200"
#endif

/**
 * Commandes d'action hôte
 *
 * Définissez les commandes d’action du diffuseur d’hôte conformément à la norme.
 *
 * Voir https://reprap.org/wiki/G-code#Action_commands
 * Commandes communes ........ poweroff, pause, pause, reprise, reprise, annulation
 * G29_RETRY_AND_RECOVER .. probe_rewipe, probe_failed
 *
 * Certaines fonctionnalités ajoutent des codes de motif pour étendre ces commandes.
 *
 * La prise en charge des invites hôtes permet à Marlin d’utiliser l’hôte pour les invites des utilisateurs afin que
 * l’exécution des détecteurs de fin defilaments et d’autres processus puissent être gérés à partir de l’hôte.
 */
//#define HOST_ACTION_COMMANDS
#if ENABLED(HOST_ACTION_COMMANDS)
  //#define HOST_PROMPT_SUPPORT
#endif

//===========================================================================
//=================== Paramètres du codeur de position I2C ==================
//===========================================================================

/**
 * Codeurs de position I2C pour le contrôle en boucle fermée.
 * Développé par Chris Barr chez Aus3D.
 *
 * Wiki: http://wiki.aus3d.com.au/Magnetic_Encoder
 * Github: https://github.com/Aus3D/MagneticEncoder
 *
 * Fournisseur: http://aus3d.com.au/magnetic-encoder-module
 * Fournisseur alternatif: http://reliabuild3d.com/
 *
 * Les codeurs Reliabuild ont été modifiés pour améliorer la fiabilité.
 */

//#define I2C_POSITION_ENCODERS
#if ENABLED(I2C_POSITION_ENCODERS)

  #define I2CPE_ENCODER_CNT         1                       // Le nombre d'encodeurs installés; maximum
                                                            // de 5 encodeurs supportés actuellement.

  #define I2CPE_ENC_1_ADDR          I2CPE_PRESET_ADDR_X     // Adresse I2C de l'encodeur. 30-200.
  #define I2CPE_ENC_1_AXIS          X_AXIS                  // Axe sur lequel le module de codeur est installé. <X | Y | Z | E> _AXIS.
  #define I2CPE_ENC_1_TYPE          I2CPE_ENC_TYPE_LINEAR   // Type de codeur: I2CPE_ENC_TYPE_LINEAR -ou-
                                                            // I2CPE_ENC_TYPE_ROTARY.
  #define I2CPE_ENC_1_TICKS_UNIT    2048                    // 1024 pour les bandes magnétiques avec des pôles de 2 mm; 2048
                                                            // pour les poteaux de 1mm. Pour les codeurs linéaires, il s'agit de ticks
                                                            // / mm. Pour les codeurs rotatifs, il s'agit de ticks / révolution.
  //#define I2CPE_ENC_1_TICKS_REV     (16 * 200)            // Seulement nécessaire pour les encodeurs rotatifs; nombre de pas
                                                            // par tour complet (pas de moteur / tour * en micropas)
  //#define I2CPE_ENC_1_INVERT                              // Inverser le sens de déplacement de l'axe.
  #define I2CPE_ENC_1_EC_METHOD     I2CPE_ECM_MICROSTEP     // Type de correction d'erreur.
  #define I2CPE_ENC_1_EC_THRESH     0.10                    // Taille du seuil d'erreur (en mm) au-dessus de laquelle l'imprimante
                                                            // tentera de corriger l'erreur; les erreurs inférieures à cette valeur sont
                                                            // ignorées afin de minimiser les effets du bruit / du temps de latence
                                                            // de la mesure (filtre).

  #define I2CPE_ENC_2_ADDR          I2CPE_PRESET_ADDR_Y     // Comme ci-dessus, mais pour le codeur 2.
  #define I2CPE_ENC_2_AXIS          Y_AXIS
  #define I2CPE_ENC_2_TYPE          I2CPE_ENC_TYPE_LINEAR
  #define I2CPE_ENC_2_TICKS_UNIT    2048
  //#define I2CPE_ENC_2_TICKS_REV   (16 * 200)
  //#define I2CPE_ENC_2_INVERT
  #define I2CPE_ENC_2_EC_METHOD     I2CPE_ECM_MICROSTEP
  #define I2CPE_ENC_2_EC_THRESH     0.10

  #define I2CPE_ENC_3_ADDR          I2CPE_PRESET_ADDR_Z     // Encoder 3. Ajouter des options de configuration supplémentaires
  #define I2CPE_ENC_3_AXIS          Z_AXIS                  // comme ci-dessus, ou utilisez les valeurs par défaut ci-dessous.

  #define I2CPE_ENC_4_ADDR          I2CPE_PRESET_ADDR_E     // Encodeur 4.
  #define I2CPE_ENC_4_AXIS          E_AXIS

  #define I2CPE_ENC_5_ADDR          34                      // Encodeur 5.
  #define I2CPE_ENC_5_AXIS          E_AXIS

  // Paramètres par défaut pour les encodeurs activés, mais sans les paramètres configurés ci-dessus.
  #define I2CPE_DEF_TYPE            I2CPE_ENC_TYPE_LINEAR
  #define I2CPE_DEF_ENC_TICKS_UNIT  2048
  #define I2CPE_DEF_TICKS_REV       (16 * 200)
  #define I2CPE_DEF_EC_METHOD       I2CPE_ECM_NONE
  #define I2CPE_DEF_EC_THRESH       0.1

  //#define I2CPE_ERR_THRESH_ABORT  100.0                   // Taille de seuil d'erreur (en mm) sur un axe
                                                            // donné, après quoi l'imprimante doit abandonner. Commentez
                                                            // pour désactiver le comportement d'abandon.

  #define I2CPE_TIME_TRUSTED        10000                   // Après une défaillance du codeur, il ne doit plus y avoir de
                                                            // défaillance pendant cette durée (en ms) avant que
                                                            // le codeur ne soit à nouveau sécurisé.

  /**
   * La position est vérifiée à chaque fois qu'une nouvelle commande est exécutée à partir de la mémoire tampon, mais lors de longs
   * déplacements, ce paramètre détermine le temps de mise à jour minimum entre les vérifications. Une valeur de 100 fonctionne bien
   * avec une moyenne glissante d'erreur en essayant de corriger uniquement les sauts et non les vibrations.
   */
  #define I2CPE_MIN_UPD_TIME_MS     4                       // (ms) Temps minimum entre les vérifications d'encodeur.

  // Utilisez une moyenne glissante pour identifier les erreurs persistantes qui indiquent des sauts, par opposition aux vibrations et au bruit.
  #define I2CPE_ERR_ROLLING_AVERAGE

#endif // I2C_POSITION_ENCODERS

/**
 * Matrice de débogage MAX7219
 *
 * Ajoutez un support pour une matrice de LED 8x8 à faible coût basée sur la puce Max7219 en tant qu'écran d'état en temps réel.
 * Nécessite 3 fils de signal. Certaines options de débogage utiles sont incluses pour illustrer son utilisation.
 */
//#define MAX7219_DEBUG
#if ENABLED(MAX7219_DEBUG)
  #define MAX7219_CLK_PIN   64
  #define MAX7219_DIN_PIN   57
  #define MAX7219_LOAD_PIN  44

  //#define MAX7219_GCODE          // Ajoutez le code G M7219 pour contrôler la matrice de LED
  #define MAX7219_INIT_TEST    2   // Effectuer un motif de test à l’initialisation (régler sur 2 pour la spirale)
  #define MAX7219_NUMBER_UNITS 1   // Nombre d'unités max7219 dans la chaîne.
  #define MAX7219_ROTATE       0   // Tourner l'affichage dans le sens des aiguilles d'une montre (en multiples de +/- 90 °)
                                   // connecteur à droite = 0 en bas = -90 en haut = 90 à gauche = 180
  //#define MAX7219_REVERSE_ORDER  // Les différentes unités de matrice de LED peuvent être dans l'ordre inverse
  //#define MAX7219_SIDE_BY_SIDE   // Les cartes Big chip + matrix peuvent être chaînées côte à côte

  /**
   * Exemples de fonctionnalités de débogage
   * Si vous ajoutez d'autres écrans de débogage, veillez à éviter les conflits!
   */
  #define MAX7219_DEBUG_PRINTER_ALIVE    // Voyant clignotant de la matrice 8x8 pour indiquer que le micrologiciel fonctionne
  #define MAX7219_DEBUG_PLANNER_HEAD  3  // Affiche la position de la tête de la file d'attente du planificateur sur cette rangée de matrices de LED
  #define MAX7219_DEBUG_PLANNER_TAIL  5  // Afficher la position de la queue de la file de planification sur cette ligne et sur la ligne suivante de la matrice

  #define MAX7219_DEBUG_PLANNER_QUEUE 0  // Afficher la profondeur actuelle de la file d'attente du planning sur cette ligne et sur la ligne suivante
                                         // de la matrice Si vous rencontrez des problèmes de bégaiement, de redémarrage, etc., cette option peut
                                         // révéler comment les modifications apportées à la configuration affectent l'imprimante en temps réel.
#endif

/**
 * Prise en charge de NanoDLP Sync
 *
 * Ajout de la prise en charge des déplacements Z synchronisés lors de l’utilisation de NanoDLP. Les déplacements d’axe G0 / G1 généreront
 * la chaîne "Z_move_comp" pour permettre la synchronisation avec l’exposition du projecteur DLP. Cette modification permettra d'utiliser
 * [[WaitForDoneMessage]] au lieu de renseigner votre gcode avec des commandes M400.

 */
//#define NANODLP_Z_SYNC
#if ENABLED(NANODLP_Z_SYNC)
  //#define NANODLP_ALL_AXIS  // Active la sortie "Z_move_comp" sur n'importe quel déplacement d'axe.
                              // Le comportement par défaut est limité à l'axe Z uniquement.
#endif

/**
 * Prise en charge WiFi (Espressif ESP32 WiFi)
 */
//#define WIFISUPPORT
#if ENABLED(WIFISUPPORT)
  #define WIFI_SSID "Wifi SSID"
  #define WIFI_PWD  "Wifi Password"
  //#define WEBSUPPORT        // Démarrer un serveur Web avec la recherche automatique
  //#define OTASUPPORT        // Prise en charge des mises à jour du micrologiciel par liaison radio
#endif

/**
 * Unité multi-matériaux Prusa v2
 * Activer dans Configuration.h
 */
#if ENABLED(PRUSA_MMU2)

  // Port série utilisé pour la communication avec MMU2.
  // Pour AVR, activez le port UART utilisé pour la MMU. (par exemple, internalSerial)
  // Pour les cartes 32 bits, vérifiez dans votre HAL les ports série disponibles. (par exemple, Serial2)
  #define INTERNAL_SERIAL_PORT 2
  #define MMU2_SERIAL internalSerial

  // Utiliser la réinitialisation matérielle pour MMU si une broche est définie pour celle-ci
  //#define MMU2_RST_PIN 23

  // Activer si le MMU2 a des moteurs pas à pas de 12 V (MMU2 Firmware 1.0.2 et supérieur)
  //#define MMU2_MODE_12V

  // GCode à exécuter lorsque MMU2 F.I.N.D.A. la sonde détecte la fin de filament
  #define MMU2_FILAMENT_RUNOUT_SCRIPT "M600"

  // Ajouter un menu LCD pour MMU2
  //#define MMU2_MENUS
  #if ENABLED(MMU2_MENUS)
    // Paramètres de chargement / déchargement du filament à partir du menu LCD.
    // Ceci est pour les extrudeurs de style Prusa MK3. Personnaliser pour votre matériel.
    #define MMU2_FILAMENTCHANGE_EJECT_FEED 80.0
    #define MMU2_LOAD_TO_NOZZLE_SEQUENCE \
      {  7.2,  562 }, \
      { 14.4,  871 }, \
      { 36.0, 1393 }, \
      { 14.4,  871 }, \
      { 50.0,  198 }

    #define MMU2_RAMMING_SEQUENCE \
      {   1.0, 1000 }, \
      {   1.0, 1500 }, \
      {   2.0, 2000 }, \
      {   1.5, 3000 }, \
      {   2.5, 4000 }, \
      { -15.0, 5000 }, \
      { -14.0, 1200 }, \
      {  -6.0,  600 }, \
      {  10.0,  700 }, \
      { -10.0,  400 }, \
      { -50.0, 2000 }

  #endif

  //#define MMU2_DEBUG  // Écrire les informations de débogage sur la sortie série

#endif // PRUSA_MMU2

/**
 * Paramètres avancés du compteur d'impression
 */
#if ENABLED(PRINTCOUNTER)
  #define SERVICE_WARNING_BUZZES  3
  // Activer jusqu'à 3 horloges de surveillance
  //#define SERVICE_NAME_1      "Service S"
  //#define SERVICE_INTERVAL_1  100 // heures d'impression
  //#define SERVICE_NAME_2      "Service L"
  //#define SERVICE_INTERVAL_2  200 // heures d'impression
  //#define SERVICE_NAME_3      "Service 3"
  //#define SERVICE_INTERVAL_3    1 // heures d'impression
#endif

// @section develop

/**
 * M43 - affiche le statut des broches, surveille les modifications, les endstop et la bascule, test de la servo-sonde Z, changement d'état des Pins
 */
//#define PINS_DEBUGGING

// Activer le mode dev Marlin qui ajoute des commandes spéciales
//#define MARLIN_DEV_MODE
