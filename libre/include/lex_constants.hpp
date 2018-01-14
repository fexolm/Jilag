//
// Created by fexolm on 27.09.17.
//

#pragma once

#undef ALC
#undef BLC
#undef CLC
#undef DLC
#undef ELC
#undef FLC
#undef GLC
#undef HLC
#undef ILC
#undef JLC
#undef KLC
#undef LLC
#undef MLC
#undef NLC
#undef OLC
#undef PLC
#undef QLC
#undef RLC
#undef SLC
#undef TLC
#undef ULC
#undef VLC
#undef WLC
#undef XLC
#undef YLC
#undef ZLC

#undef AUC
#undef BUC
#undef CUC
#undef DUC
#undef EUC
#undef FUC
#undef GUC
#undef HUC
#undef IUC
#undef JUC
#undef KUC
#undef LUC
#undef MUC
#undef NUC
#undef OUC
#undef PUC
#undef QUC
#undef RUC
#undef SUC
#undef TUC
#undef UUC
#undef VUC
#undef WUC
#undef XUC
#undef YUC
#undef ZUC

#undef D1
#undef D2
#undef D3
#undef D4
#undef D5
#undef D6
#undef D7
#undef D8
#undef D9
#undef D0

#undef PIPE
#undef OPEN_PAREN
#undef CLOSE_PAREN
#undef LESS_THEN
#undef GREATER_THEN
#undef SINGLE_QUOTE
#undef UNDERSCORE
#undef COLON
#undef HASH
#undef EQUALS
#undef EXCLAMATION
#undef AMPERSAND

#undef START_OF_NEW_LINE
#undef END_OF_SUBJECT_OR_LINE
#undef DOT
#undef ESCAPE

#undef WORD_BOUNDARY
#undef NON_WORD_BOUNDARY
#undef START_OF_SUBJECT
#undef END_OF_SUBJECT_OR_LINE_END_OF_SUBJECT
#undef END_OF_SUBJECT
#undef PREVIOUS_MATCH_IN_SUBJECT
#undef RESET_START_MATCH
#undef SUBROUTINE_OR_NAMED_REFERENCE_START_G
#undef NAMED_REFERENCE_START_K

#undef ONE_DATA_UNIT
#undef DECIMAL_DIGIT
#undef NOT_DECIMAL_DIGIT
#undef HORIZONTAL_WHITE_SPACE
#undef NOT_HORIZONTAL_WHITE_SPACE
#undef NOT_NEW_LINE
#undef CHAR_WITH_PROPERTY
#undef CHAR_WITHOUT_PROPERTY
#undef NEW_LINE_SEQUENCE
#undef WHITE_SPACE
#undef NOT_WHITE_SPACE
#undef VERTICAL_WHITE_SPACE
#undef NOT_VERTICAL_WHITE_SPACE
#undef WORD_CHAR
#undef NOT_WORD_CHAR
#undef EXTENDED_UNICODE_CHAR

#undef BELL_CHAR
#undef CONTROL_CHAR
#undef ESCAPE_CHAR
#undef FORM_FEED
#undef NEW_LINE
#undef CARRIAGE_RETURN
#undef TAB
#undef BACKSLASH
#undef HEX_CHAR

#undef QUESTION_MARK
#undef PLUS
#undef STAR
#undef OPEN_BRACE
#undef CLOSE_BRACE
#undef COMMA

#undef OPEN_RANGE_BRACKET
#undef CLOSE_RANGE_BRACKET
#undef DASH

/*
 * terms
 */

#define ALC 'a'
#define BLC 'b'
#define CLC 'c'
#define DLC 'd'
#define ELC 'e'
#define FLC 'f'
#define GLC 'g'
#define HLC 'h'
#define ILC 'i'
#define JLC 'j'
#define KLC 'k'
#define LLC 'l'
#define MLC 'm'
#define NLC 'n'
#define OLC 'o'
#define PLC 'p'
#define QLC 'q'
#define RLC 'r'
#define SLC 's'
#define TLC 't'
#define ULC 'u'
#define VLC 'v'
#define WLC 'w'
#define XLC 'x'
#define YLC 'y'
#define ZLC 'z'

