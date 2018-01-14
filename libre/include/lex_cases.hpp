#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma once

#include "lex_constants.hpp"

#undef __letter__case__
#undef __number__case__

#undef __pipe__case__
#undef __open__paren__case__
#undef __close__paren__case__
#undef __less__then__case__
#undef __greater__then__case
#undef __single__quote__case__
#undef __underscore__case__
#undef __colon__case__
#undef __hash__case__
#undef __equals__case__
#undef __exclamation__case__
#undef __ampersand__case__

#define __letter__case__    case ALC : \
                            case BLC : \
                            case CLC : \
                            case DLC : \
                            case ELC : \
                            case FLC : \
                            case GLC : \
                            case HLC : \
                            case ILC : \
                            case JLC : \
                            case KLC : \
                            case LLC : \
                            case MLC : \
                            case NLC : \
                            case OLC : \
                            case PLC : \
                            case QLC : \
                            case RLC : \
                            case SLC : \
                            case TLC : \
                            case ULC : \
                            case VLC : \
                            case WLC : \
                            case XLC : \
                            case YLC : \
                            case ZLC : \
                            case AUC : \
                            case BUC : \
                            case CUC : \
                            case DUC : \
                            case EUC : \
                            case FUC : \
                            case GUC : \
                            case HUC : \
                            case IUC : \
                            case JUC : \
                            case KUC : \
                            case LUC : \
                            case MUC : \
                            case NUC : \
                            case OUC : \
                            case PUC : \
                            case QUC : \
                            case RUC : \
                            case SUC : \
                            case TUC : \
                            case UUC : \
                            case VUC : \
                            case WUC : \
                            case XUC : \
                            case YUC : \
                            case ZUC : \

#define __digit__case__     case D1 : \
                            case D2 : \
                            case D3 : \
                            case D4 : \
                            case D5 : \
                            case D6 : \
                            case D7 : \
                            case D8 : \
                            case D9 : \
                            case D0 : \

#define __dot__case__       case DOT:

#define __escape__case__    case ESCAPE:

#define __term__case__      __letter__case__    \
                            __digit__case__     \
                            __dot__case__       \
                            __escape__case__

#define __symbol__case__    __letter__case__    \
                            __digit__case__

#define __escape__sequence__case__  case WORD_BOUNDARY:                             \
                                    case NON_WORD_BOUNDARY:                         \
                                    case START_OF_SUBJECT:                          \
                                    case END_OF_SUBJECT_OR_LINE_END_OF_SUBJECT:     \
                                    case END_OF_SUBJECT:                            \
                                    case PREVIOUS_MATCH_IN_SUBJECT:                 \
                                    case RESET_START_MATCH:                         \
                                    case SUBROUTINE_OR_NAMED_REFERENCE_START_G:     \
                                    case NAMED_REFERENCE_START_K:                   \
                                    case ONE_DATA_UNIT:                             \
                                    case DECIMAL_DIGIT:                             \
                                    case NOT_DECIMAL_DIGIT:                         \
                                    case HORIZONTAL_WHITE_SPACE:                    \
                                    case NOT_HORIZONTAL_WHITE_SPACE:                \
                                    case NOT_NEW_LINE:                              \
                                    case CHAR_WITH_PROPERTY:                        \
                                    case CHAR_WITHOUT_PROPERTY:                     \
                                    case NEW_LINE_SEQUENCE:                         \
                                    case WHITE_SPACE:                               \
                                    case NOT_WHITE_SPACE:                           \
                                    case VERTICAL_WHITE_SPACE:                      \
                                    case NOT_VERTICAL_WHITE_SPACE:                  \
                                    case WORD_CHAR:                                 \
                                    case NOT_WORD_CHAR:                             \
                                    case EXTENDED_UNICODE_CHAR:                     \
                                    case BELL_CHAR:                                 \
                                    case ESCAPE_CHAR:                               \
                                    case FORM_FEED:                                 \
                                    case NEW_LINE:                                  \
                                    case CARRIAGE_RETURN:                           \
                                    case TAB:                                       \
                                    case BACKSLASH:

#define __pipe__case__              case PIPE:

#define __closure___start__case__   case OPEN_BRACE:                                \
                                    case PLUS:                                      \
                                    case STAR:                                      \
                                    case QUESTION_MARK:

#define __start__range__case__      case OPEN_RANGE_BRACKET:

#define __open__paren__case__       case OPEN_PAREN:
#define __close__paren__case__       case CLOSE_PAREN:

#pragma clang diagnostic pop