#define AUC 'A'
#define BUC 'B'
#define CUC 'C'
#define DUC 'D'
#define EUC 'E'
#define FUC 'F'
#define GUC 'G'
#define HUC 'H'
#define IUC 'I'
#define JUC 'J'
#define KUC 'K'
#define LUC 'L'
#define MUC 'M'
#define NUC 'N'
#define OUC 'O'
#define PUC 'P'
#define QUC 'Q'
#define RUC 'R'
#define SUC 'S'
#define TUC 'T'
#define UUC 'U'
#define VUC 'V'
#define WUC 'W'
#define XUC 'X'
#define YUC 'Y'
#define ZUC 'Z'

#define D1  '1'
#define D2  '2'
#define D3  '3'
#define D4  '4'
#define D5  '5'
#define D6  '6'
#define D7  '7'
#define D8  '8'
#define D9  '9'
#define D0  '0'

/*
 * operations
 */

#define PIPE            '|'
#define OPEN_PAREN      '('
#define CLOSE_PAREN     ')'
#define LESS_THEN       '<'
#define GREATER_THEN    '>'
#define SINGLE_QUOTE    '\''
#define UNDERSCORE      '_'
#define COLON           ':'
#define HASH            '#'
#define EQUALS          '='
#define EXCLAMATION     '!'
#define AMPERSAND       '&'

/*
 * Special symbols
 */

#define START_OF_NEW_LINE                           '^'
#define END_OF_SUBJECT_OR_LINE                      '$'

#define DOT                                         '.'
#define ESCAPE                                      '\\'
#define OPEN_RANGE_BRACKET                          '['
#define CLOSE_RANGE_BRACKET                         ']'
#define DASH                                        '-'

/*
 * Escape sequences
 */

#define WORD_BOUNDARY                               'b'
#define NON_WORD_BOUNDARY                           'B'
#define START_OF_SUBJECT                            'A'
#define END_OF_SUBJECT_OR_LINE_END_OF_SUBJECT       'Z'
#define END_OF_SUBJECT                              'z'
#define PREVIOUS_MATCH_IN_SUBJECT                   'G'
#define RESET_START_MATCH                           'K'
#define SUBROUTINE_OR_NAMED_REFERENCE_START_G       'g'
#define NAMED_REFERENCE_START_K                     'k'

#define ONE_DATA_UNIT                               'C'
#define DECIMAL_DIGIT                               'd'
#define NOT_DECIMAL_DIGIT                           'D'
#define HORIZONTAL_WHITE_SPACE                      'h'
#define NOT_HORIZONTAL_WHITE_SPACE                  'H'
#define NOT_NEW_LINE                                'N'
#define CHAR_WITH_PROPERTY                          'p'
#define CHAR_WITHOUT_PROPERTY                       'P'
#define NEW_LINE_SEQUENCE                           'R'
#define WHITE_SPACE                                 's'
#define NOT_WHITE_SPACE                             'S'
#define VERTICAL_WHITE_SPACE                        'v'
#define NOT_VERTICAL_WHITE_SPACE                    'V'
#define WORD_CHAR                                   'w'
#define NOT_WORD_CHAR                               'W'
#define EXTENDED_UNICODE_CHAR                       'X'

#define BELL_CHAR                                   '\a'
#define ESCAPE_CHAR                                 '\e'
#define FORM_FEED                                   '\f'
#define NEW_LINE                                    '\n'
#define CARRIAGE_RETURN                             '\r'
#define TAB                                         '\t'
#define BACKSLASH                                   '\\'

/*
 * Closure
 */

#define QUESTION_MARK       '?'
#define PLUS                '+'
#define STAR                '*'
#define OPEN_BRACE          '{'
#define CLOSE_BRACE         '}'
#define COMMA               ','