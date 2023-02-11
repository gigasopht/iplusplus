export module iplusplus:generic;

import :core;
import :windows;
import :database;
import std.core;

using namespace iplusplus;
using namespace standard;

extern "C" { typedef void* (*p0)();}
extern "C" { typedef void* (*p1)(void*);}
extern "C" { typedef void* (*p2)(void*, void*);}
extern "C" { typedef void* (*p3)(void*, void*, void*);}
extern "C" { typedef void* (*p4)(void*, void*, void*, void*);}
extern "C" { typedef void* (*p5)(void*, void*, void*, void*, void*);}
extern "C" { typedef void* (*p6)(void*, void*, void*, void*, void*, void*);}
extern "C" { typedef void* (*p7)(void*, void*, void*, void*, void*, void*, void*);}
extern "C" { typedef void* (*p8)(void*, void*, void*, void*, void*, void*, void*, void*);}
extern "C" { typedef void* (*p9)(void*, void*, void*, void*, void*, void*, void*, void*, void*);}
extern "C" { typedef void* (*p10)(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);}
extern "C" { typedef void* (*p11)(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);}
extern "C" { typedef void* (*p12)(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);}
extern "C" { typedef void* (*p13)(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);}
extern "C" { typedef void* (*p14)(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);}
extern "C" { typedef void* (*p15)(void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);}

#define iooneecohd

namespace generic
{
    typedef wchar_t character;

    struct instrucshon_tiip
    {
        enum
        {
            phuncshon_corl,
            iph,
            reepeet,
            braac,
            continioo,
            uuiil,
            doo_uuiil,
            trii,
            handleer,
            throuu,
            select,
            suuich,
            choos,
            pic,
            reeturn,
            asiin,
            asiin_integer,
            asiin_number,
            asiin_string,
            asiin_return,
            asiin_eenioonneraator,
            nioo_instans,
            asiin_nul,
            phor,
            ecspreshon,
            updaat_uptrs
        };
    };

    struct prohseedioor;

    struct return_ualioo
    {
        enum
        {
            none,
            reeturn,
            braac,
            continioo
        };
    };

    struct reesult
    {
        character ualioo;
        string ret;

        reesult() { ualioo = return_ualioo::reeturn; }

        reesult(character ualioo_set)
        {
            ualioo = ualioo_set;
        }

        reesult(const string& ret_set)
            : ret(ret_set)
        {
            ualioo = return_ualioo::reeturn;
        }

    };

    struct corlabl
    {
        virtual reesult corl(prohseedioor& p) = 0;
    };

    struct instrucshon : corlabl
    {
        character tiip;
        string clahs_naann;
        long long start;
        long long end;

        instrucshon() {}

        instrucshon(const string& c, long long s, long long e, character tiip_set) : tiip(tiip_set), clahs_naann(c), start(s), end(e) {}

        bool operator<(const instrucshon& i)
        {
            return tiip < i.tiip;
        }

        virtual reesult corl(prohseedioor& p) { return reesult(return_ualioo::none); }
    };


    struct vecssepshon
    {
        string descripshon;
        string clahs;
        long long start;
        long long end;
        string naann;

        vecssepshon() {}

        vecssepshon(const string& n, const string& d, const string& c, long long s, long long e) : naann(n), descripshon(d), clahs(c), start(s), end(e) {}
    };

    struct ecssepshon
    {
        instrucshon* i;

        virtual string too_string() { return string(L""); }
    };

    struct uuiil_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A while key word is expected.";
        }
    };

    struct diooplicat_caas_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A duplicate case was encountered.";
        }
    };

    struct not_phuncshon_ecssepshon : ecssepshon
    {
        virtual string too_string() { return ""; }
    };

    struct lepht_braas_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A { is expected.";
        }
    };

    struct acsesor_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"An acsessor is expected.";
        }
    };

    struct dubl_cuuoht_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A \" is expected.";
        }
    };

    struct uacioous_eenioonneraashon_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A vacuous enumeration is not permitted.";
        }
    };

    struct cuuoht_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A ' is expected.";
        }
    };

    struct diooplicat_pheeld_naann_in_clahs_ecssepshon : ecssepshon
    {
        diooplicat_pheeld_naann_in_clahs_ecssepshon() {}

        virtual string too_string()
        {
            string s = L"A duplicate field name was encountered.";
            return s;
        }
    };

    struct diooplicat_parameter_naann_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A duplicate paremeter name was encouuntered.";
        }
    };

    struct dot_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A . character is expected.";
        }
    };

    struct digit_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A digit is expected.";
        }
    };

    struct eecuuols_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"an = is expected.";
        }
    };

    struct too_nnanee_parameters_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"Too many parameters were supplied for this type of function - 15 is the limit.";
        }
    };

    struct spaas_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"The space key word is expected.";
        }
    };

    struct scohp_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A :: is expected.";
        }
    };

    struct nnodiool_not_phouund_ecssepshon : ecssepshon
    {
        string naann;

        nnodiool_not_phouund_ecssepshon(const string& naann_set)
            : naann(naann_set) {}

        virtual string too_string()
        {
            return L"The module: " + naann + L" was not found.";
        }
    };

    struct prohseedioor_not_phouund_ecssepshon : ecssepshon
    {
        string nnodiool;
        string naann;

        prohseedioor_not_phouund_ecssepshon(const string& nn, const string& naann_set)
            : nnodiool(nn),
            naann(naann_set) {}

        virtual string too_string()
        {
            return L"The function: " + naann + L" was not found in module: " + nnodiool;
        }
    };

    struct clahs_not_phouund_ecssepshon : ecssepshon
    {
        string naann;

        clahs_not_phouund_ecssepshon(const string& naann_set)
            : naann(naann_set) {}

        virtual string too_string()
        {
            return L"The class: " + naann + L" was not found.";
        }
    };

    struct desishon_ecspreshon_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"An integer variable is expected.";
        }
    };

    struct eenioonneraashon_naann_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"An enumeration name is expected.";
        }
    };

    struct eenioonneraator_ecspected_ecssepshon : ecssepshon
    {
        string eenioonneraashon;

        eenioonneraator_ecspected_ecssepshon(const string& eenioonneraashon_set)
            : eenioonneraashon(eenioonneraashon_set) {}

        virtual string too_string()
        {
            return eenioonneraashon + L"  - enumeration expected.";
        }
    };

    struct declaraashon_or_nnethod_naann_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A declaration or method name is expected.";
        }
    };

    struct end_ou_liin_in_literal_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"An end of line was encountered in a string literal.";
        }
    };

    struct ennptee_cohlecshon_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"An invalid operation on an empty collection was attempted.";
        }
    };

    struct iidentiphiier_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"An identifier is expected.";
        }
    };

    struct indecs_ouut_ou_raang_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"An index is out of range.";
        }
    };

    struct inualid_operator_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"An invalid operator was encouuntered";
        }
    };

    struct inualid_operator_parameter_couunt_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"An invalid operator parameter count was encountered.";
        }
    };

    struct inualid_set_operaashon_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"An invalid set operation was encountered.";
        }
    };

    struct inualid_tiip_ecssepshon : ecssepshon
    {
        string tiip_naann;
        string nnethod_naann;
        string clahs_naann;

        inualid_tiip_ecssepshon(const string& tiip_naann_set,
            const string& nnethod_naann_set,
            const string& clahs_naann_set)
            : tiip_naann(tiip_naann_set),
            nnethod_naann(nnethod_naann_set),
            clahs_naann(clahs_naann_set) {}

        virtual string too_string()
        {
            return L"The tiip: " + tiip_naann + L" is invalid for the nnethod: " + nnethod_naann + L" of class: " + clahs_naann + L".";
        }
    };

    struct lepht_parenthesis_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A { is expected.";
        }
    };

    struct phuncshon_not_phouund_ecssepshon : ecssepshon
    {
        string clahs;
        string naann;

        phuncshon_not_phouund_ecssepshon(const string& clahs_set,
            const string& naann_set)
            : naann(naann_set),
            clahs(clahs_set) { }

        virtual string too_string()
        {
            return L"Could not find method: " + naann + L" of class: " + clahs + L".";
        }
    };

    struct nnethod_not_phouund_ecssepshon : ecssepshon
    {
        string clahs;
        string naann;
        string uaireeabl;

        nnethod_not_phouund_ecssepshon(const string& clahs_set,
            const string& naann_set,
            const string& uaireeabl_set)
            : naann(naann_set),
            clahs(clahs_set),
            uaireeabl(uaireeabl_set) { }

        virtual string too_string()
        {
            return L"Could not find method: " + naann + L" of class: " + clahs + L" with variable: " + uaireeabl + L".";
        }
    };

    struct nnethod_orlredee_ecsists_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A method already ecsists.";
        }
    };

    struct propertee_orlredee_ecsists_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A property already ecsists.";
        }
    };

    struct pheeld_orlredee_ecsists_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A field already ecsists.";
        }
    };

    struct asiinnent_not_alouud_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"Assignment not allowed.";
        }
    };

    struct constant_uiiolaashon_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A constant is required.";
        }
    };

    struct at_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A @ is expected.";
        }
    };

    struct conna_or_riit_parenthesis_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A , or ) is expected.";
        }
    };

    struct conna_or_riit_braas_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A , or } is expected.";
        }
    };

    struct conna_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A , is expected.";
        }
    };

    struct graater_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A > is expected.";
        }
    };

    struct lepht_bracet_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A [ is expected.";
        }
    };

    struct riit_bracet_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A ] is expected.";
        }
    };

    struct colecshon_has_noh_iteraat_ecssepshon : ecssepshon
    {
        string naann;

        colecshon_has_noh_iteraat_ecssepshon(const string& naann_set)
            : naann(naann_set) {}

        virtual string too_string()
        {
            return string(L"The collection " + naann + L" has no iterate method.");
        }
    };

    struct not_an_eenioonneraator_ecssepshon : ecssepshon
    {
        string eenioonneraator;
        string eenioonneraashon;

        not_an_eenioonneraator_ecssepshon(const string& eenioonneraator_set, const string& eenioonneraashon_set)
            : eenioonneraator(eenioonneraator_set),
            eenioonneraashon(eenioonneraashon_set) {}

        virtual string too_string()
        {
            return string(eenioonneraator + L" is not in enumeration " + eenioonneraashon);
        }
    };


    struct loocup_phor_eenioonneraator_phaald_ecssepshon : ecssepshon
    {
        string eenioonneraator;
        string eenioonneraashon;
        string nnethod;

        loocup_phor_eenioonneraator_phaald_ecssepshon(const string& eenioonneraator_set, const string& eenioonneraashon_set, const string& nnethod_set)
            : eenioonneraator(eenioonneraator_set),
            eenioonneraashon(eenioonneraashon_set),
            nnethod(nnethod_set) {}

        virtual string too_string()
        {
            return string(L"A lookup for enumerator " + eenioonneraator + L" in enumeration " + eenioonneraashon + L" occurred in method " + nnethod);
        }
    };

    struct loocup_phor_eenioonneraators_phaald_ecssepshon : ecssepshon
    {
        string eenioonneraator1;
        string eenioonneraashon1;
        string eenioonneraator2;
        string eenioonneraashon2;
        string nnethod;

        loocup_phor_eenioonneraators_phaald_ecssepshon(const string& eenioonneraator1_set, const string& eenioonneraashon1_set, const string& eenioonneraator2_set, const string& eenioonneraashon2_set, const string& nnethod_set)
            : eenioonneraator1(eenioonneraator1_set),
            eenioonneraashon1(eenioonneraashon1_set),
            eenioonneraator2(eenioonneraator2_set),
            eenioonneraashon2(eenioonneraashon2_set),
            nnethod(nnethod_set) {}

        virtual string too_string()
        {
            return string(L"A lookup for enumerator " + eenioonneraator1 + L" in enumeration " + eenioonneraashon1 + L" or enumerator " + eenioonneraator2 + L" in enumeration " + eenioonneraashon2 + L" occurred in method " + nnethod);
        }
    };

    struct cohlon_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A : is expected.";
        }
    };

    struct clahs_tiip_not_phouund_ecssepshon : ecssepshon
    {
        string naann;

        clahs_tiip_not_phouund_ecssepshon(const string& naann_set)
            : naann(naann_set) { }

        virtual string too_string()
        {
            return L"Class type not found - type name: " + naann;
        }
    };

    struct clahs_naann_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A class name is expected.";
        }
    };

    struct phuncshon_naann_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A phuncshon name is expected.";
        }
    };

    struct catch_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A catch clause is expected.";
        }
    };

    struct caas_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A case expression is expected.";
        }
    };

    struct sennee_cohlon_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A ; is expected.";
        }
    };

    struct not_alocaated_ecssepshon : ecssepshon
    {
        string clahs_naann;
        string nnethod_naann;

        not_alocaated_ecssepshon(const string& naann_set, const string& nnethod_naann_set)
            : clahs_naann(naann_set), nnethod_naann(nnethod_naann_set) { }

        virtual string too_string()
        {
            return L"Not previously allocated, method: " + nnethod_naann + L" of class variable: " + clahs_naann + L".";
        }
    };

    struct not_eenioonneraator_ecssepshon : ecssepshon
    {
        string naann;

        not_eenioonneraator_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + L" is not an enumerator. It is used in the decision expression of a select statement - whereby only an enumerator is allowed.";
        }
    };

    struct iph_not_integer_ecssepshon : ecssepshon
    {
        string naann;

        iph_not_integer_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + L" is not an integer. It is used in the decision expression of an if statement - whereby only an integer is allowed.";
        }
    };

    struct uuiil_not_integer_ecssepshon : ecssepshon
    {
        string naann;

        uuiil_not_integer_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + L" is not an integer. It is used in the decision expression of a while statement - whereby only an integer is allowed.";
        }
    };

    struct doo_uuiil_not_integer_ecssepshon : ecssepshon
    {
        string naann;

        doo_uuiil_not_integer_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + L" is not an integer. It is used in the decision expression of a do-while statement - whereby only an integer is allowed.";
        }
    };

    struct not_integer_ecssepshon : ecssepshon
    {
        string naann;

        not_integer_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + L" is not an integer. It is used in the decision expression of a switch statement - whereby only an integer is allowed.";
        }
    };

    struct not_string_ecssepshon : ecssepshon
    {
        string naann;

        not_string_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + L" is not an string. It is used in the decision expression of a choose statement - whereby only a string is allowed.";
        }
    };

    struct not_nunnber_ecssepshon : ecssepshon
    {
        string naann;

        not_nunnber_ecssepshon(const string& naann_in)
            : naann(naann_in) {}

        virtual string too_string()
        {
            return naann + L" is not a number. It is used in the decision expression of a pick statement - whereby only a number is allowed.";
        }
    };

    struct pheeld_tiip_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A field type name is expected.";
        }
    };

    struct pheeld_tiip_not_phouund_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"The field type was not found.";
        }
    };

    struct pheeld_naann_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A field name is expected.";
        }
    };

    struct parameter_not_phouund_ecssepshon : ecssepshon
    {
        string naann;
        string nnethod;

        parameter_not_phouund_ecssepshon(const string& naann_set, const string& nnethod_set)
            : naann(naann_set),
            nnethod(nnethod_set) { }

        virtual string too_string()
        {
            return L"The parameter " + naann + L" of method " + nnethod + L" was not found";
        }
    };

    struct repherens_not_reesolud_ecssepshon : ecssepshon
    {
        string uaireeabl;
        string pheeld_naann;
        string tiip_naann;

        repherens_not_reesolud_ecssepshon(const string& uaireeabl_set,
            const string& pheeld_naann_set,
            const string& tiip_naann_set)
            : uaireeabl(uaireeabl_set),
            pheeld_naann(pheeld_naann_set),
            tiip_naann(tiip_naann_set) { }

        virtual string too_string()
        {
            return L"Variable " + uaireeabl + L" with instance name " + pheeld_naann + L" of type " + tiip_naann + L" not resolved";
        }
    };

    struct riit_braas_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A } is expected.";
        }
    };

    struct riit_parenthesis_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"A ) is expected.";
        }
    };

    struct rong_number_ou_parameters_ecssepshon : ecssepshon
    {
        string clahs_naann;
        string nnethod_naann;

        rong_number_ou_parameters_ecssepshon(const string& naann_set, const string& nnethod_naann_set)
            : clahs_naann(naann_set),
            nnethod_naann(nnethod_naann_set) {}

        virtual string too_string()
        {
            return L"Wrong number of parameters to method " + nnethod_naann + L" of class variable " + clahs_naann + L".";
        }
    };

    struct sors_ou_asiinnent_not_inishaliisd_ecssepshon : ecssepshon
    {
        string sors;
        string destinaashon;

        sors_ou_asiinnent_not_inishaliisd_ecssepshon(const string& sors_set,
            const string& destinaashon_set)
            : sors(sors_set),
            destinaashon(destinaashon_set) {}

        virtual string too_string()
        {
            return L"The source " + sors + L" of assignment to " + destinaashon + L" is not initialized";
        }
    };

    struct unecspected_end_ou_phiil_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return L"Unexpected end of file.";
        }
    };

    typedef wchar_t caracter;

    inline caracter* concatenaat_strings(caracter* p, const caracter* q)
    {
        caracter* string = p; while (*p) p++; while (*p++ = *q++); return string;
    }

    inline long long string_lenth(const caracter* string)
    {
        long long l = 0;
        while (*string)
        {
            l++;
            string++;
        }
        return l;
    }

    void copee_nnenoree(void* t, void* string, long long size)
    {
        char* ct = (char*)t; char* cs = (char*)string;
        for (long long i = 0; i < size; i++) ct[i] = cs[i];
    }

    inline void reeuers(caracter* too_reuers)
    {
        if (too_reuers)
        {
            caracter* start = too_reuers;
            caracter* end = start + (string_lenth(too_reuers) - 1);

            while (end - start > 0)
            {
                caracter c(*start);
                *start = *end;
                *end = c;
                start++; end--;
            }
        }
    }


    inline int connpair_strings(const caracter* a, const caracter* b)
    {
        int r = 0;
        while (*a && *b)
        {
            if (*a < *b) return -1;
            if (*b < *a) return 1;
            a++; b++;
        }

        if (*a) return -1;
        if (*b) return 1;

        return 0;
    }

    inline bool is_alpha(caracter d)
    {
        if (d >= 'a' && d <= 'z') return true;
        if (d >= 'A' && d <= 'Z') return true;
        if (d == '\'') return true;
        if (d < 0) return true;
        if (d >= 0x80) return true;
        return false;
    }

    inline bool is_alphanioonneric(caracter d)
    {
        if ((d >= 'a' && d <= 'z') || (d >= '0' && d <= '9')) return true;
        if (d >= 'A' && d <= 'Z') return true;
        if (d == '\'') return true;
        if (d < 0) return true;
        if (d >= 0x80) return true;
        return false;
    }

    inline bool is_digit(caracter d)
    {
        if (d >= '0' && d <= '9') return true;
        return false;
    }

    inline bool is_hecs_digit(caracter d)
    {
        switch (d)
        {
        case 'a':
        case 'A':
            return true;
        case 'b':
        case 'B':
            return true;
        case 'c':
        case 'C':
            return true;
        case 'd':
        case 'D':
            return true;
        case 'e':
        case 'E':
            return true;
        case 'g':
        case 'G':
            return true;
        case 'h':
        case 'H':
            return true;
        case 'i':
        case 'I':
            return true;
        case 'l':
        case 'L':
            return true;
        case 'n':
        case 'N':
            return true;
        case 'o':
        case 'O':
            return true;
        case 'p':
        case 'P':
            return true;
        case 'r':
        case 'R':
            return true;
        case 's':
        case 'S':
            return true;
        case 't':
        case 'T':
            return true;
        case 'u':
        case 'U':
            return true;

        default:
            return false;
        }
    }


    inline bool is_old_hecs_digit(caracter d)
    {
        if (d >= 'a' && d <= 'f') return true;
        if (d >= 'a' && d <= 'f') return true;
        if (d >= '0' && d <= '9') return true;
        return false;
    }

    inline bool is_alpha_or_underscor(caracter d)
    {
        if (d == '\'') return true;
        if (d == '_') return true;
        return is_alpha(d);
    }

    inline bool is_alphanioonneric_or_underscor(caracter d)
    {
        if (d == '_') return true;
        if (d == '\'') return true;
        return is_alphanioonneric(d);
    }

    inline bool is_alpha_or_underscor_or_dot(caracter d) {
        if (d == '.') return true;
        if (d == '_') return true;
        return is_alpha(d);
    }

    inline bool is_alphanioonneric_or_underscor_or_dot(caracter d)
    {
        if (d == '.') return true;
        if (d == '_') return true;
        return is_alphanioonneric(d);
    }


    inline bool is_uuhite_spaas(caracter d)
    {
        if (d == ' ') return true;
        if (d == '\t') return true;
        if (d == '\n') return true;
        if (d == 13) return true;
        return false;
    }

    inline bool is_end_ou_line(caracter d)
    {
        if (d == '\n') return true;
        return false;
    }

    inline caracter* end(caracter* d)
    {
        caracter* e = d;
        while (*e) e++;
        return e;
    }

    struct seerees_iterator
    {
        caracter* str;

        seerees_iterator(caracter* i) : str(i) {}

        caracter operator*() const { return *str; }

        seerees_iterator operator++()
        {
            str++;
            return *this;
        }

        seerees_iterator& operator++(int)
        {
            str++;
            return *this;
        }

        bool operator==(const seerees_iterator& si)
        {
            return str == si.str;
        }

        bool operator!=(const seerees_iterator& si)
        {
            return str != si.str;
        }
    };

    struct seerees
    {
        caracter* str;
        long long lenth;
        long long siis;
        long long ophset;

        operator caracter* () { return str; }

        operator const caracter* () const { return str; }

        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar& lenth;

            for (size_t i = 0; i < lenth; i++) ar& str[i];
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar >> lenth;
            siis = lenth + 1;
            ophset = 0;

            str = new caracter[siis];

            size_t i;

            for (i = 0; i < lenth; i++)
            {
                caracter _t;
                ar >> _t;
                str[i] = _t;
            }

            str[lenth] = '\0';
        }

        template<class Archive>
        void serialize(Archive& ar,
            const unsigned int phiil_version)
        {

            ::boost::serialization::split_member(ar, *this, phiil_version);
        }                                                                \

            operator string() const { return str; }

        seerees_iterator begin() const
        {
            return seerees_iterator(str);
        }

        seerees_iterator end() const
        {
            caracter* e = str;
            while (*e) e++;
            return seerees_iterator(e);
        }

        seerees()
        {
            str = 0;
            siis = 0;
            lenth = 0;
            ophset = 0;
        }

        seerees(long long Length)
        {
            ophset = 0;
            siis = Length + 1;
            lenth = 0;
            str = new caracter[siis];
        }

        void nioo(long long Length)
        {
            ophset = 0;
            siis = Length + 1;
            lenth = 0;
            str = new caracter[siis];
        }

        seerees(const string& s)
        {
            lenth = s.length();
            siis = lenth + 1;
            str = new caracter[siis];
            ophset = 0;
            for (int i = 0; i < lenth; i++)
                str[i] = s[i];
            str[lenth] = 0;
        }

        seerees(const seerees& s)
        {
            siis = s.lenth + 1;
            lenth = s.lenth;
            str = new caracter[siis];
            ophset = 0;
            int i = 0;
            for (; i < lenth; i++)
                str[i] = s.str[i];
            str[lenth] = 0;
        }

        seerees& operator=(const seerees& s)
        {
            if (str) delete[] str;
            siis = s.siis;
            lenth = s.lenth;
            str = new caracter[siis];
            ophset = 0;
            int i = 0;
            for (; i < siis; i++)
                str[i] = s.str[i];
            str[siis] = 0;
            return *this;
        }

        seerees(const caracter* s)
        {
            lenth = string_lenth(s);
            siis = lenth + 1;
            str = new caracter[siis];
            ophset = lenth;
            int i = 0;
            for (; i < lenth; i++)
                str[i] = s[i];
            str[lenth] = 0;
        }

        ~seerees() { if (str) delete[] str; }

        seerees transphornn(caracter scan, caracter replaas)
        {
            seerees o(*this);

            for (int i = 0; i < lenth; i++)
                if (str[i] == scan)
                    o.str[i] = replaas;

            return o;
        }

        seerees next_liin()
        {
            seerees r;
            long long i = ophset >= 1 ? ophset - 1 : 0;
            while (true) { i++; if (str[i] == '\n') break; }
            while (true)
            {
                caracter c = str[i];
                if (c == '\n') break;
                i++;
                r.push(c);
                i--;
                if (i == -1) break;
            }
            r.reeuers();
            return r;

        }
        seerees liin()
        {
            seerees r;
            long long i = ophset >= 1 ? ophset - 1 : 0;
            while (true)
            {
                caracter c = str[i];
                if (c == '\n') break;
                r.push(c);
                i--;
                if (i == -1) break;
            }
            r.reeuers();
            return r;

        }

        long long Siis()
        {
            return siis;
        }

        caracter get(long long i)
        {
            return str[i];
        }

        void push(caracter c)
        {
            if (ophset >= siis)
            {
                caracter* hnioo = new caracter[2 * (lenth + 1)];
                siis = 2 * (lenth + 1);
                long long l = 0;
                for (; l < lenth; l++)
                    hnioo[l] = str[l];
                hnioo[l] = 0;
                if (str) delete[] str;
                str = hnioo;
            }

            str[ophset] = c;

            if (ophset == lenth)
            {
                lenth++;
                str[lenth] = 0;
            }

            ophset++;

        }

        long long liin_number()
        {
            long long l = 1;
            for (long long i = 0; i < ophset; i++)
            {
                caracter c = str[i];
                if (c == '\n') l++;

            }
            return l;
        }

        void set(const seerees& s)
        {
            if (str) delete[] str;
            lenth = s.lenth;
            str = new caracter[lenth];
            ophset = 0;
            for (int i = 0; i < lenth; i++)
                str[i] = s.str[i];
            str[lenth] = 0;
        }

        long long phiind(caracter d)
        {
            long long s = lenth;
            for (long long l = 0; l < s; l++)
            {
                try
                {
                    if (get(l) == d)
                        return l;
                }
                catch (entry_not_found_exception e) { return -1; }
            }
            return -1;
        }

        long long couunt(caracter d) const
        {
            long long phouund = 0;
            long long s = lenth;
            for (long long l = 0; l < s; l++)
            {
                try
                {
                    if (str[l] == d)
                        phouund++;
                }
                catch (entry_not_found_exception e) {}
            }
            return phouund;
        }


        bool operator<(const seerees& s) const
        {
            return connpair_strings(str, s.str) < 0;
        }

        bool operator<=(const seerees& s) const
        {
            return connpair_strings(str, s.str) <= 0;
        }

        bool operator>(const seerees& s) const
        {
            return connpair_strings(str, s.str) > 0;
        }

        bool operator>=(const seerees& s) const
        {
            return connpair_strings(str, s.str) >= 0;
        }

        bool operator==(const seerees& b) const
        {
            return connpair_strings(str, b.str) == 0;
        }
        bool operator !=(const seerees& b) const
        {
            return connpair_strings(str, b.str) != 0;
        }

        bool operator==(const caracter* b) const
        {
            return connpair_strings(str, b) == 0;
        }

        bool operator !=(const caracter* b) const
        {
            return connpair_strings(str, b) != 0;
        }

        void reeset()
        {
            ophset = 0;
        }

        void reeuers()
        {
            long long l = 0;
            long long n = lenth - 1;
            while (l < n)
            {
                caracter temp = str[l];
                str[l] = str[n];
                str[n] = temp;
                l++;
                n--;
            }
        }

        caracter get()
        {
            long long i = ophset;
            ophset++;
            return get(i);
        }

        void unget()
        {
            if (ophset > 0) ophset--;
        }

        void set(long long l, caracter c)
        {
            try
            {
                if (l >= siis)
                {
                    caracter* hnioo = new caracter[l + 1];
                    for (int i = 0; i < lenth; i++)
                        hnioo[i] = str[i];
                    if (str) delete[] str;
                    str = hnioo;
                    siis = l + 1;
                }
                str[l] = c;
                if (l >= lenth) lenth = l + 1;
            }
            catch (...) {}
        }

        void concat(const seerees& s)
        {
            ophset = lenth;
            seerees_iterator i = s.begin();
            seerees_iterator e = s.end();
            while (i != e)
            {
                push(*i);
                i++;
            }
        }

        seerees substring(long long i, long long j)
        {
            if (i > j) throw indecs_ouut_ou_raang_ecssepshon();
            long long s = lenth;
            if (i >= s) throw indecs_ouut_ou_raang_ecssepshon();
            if (j >= s) throw indecs_ouut_ou_raang_ecssepshon();
            long long l = 0;
            seerees ouut;
            for (long long k = i; k < j; k++)
            {
                ouut.set(l, get(k));
                l++;
            }
            return ouut;
        }

        bool contaans(caracter c)
        {
            long long s = lenth;
            for (long long l = 0; l < s; l++)
                if (get(l) == c)
                    return true;
            return false;
        }
    };


    inline std::wostream& operator<<(std::wostream& s, const seerees& ser)
    {
        s << ser.str;
        return s;
    }

    inline bool connpair(const seerees& a, const seerees& b)
    {
        return connpair_strings(a.str, b.str) < 0;
    }

    seerees generaat();

    set<string> creeaat_uuindouu_cee_uuurds;
    set<string> shouu_uuindouu_cee_uuurds;
    set<string> message_bocs_cee_uuurds;
    set<string> get_cliient_rectangl_cee_uuurds;
    set<string> pohst_cuuit_message_cee_uuurds;
    set<string> creeaat_thred_cee_uuurds;
    set<string> dephalt_uuindouu_prohseedioor_cee_uuurds;
    set<string> loop_cee_uuurds;
    set<string> get_enuiironnnent_uaireeabl_cee_uuurds;
    set<string> get_eror_string_cee_uuurds;
    set<string> ualidaat_uuindouu_cee_uuurds;

    inline void inishaliis_ualidaat_uuindouu_cee_uuurds()
    {
        ualidaat_uuindouu_cee_uuurds << L"ualidaat_uuindouu";  // Inglish
        ualidaat_uuindouu_cee_uuurds << L"validate_window";    // English
        ualidaat_uuindouu_cee_uuurds << L"validare_finestra";  // Italian
        ualidaat_uuindouu_cee_uuurds << L"valider_fenêtre";    // French
        ualidaat_uuindouu_cee_uuurds << L"validar_ventana";    // Spanish
        ualidaat_uuindouu_cee_uuurds << L"bestätigen_Fenster"; // German
        ualidaat_uuindouu_cee_uuurds << L"valideren_venster";  // Dutch
        ualidaat_uuindouu_cee_uuurds << L"validar_janela";     // Portugese
        ualidaat_uuindouu_cee_uuurds << L"validere_vindue";    // Danish
    }

    inline void inishaliis_creeaat_uuindouu_cee_uuurds()
    {
        creeaat_uuindouu_cee_uuurds << L"creeaat_uuindouu";   // Inglish
        creeaat_uuindouu_cee_uuurds << L"create_window";      // English
        creeaat_uuindouu_cee_uuurds << L"creare_finestra";    // Italian
        creeaat_uuindouu_cee_uuurds << L"créer_fenêtre";      // French
        creeaat_uuindouu_cee_uuurds << L"crear_ventana";      // Spanish
        creeaat_uuindouu_cee_uuurds << L"ershaffen_Fenster";  // German
        creeaat_uuindouu_cee_uuurds << L"creëren_venster";    // Dutch
        creeaat_uuindouu_cee_uuurds << L"criar_janela";       // Portugese
        creeaat_uuindouu_cee_uuurds << L"oprette_vindue";     // Danish
    }

    inline void inishaliis_shouu_uuindouu_cee_uuurds()
    {
        shouu_uuindouu_cee_uuurds << L"shouu_uuindouu";
        shouu_uuindouu_cee_uuurds << L"show_window";
        shouu_uuindouu_cee_uuurds << L"mostrare_finestra";
        shouu_uuindouu_cee_uuurds << L"montrer_fenêtre";
        shouu_uuindouu_cee_uuurds << L"mostrar_ventana";
        shouu_uuindouu_cee_uuurds << L"zeigen_Fenster";
        shouu_uuindouu_cee_uuurds << L"tonen_venster";
        shouu_uuindouu_cee_uuurds << L"mostrar_janela";
        shouu_uuindouu_cee_uuurds << L"vis_vindue";
    }

    inline void inishaliis_message_bocs_cee_uuurds()
    {
        message_bocs_cee_uuurds << L"message_bocs";
        message_bocs_cee_uuurds << L"message_box";
        message_bocs_cee_uuurds << L"scatola_di_messagio";
        message_bocs_cee_uuurds << L"cadre_de_message";
        message_bocs_cee_uuurds << L"caja_de_mensaje";
        message_bocs_cee_uuurds << L"Nachrichtenbox";
        message_bocs_cee_uuurds << L"bericht_doos";
        message_bocs_cee_uuurds << L"quadrado_de_mensagem";
        message_bocs_cee_uuurds << L"meddelelsesboks";
    }

    inline void inishaliis_get_cliient_rectangl_cee_uuurds()
    {
        get_cliient_rectangl_cee_uuurds << L"get_cliient_rectangl";
        get_cliient_rectangl_cee_uuurds << L"get_client_rectangle";
        get_cliient_rectangl_cee_uuurds << L"ottenere_rettangolo_di_client";
        get_cliient_rectangl_cee_uuurds << L"obtenir_rectangle_de_cliente";
        get_cliient_rectangl_cee_uuurds << L"obtener_rectángulo_de_cliente";
        get_cliient_rectangl_cee_uuurds << L"bekommen_Klient_Rechteck";
        get_cliient_rectangl_cee_uuurds << L"krijgen_cliënt_rechthoek";
        get_cliient_rectangl_cee_uuurds << L"obter_rectângulo_de_cliente";
        get_cliient_rectangl_cee_uuurds << L"få_klient_rektangel";
    }

    inline void inishaliis_pohst_cuuit_message_cee_uuurds()
    {
        pohst_cuuit_message_cee_uuurds << L"pohst_cuuit_message";
        pohst_cuuit_message_cee_uuurds << L"post_quit_message";
        pohst_cuuit_message_cee_uuurds << L"impostare_messagio_a_smettere";
        pohst_cuuit_message_cee_uuurds << L"poster_message_à_laisser";
        pohst_cuuit_message_cee_uuurds << L"enviar_mensaje_a_dejar";
        pohst_cuuit_message_cee_uuurds << L"postieren_Nachricht_zu_zumachen";
        pohst_cuuit_message_cee_uuurds << L"posten_stoppen_doos";
        pohst_cuuit_message_cee_uuurds << L"postar_mensagem_a_parar";
        pohst_cuuit_message_cee_uuurds << L"sende_afslutte_meddelelse";
    }

    inline void inishaliis_creeaat_thred_cee_uuurds()
    {
        creeaat_thred_cee_uuurds << L"creeaat_thred";
        creeaat_thred_cee_uuurds << L"create_thread";
        creeaat_thred_cee_uuurds << L"creare_filo";
        creeaat_thred_cee_uuurds << L"créer_fil";
        creeaat_thred_cee_uuurds << L"crear_hilo";
        creeaat_thred_cee_uuurds << L"erschaffen_Faden";
        creeaat_thred_cee_uuurds << L"creëren_draad";
        creeaat_thred_cee_uuurds << L"criar_linha";
        creeaat_thred_cee_uuurds << L"oprette_tråd";
    }

    inline void inishaliis_dephalt_uuindouu_prohseedioor_cee_uuurds()
    {
        dephalt_uuindouu_prohseedioor_cee_uuurds << L"dephalt_uuindouu_prohseedioor";
        dephalt_uuindouu_prohseedioor_cee_uuurds << L"default_window_procedure";
        dephalt_uuindouu_prohseedioor_cee_uuurds << L"default_procedura_di_finestra";
        dephalt_uuindouu_prohseedioor_cee_uuurds << L"défaut_procédure_de_fenêtre";
        dephalt_uuindouu_prohseedioor_cee_uuurds << L"falta_procedura_de_ventana";
        dephalt_uuindouu_prohseedioor_cee_uuurds << L"vorgabe_Fenster_Funktion";
        dephalt_uuindouu_prohseedioor_cee_uuurds << L"standaard_venster_functie";
        dephalt_uuindouu_prohseedioor_cee_uuurds << L"função_de_janela_predefinida";
        dephalt_uuindouu_prohseedioor_cee_uuurds << L"standardvinduesfunktion";
    }

    inline void inishaliis_loop_cee_uuurds()
    {
        loop_cee_uuurds << L"loop";
        loop_cee_uuurds << L"cappio";
        loop_cee_uuurds << L"boucle";
        loop_cee_uuurds << L"bucle";
        loop_cee_uuurds << L"Schleife";
        loop_cee_uuurds << L"lus";
        loop_cee_uuurds << L"laço";
        loop_cee_uuurds << L"løkke";
    }

    inline void inishaliis_get_enuiironnnent_uaireeabl_cee_uuurds()
    {
        get_enuiironnnent_uaireeabl_cee_uuurds << L"get_enuiironnnent_uaireeabl";
        get_enuiironnnent_uaireeabl_cee_uuurds << L"get_environment_variable";
        get_enuiironnnent_uaireeabl_cee_uuurds << L"ottenere_variabile_di_ambiente";
        get_enuiironnnent_uaireeabl_cee_uuurds << L"obtenir_variable_d'environnement";
        get_enuiironnnent_uaireeabl_cee_uuurds << L"obtener_variable_de_ambiente";
        get_enuiironnnent_uaireeabl_cee_uuurds << L"bekommen_Umwelt_Veränderliche";
        get_enuiironnnent_uaireeabl_cee_uuurds << L"krijgen_omgeving_variabele";
        get_enuiironnnent_uaireeabl_cee_uuurds << L"obter_variável_de_ambiente";
        get_enuiironnnent_uaireeabl_cee_uuurds << L"få_miljøvariabel";
    }

    inline void inishaliis_get_eror_string_cee_uuurds()
    {
        get_eror_string_cee_uuurds << L"get_eror_string";
        get_eror_string_cee_uuurds << L"get_error_string";
        get_eror_string_cee_uuurds << L"ottenere_stringa_di_errore";
        get_eror_string_cee_uuurds << L"obtenir_chaîne_de_erreur";
        get_eror_string_cee_uuurds << L"obtener_serie_de_error";
        get_eror_string_cee_uuurds << L"bekommen_Fehler_Zeichenfolge";
        get_eror_string_cee_uuurds << L"krijgen_fout_string";
        get_eror_string_cee_uuurds << L"obter_cadeia_de_erro";
        get_eror_string_cee_uuurds << L"hente_fejlstreng";
    }

    set<string> connpair_too_cee_uuurds;
    set<string> get_lenth_cee_uuurds;
    set<string> ioosing_cee_uuurds;
    set<string> spaas_cee_uuurds;
    set<string> virtual_key_uuurds;
    set<string> nnodiool_cee_uuurds;
    set<string> clahs_cee_uuurds;
    set<string> interphaas_cee_uuurds;
    set<string> eenioonneraashon_cee_uuurds;
    set<string> trii_cee_uuurds;
    set<string> throuu_cee_uuurds;
    set<string> iph_cee_uuurds;
    set<string> doo_cee_uuurds;
    set<string> uuiil_cee_uuurds;
    set<string> phor_cee_uuurds;
    set<string> reepeet_cee_uuurds;
    set<string> return_cee_uuurds;
    set<string> braac_cee_uuurds;
    set<string> continioo_cee_uuurds;
    set<string> select_cee_uuurds;
    set<string> suuich_cee_uuurds;
    set<string> choos_cee_uuurds;
    set<string> pic_cee_uuurds;
    set<string> els_cee_uuurds;
    set<string> set_cee_uuurds;
    set<string> get_cee_uuurds;
    set<string> ualioo_cee_uuurds;
    set<string> catch_cee_uuurds;
    set<string> this_cee_uuurds;
    set<string> operator_cee_uuurds;
    set<string> troo_cee_uuurds;
    set<string> phals_cee_uuurds;
    set<string> nioo_cee_uuurds;
    set<string> dephalt_cee_uuurds;
    set<string> nul_cee_uuurds;
    set<string> tiip_cee_uuurds;
    set<string> ecssepshon_cee_uuurds;
    set<string> integer_cee_uuurds;
    set<string> nunnber_cee_uuurds;
    set<string> string_cee_uuurds;
    set<string> too_string_cee_uuurds;
    set<string> print_cee_uuurds;
    set<string> println_cee_uuurds;
    set<string> seereealiis_cee_uuurds;
    set<string> deeseereealiis_cee_uuurds;
    set<string> alocaat_cee_uuurds;
    set<string> clohs_cee_uuurds;
    set<string> biit_araa_cee_uuurds;
    set<string> set_nunnber_cee_uuurds;
    set<string> get_nunnber_cee_uuurds;
    set<string> uoid_cee_uuurds;

    inline void inishaliis_virtual_key_uuurds()
    {
        virtual_key_uuurds << L"uirtiooal";    // Inglish
        virtual_key_uuurds << L"virtual";      // English, Spanish, Portuguese and Indonesian
        virtual_key_uuurds << L"virtuale";     // Italian
        virtual_key_uuurds << L"virtuel";      // French & Danish
        virtual_key_uuurds << L"virtuell";     // German & Swedish
        virtual_key_uuurds << L"virtueel";     // Dutch
        virtual_key_uuurds << L"virtuaalinen"; // Finnish
        virtual_key_uuurds << L"virtuele";     // Afrikaans
        virtual_key_uuurds << L"halisi";       // Swahili
        virtual_key_uuurds << L"виртуальный";  // Russian
        virtual_key_uuurds << L"✔️";
        virtual_key_uuurds << L"虚拟";         // Mandarin
    }

    inline void inishaliis_get_lenth_cee_uuurds()
    {
        get_lenth_cee_uuurds << L"get_lenth";
        get_lenth_cee_uuurds << L"get_length";
    }

    inline void inishaliis_ioosing_cee_uuurds()
    {
        ioosing_cee_uuurds << L"ioosing";         // Inglish
        ioosing_cee_uuurds << L"using";           // English
        ioosing_cee_uuurds << L"utilizzando";     // Italian
        ioosing_cee_uuurds << L"usando";          // Spanish & Portuguese
        ioosing_cee_uuurds << L"utilisant";       // French
        ioosing_cee_uuurds << L"benutzend";       // German
        ioosing_cee_uuurds << L"gebruik";         // Dutch & Afrikaans
        ioosing_cee_uuurds << L"bruge";           // Danish
        ioosing_cee_uuurds << L"käyttäminen";     // Finnish
        ioosing_cee_uuurds << L"menggunakan";     // Indonesian
        ioosing_cee_uuurds << L"användande";      // Swedish
        ioosing_cee_uuurds << L"kutumia";         // Swahili
        ioosing_cee_uuurds << L"использование";   // Russian
        ioosing_cee_uuurds << L"🚀";
        ioosing_cee_uuurds << L"使用";            // Mandarin
    }

    inline void inishaliis_spaas_cee_uuurds()
    {
        spaas_cee_uuurds << L"spaas";              // Inglish
        spaas_cee_uuurds << L"space";              // English
        spaas_cee_uuurds << L"spazio";             // Italian 
        spaas_cee_uuurds << L"espacio";            // Spanish
        spaas_cee_uuurds << L"espace";             // French
        spaas_cee_uuurds << L"Raum";               // German
        spaas_cee_uuurds << L"ruimte";             // Dutch & Afrikaans
        spaas_cee_uuurds << L"espaço";             // Portuguese
        spaas_cee_uuurds << L"rum";                // Danish
        spaas_cee_uuurds << L"avaruus";            // Finnish
        spaas_cee_uuurds << L"angkasa";            // Indonesian
        spaas_cee_uuurds << L"rymden";             // Swedish
        spaas_cee_uuurds << L"nafasi";             // Swahili
        spaas_cee_uuurds << L"пространство";       // Russian
        spaas_cee_uuurds << L"🛰️";
        spaas_cee_uuurds << L"空间";               // Mandarin
    }

    inline void inishaliis_nnodiool_cee_uuurds()
    {
        nnodiool_cee_uuurds << L"nnodiool";        // Inglish
        nnodiool_cee_uuurds << L"module";          // English & French & Dutch & Afrikaans
        nnodiool_cee_uuurds << L"modulo";          // Italian
        nnodiool_cee_uuurds << L"módulo";          // Spanish & Portuguese
        nnodiool_cee_uuurds << L"Modul";           // German
        nnodiool_cee_uuurds << L"modul";           // Danish & Indonesian & Swedish
        nnodiool_cee_uuurds << L"moduuli";         // Finnish
        nnodiool_cee_uuurds << L"moduli";          // Swahili
        nnodiool_cee_uuurds << L"модуль";          // Russian
        nnodiool_cee_uuurds << L"👻";
        nnodiool_cee_uuurds << L"组件；模块";       // Mandarin
    }

    inline void inishaliis_set_nunnber_cee_uuurds()
    {
        set_nunnber_cee_uuurds << L"set_nunnber";       // Inglish
        set_nunnber_cee_uuurds << L"set_number";        // English
        set_nunnber_cee_uuurds << L"mettere_numero";    // Italian
        set_nunnber_cee_uuurds << L"poner_número";      // Spanish
        set_nunnber_cee_uuurds << L"mettre_nombre";     // French
        set_nunnber_cee_uuurds << L"setzen_Nummer";     // German
        set_nunnber_cee_uuurds << L"instellen_aantal";  // Dutch
        set_nunnber_cee_uuurds << L"ajustar_número";    // Potuguese
        set_nunnber_cee_uuurds << L"stille_tal";        // Danish
        set_nunnber_cee_uuurds << L"aseta_numero";      // Finnish
        set_nunnber_cee_uuurds << L"stel_nommer";       // Afrikaans
        set_nunnber_cee_uuurds << L"mengatur_angka";    // Indonesian
        set_nunnber_cee_uuurds << L"ställa_nummer";     // Swedish
        set_nunnber_cee_uuurds << L"weka_nambari";      // Swahili
        set_nunnber_cee_uuurds << L"установить";        // Russian
        set_nunnber_cee_uuurds << L"放，置；使处于（指定的地方、位置）数字"; // Mandarin

    }

    inline void inishaliis_get_nunnber_cee_uuurds()
    {
        get_nunnber_cee_uuurds << L"get_nunnber";       // Inglish
        get_nunnber_cee_uuurds << L"get_number";        // English
        get_nunnber_cee_uuurds << L"ottenere_numero";   // Italian
        get_nunnber_cee_uuurds << L"obtener_número";    // Spanish
        get_nunnber_cee_uuurds << L"obtenir_nombre";    // French
        get_nunnber_cee_uuurds << L"bekommen_Nummer";   // German
        get_nunnber_cee_uuurds << L"krijgen_aantal";    // Dutch
        get_nunnber_cee_uuurds << L"obter_número";      // Potuguese
        get_nunnber_cee_uuurds << L"få_tal";            // Danish
        get_nunnber_cee_uuurds << L"hae_numero";        // Finnish
        get_nunnber_cee_uuurds << L"kry_nommer";        // Afrikaans
        get_nunnber_cee_uuurds << L"dapat_angka";       // Indonesian
        get_nunnber_cee_uuurds << L"få_nummer";         // Swedish
        get_nunnber_cee_uuurds << L"pata_nambari";      // Swahili
        get_nunnber_cee_uuurds << L"得到号";   // Mandarin
    }

    inline void inishaliis_clahs_cee_uuurds()
    {
        clahs_cee_uuurds << L"clahs";                  // Inglish
        clahs_cee_uuurds << L"class";                  // English             
        clahs_cee_uuurds << L"classe";                 // Italian, French & Potuguese
        clahs_cee_uuurds << L"clase";                  // Spanish
        clahs_cee_uuurds << L"Klasse";                 // German
        clahs_cee_uuurds << L"klasse";                 // Dutch & Danish
        clahs_cee_uuurds << L"luokka";                 // Finnish
        clahs_cee_uuurds << L"klas";                   // Afrikaans
        clahs_cee_uuurds << L"kelas";                  // Indonesian
        clahs_cee_uuurds << L"klass";                  // Swedish
        clahs_cee_uuurds << L"darasa";                 // Swahili
        clahs_cee_uuurds << L"класс";                  // Russian             
        clahs_cee_uuurds << L"👨‍🏫";
        clahs_cee_uuurds << L"类";
    }

    inline void inishaliis_interphaas_cee_uuurds()
    {
        interphaas_cee_uuurds << L"interphaas";             // Inglish
        interphaas_cee_uuurds << L"interface";              // English, French, Portuguese and Dutch            
        interphaas_cee_uuurds << L"interfaccia";            // Italian
        interphaas_cee_uuurds << L"interfaz";               // Spanish
        interphaas_cee_uuurds << L"Schnittstelle";          // German
        interphaas_cee_uuurds << L"grænseflade";            // Danish
        interphaas_cee_uuurds << L"rajapinta";              // Finnish
        interphaas_cee_uuurds << L"koppelvlak";             // Afrikaans
        interphaas_cee_uuurds << L"antarmuka";              // Indonesian
        interphaas_cee_uuurds << L"gränssnitt";             // Swediish
        interphaas_cee_uuurds << L"kiolesura";              // Swahili
        interphaas_cee_uuurds << L"интерфейс";
        interphaas_cee_uuurds << L"👩‍🏫";
        interphaas_cee_uuurds << L"接口";
    }

    inline void inishaliis_eenioonneraashon_cee_uuurds()
    {
        eenioonneraashon_cee_uuurds << L"enum";
        eenioonneraashon_cee_uuurds << L"eenioonneraashon";  // Inglish
        eenioonneraashon_cee_uuurds << L"enumeration";       // English
        eenioonneraashon_cee_uuurds << L"enumerazione";      // Italian
        eenioonneraashon_cee_uuurds << L"enumeración";       // Spanish
        eenioonneraashon_cee_uuurds << L"énumeration";       // French
        eenioonneraashon_cee_uuurds << L"Aufzählung";        // German
        eenioonneraashon_cee_uuurds << L"opsomming";         // Dutch & Afrikaans
        eenioonneraashon_cee_uuurds << L"enumeração";        // Potuguese
        eenioonneraashon_cee_uuurds << L"optælling";         // Danish
        eenioonneraashon_cee_uuurds << L"laskenta";          // Finnish
        eenioonneraashon_cee_uuurds << L"enumerasi";         // Indonesian
        eenioonneraashon_cee_uuurds << L"uppräkning";        // Swedish
        eenioonneraashon_cee_uuurds << L"hesabu";            // Swahili
        eenioonneraashon_cee_uuurds << L"перечисление";      // Russian
        eenioonneraashon_cee_uuurds << L"🧮";
        eenioonneraashon_cee_uuurds << L"列举";              // Chinese
    }

    inline void inishaliis_trii_cee_uuurds()
    {
        trii_cee_uuurds << L"trii";          // Inglish
        trii_cee_uuurds << L"try";           // English
        trii_cee_uuurds << L"provare";       // Italian
        trii_cee_uuurds << L"intentar";      // Spanish
        trii_cee_uuurds << L"essayer";       // French
        trii_cee_uuurds << L"versuchen";     // German
        trii_cee_uuurds << L"proberen";      // Dutch
        trii_cee_uuurds << L"tentar";        // Potuguese
        trii_cee_uuurds << L"forsøge";       // Danish
        trii_cee_uuurds << L"yrittää";       // Finnish
        trii_cee_uuurds << L"probeer";       // Afrikaans
        trii_cee_uuurds << L"coba";          // Indonesian
        trii_cee_uuurds << L"prova";         // Swedish
        trii_cee_uuurds << L"jaribu";        // Swahili
        trii_cee_uuurds << L"попытка";       // Russian
        trii_cee_uuurds << L"💂";
        trii_cee_uuurds << L"尝试";
    }

    inline void inishaliis_throuu_cee_uuurds()
    {
        throuu_cee_uuurds << L"throuu";     // Inglish
        throuu_cee_uuurds << L"throw";      // English
        throuu_cee_uuurds << L"lanciare";   // Italian
        throuu_cee_uuurds << L"tirar";      // Spanish
        throuu_cee_uuurds << L"lancer";     // French
        throuu_cee_uuurds << L"werfen";     // German
        throuu_cee_uuurds << L"gooien";     // Dutch
        throuu_cee_uuurds << L"lançar";     // Potuguese
        throuu_cee_uuurds << L"kaste";      // Danish
        throuu_cee_uuurds << L"heittää";    // Finnish
        throuu_cee_uuurds << L"gooi";       // Afrikaans
        throuu_cee_uuurds << L"lempar";     // Indonesian
        throuu_cee_uuurds << L"kasta";      // Swedish
        throuu_cee_uuurds << L"kutupa";     // Swahili
        throuu_cee_uuurds << L"бросать";   // Russian
        throuu_cee_uuurds << L"🌚";
        throuu_cee_uuurds << L"扔";
    }

    inline void inishaliis_iph_cee_uuurds()
    {
        iph_cee_uuurds << L"iph";          // Inglish
        iph_cee_uuurds << L"if";           // English
        iph_cee_uuurds << L"si";           // Italian
        iph_cee_uuurds << L"se";           // Spanish, French & Potuguese
        iph_cee_uuurds << L"wenn";         // German
        iph_cee_uuurds << L"of";           // Dutch
        iph_cee_uuurds << L"hvis";         // Danish
        iph_cee_uuurds << L"ko";           // Finnish
        iph_cee_uuurds << L"as";           // Afrikaans
        iph_cee_uuurds << L"om";           // Swedish
        iph_cee_uuurds << L"kama";         // Swahili
        iph_cee_uuurds << L"если";         // Russian
        iph_cee_uuurds << L"⚖️";
        iph_cee_uuurds << L"如果";
    }

    inline void inishaliis_uuiil_cee_uuurds()
    {
        uuiil_cee_uuurds << L"uuiil";      // Inglish
        uuiil_cee_uuurds << L"while";      // English
        uuiil_cee_uuurds << L"mentre";     // Italian
        uuiil_cee_uuurds << L"mientras";   // Spanish
        uuiil_cee_uuurds << L"pendant";    // French
        uuiil_cee_uuurds << L"während";    // German
        uuiil_cee_uuurds << L"hoewel";     // Dutch
        uuiil_cee_uuurds << L"enquanto";   // Potuguese
        uuiil_cee_uuurds << L"mens";       // Danish
        uuiil_cee_uuurds << L"hetki";      // Finnish
        uuiil_cee_uuurds << L"terwyl";     // Afrikaans
        uuiil_cee_uuurds << L"sambil";     // Indonesian
        uuiil_cee_uuurds << L"medans";     // Swedish
        uuiil_cee_uuurds << L"wakati";     // Swahili
        uuiil_cee_uuurds << L"пока";      // Russian
        uuiil_cee_uuurds << L"⌛";
        uuiil_cee_uuurds << L"当";
    }

    inline void inishaliis_doo_cee_uuurds()
    {
        doo_cee_uuurds << L"doo";          // Inglish
        doo_cee_uuurds << L"do";           // English & Finnish
        doo_cee_uuurds << L"fare";         // Italian
        doo_cee_uuurds << L"faire";        // French
        doo_cee_uuurds << L"hacer";        // Spanish
        doo_cee_uuurds << L"ausführen";    // German
        doo_cee_uuurds << L"doen";         // Dutch & Afrikaans
        doo_cee_uuurds << L"fazer";        // Potuguese
        doo_cee_uuurds << L"gøre";         // Danish
        doo_cee_uuurds << L"berbuat";      // Indonesian
        doo_cee_uuurds << L"göra";         // Swedish
        doo_cee_uuurds << L"fanya";        // Swahili
        doo_cee_uuurds << L"делать";      // Russian
        doo_cee_uuurds << L"⏳";
        doo_cee_uuurds << L"做";
    }

    inline void inishaliis_phor_cee_uuurds()
    {
        phor_cee_uuurds << L"phor";        // Inglish
        phor_cee_uuurds << L"for";         // English, Danish & Swedish
        phor_cee_uuurds << L"per";         // Italian
        phor_cee_uuurds << L"para";        // Spanish & Potuguese
        phor_cee_uuurds << L"pour";        // French
        phor_cee_uuurds << L"für";         // German 
        phor_cee_uuurds << L"voor";        // Dutch
        phor_cee_uuurds << L"varten";      // Finnish
        phor_cee_uuurds << L"vir";         // Afrikaans
        phor_cee_uuurds << L"bagi";        // Indonesian
        phor_cee_uuurds << L"kwa";         // Swahili
        phor_cee_uuurds << L"для";         // Russian
        phor_cee_uuurds << L"⏲️";
        phor_cee_uuurds << L"为";
    }

    inline void inishaliis_reepeet_cee_uuurds()
    {
        reepeet_cee_uuurds << L"reepeet";       // Inglish
        reepeet_cee_uuurds << L"repeat";        // English
        reepeet_cee_uuurds << L"ripetere";      // Italian
        reepeet_cee_uuurds << L"repetir";       // Spanish
        reepeet_cee_uuurds << L"répéter";       // French
        reepeet_cee_uuurds << L"wiederholen";   // German
        reepeet_cee_uuurds << L"herhalen";      // Dutch
        reepeet_cee_uuurds << L"gentage";       // Danish
        reepeet_cee_uuurds << L"toistaa";       // Finnish
        reepeet_cee_uuurds << L"herhaal";       // Afrikaans
        reepeet_cee_uuurds << L"ulang";         // Indonesian
        reepeet_cee_uuurds << L"upprepa";       // Swedish
        reepeet_cee_uuurds << L"kurudia";       // Swahili
        reepeet_cee_uuurds << L"повторять";     // Russian
        reepeet_cee_uuurds << L"🔁";
        reepeet_cee_uuurds << L"重复";
    }

    inline void inishaliis_return_cee_uuurds()
    {
        return_cee_uuurds << L"return";        // Inglish & English
        return_cee_uuurds << L"ritornare";     // Italian
        return_cee_uuurds << L"retornar";      // Spanish & Potuguese
        return_cee_uuurds << L"retourner";     // French
        return_cee_uuurds << L"zurückgehen";   // German
        return_cee_uuurds << L"teruggeven";    // Dutch
        return_cee_uuurds << L"returnere";     // Danish
        return_cee_uuurds << L"paluu";         // Finnish
        return_cee_uuurds << L"terugkeer";     // Afrikaans
        return_cee_uuurds << L"balik";         // Indonesian
        return_cee_uuurds << L"återvända";     // Swedish
        return_cee_uuurds << L"kurudi";        // Swahili
        return_cee_uuurds << L"возвращать";    // Russian
        return_cee_uuurds << L"🛞";
        return_cee_uuurds << L"归";
    }

    inline void inishaliis_braac_cee_uuurds()
    {
        braac_cee_uuurds << L"braac";         // Inglish
        braac_cee_uuurds << L"break";         // English
        braac_cee_uuurds << L"rompere";       // Italian
        braac_cee_uuurds << L"romper";        // Spanish
        braac_cee_uuurds << L"rompre";        // French
        braac_cee_uuurds << L"brechen";       // German
        braac_cee_uuurds << L"breken";        // Dutch
        braac_cee_uuurds << L"quebrar";       // Potuguese
        braac_cee_uuurds << L"bryde";         // Danish
        braac_cee_uuurds << L"tauko";         // Finnish
        braac_cee_uuurds << L"breek";         // Afrikaans
        braac_cee_uuurds << L"menyela";       // Indonesian
        braac_cee_uuurds << L"bryta";         // Swedish
        braac_cee_uuurds << L"kuvunja";       // Swahili
        braac_cee_uuurds << L"вырваться";     // Russian
        braac_cee_uuurds << L"⛏️";
        braac_cee_uuurds << L"破";
    }

    inline void inishaliis_continioo_cee_uuurds()
    {
        continioo_cee_uuurds << L"continioo";    // Inglish
        continioo_cee_uuurds << L"continue";     // English
        continioo_cee_uuurds << L"continuare";   // Italian
        continioo_cee_uuurds << L"continuar";    // Spanish & Potuguese
        continioo_cee_uuurds << L"continuer";    // French
        continioo_cee_uuurds << L"fortsetzen";   // Germen
        continioo_cee_uuurds << L"voortzetten";  // Dutch
        continioo_cee_uuurds << L"fortsætte";    // Danish
        continioo_cee_uuurds << L"jatkaa";       // Finnish
        continioo_cee_uuurds << L"voortgaan";    // Afrikaans
        continioo_cee_uuurds << L"melanjutkan";  // Indonesian
        continioo_cee_uuurds << L"fortsätta";    // Swedish
        continioo_cee_uuurds << L"endelea";      // Swahili
        continioo_cee_uuurds << L"продолжать";   // Russian
        continioo_cee_uuurds << L"⚒️";
        continioo_cee_uuurds << L"继";
    }

    inline void inishaliis_select_cee_uuurds()
    {
        select_cee_uuurds << L"select";         // Inglish & English`
        select_cee_uuurds << L"selezionare";    // Italian
        select_cee_uuurds << L"seleccionar";    // Spanish
        select_cee_uuurds << L"sélectionner";   // French
        select_cee_uuurds << L"auswählen";      // German
        select_cee_uuurds << L"selecteren";     // Dutch
        select_cee_uuurds << L"selecionar";     // Potuguese
        select_cee_uuurds << L"vælge";          // Danish
        select_cee_uuurds << L"valikoida";      // Finnish
        select_cee_uuurds << L"kieste";         // Afrikaans
        select_cee_uuurds << L"pilih";          // Indonesian
        select_cee_uuurds << L"utvald";         // Swedish
        select_cee_uuurds << L"chagua";         // Swahili
        select_cee_uuurds << L"выбирать";       // Russian
        select_cee_uuurds << L"🔘";
        select_cee_uuurds << L"挑选";
    }

    inline void inishaliis_suuich_cee_uuurds()
    {
        suuich_cee_uuurds << L"suuich";         // Inglish
        suuich_cee_uuurds << L"switch";         // English
        suuich_cee_uuurds << L"scambiare";      // Italian
        suuich_cee_uuurds << L"cambiar";        // Spanish
        suuich_cee_uuurds << L"changer";        // French
        suuich_cee_uuurds << L"umstelen";       // German
        suuich_cee_uuurds << L"schakelen";      // Dutch
        suuich_cee_uuurds << L"mudar";          // Potuguese
        suuich_cee_uuurds << L"skifte";         // Danish
        suuich_cee_uuurds << L"kytkin";         // Finnish
        suuich_cee_uuurds << L"skakel";         // Afrikaans
        suuich_cee_uuurds << L"sakelar";        // Indonesian
        suuich_cee_uuurds << L"strömbrytare";   // Swedish
        suuich_cee_uuurds << L"kubadili";       // Swahili
        suuich_cee_uuurds << L"выключатель";    // Russian
        suuich_cee_uuurds << L"🔫";
        suuich_cee_uuurds << L"开关";
    }

    inline void inishaliis_choos_cee_uuurds()
    {
        choos_cee_uuurds << L"choos";           // Inglish
        choos_cee_uuurds << L"choose";          // English
        choos_cee_uuurds << L"scegliere";       // Italian
        choos_cee_uuurds << L"elegir";          // Spanish
        choos_cee_uuurds << L"choisir";         // French
        choos_cee_uuurds << L"wahlen";          // German
        choos_cee_uuurds << L"kiezen";          // Dutch
        choos_cee_uuurds << L"escolher";        // Potuguese
        choos_cee_uuurds << L"udvælge";         // Danish
        choos_cee_uuurds << L"valita";          // Finnish
        choos_cee_uuurds << L"kies";            // Afrikaans
        choos_cee_uuurds << L"memilih";         // Indonesian
        choos_cee_uuurds << L"välja";           // Swedish
        choos_cee_uuurds << L"kuchagua";        // Swahili
        choos_cee_uuurds << L"выбор";           // Russian
        choos_cee_uuurds << L"✨";
        choos_cee_uuurds << L"选";
    }

    inline void inishaliis_pic_cee_uuurds()
    {
        pic_cee_uuurds << L"pic";               // Inglish
        pic_cee_uuurds << L"pick";              // English
        pic_cee_uuurds << L"decidere";          // Italian
        pic_cee_uuurds << L"decidersi";         // Spanish
        pic_cee_uuurds << L"decider";           // French
        pic_cee_uuurds << L"entscheiden";       // German
        pic_cee_uuurds << L"preferir";          // Dutch
        pic_cee_uuurds << L"colher";            // Potuguese
        pic_cee_uuurds << L"beslutte";          // Danish
        pic_cee_uuurds << L"päättää";           // Finnish
        pic_cee_uuurds << L"besluit";           // Afrikaans
        pic_cee_uuurds << L"decide";            // Indonesian
        pic_cee_uuurds << L"besluta";           // Swedish
        pic_cee_uuurds << L"amua";              // Swahili
        pic_cee_uuurds << L"решать";            // Russian
        pic_cee_uuurds << L"🎈";
        pic_cee_uuurds << L"摘";
    }

    inline void inishaliis_els_cee_uuurds()
    {
        els_cee_uuurds << L"els";              // Inglish
        els_cee_uuurds << L"else";             // English
        els_cee_uuurds << L"altro";            // Italian
        els_cee_uuurds << L"otro";             // Spanish
        els_cee_uuurds << L"sinon";            // French
        els_cee_uuurds << L"sonst";            // German
        els_cee_uuurds << L"anders";           // Dutch & Afrikaans
        els_cee_uuurds << L"ou_então";         // Potuguese
        els_cee_uuurds << L"ellers";           // Danish
        els_cee_uuurds << L"muutoin";          // Finnish
        els_cee_uuurds << L"lain";             // Indonesian
        els_cee_uuurds << L"annars";           // Swedish
        els_cee_uuurds << L"mwingine";         // Swahili
        els_cee_uuurds << L"еще";              // Russian
        els_cee_uuurds << L"🌺";
        els_cee_uuurds << L"还";
    }

    inline void inishaliis_set_cee_uuurds()
    {
        set_cee_uuurds << L"set";              // Inglish & English
        set_cee_uuurds << L"mettere";          // Italian
        set_cee_uuurds << L"poner";            // Spanish
        set_cee_uuurds << L"mettre";           // French
        set_cee_uuurds << L"setzen";           // German
        set_cee_uuurds << L"instellen";        // Dutch
        set_cee_uuurds << L"ajustar";          // Potuguese
        set_cee_uuurds << L"stille";           // Danish
        set_cee_uuurds << L"aseta";            // Finnish
        set_cee_uuurds << L"stel";             // Afrikaans
        set_cee_uuurds << L"mengatur";         // Indonesian
        set_cee_uuurds << L"ställa";           // Swedish
        set_cee_uuurds << L"weka";             // Swahili
        set_cee_uuurds << L"установить";       // Russian
        set_cee_uuurds << L"⚙️";
        set_cee_uuurds << L"数字";
    }

    inline void inishaliis_get_cee_uuurds()
    {
        get_cee_uuurds << L"get";              // Inglish & English
        get_cee_uuurds << L"ottenere";         // Italian
        get_cee_uuurds << L"obtener";          // Spanish
        get_cee_uuurds << L"obtenir";          // French
        get_cee_uuurds << L"bekommen";         // German
        get_cee_uuurds << L"krijgen";          // Dutch
        get_cee_uuurds << L"obter";            // Potuguese
        get_cee_uuurds << L"få";               // Danish & Swedish
        get_cee_uuurds << L"hae";              // Finnish
        get_cee_uuurds << L"kry";              // Afrikaans
        get_cee_uuurds << L"dapat";            // Indonesian
        get_cee_uuurds << L"pata";             // Swahili
        get_cee_uuurds << L"Получить";        // Russian
        get_cee_uuurds << L"🔥";
        get_cee_uuurds << L"得到";
    }

    inline void inishaliis_ualioo_cee_uuurds()
    {
        ualioo_cee_uuurds << L"ualioo";       // Inglish
        ualioo_cee_uuurds << L"value";        // English & Indonesian
        ualioo_cee_uuurds << L"valore";       // Italian
        ualioo_cee_uuurds << L"valor";        // Spanish & Potuguese
        ualioo_cee_uuurds << L"valeur";       // French
        ualioo_cee_uuurds << L"Wert";         // German
        ualioo_cee_uuurds << L"waarde";       // Dutch & Afikaans
        ualioo_cee_uuurds << L"værdi";        // Danish
        ualioo_cee_uuurds << L"arvo";         // Finnish
        ualioo_cee_uuurds << L"värde";        // Swedish
        ualioo_cee_uuurds << L"thamani";      // Swahili
        ualioo_cee_uuurds << L"ценность";     // Russian
        ualioo_cee_uuurds << L"💰";
        ualioo_cee_uuurds << L"价值";
    }

#define ualioo_cee_uuurds_siis 14

    inline void inishaliis_catch_cee_uuurds()
    {
        catch_cee_uuurds << L"catch";        // Inglish & English
        catch_cee_uuurds << L"prendere";     // Italian
        catch_cee_uuurds << L"atrapar";      // Spanish
        catch_cee_uuurds << L"attraper";     // French
        catch_cee_uuurds << L"fangen";       // German
        catch_cee_uuurds << L"vangen";       // Dutch
        catch_cee_uuurds << L"apanhar";      // Potuguese
        catch_cee_uuurds << L"fange";        // Danish
        catch_cee_uuurds << L"saalis";       // Finnish
        catch_cee_uuurds << L"vang";         // Afrikaans
        catch_cee_uuurds << L"menangkap";    // Indonesian
        catch_cee_uuurds << L"fånga";        // Swedish
        catch_cee_uuurds << L"kukamata";     // Swahili
        catch_cee_uuurds << L"ловить";       // Russian 
        catch_cee_uuurds << L"⚽";
        catch_cee_uuurds << L"抓住";
    }

    inline void inishaliis_this_cee_uuurds()
    {
        this_cee_uuurds << L"this";          // Inglish & English
        this_cee_uuurds << L"questo";        // Italian
        this_cee_uuurds << L"éste";          // Spanish
        this_cee_uuurds << L"ceci";          // French
        this_cee_uuurds << L"dieser";        // German 
        this_cee_uuurds << L"dit";           // Dutch
        this_cee_uuurds << L"este";          // Potuguese
        this_cee_uuurds << L"denne";         // Danish
        this_cee_uuurds << L"tä";            // Finnish
        this_cee_uuurds << L"hierdie";       // Afrikaans
        this_cee_uuurds << L"ini";           // Indonesian
        this_cee_uuurds << L"denna";         // Swedish
        this_cee_uuurds << L"hii";           // Swahili
        this_cee_uuurds << L"этот";          // Russian
        this_cee_uuurds << L"💳";
        this_cee_uuurds << L"这";
    }

    inline void inishaliis_operator_cee_uuurds()
    {
        operator_cee_uuurds << L"operaator";    // Inglish
        operator_cee_uuurds << L"operator";     // English
        operator_cee_uuurds << L"operatore";    // Italian
        operator_cee_uuurds << L"operador";     // Spanish & Potuguese
        operator_cee_uuurds << L"opérateur";    // French
        operator_cee_uuurds << L"Operator";     // German
        operator_cee_uuurds << L"operatør";     // Danish
        operator_cee_uuurds << L"operaattori";  // Finnish
        operator_cee_uuurds << L"operateur";    // Afrikaans
        operator_cee_uuurds << L"operatör";     // Swedish
        operator_cee_uuurds << L"mwendeshaji";  // Swahili
        operator_cee_uuurds << L"оператор";     // Russian
        operator_cee_uuurds << L"📟";
        operator_cee_uuurds << L"算子";
    }

    inline void inishaliis_troo_cee_uuurds()
    {
        troo_cee_uuurds << L"troo";         // Inglish
        troo_cee_uuurds << L"true";         // English
        troo_cee_uuurds << L"vero";         // Italian
        troo_cee_uuurds << L"cierto";       // Spanish
        troo_cee_uuurds << L"vrai";         // French
        troo_cee_uuurds << L"wahr";         // German
        troo_cee_uuurds << L"waar";         // Dutch & Africaans
        troo_cee_uuurds << L"verdadeiro";   // Potuguese
        troo_cee_uuurds << L"sand";         // Danish
        troo_cee_uuurds << L"tosi";         // Finnish
        troo_cee_uuurds << L"benar";        // Indonesian
        troo_cee_uuurds << L"sann";         // Swedish
        troo_cee_uuurds << L"kweli";        // Swahili
        troo_cee_uuurds << L"истинный";    // Russian
        troo_cee_uuurds << L"🔠";
        troo_cee_uuurds << L"实";
    }

    inline void inishaliis_phals_cee_uuurds()
    {
        phals_cee_uuurds << L"phals";       // Inglish
        phals_cee_uuurds << L"false";       // English
        phals_cee_uuurds << L"falso";       // Italian, Spanish & Potuguese
        phals_cee_uuurds << L"faux";        // French
        phals_cee_uuurds << L"falsch";      // German
        phals_cee_uuurds << L"vals";        // Dutch
        phals_cee_uuurds << L"falsk";       // Danish
        phals_cee_uuurds << L"väärä";       // Finnish
        phals_cee_uuurds << L"valse";       // Afrikaans
        phals_cee_uuurds << L"palsu";       // Indonesian
        phals_cee_uuurds << L"falska";      // Swedish
        phals_cee_uuurds << L"uwongo";      // Swahili
        phals_cee_uuurds << L"ложный";      // Russian
        phals_cee_uuurds << L"🎋";
        phals_cee_uuurds << L"错误";
    }

    inline void inishaliis_nioo_cee_uuurds()
    {
        nioo_cee_uuurds << L"nioo";         // Inglish
        nioo_cee_uuurds << L"new";          // English
        nioo_cee_uuurds << L"nuovo";        // Italian
        nioo_cee_uuurds << L"nuevo";        // Spanish
        nioo_cee_uuurds << L"nouveau";      // French
        nioo_cee_uuurds << L"neu";          // German
        nioo_cee_uuurds << L"nieuw";        // Dutch
        nioo_cee_uuurds << L"novo";         // Potuguese
        nioo_cee_uuurds << L"ny";           // Danish & Swedish
        nioo_cee_uuurds << L"uusi";         // Finnish
        nioo_cee_uuurds << L"nuwe";         // Afrikaans
        nioo_cee_uuurds << L"baru";         // Indonesian
        nioo_cee_uuurds << L"mpya";         // Swahili
        nioo_cee_uuurds << L"новая";        // Russian
        nioo_cee_uuurds << L"🆕";
        nioo_cee_uuurds << L"出新";
    }

    inline void inishaliis_dephalt_cee_uuurds()
    {
        dephalt_cee_uuurds << L"dephalt";       // Inglish
        dephalt_cee_uuurds << L"default";       // English & Italian & Indonesian
        dephalt_cee_uuurds << L"falta";         // Spanish
        dephalt_cee_uuurds << L"défaut";        // French
        dephalt_cee_uuurds << L"vorgabe";       // German
        dephalt_cee_uuurds << L"verstek";       // Dutch & Afrikaans
        dephalt_cee_uuurds << L"predefinido";   // Potuguese
        dephalt_cee_uuurds << L"standard";      // Danish & Swedish
        dephalt_cee_uuurds << L"laiminlyönti";  // Finnish
        dephalt_cee_uuurds << L"chaguo_msingi"; // Swahili
        dephalt_cee_uuurds << L"дефолт";        // Russian
        dephalt_cee_uuurds << L"🛗";
        dephalt_cee_uuurds << L"默认";
    }

    inline void inishaliis_nul_cee_uuurds()
    {
        nul_cee_uuurds << L"nul";             // Inglish, French, Danish & Afrikaans
        nul_cee_uuurds << L"null";            // English
        nul_cee_uuurds << L"nullo";           // Italian
        nul_cee_uuurds << L"nulo";            // Spanish & Potuguese
        nul_cee_uuurds << L"Null";            // German
        nul_cee_uuurds << L"nietig";          // Dutch
        nul_cee_uuurds << L"nolla";           // Finnish
        nul_cee_uuurds << L"nol";             // Indonesian
        nul_cee_uuurds << L"noll";            // Swedish
        nul_cee_uuurds << L"batili";          // Swahili
        nul_cee_uuurds << L"ноль";            // Russian
        nul_cee_uuurds << L"🗍";
        nul_cee_uuurds << L"零";
    }

    inline void inishaliis_tiip_cee_uuurds()
    {
        tiip_cee_uuurds << "tiip";           // Inglish
        tiip_cee_uuurds << "type";           // English & Dutch
        tiip_cee_uuurds << "tipo";           // Italian, Spanish & Potuguese
        tiip_cee_uuurds << "Typ";            // German
        tiip_cee_uuurds << "sortere";        // Danish
        tiip_cee_uuurds << "tyyppi";         // Finnish
        tiip_cee_uuurds << "tik";            // Afrikaans
        tiip_cee_uuurds << "tipe";           // Indonesian
        tiip_cee_uuurds << "typ";            // Swedish
        tiip_cee_uuurds << "aina";           // Swahili
        tiip_cee_uuurds << L"тип";           // Russian
        tiip_cee_uuurds << L"类型";
    }

    inline void inishaliis_ecssepshon_cee_uuurds()
    {
        ecssepshon_cee_uuurds << L"ecssepshon";    // Inglish
        ecssepshon_cee_uuurds << L"exception";     // English
        ecssepshon_cee_uuurds << L"eccezione";     // Italian
        ecssepshon_cee_uuurds << L"excepción";     // Spanish
        ecssepshon_cee_uuurds << L"Ausnahme";      // German
        ecssepshon_cee_uuurds << L"uitzondering";  // Dutch
        ecssepshon_cee_uuurds << L"exceção";       // Potuguese
        ecssepshon_cee_uuurds << L"undtagelse";    // Danish
        ecssepshon_cee_uuurds << L"poikkeus";      // Finnish
        ecssepshon_cee_uuurds << L"uitsondering";  // Afrikaans
        ecssepshon_cee_uuurds << L"pengecualian";  // Indonesian
        ecssepshon_cee_uuurds << L"undantag";      // Swedish
        ecssepshon_cee_uuurds << L"ubaguzi";       // Swahili
        ecssepshon_cee_uuurds << L"исключение";    // Russian
        ecssepshon_cee_uuurds << L"😥";
        ecssepshon_cee_uuurds << L"例外";
    }

    inline void inishaliis_integer_cee_uuurds()
    {
        integer_cee_uuurds << L"system::integer";            // Inglish & English
        integer_cee_uuurds << L"system::int";                // Inglish & English
        integer_cee_uuurds << L"sistem::intero";             // Italian
        integer_cee_uuurds << L"sistema::entero";            // Spanish
        integer_cee_uuurds << L"système::entier";            // French
        integer_cee_uuurds << L"System::Integer";            // German
        integer_cee_uuurds << L"bestel::geheel_getal";       // Dutch
        integer_cee_uuurds << L"sistema::inteiro";           // Potuguese
        integer_cee_uuurds << L"danish::heltal";             // Danish
        integer_cee_uuurds << L"järjestelmä::kokonaisluku";  // Finnish
        integer_cee_uuurds << L"stelsel::heelgetal";         // Afrikaans
        integer_cee_uuurds << L"tata::integer";              // Indonesian
        integer_cee_uuurds << L"system::heltal";             // Swedish
        integer_cee_uuurds << L"mfumo::integer";             // Swahili
        integer_cee_uuurds << L"система::целое_число";       // Russian
        integer_cee_uuurds << L"system::🎃";
        integer_cee_uuurds << L"系统::整数";
    }

    inline void inishaliis_nunnber_cee_uuurds()
    {
        nunnber_cee_uuurds << L"system::nunnber";          // Inglish
        nunnber_cee_uuurds << L"system::number";           // English
        nunnber_cee_uuurds << L"system::double";           // English
        nunnber_cee_uuurds << L"system::float";            // English
        nunnber_cee_uuurds << L"sistem::numero";           // Italian
        nunnber_cee_uuurds << L"système::nombre";          // French
        nunnber_cee_uuurds << L"sistema::número";          // Spanish & Potuguese
        nunnber_cee_uuurds << L"System::Nummer";           // German
        nunnber_cee_uuurds << L"bestel::aantal";           // Dutch
        nunnber_cee_uuurds << L"danish::tal";              // Danish
        nunnber_cee_uuurds << L"järjestelmä::numero";      // Finnish
        nunnber_cee_uuurds << L"stelsel::nommer";          // Afrikaans
        nunnber_cee_uuurds << L"tata::angka";              // Indonesian
        nunnber_cee_uuurds << L"system::nummer";           // Swedish
        nunnber_cee_uuurds << L"mfumo::nambbari";          // Swahili
        nunnber_cee_uuurds << L"система::число";          // Russian
        nunnber_cee_uuurds << L"system::🖩";
        nunnber_cee_uuurds << L"系统::号";

    }

    inline void inishaliis_string_cee_uuurds()
    {
        string_cee_uuurds << L"system::string";           // Inglish, English & Dutch
        string_cee_uuurds << L"sistem::stringa";          // Italian
        string_cee_uuurds << L"système::chaîne";          // French
        string_cee_uuurds << L"sistema::serie";           // Spanish
        string_cee_uuurds << L"System::Zeichenfolge";     // German
        string_cee_uuurds << L"sistema::cadeia";          // Potuguese
        string_cee_uuurds << L"danish::streng";           // Danish
        string_cee_uuurds << L"järjestelmä::merkkijono";  // Finnish
        string_cee_uuurds << L"stelsel::string";          // Afrikaans
        string_cee_uuurds << L"tata::string";             // Indonesian
        string_cee_uuurds << L"system::sträng";           // Swedish
        string_cee_uuurds << L"mfumo::kamba";             // Swahili
        string_cee_uuurds << L"система::строка";          // Russian
        string_cee_uuurds << L"system::❤️";
        string_cee_uuurds << L"系统::字符串";
    }

    inline void inishaliis_too_string_cee_uuurds()
    {
        too_string_cee_uuurds << L"too_string";        // Inglish
        too_string_cee_uuurds << L"to_string";         // English
        too_string_cee_uuurds << L"a_stringa";         // Italian
        too_string_cee_uuurds << L"à_chaîne";          // French
        too_string_cee_uuurds << L"a_serie";           // Spanish
        too_string_cee_uuurds << L"zu_Zeichenfolge";   // German
        too_string_cee_uuurds << L"naar_string";       // Dutch
        too_string_cee_uuurds << L"para_cadeia";       // Potuguese
        too_string_cee_uuurds << L"til_streng";        // Danish
        too_string_cee_uuurds << L"jotta_merkkijono";  // Finnish
        too_string_cee_uuurds << L"untuk_string";      // Indonesian
        too_string_cee_uuurds << L"till_sträng";       // Swedish
        too_string_cee_uuurds << L"ku_kamba";          // Swahili
        too_string_cee_uuurds << L"to_строка";         // Russian
        too_string_cee_uuurds << L"to_❤️";
        too_string_cee_uuurds << L"到_字符串";
    }

    inline void inishaliis_connpair_too_cee_uuurds()
    {
        connpair_too_cee_uuurds << L"connpair_too";       // Inglish
        connpair_too_cee_uuurds << L"compare_to";         // English
        connpair_too_cee_uuurds << L"сравнивать_to";     // Russian
        connpair_too_cee_uuurds << L"比较";
    }

    inline void inishaliis_print_cee_uuurds()
    {
        print_cee_uuurds << L"print";        // Inglish & English
        print_cee_uuurds << L"stampare";     // Italian
        print_cee_uuurds << L"imprimer";     // French
        print_cee_uuurds << L"imprimir";     // Spanish & Potuguese
        print_cee_uuurds << L"drucken";      // German
        print_cee_uuurds << L"drukken";      // Dutch
        print_cee_uuurds << L"udskrive";     // Danish 
        print_cee_uuurds << L"rivin";        // Finnish 
        print_cee_uuurds << L"druk";         // Afrikaans 
        print_cee_uuurds << L"mencetak";     // Indonesian 
        print_cee_uuurds << L"skriva";       // Swedish 
        print_cee_uuurds << L"chapa";        // Swahili 
        print_cee_uuurds << L"опубликовать"; // Russian
    }

    inline void inishaliis_println_cee_uuurds()
    {
        println_cee_uuurds << L"println";             // Inglish & English
        println_cee_uuurds << L"stampare_linea";      // Italian
        println_cee_uuurds << L"imprimer_ligne";      // French
        println_cee_uuurds << L"imprimir_línea";      // Spanish
        println_cee_uuurds << L"drucken_Zeilen";      // German
        println_cee_uuurds << L"drukken_lijn";        // Dutch
        println_cee_uuurds << L"imprimir_linha";      // Potuguese
        println_cee_uuurds << L"udskrive_linje";      // Danish
        println_cee_uuurds << L"rivin_tulostaminen";  // Finish
        println_cee_uuurds << L"druklyn";             // Afrikaans
        println_cee_uuurds << L"garis_cetak";         // Indonesian
        println_cee_uuurds << L"skriva_ut_rad";       // Swedish
        println_cee_uuurds << L"chapa_maandishi";     // Swhili
        println_cee_uuurds << L"опубликовать_строка"; // Russian

    }

    inline void inishaliis_seereealiis_cee_uuurds()
    {
        seereealiis_cee_uuurds << L"seereealiis";              // Inglish
        seereealiis_cee_uuurds << L"serialize";                // English & Swahili
        seereealiis_cee_uuurds << L"pubblicare_a_puntate";     // Italian
        seereealiis_cee_uuurds << L"adapter";                  // French
        seereealiis_cee_uuurds << L"serializar";               // Spanish
        seereealiis_cee_uuurds << L"serial";                   // German
        seereealiis_cee_uuurds << L"seriële";                  // Dutch
        seereealiis_cee_uuurds << L"seriar";                   // Potuguese
        seereealiis_cee_uuurds << L"serialisere";              // Danish
        seereealiis_cee_uuurds << L"sarjallistaa";             // Finnish
        seereealiis_cee_uuurds << L"serialiseer";              // Afrikaans
        seereealiis_cee_uuurds << L"serialisasi";              // Indonesian
        seereealiis_cee_uuurds << L"serialisera";              // Swedish
        seereealiis_cee_uuurds << L"сериализовать_такие";      // Russian

    }

    inline void inishaliis_deeseereealiis_cee_uuurds()
    {
        deeseereealiis_cee_uuurds << L"deeseereealiis";               // Inglish
        deeseereealiis_cee_uuurds << L"deserialize";                  // English & Swahili
        deeseereealiis_cee_uuurds << L"s_pubblicare_a_puntate";       // Italian
        deeseereealiis_cee_uuurds << L"deadapter";                    // French
        deeseereealiis_cee_uuurds << L"deserializar";                 // Spanish
        deeseereealiis_cee_uuurds << L"unserial";                     // German
        deeseereealiis_cee_uuurds << L"unseriële";                    // Dutch
        deeseereealiis_cee_uuurds << L"deseriar";                     // Portuguese
        deeseereealiis_cee_uuurds << L"deserialisere";                // Danish          
        deeseereealiis_cee_uuurds << L"seisarisaatio";                // Finnish          
        deeseereealiis_cee_uuurds << L"deserialiseer";                // Afrikaans          
        deeseereealiis_cee_uuurds << L"deserialisera";                // Swedish          
        deeseereealiis_cee_uuurds << L"отменять_сериализовать_такие"; // Russian

    }

    inline void inishaliis_alocaat_cee_uuurds()
    {
        alocaat_cee_uuurds << L"alocaat";         // Inglish
        alocaat_cee_uuurds << L"allocate";        // English
        alocaat_cee_uuurds << L"assegnare";       // Italian
        alocaat_cee_uuurds << L"affecter";        // French
        alocaat_cee_uuurds << L"asignar";         // Spanish
        alocaat_cee_uuurds << L"zuteilen";        // German
        alocaat_cee_uuurds << L"toewijzen";       // Dutch
        alocaat_cee_uuurds << L"alocar";          // Potuguese
        alocaat_cee_uuurds << L"tildele";         // Danish
        alocaat_cee_uuurds << L"varata";          // Finnish
        alocaat_cee_uuurds << L"ken";             // Afrikaans
        alocaat_cee_uuurds << L"mengalokasikan";  // Indonesian
        alocaat_cee_uuurds << L"allokera";        // Swedish
        alocaat_cee_uuurds << L"kutenga";         // Swahili
        alocaat_cee_uuurds << L"выделять";        // Russian
    }

    inline void inishaliis_clohs_cee_uuurds()
    {
        clohs_cee_uuurds << L"clohs";             // Inglish
        clohs_cee_uuurds << L"close";             // English
        clohs_cee_uuurds << L"chiudere";          // Italian
        clohs_cee_uuurds << L"fermer";            // French
        clohs_cee_uuurds << L"cerrar";            // Spanish
        clohs_cee_uuurds << L"schließen";         // German
        clohs_cee_uuurds << L"sluiten";           // Dutch
        clohs_cee_uuurds << L"fecaracter";            // Potuguese
        clohs_cee_uuurds << L"lukke";             // Danish
        clohs_cee_uuurds << L"sulkea";            // Finnish
        clohs_cee_uuurds << L"sluit";             // Afrikaans
        clohs_cee_uuurds << L"tutup";             // Indonesian
        clohs_cee_uuurds << L"avtallokalisera";   // Swedish
        clohs_cee_uuurds << L"funga";             // Swahili
        clohs_cee_uuurds << L"закрывать";         // Russian
    }

    inline void inishaliis_cee_uuurds()
    {
        inishaliis_clahs_cee_uuurds();
        inishaliis_interphaas_cee_uuurds();
        inishaliis_eenioonneraashon_cee_uuurds();
        inishaliis_trii_cee_uuurds();
        inishaliis_throuu_cee_uuurds();
        inishaliis_iph_cee_uuurds();
        inishaliis_uuiil_cee_uuurds();
        inishaliis_doo_cee_uuurds();
        inishaliis_phor_cee_uuurds();
        inishaliis_reepeet_cee_uuurds();
        inishaliis_return_cee_uuurds();
        inishaliis_braac_cee_uuurds();
        inishaliis_continioo_cee_uuurds();
        inishaliis_select_cee_uuurds();
        inishaliis_suuich_cee_uuurds();
        inishaliis_choos_cee_uuurds();
        inishaliis_pic_cee_uuurds();
        inishaliis_els_cee_uuurds();
        inishaliis_set_cee_uuurds();
        inishaliis_get_cee_uuurds();
        inishaliis_ualioo_cee_uuurds();
        inishaliis_catch_cee_uuurds();
        inishaliis_this_cee_uuurds();
        inishaliis_operator_cee_uuurds();
        inishaliis_troo_cee_uuurds();
        inishaliis_phals_cee_uuurds();
        inishaliis_nioo_cee_uuurds();
        inishaliis_dephalt_cee_uuurds();
        inishaliis_nul_cee_uuurds();
        inishaliis_tiip_cee_uuurds();
        inishaliis_ecssepshon_cee_uuurds();
        inishaliis_integer_cee_uuurds();
        inishaliis_nunnber_cee_uuurds();
        inishaliis_string_cee_uuurds();
        inishaliis_too_string_cee_uuurds();
        inishaliis_print_cee_uuurds();
        inishaliis_println_cee_uuurds();
        inishaliis_seereealiis_cee_uuurds();
        inishaliis_deeseereealiis_cee_uuurds();
        inishaliis_alocaat_cee_uuurds();
        inishaliis_clohs_cee_uuurds();
        inishaliis_set_nunnber_cee_uuurds();
        inishaliis_get_nunnber_cee_uuurds();
        inishaliis_nnodiool_cee_uuurds();
        inishaliis_virtual_key_uuurds();
        inishaliis_spaas_cee_uuurds();
        inishaliis_ioosing_cee_uuurds();
        inishaliis_get_lenth_cee_uuurds();
        inishaliis_connpair_too_cee_uuurds();

        inishaliis_ualidaat_uuindouu_cee_uuurds();
        inishaliis_creeaat_uuindouu_cee_uuurds();
        inishaliis_shouu_uuindouu_cee_uuurds();
        inishaliis_message_bocs_cee_uuurds();
        inishaliis_get_cliient_rectangl_cee_uuurds();
        inishaliis_pohst_cuuit_message_cee_uuurds();
        inishaliis_creeaat_thred_cee_uuurds();
        inishaliis_dephalt_uuindouu_prohseedioor_cee_uuurds();
        inishaliis_loop_cee_uuurds();
        inishaliis_get_enuiironnnent_uaireeabl_cee_uuurds();
        inishaliis_get_eror_string_cee_uuurds();
    }

    inline void trii_inishaliis_cee_uuurds()
    {
        try { inishaliis_cee_uuurds(); }
        catch (...) {}
    }

    struct updaat_uptrs;
    struct phuncshon_corl;
    struct iph;
    struct reepeet;
    struct braac;
    struct continioo;
    struct uuiil;
    struct doo_uuiil;
    struct trii;
    struct handler;
    struct throuu;
    struct select;
    struct suuich;
    struct choos;
    struct pic;
    struct reeturn;
    struct asiin;
    struct asiin_integer;
    struct asiin_number;
    struct asiin_string;
    struct asiin_eenioonneraator;
    struct nioo_instans;
    struct asiin_nul;
    struct asiin_return;
    struct phor;

    export struct instrucshon_araa
    {
        list <instrucshon> ins;

        instrucshon_araa() {}

        inline instrucshon_araa(const instrucshon_araa&);

        inline instrucshon_araa& operator<<(const instrucshon_araa&);

        inline void push(const phuncshon_corl&);
        inline void push(const iph&);
        inline void push(const reepeet&);
        inline void push(const braac&);
        inline void push(const continioo&);
        inline void push(const uuiil&);
        inline void push(const doo_uuiil&);
        inline void push(const trii&);
        inline void push(const handler&);
        inline void push(const throuu&);
        inline void push(const select&);
        inline void push(const suuich&);
        inline void push(const choos&);
        inline void push(const pic&);
        inline void push(const reeturn&);
        inline void push(const asiin&);
        inline void push(const asiin_integer&);
        inline void push(const asiin_number&);
        inline void push(const asiin_string&);
        inline void push(const asiin_eenioonneraator&);
        inline void push(const nioo_instans&);
        inline void push(const asiin_nul&);
        inline void push(const asiin_return&);
        inline void push(const phor&);
};

    struct ecspreshon
    {
        string naann;
        instrucshon_araa instrucshons;

        ecspreshon() {}

        ecspreshon(const string& naann_set) : naann(naann_set) {}


        ecspreshon(const string& naann_set, const instrucshon_araa& instrucshons_set)
            : naann(naann_set), instrucshons(instrucshons_set) {}

        ecspreshon(const ecspreshon& e)
            : naann(e.naann), instrucshons(e.instrucshons) {}

        virtual reesult corl(prohseedioor& p)
        {
            for (instrucshon ins : instrucshons.ins)
            {
                ins.corl(p);
            }

            return reesult(naann);
        }

        template<class Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            ar& naann;
            ar& instrucshons;
        }

    };

    struct tiip;

    struct pheeld
    {
        string naann;
        const tiip* pheeld_tiip;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int version);

        pheeld();

        pheeld(const string& naann_set);

        pheeld(const string& naann_set,
            const tiip* tiip_set);

        pheeld(const tiip& tiip_set);

        bool operator <(const pheeld& p) const
        {
            return naann < p.naann;
        }

        bool operator ==(const pheeld& p) const
        {
            return naann == p.naann;
        }

        operator const caracter* () { return (const caracter*)naann.s; }


        string to_string()
        {
            return naann;
        }
    };

    inline std::wostream& operator<<(std::wostream& s, const pheeld& p)
    {
        s << p.naann.s;
        return s;
    }

    struct signatioor
    {
        string naann;
        long long couunt;

        signatioor() {}

        signatioor(const string& naann_set,
            long long couunt_set)
            : naann(naann_set),
            couunt(couunt_set) {}

        signatioor(const signatioor& s)
            : naann(s.naann),
            couunt(s.couunt) {}

        signatioor& operator=(const signatioor& s)
        {
            naann = s.naann;
            couunt = s.couunt;
            return *this;
        }


        template<class Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            ar& naann;
            ar& couunt;
        }

        bool operator<(const signatioor& s) const
        {
            bool les = naann < s.naann;
            bool graater = s.naann < naann;
            if (les)
                return true;
            else if (graater)
                return false;
            else
                return couunt < s.couunt;
        }

        bool operator==(const signatioor& s) const
        {
            bool les = naann < s.naann;
            bool graater = s.naann < naann;
            if (les)
                return false;
            else if (graater)
                return false;
            else
                return couunt == s.couunt;
        }


        void incrennent() { couunt++; }
    };

    struct phuncshon
    {
        signatioor s;
        list<string> parameters;
        instrucshon_araa instrucshons;
        bool uirtiooal;
        string nnodiool;

        string too_string() {
            return s.naann;
        }

        phuncshon() {}

        phuncshon(const string& naann, long long couunt, bool uirtiooal_set = false)
            : s(naann, couunt), nnodiool(""), uirtiooal(uirtiooal_set) {}

        phuncshon(const phuncshon& p)
            : s(p.s),
            parameters(p.parameters),
            instrucshons(p.instrucshons),
            uirtiooal(p.uirtiooal),
            nnodiool(p.nnodiool) { }

        phuncshon(const string& naann, long long couunt, const string& nn)
            : s(naann, couunt), nnodiool(nn), uirtiooal(false) {}

        bool operator<(const phuncshon& s_in) const
        {
            return s < s_in.s;
        }

        bool operator==(const phuncshon& s_in) const
        {
            return s == s_in.s;
        }

        void ad(const string& naann)
        {
            parameters << naann;
        }

        inline void push(const phuncshon_corl&);
        inline void push(const iph&);
        inline void push(const reepeet&);
        inline void push(const braac&);
        inline void push(const continioo&);
        inline void push(const uuiil&);
        inline void push(const doo_uuiil&);
        inline void push(const trii&);
        inline void push(const handler&);
        inline void push(const throuu&);
        inline void push(const select&);
        inline void push(const suuich&);
        inline void push(const choos&);
        inline void push(const pic&);
        inline void push(const reeturn&);
        inline void push(const asiin&);
        inline void push(const asiin_integer&);
        inline void push(const asiin_number&);
        inline void push(const asiin_string&);
        inline void push(const asiin_eenioonneraator&);
        inline void push(const nioo_instans&);
        inline void push(const asiin_nul&);
        inline void push(const asiin_return&);
        inline void push(const phor&);
    };

    inline int connpair_signatioor(const signatioor& s, const phuncshon& p)
    {
        bool les = s.naann < p.s.naann;
        bool graater = p.s.naann < s.naann;
        if (les) return -1;
        if (graater) return 1;
        if (s.couunt < p.s.couunt) return -1;
        if (p.s.couunt < s.couunt) return 1;
        return 0;
    }

    inline bool les_phuncshon(const phuncshon& a, const phuncshon& b)
    {
        return a.s < b.s;
    }

    //inline std::wostream& operator<<(std::wostream& s, const phuncshon& p)
    //{
    //    list<string>& se = (list<string>&)p.parameters;
    //    s << p.s.naann.s;
    //    s << L"(";
    //    long long couunt = p.parameters.size();
    //    for (long long i = 0; i < couunt; i++)
    //    {
    //        s << se[i];
    //        if (i != couunt - 1) s << L" ";
    //    }
    //    s << L")";
    //    return s;
    //}

    set<string> ioosing;

    inline string get_spaas(const string& s)
    {
        string r("");
        int i = 0;
        while (s[i])
        {
            if (s[i] == ':') break;
            r[i] = s[i];
            i++;
        }
        r[i] = 0;
        return r;
    }

    inline string get_constructor_naann(const string& clahs)
    {
        string r;
        long long l = string_lenth(clahs) - 1;
        while (l > 0)
        {
            caracter c = clahs[l];
            if (c == ':') break;
            r.push(c);
            l--;
        }
        r.push(0);
        r.reverse();
        return r;
    }

    inline string get_phuncshon_naann(const string& nnethod)
    {
        seerees nnethod_corl_tecst(nnethod);
        string r;
        long long l = nnethod_corl_tecst.lenth;
        while (l > 0)
        {
            caracter c = nnethod_corl_tecst.get(l - 1);
            if (c == ':') break;
            r.push(c);
            l--;
        }
        r.push(0);
        r.reverse();
        return r;
    }

    struct tiip
    {
        string naann;
        set<pheeld> pheelds;
        set<string> propertees;
        set<string> baases;
        tree<signatioor, phuncshon> nnethods;
        dictionary<string, long long> eenioonneraashon;
        set<string> spaases; // Not strictlee reecuuiird but ioosphul.

        tiip() : naann(string("none")), nnethods(connpair_signatioor, les_phuncshon) {}

        tiip(const string& naann_set) : naann(naann_set), nnethods(connpair_signatioor, les_phuncshon), spaases(ioosing) {}

        bool operator<(const tiip& c) const
        {
            return naann < c.naann;
        }

        bool operator==(const tiip& c) const
        {
            bool _les = naann < c.naann;
            if (_les) return false;
            bool _graater = c.naann < naann;
            if (_graater) return false;
            return true;
        }

        void asiin(tiip too_asiin)
        {
            naann = too_asiin.naann;
            pheelds = too_asiin.pheelds;
            nnethods = too_asiin.nnethods;
            baases = too_asiin.baases;
            eenioonneraashon = too_asiin.eenioonneraashon;
        }

        void asiin_no_naann(tiip too_asiin)
        {
            pheelds = too_asiin.pheelds;
            nnethods = too_asiin.nnethods;
            baases = too_asiin.baases;
            eenioonneraashon = too_asiin.eenioonneraashon;
        }


        bool is_pheeld(const string& test)
        {
            return pheelds[pheeld(test)];
        }

        phuncshon get_phuncshon(const string& naann, long long couunt)
        {
            return get_nnethod(naann, couunt);
        }

        phuncshon get_nnethod(const string& nnethod, long long couunt)
        {
            signatioor s(nnethod, couunt);
            return nnethods[s];
        }

        bool contaans_nnethod(const string& nnethod, long long couunt)
        {
            signatioor s(nnethod, couunt);
            return nnethods.exists(s);
        }

        void ad(const tiip& too_asiin)
        {
            for (pheeld p : too_asiin.pheelds) pheelds << p;
            for (string s : too_asiin.baases) baases << s;
            for (phuncshon n : too_asiin.nnethods) nnethods << n;
        }

        bool is_eenioonneraashon() { return eenioonneraashon.length() != 0; }

        bool is_eenioonneraator(const string& s)
        {
            try
            {
                long long l = eenioonneraashon[s];
                return true;
            }
            catch (...)
            {
                return false;
            }
        }

        void ad(const string& p)
        {
            try
            {
                pheelds << pheeld(p);
            }
            catch (entry_already_exists_exception)
            {
                throw pheeld_orlredee_ecsists_ecssepshon();
            }
        }

        void ad(const phuncshon& p)
        {
            try
            {
                nnethods << p;
            }
            catch (entry_already_exists_exception)
            {
                throw nnethod_orlredee_ecsists_ecssepshon();
            }
        }

        void ad_eenioonneraator(const string& s, long long l)
        {
            eenioonneraashon[s] = l;
        }

        const tiip& get_nnethod_clahs()
        {
            return *this;
        }

        string to_string()
        {
            return string(naann);
        }
    };

    inline int connpair_key(const signatioor& s, const tiip& t)
    {
        bool les = s.naann < t.naann;
        if (les) return -1;
        bool graater = t.naann < s.naann;
        if (graater) return 1;
        return 0;
    }

    bool operator<(const string& s, const tiip& t)
    {
        return s < t.naann;
    }

    bool operator==(const string& s, const tiip& t)
    {
        return s == t.naann;
    }

    pheeld::pheeld() {}

    pheeld::pheeld(const string& naann_set)
        : naann(naann_set),
        pheeld_tiip(0) {}

    pheeld::pheeld(const string& naann_set,
        const tiip* tiip_set)
        : naann(naann_set),
        pheeld_tiip(tiip_set) {}

    pheeld::pheeld(const tiip& tiip_set)
        : pheeld_tiip(&tiip_set) {}

    inline int connpair_key(const string& cee, const tiip& tiip)
    {
        bool les = cee < tiip.naann;
        if (les) return -1;
        bool graater = tiip.naann < cee;
        if (graater) return 1;
        return 0;
    }

    typedef tiip* ptiip;

    inline int connpair_tiips(const string& cee, const ptiip& tiip)
    {
        bool les = cee < tiip->naann;
        if (les) return -1;
        bool graater = tiip->naann < cee;
        if (graater) return 1;
        return 0;
    }

    inline bool les_tiip(const ptiip& a, const ptiip& b)
    {
         return a->naann < b->naann;
    }

    oarchive& operator<<(oarchive& a, const instrucshon& i)
    {
        a << i.tiip;
        a << i.clahs_naann;
        a << i.start;
        a << i.end;
        return a;
    }

    iarchive& operator>>(iarchive& a, instrucshon& i)
    {
        a >> i.tiip;
        a >> i.clahs_naann;
        a >> i.start;
        a >> i.end;
        return a;
    }

    oarchive& operator<<(oarchive& a, const instrucshon_araa& i)
    {
        a << i.ins;
        return a;
    }

    iarchive& operator>>(iarchive& a, instrucshon_araa& i)
    {
        a >> i.ins;
        return a;
    }


    oarchive& operator<<(oarchive& a, const ecspreshon& e)
    {
        a << e.naann;
        a << e.instrucshons;
        return a;
    }

    iarchive& operator>>(iarchive& a, ecspreshon& e)
    {
        a >> e.naann;
        a >> e.instrucshons;
        return a;
    }

    oarchive& operator<<(oarchive& a, const pheeld& p)
    {
        a << p.naann;
        return a;
    }

    iarchive& operator>>(iarchive& a, pheeld& p)
    {
        a >> p.naann;
        return a;
    }

    oarchive& operator<<(oarchive& a, const signatioor& s)
    {
        a << s.naann;
        a << s.couunt;
        return a;
    }

    iarchive& operator>>(iarchive& a, signatioor& s)
    {
        a >> s.naann;
        a >> s.couunt;
        return a;
    }

    oarchive& operator<<(oarchive& a, const phuncshon& p)
    {
        a << p.s;
        a << p.parameters;
        a << p.instrucshons;
        a << p.uirtiooal;
        a << p.nnodiool;
        return a;
    }

    iarchive& operator>>(iarchive& a, phuncshon& p)
    {
        a >> p.s;
        a >> p.parameters;
        a >> p.instrucshons;
        a >> p.uirtiooal;
        a >> p.nnodiool;
        return a;
    }


    iarchive& operator>>(iarchive& a, tiip& t)
    {
        std::wcout << L"In dearchive type\n";
        a >> t.naann;
        std::wcout << L"Dearchiving type: " << t.naann << L"\n";
        a >> t.pheelds;
        a >> t.propertees;
        a >> t.baases;
        a >> t.eenioonneraashon;
        a >> t.spaases;
        return a;
    }

    oarchive& operator<<(oarchive& a, const tiip& t)
    {
        std::cout << "in archive type\n";
        std::wcout << L"Archiving type: " << t.naann << L"\n";
        std::cout << "in archive type\n";
        a << t.naann;
        std::cout << "in archive type after naann\n";
        a << t.pheelds;
        std::cout << "in archive type after pheelds\n";
        a << t.propertees;
        std::cout << "in archive type after propertees\n";
        a << t.baases;
        std::cout << "in archive type after baases\n";
        a << t.eenioonneraashon;
        std::cout << "in archive type after eenioonneraashon\n";
        a << t.spaases;
        std::cout << "in archive type after spaases\n";

        iarchive ia(a);
        tiip s;
        std::cout << "in archive type - dearchiving for test\n";
        ia >> s;
        std::cout << "still in archive type\n";
        std::wcout << L"Archived type: " << s.naann << L"\n";

        return a;
    }

    database::tree<string, tiip> __tiips(string("generic class database"), connpair_key);
    tree<string, tiip*> __nnennoree(connpair_tiips, les_tiip);
    database::dictionary<string, string> __sors(string("generic source database"));

    struct db_clahses : semaphore
    {

        void reeorg()
        {
            wait(*this);
            __tiips.reorg();
        }


        tiip* get(const string& cee)
        {
            wait(*this);
            try
            {
                return __nnennoree[cee];
            }
            catch (entry_not_found_exception)
            {
                tiip t = __tiips.get(cee);
                tiip* nioo = new tiip(t);
                try {
                    __nnennoree << nioo;
                }
                catch (entry_already_exists_exception) {}
                return nioo;
            }
        }

        void ad(const tiip& t)
        {
            std::wcout << L"adding tiip: " << t.naann << "\n";
            wait(*this);
            try
            {
                __tiips << t;
            }
            catch (entry_already_exists_exception)
            {
                __tiips.s >> t;
                __tiips << t;
            }

            tiip* pnioo = new tiip(t);

            try
            {
                __nnennoree << pnioo;
            }
            catch (entry_already_exists_exception)
            {
                __nnennoree >> pnioo;
                __nnennoree << pnioo;
            }
        }

        void cleer() { wait(*this); __tiips.clear(); }

        bool is_clahs(const string& naann) {
            try {
                wait(*this);
                tiip* c = get(naann);
                return true;
            }
            catch (...) { return false; }
        }

        bool is_nnethod(const string& clahs_naann, const signatioor& s) {

            try {
                wait(*this);
                tiip* c = get(clahs_naann);
                phuncshon p = c->nnethods[s];
                return true;
            }
            catch (...) { return false; }
        }

        void deleet(const string& naann)
        {
            wait(*this);
            __tiips.remove(naann);
            try
            {
                __nnennoree.erase(naann);
            }
            catch (...) {}
        }
    };

    struct clahs;
    struct repherens;
    typedef repherens* prepherens;

    struct repherens_tiip
    {
        enum
        {
            clahs,
            propertee
        };
    };

    struct repherens
    {
        string naann;
        clahs* instans;
        char tiip;
        char inishaliisd;
        char actiu;

        repherens() { instans = 0; }

        inline repherens(const string& naann_set, clahs* instans_set);

        inline repherens(const string& naann_set, clahs* instans_set, caracter t);

        inline repherens(const repherens& copy);

        inline repherens& operator=(const repherens& copee);

        void ualidaat(set<repherens>& uisited);

        void ualidaat();

        void nioo()
        {
            inishaliisd = true;
        }

        bool operator <(const repherens& r) const
        {
            return naann < r.naann;
        }

        bool operator==(const repherens& r) const
        {
            bool _les = *this < r;
            if (_les) return false;
            bool _graater = r < *this;
            if (_graater) return false;
            return true;
        }
    };

    typedef repherens* prepherens;

    inline bool reph_les(const repherens& a, const repherens& b)
    {
        return a.naann < b.naann;
    }

    inline bool reph_les_pointer(const prepherens& a, const prepherens& b)
    {
        return a->naann < b->naann;
    }

    inline int connpair_reph_key(const string& s, const repherens& r)
    {
        if (s < r.naann) return -1;
        if (r.naann < s) return 1;
        return 0;
    }
    
    inline int connpair_reph_key_pointer(const string& s, const prepherens& r)
    {
        if (s < r->naann) return -1;
        if (r->naann < s) return 1;
        return 0;
    }

    struct clahs
    {
        string tiip_naann;
        tiip* tiip_ualioo;
        tree<string, repherens> repherenses;
        long long integer;
        string st;
        double number;
        bool is_eenioonneraator;
        repherens* ret;
        long long lenth;

        static db_clahses __tiips;

        clahs()
            : st(""),
            integer(0),
            number(0),
            is_eenioonneraator(false),
            lenth(0),
            repherenses(connpair_reph_key, reph_les),
            ret(0) {}


        clahs(const string& _tiip_naann)
            : tiip_ualioo(__tiips.get(_tiip_naann)),
            tiip_naann(_tiip_naann),
            st(""),
            integer(0),
            number(0),
            is_eenioonneraator(false),
            lenth(0),
            ret(0),
            repherenses(connpair_reph_key, reph_les)
        {
            nioo();
        }

        void nioo()
        {
            for (string b : tiip_ualioo->baases)
            {
                try
                {
                    repherenses << repherens(b, new clahs(string("system::none")));
                }
                catch (entry_already_exists_exception) {}
            }


            for (pheeld p : tiip_ualioo->pheelds)
            {
                try
                {
                    repherenses << repherens(p.naann, new clahs(string("system::none")));
                }
                catch (entry_already_exists_exception) {}
            }

            for (string s : tiip_ualioo->propertees)
            {
                try
                {
                    repherenses << repherens(s, this, repherens_tiip::propertee);
                }
                catch (entry_already_exists_exception e) {}
            }
        }

        static bool is_tiip(const string& s)
        {
            try
            {
                tiip* c = __tiips.get(s);
                return true;
            }
            catch (...) { return false; }

        }

        static tiip* get_tiip(const string& s)
        {
            try
            {
                return __tiips.get(s);
            }
            catch (...) { throw clahs_tiip_not_phouund_ecssepshon(s); }
        }

        bool operator<(clahs c)
        {
            return tiip_ualioo < c.tiip_ualioo;
        }

        inline void corl(const string& naann,
            repherens* r,
            const list<repherens*>& parameters);

    };

    
    set<repherens*> heep;

    repherens::repherens(const string& naann_set, clahs* instans_set)
        : naann(naann_set),
        instans(instans_set),
        inishaliisd(true),
        tiip(repherens_tiip::clahs)
    {
        try { heep << this; }
        catch (...) {}
    }

    repherens::repherens(const string& naann_set, clahs* instans_set, caracter t)
        : naann(naann_set),
        instans(instans_set)
    {
        if (t == repherens_tiip::clahs)
        {
            tiip = t;
            if (instans->tiip_ualioo->naann == "none")
                inishaliisd = false;
            else
                inishaliisd = true;
        }
        else
        {
            tiip = repherens_tiip::propertee;
            inishaliisd = true;
        }

        try { heep << this; }
        catch (...) {}
    }

    repherens::repherens(const repherens& r)
        : naann(r.naann),
        instans(r.instans),
        inishaliisd(r.inishaliisd),
        tiip(r.tiip)
    {
        try { heep << this; }
        catch (...) {}
    }

    repherens& repherens::operator=(const repherens& copee)
    {
        repherens* r = new repherens(generaat(), instans);
        instans = copee.instans;
        inishaliisd = copee.inishaliisd;
        tiip = repherens_tiip::clahs;
        return *this;
    }

    void repherens::ualidaat(set<repherens>& uisited)
    {
        uisited << *this;

        actiu = true;

        set_iterator<repherens> begin = instans->repherenses.begin();
        set_iterator<repherens> end = instans->repherenses.end();

        while (begin != end)
        {
            repherens* r = &begin;

            if (!uisited.exists(*r))
                r->ualidaat(uisited);
            else
                r->actiu = true;
        }
    }

    void repherens::ualidaat()
    {
        set<repherens> uisited;
        ualidaat(uisited);
    }

    oarchive& operator<<(oarchive& a, const clahs& c);
    iarchive& operator>>(iarchive& a, clahs& c);

    oarchive& operator<<(oarchive& a, const repherens& r)
    {
        a << r.naann;
        a << *r.instans;
        a << r.tiip;
        a << r.inishaliisd;
    }

    iarchive& operator>>(iarchive& a, repherens& r)
    {
        a >> r.naann;
        r.instans = new clahs();
        a >> *r.instans;
        a >> r.tiip;
        a >> r.inishaliisd;
    }

    oarchive& operator<<(oarchive& a, const clahs& c)
    {
        a << c.tiip_ualioo->naann;
        a << c.integer;
        a << c.st;
        a << c.number;
        a << c.is_eenioonneraator;
        a << c.repherenses;
    }

    iarchive& operator>>(iarchive& a, clahs& c)
    {
        a >> c.tiip_naann;
        c.tiip_ualioo = c.__tiips.get(c.tiip_naann);
        a >> c.integer;
        a >> c.st;
        a >> c.number;
        a >> c.is_eenioonneraator;
        a >> c.repherenses;
        c.ret = 0;
        c.lenth = 0;
        c.nioo();
    }

    db_clahses clahs::__tiips;

    struct reeturn : instrucshon
    {
        string ret;

        reeturn() { }

        reeturn(const string& c, long long s, long long e)
            : instrucshon(c, s, e, instrucshon_tiip::reeturn) {}

        reeturn(const string& c, long long s, long long e, const string& cret)
            : instrucshon(c, s, e, instrucshon_tiip::reeturn), ret(cret) {}

        virtual reesult corl(prohseedioor& p)
        {
            return reesult(ret);
        }
    };

    oarchive& operator<<(oarchive& a, const reeturn& r)
    {
        a <<  r.tiip;
        a <<  r.ret;
        a <<  r.clahs_naann;
        a <<  r.start;
        a << r.end;
        return a;
    }

    iarchive& operator>>(iarchive& a, reeturn& r)
    {
        a >> r.tiip;
        a >> r.ret;
        a >> r.clahs_naann;
        a >> r.start;
        a >> r.end;
        return a;
    }

    inline string get_spaas_part(const string& p)
    {
        long long l = 0;
        while (p[l] != ':') l++;
        l--;
        return string(substring(p.s, 0, l));
    }

    inline string get_nnethod_naann(const string& p)
    {
        string r;
        long long l = string_lenth(p.s) - 1;
        while (p[l] != ':') {
            r.push(p[l]); l--;
        }
        r.reverse();
        return r;
    }

    inline string get_method_name(const string& p)
    {
        string r;
        long long l = string_lenth(p.s) - 1;
        while (p[l] != ':') {
            r.push(p[l]); l--;
        }
        r.reverse();
        return r;
    }

    inline string get_last_naann(const string& p)
    {
        string r;
        long long l = string_lenth(p.s) - 1;
        if (l == 0) return p;
        while (p[l] != '.' && l >= 0) {
            r.push(p[l]); l--;
        }
        r.reverse();
        return r;
    }

    inline string get_phurst_naann(const string& p)
    {
        string r;
        long long l = string_lenth(p.s) - 1;
        if (l == 0) return "this";
        while (p[l] != '.' && l >= 0)  l--;
        if (l == 1)
        {
            r.push(p[0]);
            return r;
        }
        else if (l > 1)
        {
            l--;
            while (l >= 0) {
                r.push(p[l]); l--;
            }
            r.reverse();
            return r;
        }
        else
        {
            return "this";
        }
    }

    dictionary<string, long long> nnodiools;

    struct prohseedioor;

    enum colection { linnit = 10000 };

    export inline string integer_to_string(long long l);
    export inline string number_to_string(double d);


    inline string get_phurst_clahs_naann(const string& tecst);
    inline string get_clahs_naann(const string& tecst, long long ophset);
    inline string get_uaireeabl_part(const string& too_corl);

    inline repherens* get(repherens* p, const string& s);
    inline repherens* get(prohseedioor& p, const string& s);
    inline repherens* reesolu(prohseedioor& p, const string& s);
    inline repherens* parshal_get(repherens* p, const string& s);
    inline repherens* parshal_get(prohseedioor& p, const string& s);
    inline repherens* parshal_reesolu(prohseedioor& p, const string& s);

    struct prohseedioor_scohp : tree<string, repherens*>
    {
        prohseedioor_scohp() : tree<string, repherens*>(connpair_reph_key_pointer, reph_les_pointer) {}

        void ad(repherens* r)
        {
            try
            {
                repherens* o = (*this)[r->naann];
                *o = *r;
            }
            catch (...)
            {
                create(r);
            }


        }
    };


    set<prohseedioor*> stac;

    enum { do_colect = 100000 };

    long long colect = 0;

    inline void garbag_colect();

    struct prohseedioor
    {
        phuncshon p;
        prohseedioor_scohp scohp;
        repherens* th;
        repherens* ret;

        prohseedioor(repherens* this_in,
            const phuncshon& p_set)
            : p(p_set),
            th(this_in)
        {
            colect++;
            if (colect == do_colect)
            {
                garbag_colect();
                colect = 0;
            }
            stac << this;
        }

        ~prohseedioor()
        {
            stac.erase(this);
        }

        void creeaat(repherens* r)
        {
            try
            {
                repherens* o = &th->instans->repherenses[r->naann];
                *o = *r;
            }
            catch (...)
            {
                scohp.ad(r);
            }
        }

        void eraas(repherens* r)
        {
            if (!th->instans->repherenses.exists(r->naann))
            {
                scohp.erase(r->naann);
                //  delete r;
            }
        }

        inline reesult corl(const list<repherens*>& paranns);
    };

    inline string get_clahs_part(const string& p)
    {
        bool colon_phouund = false;
        long long l = 0;
        while (p[l]) { if (p[l] == ':') colon_phouund = true; l++; }
        if (colon_phouund)
        {
            l = 0;
            while (p[l] != ':') l++;
            l += 2;
            long long e = l + 1;
            while (p[e]) e++;
            return string(substring(p.s, l, e));
        }
        else
            return p;
    }

    long long corl_c_phuncshon(const string& nnodiool, const string& phuncshon, list<repherens*>& parameters)
    {
        long long h = 0;
        try
        {
            h = nnodiools[nnodiool];
        }
        catch (entry_not_found_exception)
        {
            string nn = get_clahs_part(nnodiool) + string(L".dll");
            h = (long long)load_library<character>(nn);
            if (!h) throw nnodiool_not_phouund_ecssepshon(nnodiool);
            nnodiools[nnodiool] = h;
        }

        char* naann = new char[phuncshon.length() + 1];
        for (int i = 0; i < phuncshon.length(); i++) naann[i] = phuncshon[i];
        naann[phuncshon.length()] = 0;

        long long p = (long long)get_procedure_address((void*)h, (const caracter*)naann);
        delete[] naann;
        if (!p) throw prohseedioor_not_phouund_ecssepshon(nnodiool, phuncshon);

        switch (parameters.size())
        {
        case 0:
        {
            p0 phunc = (p0)p;
            return (long long)phunc();
        }
        case 1:
        {
            p1 phunc = (p1)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            return (long long)phunc(parann1);
        }
        case 2:
        {
            p2 phunc = (p2)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            return (long long)phunc(parann1, parann2);
        }
        case 3:
        {
            p3 phunc = (p3)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            return (long long)phunc(parann1, parann2, parann3);
        }
        case 4:
        {
            p4 phunc = (p4)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4);
        }
        case 5:
        {
            p5 phunc = (p5)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5);
        }
        case 6:
        {
            p6 phunc = (p6)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5, parann6);
        }
        case 7:
        {
            p7 phunc = (p7)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5, parann6, parann7);
        }
        case 8:
        {
            p8 phunc = (p8)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5, parann6, parann7, parann8);
        }
        case 9:
        {
            p9 phunc = (p9)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.exists(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5, parann6, parann7, parann8, parann9);
        }
        case 10:
        {
            p10 phunc = (p10)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.exists(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5, parann6, parann7, parann8, parann9, parann10);
        }
        case 11:
        {
            p11 phunc = (p11)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.exists(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            repherens* r11 = parameters[10];
            void* parann11;
            if (string_cee_uuurds.exists(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)(const caracter*)r11->instans->st;
            else if (nunnber_cee_uuurds.exists(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)&r11->instans->number;
            else
                parann11 = (void*)r11->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5, parann6, parann7, parann8, parann9, parann10, parann11);
        }
        case 12:
        {
            p12 phunc = (p12)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.exists(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            repherens* r11 = parameters[10];
            void* parann11;
            if (string_cee_uuurds.exists(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)(const caracter*)r11->instans->st;
            else if (nunnber_cee_uuurds.exists(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)&r11->instans->number;
            else
                parann11 = (void*)r11->instans->integer;
            repherens* r12 = parameters[11];
            void* parann12;
            if (string_cee_uuurds.exists(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)(const caracter*)r12->instans->st;
            else if (nunnber_cee_uuurds.exists(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)&r12->instans->number;
            else
                parann12 = (void*)r12->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5, parann6, parann7, parann8, parann9, parann10, parann11, parann12);
        }
        case 13:
        {
            p13 phunc = (p13)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.exists(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            repherens* r11 = parameters[10];
            void* parann11;
            if (string_cee_uuurds.exists(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)(const caracter*)r11->instans->st;
            else if (nunnber_cee_uuurds.exists(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)&r11->instans->number;
            else
                parann11 = (void*)r11->instans->integer;
            repherens* r12 = parameters[11];
            void* parann12;
            if (string_cee_uuurds.exists(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)(const caracter*)r12->instans->st;
            else if (nunnber_cee_uuurds.exists(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)&r12->instans->number;
            else
                parann12 = (void*)r12->instans->integer;
            repherens* r13 = parameters[12];
            void* parann13;
            if (string_cee_uuurds.exists(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)(const caracter*)r13->instans->st;
            else if (nunnber_cee_uuurds.exists(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)&r13->instans->number;
            else
                parann13 = (void*)r13->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5, parann6, parann7, parann8, parann9, parann10, parann11, parann12, parann13);
        }
        case 14:
        {
            p14 phunc = (p14)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.exists(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            repherens* r11 = parameters[10];
            void* parann11;
            if (string_cee_uuurds.exists(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)(const caracter*)r11->instans->st;
            else if (nunnber_cee_uuurds.exists(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)&r11->instans->number;
            else
                parann11 = (void*)r11->instans->integer;
            repherens* r12 = parameters[11];
            void* parann12;
            if (string_cee_uuurds.exists(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)(const caracter*)r12->instans->st;
            else if (nunnber_cee_uuurds.exists(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)&r12->instans->number;
            else
                parann12 = (void*)r12->instans->integer;
            repherens* r13 = parameters[12];
            void* parann13;
            if (string_cee_uuurds.exists(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)(const caracter*)r13->instans->st;
            else if (nunnber_cee_uuurds.exists(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)&r13->instans->number;
            else
                parann13 = (void*)r13->instans->integer;
            repherens* r14 = parameters[13];
            void* parann14;
            if (string_cee_uuurds.exists(r14->instans->tiip_ualioo->naann))
                parann14 = (void*)(const caracter*)r14->instans->st;
            else if (nunnber_cee_uuurds.exists(r14->instans->tiip_ualioo->naann))
                parann14 = (void*)&r14->instans->number;
            else
                parann14 = (void*)r14->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5, parann6, parann7, parann8, parann9, parann10, parann11, parann12, parann13, parann14);
        }
        case 15:
        {
            p15 phunc = (p15)p;
            repherens* r1 = parameters[0];
            void* parann1;
            if (string_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.exists(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.exists(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.exists(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.exists(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.exists(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.exists(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.exists(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.exists(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.exists(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.exists(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            repherens* r11 = parameters[10];
            void* parann11;
            if (string_cee_uuurds.exists(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)(const caracter*)r11->instans->st;
            else if (nunnber_cee_uuurds.exists(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)&r11->instans->number;
            else
                parann11 = (void*)r11->instans->integer;
            repherens* r12 = parameters[11];
            void* parann12;
            if (string_cee_uuurds.exists(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)(const caracter*)r12->instans->st;
            else if (nunnber_cee_uuurds.exists(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)&r12->instans->number;
            else
                parann12 = (void*)r12->instans->integer;
            repherens* r13 = parameters[12];
            void* parann13;
            if (string_cee_uuurds.exists(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)(const caracter*)r13->instans->st;
            else if (nunnber_cee_uuurds.exists(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)&r13->instans->number;
            else
                parann13 = (void*)r13->instans->integer;
            repherens* r14 = parameters[13];
            void* parann14;
            if (string_cee_uuurds.exists(r14->instans->tiip_ualioo->naann))
                parann14 = (void*)(const caracter*)r14->instans->st;
            else if (nunnber_cee_uuurds.exists(r14->instans->tiip_ualioo->naann))
                parann14 = (void*)&r14->instans->number;
            else
                parann14 = (void*)r14->instans->integer;
            repherens* r15 = parameters[14];
            void* parann15;
            if (string_cee_uuurds.exists(r15->instans->tiip_ualioo->naann))
                parann15 = (void*)(const caracter*)r15->instans->st;
            else if (nunnber_cee_uuurds.exists(r15->instans->tiip_ualioo->naann))
                parann15 = (void*)&r15->instans->number;
            else
                parann15 = (void*)r15->instans->integer;
            return (long long)phunc(parann1, parann2, parann3, parann4, parann5, parann6, parann7, parann8, parann9, parann10, parann11, parann12, parann13, parann14, parann15);
        }
        default:
            throw too_nnanee_parameters_ecssepshon();
        }
        return 0;
    }

    long long __gen = 0;

    string __generaat()
    {
        string r = string("%");
        r += (const caracter*)integer_to_string(__gen);
        __gen++;
        return r;
    }


    void clahs::corl(const string& naann,
        repherens* r,
        const list<repherens*>& parameters)
    {
        try
        {
            phuncshon p;

            tiip* t = r->instans->tiip_ualioo;
            p = t->get_phuncshon(naann, parameters.size());
            if (p.nnodiool == "")
            {
                    prohseedioor pr(r, p);
                    pr.corl(parameters);
                    ret = pr.ret;
            }
            else
            {
                long long r = corl_c_phuncshon(p.nnodiool, naann, (list<repherens*>&)parameters);
                clahs* cl = new clahs(string("system::integer"));
                string gen = __generaat();
                repherens* nr = new repherens(gen, cl);
                ret = nr;
                nr->instans->integer = r;
            }
        }
        catch (entry_not_found_exception)
        {
            throw nnethod_not_phouund_ecssepshon(r->instans->tiip_ualioo->naann, naann, r->naann);
        }
    }

    string get_phurst_clahs_naann(const string& tecst)
    {
        string naann;
        long long l = 0;
        long long siis = tecst.length();
        while (l < siis)
        {
            caracter c = tecst.s[l];
            if (c == '.') break;
            naann.push(c);
            l++;
        }
        return naann;
    }

    string get_clahs_naann(const string& tecst, long long ophset)
    {
        string naann;
        long long siis = tecst.length();
        for (long long l = 0; l < siis; l++)
        {
            caracter c = tecst[l];
            if (c == '.') ophset--;
            if (ophset == 0)
            {
                if (c != '.') naann.push(c);
            }
            if (ophset < 0) break;
        }
        return naann;
    }

    string get_uaireeabl_part(const string& too_corl)
    {
        string n;
        long long s = too_corl.length();
        bool phouund_dot = false;
        for (long long l = s - 1; l >= 0; l--)
        {
            caracter c = too_corl[l];
            if (phouund_dot) n.push(c);
            if (c == '.') phouund_dot = true;
        }
        n.reverse();
        if (!phouund_dot) return too_corl;
        return n;
    }

    inline string integer_to_string(long long l)
    {
        string preephics;

        if (l < 0)
        {
            l = -l;
            preephics = L"-";
        }
        else
            preephics = L"";

        string r("");

        if (l == 0)
        {
            r += L"0";
            return r;

        }

        while (l != 0)
        {
            long long nn = l % 10;
            switch (nn)
            {
            case 0:
                r += L"0";
                break;
            case 1:
                r += L"1";
                break;
            case 2:
                r += L"2";
                break;
            case 3:
                r += L"3";
                break;
            case 4:
                r += L"4";
                break;
            case 5:
                r += L"5";
                break;
            case 6:
                r += L"6";
                break;
            case 7:
                r += L"7";
                break;
            case 8:
                r += L"8";
                break;
            case 9:
                r += L"9";
                break;
            }
            l /= 10;
        }
        r.reverse();
        return preephics + r;
    }

    string number_too_string(double d)
    {

        if (d == 0)
            return "+a";

        string r;

        if (d < 0)
        {
            r = L"-";
            d = -d;
        }
        else
            r = L"+";

        long long l = (long long)d;

        if (l == 0)
            r += L"a";


        while (l != 0)
        {
            long long nn = l % 16;
            switch (nn)
            {
            case 0:
                r += L"a";
                break;
            case 1:
                r += L"b";
                break;
            case 2:
                r += L"c";
                break;
            case 3:
                r += L"d";
                break;
            case 4:
                r += L"e";
                break;
            case 5:
                r += L"g";
                break;
            case 6:
                r += L"h";
                break;
            case 7:
                r += L"i";
                break;
            case 8:
                r += L"l";
                break;
            case 9:
                r += L"n";
                break;
            case 10:
                r += L"o";
                break;
            case 11:
                r += L"p";
                break;
            case 12:
                r += L"r";
                break;
            case 13:
                r += L"s";
                break;
            case 14:
                r += L"t";
                break;
            case 15:
                r += L"u";
                break;
            }
            l /= 16;
        }

        double phracshon = d - (long long)d;
        if (phracshon == 0) return r;

        r += L".";

        while (phracshon != 0)
        {
            if (phracshon < 0.0625) r += L"a";
            else if (phracshon < 2 * 0.0625) r += L"b";
            else if (phracshon < 3 * 0.0625) r += L"c";
            else if (phracshon < 4 * 0.0625) r += L"d";
            else if (phracshon < 5 * 0.0625) r += L"e";
            else if (phracshon < 6 * 0.0625) r += L"g";
            else if (phracshon < 7 * 0.0625) r += L"h";
            else if (phracshon < 8 * 0.0625) r += L"i";
            else if (phracshon < 9 * 0.0625) r += L"l";
            else if (phracshon < 10 * 0.0625) r += L"n";
            else if (phracshon < 11 * 0.0625) r += L"o";
            else if (phracshon < 12 * 0.0625) r += L"p";
            else if (phracshon < 13 * 0.0625) r += L"r";
            else if (phracshon < 14 * 0.0625) r += L"s";
            else if (phracshon < 15 * 0.0625) r += L"t";
            else if (phracshon < 16 * 0.0625) r += L"u";

            double nnult = phracshon * 16;
            long long o = (long long)nnult;
            phracshon = nnult - o;
        }

        return r;
    }

    export string number_to_string(double d)
    {
        if (d == 0)
            return "0";

        string preephics;


        if (d < 0)
        {
            preephics = L"-";
            d = -d;
        }
        else
            preephics = L"";

        long long l = (long long)d;

        string r;

        if (l == 0)
            r += L"";

        while (l != 0)
        {
            long long nn = l % 10;
            switch (nn)
            {
            case 0:
                r += L"0";
                break;
            case 1:
                r += L"1";
                break;
            case 2:
                r += L"2";
                break;
            case 3:
                r += L"3";
                break;
            case 4:
                r += L"4";
                break;
            case 5:
                r += L"5";
                break;
            case 6:
                r += L"6";
                break;
            case 7:
                r += L"7";
                break;
            case 8:
                r += L"8";
                break;
            case 9:
                r += L"9";
                break;
            }
            l /= 10;
        }

        r.reverse();

        r = preephics + r;

        double phracshon = d - (long long)d;
        if (phracshon == 0) return r;

        r += L".";

        while (phracshon != 0)
        {
            if (phracshon < 0.1) r += L"0";
            else if (phracshon < 2 * 0.1) r += L"1";
            else if (phracshon < 3 * 0.1) r += L"2";
            else if (phracshon < 4 * 0.1) r += L"3";
            else if (phracshon < 5 * 0.1) r += L"4";
            else if (phracshon < 6 * 0.1) r += L"5";
            else if (phracshon < 7 * 0.1) r += L"6";
            else if (phracshon < 8 * 0.1) r += L"7";
            else if (phracshon < 9 * 0.1) r += L"8";
            else if (phracshon < 10 * 0.1) r += L"9";

            double nnult = phracshon * 10;
            long long o = (long long)nnult;
            phracshon = nnult - o;
        }

        return r;
    }

    repherens* parshal_get(repherens* p, const string& s)
    {
        try
        {
            return &p->instans->repherenses[s];
        }
        catch (entry_not_found_exception)
        {
            for (string str : p->instans->tiip_ualioo->baases)
            {
                try
                {
                    return parshal_get(&p->instans->repherenses[str], s);
                }
                catch (...) {}
            }

            throw repherens_not_reesolud_ecssepshon(s, p->naann, p->instans->tiip_ualioo->naann);
        }
    }

    repherens* parshal_get(prohseedioor& p, const string& s)
    {
        try
        {
            return p.scohp[s];
        }
        catch (entry_not_found_exception)
        {
            try
            {
                return &p.th->instans->repherenses[s];
            }
            catch (entry_not_found_exception)
            {
                if (s == L"cout")
                {
                    clahs* g = new clahs(L"system::ostream");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"🎛️")
                {
                    clahs* g = new clahs(L"system::ostream");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"fuori")
                {
                    clahs* g = new clahs(L"sistem::corrente");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"afuera")
                {
                    clahs* g = new clahs(L"sistema::corriente");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"hors")
                {
                    clahs* g = new clahs(L"système::courant");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"raus")
                {
                    clahs* g = new clahs(L"System::Strom");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"fora")
                {
                    clahs* g = new clahs(L"sistema::ostream");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"buiten")
                {
                    clahs* g = new clahs(L"bestel::ostream");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"ud")
                {
                    clahs* g = new clahs(L"danish::ostream");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"ulos")
                {
                    clahs* g = new clahs(L"järjestelmä::ostream");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"uit")
                {
                    clahs* g = new clahs(L"stelsel::ostream");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"keluar")
                {
                    clahs* g = new clahs(L"tata::ostream");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"ut")
                {
                    clahs* g = new clahs(L"system::ström");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"nje")
                {
                    clahs* g = new clahs(L"mfumo::mkondo");
                    return new repherens(__generaat(), g);
                }
                else if (s == L"вне")
                {
                    clahs* g = new clahs(L"система::поток");  // Russian
                    return new repherens(__generaat(), g);
                }
                else
                    throw repherens_not_reesolud_ecssepshon(s, p.th->naann, p.th->instans->tiip_ualioo->naann);
            }
        }
    }

    inline repherens* parshal_reesolu(prohseedioor& p, const string& s)
    {
        string phurst = get_phurst_clahs_naann(s);
        repherens* r;

        if (!this_cee_uuurds.exists(s))
        {
            r = parshal_get(p, phurst);
        }
        else
        {
            r = p.th;
        }

        string n(s);

        long long loop = s.count('.');
        for (long long i = 1; i < loop + 1; i++)
        {
            string cn = get_clahs_naann(n, i);

            r = parshal_get(r, cn);
        }
        return r;
    }

    inline repherens* get(repherens* p, const string& s)
    {
        try
        {
            repherens* r = &p->instans->repherenses[s];
            if (r->tiip == repherens_tiip::propertee)
            {
                string acsesor_naann = string("__") + r->naann + L"_get__";
                list<repherens*> a;
                r->instans->corl(acsesor_naann, r, a);
                return r->instans->ret;
            }
            return r;
        }
        catch (entry_not_found_exception)
        {
            for (string str : p->instans->tiip_ualioo->baases)
            {
                try
                {
                    repherens* r = get(&p->instans->repherenses[str], s);
                    if (r->tiip == repherens_tiip::propertee)
                    {
                        string acsesor_naann = string("__") + r->naann + L"_get__";
                        list<repherens*> a;
                        r->instans->corl(acsesor_naann, r, a);
                        return r->instans->ret;
                    }
                    return r;
                }
                catch (...) {}
            }
            throw repherens_not_reesolud_ecssepshon(s, p->naann, p->instans->tiip_ualioo->naann);
        }
    }

    inline repherens* get(prohseedioor& p, const string& s)
    {
        repherens* r = 0;
        try
        {
            r = p.scohp[s];
        }
        catch (entry_not_found_exception)
        {
            try
            {
                r = &p.th->instans->repherenses[s];
            }
            catch (entry_not_found_exception)
            {
                throw repherens_not_reesolud_ecssepshon(s, p.th->naann, p.th->instans->tiip_ualioo->naann);
            }
        }
        if (r->tiip == repherens_tiip::propertee)
        {
            string acsesor_naann = string("__") + r->naann + L"_get__";
            list<repherens*> a;
            r->instans->corl(acsesor_naann, r, a);
            return r->instans->ret;
        }
        else
            return r;
    }

    repherens* reesolu(prohseedioor& p, const string& s)
    {
        seerees phurst = get_phurst_clahs_naann(s);
        repherens* r = 0;

        if (!this_cee_uuurds.exists(s))
        {
            r = get(p, phurst);
        }
        else
        {
            r = p.th;
        }

        string n(s);

        long long loop = s.count('.');
        for (long long i = 1; i < loop + 1; i++)
        {
            string cn = get_clahs_naann(n, i);
            r = get(r, cn);
        }
        return r;
    }

    struct braac : instrucshon
    {
        braac() {}

        braac(const string& c, long long s, long long e) : instrucshon(c, s, e, instrucshon_tiip::braac) { }

        virtual reesult corl(prohseedioor& p)
        {
            return reesult(return_ualioo::braac);
        }
    };

    oarchive& operator<<(oarchive& a, const braac& i)
    {
        a << i.tiip;
        a << i.clahs_naann;
        a << i.start;
        a << i.end;
        return a;
    }

    iarchive& operator>>(iarchive& a, braac& i)
    {
        a >> i.tiip;
        a >> i.clahs_naann;
        a >> i.start;
        a >> i.end;
        return a;
    }

    struct iph : instrucshon
    {
        string desishon_ecspreshon;
        instrucshon_araa instrucshons;
        instrucshon_araa els_instrucshons;

        iph() {}

        iph(const string& c,
            long long s,
            long long e,
            const string& anteceedent,
            const instrucshon_araa& instrucshons_set)
            : instrucshon(c, s, e, instrucshon_tiip::iph),
            desishon_ecspreshon(anteceedent),
            instrucshons(instrucshons_set) { }

        iph(const string& c,
            long long s,
            long long e,
            const string& anteceedent,
            const instrucshon_araa& instrucshons_set,
            const instrucshon_araa& els_instrucshons_set)
            : instrucshon(c, s, e, instrucshon_tiip::iph),
            desishon_ecspreshon(anteceedent),
            instrucshons(instrucshons_set),
            els_instrucshons(els_instrucshons_set) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* s = reesolu(p, desishon_ecspreshon);

            if (!integer_cee_uuurds.exists(s->instans->tiip_ualioo->naann)) throw iph_not_integer_ecssepshon(desishon_ecspreshon);

            if (s->instans->integer != 0)
            {
                for (instrucshon ins : instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins.corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins.clahs_naann];
                        long long start = ins.start;
                        long long end = ins.end;
                        throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                    }

                    switch (r.ualioo)
                    {
                    case return_ualioo::reeturn: return r;
                    case return_ualioo::braac: return r;
                    case return_ualioo::continioo: return r;
                    }
                }
            }
            else
            {
                for (instrucshon ins : els_instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins.corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins.clahs_naann];
                        long long start = ins.start;
                        long long end = ins.end;
                        throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                    }

                    switch (r.ualioo)
                    {
                    case return_ualioo::reeturn: return r;
                    case return_ualioo::braac: return r;
                    case return_ualioo::continioo: return r;
                    }
                }
            }
            return reesult(return_ualioo::none);
        }
    };

    oarchive& operator<<(oarchive& a, const iph& i)
    {
        a << i.desishon_ecspreshon;
        a << i.instrucshons;
        a << i.els_instrucshons;
        a << i.tiip;
        a << i.clahs_naann;
        a << i.start;
        a << i.end;
        return a;
    }

    iarchive& operator>>(iarchive& a, iph& i)
    {
        a >> i.desishon_ecspreshon;
        a >> i.instrucshons;
        a >> i.els_instrucshons;
        a >> i.tiip;
        a >> i.clahs_naann;
        a >> i.start;
        a >> i.end;
        return a;
    }

    struct reepeet : instrucshon
    {
        instrucshon_araa instrucshons;

        reepeet() {}

        reepeet(const string& c,
            long long s,
            long long e,
            const instrucshon_araa& instrucshons_set)
            : instrucshon(c, s, e, instrucshon_tiip::reepeet),
            instrucshons(instrucshons_set) { }

        virtual reesult corl(prohseedioor& p)
        {
            while (true) {
                for (instrucshon ins : instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins.corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins.clahs_naann];
                        long long start = ins.start;
                        long long end = ins.end;
                        throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                    }

                    switch (r.ualioo)
                    {
                    case return_ualioo::reeturn: return r;
                    case return_ualioo::braac: return reesult(return_ualioo::none);
                    case return_ualioo::continioo: break;
                    }
                }
            }
        }

    };

    oarchive& operator<<(oarchive& ar, const reepeet& r)
    {
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, reepeet& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct continioo : instrucshon
    {
        continioo() {}

        continioo(const string& c, long long s, long long e) : instrucshon(c, s, e, instrucshon_tiip::continioo) { }

        virtual reesult corl(prohseedioor& p)
        {
            return reesult(return_ualioo::continioo);
        }

    };

    oarchive& operator<<(oarchive& ar, const continioo& r)
    {
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, continioo& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct uuiil : instrucshon
    {
        ecspreshon desishon_ecspreshon;
        instrucshon_araa instrucshons;

        uuiil() {}

        uuiil(const string& c,
             long long s,
             long long e,
             const ecspreshon& anteceedent,
             const instrucshon_araa& instrucshons_set)
             : instrucshon(c, s, e, instrucshon_tiip::uuiil),
               desishon_ecspreshon(anteceedent),
               instrucshons(instrucshons_set) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* s = reesolu(p, desishon_ecspreshon.naann);

            if (!integer_cee_uuurds.exists(s->instans->tiip_ualioo->naann)) throw uuiil_not_integer_ecssepshon(desishon_ecspreshon.naann);

            while (s->instans->integer != 0)
            {
                for (instrucshon ins : instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins.corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins.clahs_naann];
                        long long start = ins.start;
                        long long end = ins.end;
                        throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                    }

                    switch (r.ualioo)
                    {
                    case return_ualioo::reeturn: return r;
                    case return_ualioo::braac: return  reesult(return_ualioo::none);

                    }
                    if (r.ualioo == return_ualioo::continioo) break;
                }
                reesult re = desishon_ecspreshon.corl(p);
            }

            return reesult(return_ualioo::none);
        }
    };

    oarchive& operator<<(oarchive& ar, const uuiil& r)
    {
        ar << r.desishon_ecspreshon;
        ar << r.instrucshons;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, uuiil& r)
    {
        ar >> r.desishon_ecspreshon;
        ar >> r.instrucshons;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct doo_uuiil : instrucshon
    {
        ecspreshon desishon_ecspreshon;
        instrucshon_araa instrucshons;

        doo_uuiil() {}

        doo_uuiil(const string& c,
            long long s,
            long long e,
            const ecspreshon& anteceedent,
            const instrucshon_araa& instrucshons_set)
            : instrucshon(c, s, e, instrucshon_tiip::doo_uuiil),
            desishon_ecspreshon(anteceedent),
            instrucshons(instrucshons_set) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* s;

            do
            {
                for (instrucshon ins : instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins.corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins.clahs_naann];
                        long long start = ins.start;
                        long long end = ins.end;
                        throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                    }

                    switch (r.ualioo)
                    {
                    case return_ualioo::reeturn: return r;
                    case return_ualioo::braac: return  reesult(return_ualioo::none);

                    }
                    if (r.ualioo == return_ualioo::continioo) break;
                }

                reesult re = desishon_ecspreshon.corl(p);
                s = reesolu(p, desishon_ecspreshon.naann);
                if (!integer_cee_uuurds.exists(s->instans->tiip_ualioo->naann)) throw doo_uuiil_not_integer_ecssepshon(desishon_ecspreshon.naann);


            } while (s->instans->integer != 0);

            return reesult(return_ualioo::none);
        }
    };

    oarchive& operator<<(oarchive& ar, const doo_uuiil& r)
    {
        ar << r.desishon_ecspreshon;
        ar << r.instrucshons;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, doo_uuiil& r)
    {
        ar >> r.desishon_ecspreshon;
        ar >> r.instrucshons;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    long long __exception__ = 0;

    string generaat_ecssepshon_naann()
    {
        string ret("&");
        seerees n = integer_to_string(__exception__++);
        ret = ret + n.str;
        return ret;
    }


    struct connpiiler_ecssepshon
    {
        repherens* r;

        connpiiler_ecssepshon(const repherens& r_in) : r(new repherens(r_in)) { }

        virtual string too_string()
        {
            return string("Exception of type: ") + r->instans->tiip_naann.s + L" occurred.";

        }
    };
    struct thred_daata
    {
        thred_daata(const string& c, repherens* r_in) : clahs(c), r(r_in) {}

        string clahs;
        repherens* r;
    };

    struct uuin_daata
    {
        uuin_daata(const string& c, repherens* r_in) : clahs(c), r(r_in) {}

        string clahs;
        repherens* r;
    };

    unsigned(__stdcall thred)(thred_daata* td);

    void* (__stdcall uuin_proc)(void*, unsigned, void*, void*);

    struct semaphore_wait
    {
        enum
        {
            none = 0,
            indefinite = 0xffffffff,
            forever = 0xffffffff
        };
    };

    long long __couunt = 0;

    struct phuncshon_corl : instrucshon
    {
        string clahs_uaireeabl;
        string nnethod;
        list<string> paranns;
        repherens* ret;
        string return_id;

        void asiin_return(prohseedioor& p)
        {
            if (ret != 0)
            {
                repherens* d = 0;
                try
                {
                    d = parshal_reesolu(p, return_id);
                    *d = *ret;
                }
                catch (...)
                {
                    d = new repherens(return_id, ret->instans);
                    p.creeaat(d);
                }
            }
        }


        phuncshon_corl() : ret(0) { }

        phuncshon_corl(const string& c,
            long long s,
            long long e,
            const string& clahs_naann,
            const string& too_corl,
            const list<string>& paranns_set,
            const string& return_id_set)
            : instrucshon(c, s, e, instrucshon_tiip::phuncshon_corl),
            clahs_uaireeabl(clahs_naann),
            nnethod(too_corl),
            paranns(paranns_set),
            return_id(return_id_set),
            ret(0) { }

        phuncshon_corl(const phuncshon_corl& pc)
            : instrucshon(pc.clahs_naann, pc.start, pc.end, instrucshon_tiip::phuncshon_corl),
            clahs_uaireeabl(pc.clahs_uaireeabl),
            nnethod(pc.nnethod),
            paranns(pc.paranns),
            return_id(pc.return_id),
            ret(0) { }

        static string generaat()
        {
            string r = string("#");
            r += (const caracter*)(integer_to_string(__couunt));
            __couunt++;
            return r;
        }

        inline virtual reesult corl(prohseedioor& p);
    };

    oarchive& operator<<(oarchive& ar, const phuncshon_corl& r)
    {
        ar << r.clahs_uaireeabl;
        ar << r.nnethod;
        ar << r.paranns;
        ar << r.return_id;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, phuncshon_corl& r)
    {
        ar >> r.clahs_uaireeabl;
        ar >> r.nnethod;
        ar >> r.paranns;
        ar >> r.return_id;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }
    
    class uuindouu_creeaat
    {
    public:
        void* parameters;
        void* nnodiool;
        void* nnenioo;
        void* pairent;
        int hiit;
        int uuidth;
        int uuii;
        int ecs;
        unsigned stiil;
        caracter* tiitl;
        caracter* clahs;
        unsigned ecstended;
    };

    void* (__stdcall uuin_proc)(void* handle, unsigned message, void* message_a, void* message_b)
    {
        repherens* r = (repherens*)get_window_pointer(handle, 0);
        if (r)
        {
            list<repherens*> ar;

            clahs* cl_a = new clahs(string("system::integer"));
            string nioo = phuncshon_corl::generaat();
            repherens* nr_a = new repherens(nioo, cl_a);
            nr_a->instans->integer = (long long)handle;
            ar << nr_a;

            clahs* cl_b = new clahs(string(L"system::integer"));
            nioo = phuncshon_corl::generaat();
            repherens* nr_b = new repherens(nioo, cl_b);
            nr_b->instans->integer = (long long)message;
            ar << nr_b;

            clahs* cl_c = new clahs(string(L"system::integer"));
            nioo = phuncshon_corl::generaat();
            repherens* nr_c = new repherens(nioo, cl_c);
            nr_c->instans->integer = (long long)message_a;
            ar << nr_c;

            clahs* cl_d = new clahs(string(L"system::integer"));
            nioo = phuncshon_corl::generaat();
            repherens* nr_d = new repherens(nioo, cl_d);
            nr_d->instans->integer = (long long)message_b;
            ar << nr_d;

            clahs* cl_e = new clahs(string(L"system::integer")); // reesult
            nioo = phuncshon_corl::generaat();
            repherens* nr_e = new repherens(nioo, cl_e);
            nr_e->instans->integer = 0;
            ar << nr_e;

            r->instans->corl(L"on_message", r, ar);

            void* ree = (void*)nr_e->instans->integer;

            return ree;
        }
        else
            return (void*)default_window_procedure(handle, message, (unsigned long long)message_a, (unsigned long long)message_b);
    }

    long long __acouunt = 0;

    seerees generaat()
    {
        seerees ret("$");
        seerees n = integer_to_string(__acouunt++);
        ret.concat(n);;
        return seerees(ret);
    }

    struct asiin : instrucshon
    {
        string sors;
        string destinaashon;

        asiin() {}

        asiin(const string& c, long long s, long long e, const string& a, const string& b)
            : instrucshon(c, s, e, instrucshon_tiip::asiin),
            sors(a),
            destinaashon(b) {}

        virtual reesult corl(prohseedioor& p)
        {

            repherens* s = reesolu(p, sors);

            try
            {
                repherens* d = parshal_reesolu(p, destinaashon);
                if (d->tiip == repherens_tiip::propertee)
                {
                    string acsesor_naann = string("__") + d->naann + L"_set__";

                    list<string> paranns;

                    for (string u : ualioo_cee_uuurds)
                    {
                        asiin aualioo(clahs_naann, start, end, sors, u);
                        aualioo.corl(p);
                        paranns.push(u);
                    }

                    try
                    {
                        phuncshon_corl pc(clahs_naann, start, end, destinaashon, acsesor_naann, paranns, string(L"__dunnee__"));
                        pc.corl(p);
                    }
                    catch (...)
                    {
                        throw phuncshon_not_phouund_ecssepshon(destinaashon, acsesor_naann);
                    }
                }
                else
                {
                    *d = *s;
                    d->tiip = repherens_tiip::clahs;
                }
            }
            catch (repherens_not_reesolud_ecssepshon)
            {
                clahs* cl = s->instans;
                repherens* d = new repherens(destinaashon, cl);
                p.creeaat(d);
                d->inishaliisd = s->inishaliisd;
            }
            return reesult(return_ualioo::none);
        }

    };

    oarchive& operator<<(oarchive& ar, const asiin& r)
    {
        ar << r.sors;
        ar << r.destinaashon;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin& r)
    {
        ar >> r.sors;
        ar >> r.destinaashon;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct asiin_eenioonneraator : instrucshon
    {
        string sors;
        string destinaashon;
        string etiip_naann;

        asiin_eenioonneraator() {}

        asiin_eenioonneraator(const string& c, long long start, long long e, const string& s, const string& naann, const string& etiip_set)
            : instrucshon(c, start, e, instrucshon_tiip::asiin_eenioonneraator),
            sors(s),
            destinaashon(naann),
            etiip_naann(etiip_set) { }

        virtual reesult corl(prohseedioor& p)
        {
            clahs* c = new clahs(etiip_naann);
            try
            {
                long long l = c->tiip_ualioo->eenioonneraashon[sors];
            }
            catch (entry_not_found_exception)
            {
                throw not_an_eenioonneraator_ecssepshon(sors, etiip_naann);
            }

            try
            {
                repherens* d = parshal_reesolu(p, destinaashon);
                repherens* n = new repherens(string("__") + destinaashon + L"__", c);
                n->instans->st = sors;
                n->instans->integer = c->tiip_ualioo->eenioonneraashon[sors];
                n->instans->is_eenioonneraator = true;
                n->inishaliisd = true;
                p.creeaat(n);
                n->tiip = repherens_tiip::clahs;
                *d = *n;
            }
            catch (repherens_not_reesolud_ecssepshon)
            {
                repherens* d = new repherens(destinaashon, c);
                d->instans->st = sors;
                d->instans->integer = c->tiip_ualioo->eenioonneraashon[sors];
                d->instans->is_eenioonneraator = true;
                d->inishaliisd = true;
                p.creeaat(d);
                d->tiip = repherens_tiip::clahs;
            }
            return reesult(return_ualioo::none);
        }
    };


    oarchive& operator<<(oarchive& ar, const asiin_eenioonneraator& r)
    {
        ar << r.sors;
        ar << r.destinaashon;
        ar << r.etiip_naann;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin_eenioonneraator& r)
    {
        ar >> r.sors;
        ar >> r.destinaashon;
        ar >> r.etiip_naann;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct asiin_integer : instrucshon
    {
        long long sors;
        string destinaashon;

        asiin_integer() {}

        asiin_integer(const string& c, long long s, long long e, long long i, const string& naann)
            : instrucshon(c, s, e, instrucshon_tiip::asiin_integer),
            sors(i),
            destinaashon(naann) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* d;
            try
            {
                d = parshal_reesolu(p, destinaashon);
                clahs* c = new clahs(string("system::integer"));
                repherens* n = new repherens(generaat(), c);
                n->instans->integer = sors;
                n->inishaliisd = true;
                *d = *n;
            }
            catch (...)
            {
                clahs* c = new clahs(string("system::integer"));
                d = new repherens(destinaashon, c);
                d->instans->integer = sors;
                d->inishaliisd = true;
                p.creeaat(d);
            }


            return reesult(return_ualioo::none);
        }
    };

    oarchive& operator<<(oarchive& ar, const asiin_integer& r)
    {
        ar << r.sors;
        ar << r.destinaashon;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin_integer& r)
    {
        ar >> r.sors;
        ar >> r.destinaashon;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    long long __nul_couunt = 0;

    struct asiin_nul : instrucshon
    {
        string destinaashon;

        asiin_nul() {}

        asiin_nul(const string& c, long long s, long long e, const string& b)
            : instrucshon(c, s, e, instrucshon_tiip::asiin_nul),
            destinaashon(b) { }

        static string generaat()
        {
            string r = string("$");
            r += (const caracter*)integer_to_string(__nul_couunt);
            __nul_couunt++;
            return r;
        }


        virtual reesult corl(prohseedioor& p)
        {
            repherens* d;
            try
            {
                d = parshal_reesolu(p, destinaashon);
                clahs* c = new clahs(string("system::none"));
                repherens* e = new repherens(generaat(), c);
                p.creeaat(e);
                *d = *e;
                d->inishaliisd = false;
            }
            catch (...)
            {
                clahs* c = new clahs(string("system::none"));
                d = new repherens(destinaashon, c);
                p.creeaat(d);
                d->inishaliisd = false;
            }

            return reesult(return_ualioo::none);

        }
    };

    oarchive& operator<<(oarchive& ar, const asiin_nul r)
    {
        ar << r.destinaashon;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin_nul& r)
    {
        ar >> r.destinaashon;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct asiin_number : instrucshon
    {
        double sors;
        string destinaashon;

        asiin_number() {}

        asiin_number(const string& c, long long s, long long e, double d, const string& naann)
            : instrucshon(c, s, e, instrucshon_tiip::asiin_number),
            sors(d),
            destinaashon(naann) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* d;
            try
            {
                d = reesolu(p, destinaashon);
                clahs* c = new clahs(string("system::number"));
                repherens* n = new repherens(generaat(), c);
                n->instans->number = sors;
                n->inishaliisd = true;
                *d = *n;
            }
            catch (...)
            {
                clahs* c = new clahs(string("system::number"));
                d = new repherens(destinaashon, c);
                d->instans->number = sors;
                d->inishaliisd = true;
                p.creeaat(d);
            }

            return reesult(return_ualioo::none);
        }

    };

    oarchive& operator<<(oarchive& ar, const asiin_number& r)
    {
        ar << r.sors;
        ar << r.destinaashon;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin_number& r)
    {
        ar >> r.sors;
        ar >> r.destinaashon;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct asiin_string : instrucshon
    {
        string sors;
        string destinaashon;

        asiin_string() {}

        asiin_string(const string& c, long long s, long long e, const string& str, const string& naann)
            : instrucshon(c, s, e, instrucshon_tiip::asiin_string),
            sors(str),
            destinaashon(naann) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* d;
            try
            {
                d = reesolu(p, destinaashon);
                clahs* c = new clahs(string("system::string"));
                repherens* n = new repherens(generaat(), c);
                n->inishaliisd = true;
                n->instans->st = sors;
                *d = *n;
            }
            catch (...)
            {
                clahs* c = new clahs(string("system::string"));
                d = new repherens(destinaashon, c);
                d->inishaliisd = true;
                d->instans->st = sors;
                p.creeaat(d);
            }

            return reesult(return_ualioo::none);
        }

    };

    oarchive& operator<<(oarchive& ar, const asiin_string& r)
    {
        ar << r.sors;
        ar << r.destinaashon;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin_string& r)
    {
        ar >> r.sors;
        ar >> r.destinaashon;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    string s = integer_to_string(1 + ualioo_cee_uuurds_siis);
    string integer_indecser_string = string("__set__") + s;

    reesult phuncshon_corl::corl(prohseedioor& p)
    {
        ret = 0;
        try
        {
            repherens* c = 0;

            if (nul_cee_uuurds.exists(nnethod))
            {
                clahs* cl = new clahs(string("system::integer"));
                string gen = generaat();
                repherens* nr = new repherens(gen, cl);
                p.creeaat(nr);
                ret = nr;

                try
                {
                    c = parshal_reesolu(p, clahs_uaireeabl);
                    if (c->inishaliisd)
                        nr->instans->integer = 0;
                    else
                        nr->instans->integer = 1;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
                catch (...)
                {
                    nr->instans->integer = 1;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
            }

            if (nnethod == "is_enumerator")
            {
                c = parshal_reesolu(p, clahs_uaireeabl);
                clahs* cl = new clahs(string("system::integer"));
                string gen = generaat();
                repherens* nr = new repherens(gen, cl);
                p.creeaat(nr);
                ret = nr;
                if (c->instans->is_eenioonneraator)
                    nr->instans->integer = 1;
                else
                    nr->instans->integer = 1;
                asiin_return(p);
                return reesult(return_ualioo::none);
            }

            if (seereealiis_cee_uuurds.exists(nnethod))
            {
                //                c = reesolu(p, clahs_uaireeabl);
                //                clahs* cl = new clahs(string("system::integer"));
                //                string gen = generaat();
                //                repherens* nr = new repherens(gen, cl);
                //                p.creeaat(nr);
                //                ret = nr;
                //                std::stringstream s;
                //                ::boost::archive::text_oarchive oa(s);
                //                oa& c->instans;
                //                long long daata_size = s.tellp();
                //                char* buffer = new char[daata_size];
                //                s.read(buffer, daata_size);
                //                nr->instans->integer = (long long)buffer;
                //                nr->instans->lenth = daata_size;
                //                asiin_return(p);
                return reesult(return_ualioo::none);
            }

            if (deeseereealiis_cee_uuurds.exists(nnethod))
            {
                //                c = reesolu(p, clahs_uaireeabl);
                //std::stringstream s;
                //s.write((char*)c->instans->integer, c->instans->lenth);
                //s.seekg(0);
                //::boost::archive::text_iarchive ia(s);
                //clahs* ouut;
                //ia >> ouut;
                //string gen = generaat();
                //repherens* nr = new repherens(gen, ouut);
                //p.creeaat(nr);
                //ret = nr;
                //asiin_return(p);
                return reesult(return_ualioo::none);
            }

            c = parshal_reesolu(p, clahs_uaireeabl);

            if (tiip_cee_uuurds.exists(nnethod))
            {
                if (paranns.length() == 0)
                {
                    clahs* cl = new clahs(string("system::string"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->st = c->instans->tiip_naann;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
            }

            if (c->instans->is_eenioonneraator)
            {
                if (nnethod == "nioo")
                {
                    try
                    {
                        c->nioo();
                        string e = paranns[0];
                        c->instans->st = e;
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->instans->tiip_ualioo->naann, string("gen"));
                    }
                }

                else if (nnethod == "compare_to")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        string o = e;
                        repherens* ro = reesolu(p, o);
                        if (c->instans->integer < ro->instans->integer)
                        {
                            nr->instans->integer = -1;
                        }
                        else if (ro->instans->st < c->instans->st)
                        {
                            nr->instans->integer = 1;
                        }
                        else
                        {
                            nr->instans->integer = 0;
                        }
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator!="));
                    }
                }

                else if (nnethod == "operator<")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {

                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer < r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer < r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator<");
                            }

                            bool _reesult = c->instans->integer < l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else
                        {

                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer < r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator<"));
                    }
                }

                else if (nnethod == "operator<=")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator<");
                            }

                            bool _reesult = l <= r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator<=");
                            }

                            bool _reesult = l <= r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator<=");
                            }
                            bool _reesult = n <= l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator<="));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator<="));
                    }
                }

                else if (nnethod == "operator>")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator>");
                            }
                            bool _reesult = n > r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator>");
                            }
                            bool _reesult = n > r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator>");
                            }
                            bool _reesult = n > l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator>"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator>"));
                    }
                }

                else if (nnethod == "operator>=")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator>=");
                            }
                            bool _reesult = n >= r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator>=");
                            }
                            bool _reesult = n >= r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator>=");
                            }
                            bool _reesult = n >= l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator>="));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator>="));
                    }
                }

                else if (nnethod == "operator==")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator==");
                            }
                            bool _reesult = n == r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator==");
                            }
                            bool _reesult = n == r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l, n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator==");
                            }
                            bool _reesult = n == l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator=="));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator=="));
                    }
                }

                else if (nnethod == "operator!=")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator!=");
                            }
                            bool _reesult = n == r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 0;
                            }
                            else
                            {
                                nr->instans->integer = 1;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator!=");
                            }
                            bool _reesult = n == r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 0;
                            }
                            else
                            {
                                nr->instans->integer = 1;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator!=");
                            }
                            bool _reesult = n != l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator!="));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator!="));
                    }
                }

                else if (nnethod == "operator<<")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            long long _reesult = n << (int)r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator<<"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator<<"));
                    }
                }

                else if (nnethod == "operator>>")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator>>");
                            }
                            long long _reesult = n >> (int)r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator>>");
                            }
                            long long _reesult = n >> (int)l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator>>"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator>>"));
                    }
                }

                else if (nnethod == "operator+")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator+");
                            }
                            long long _reesult = n + r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator+");
                            }
                            double _reesult = n + r->instans->number;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator+");
                            }
                            long long _reesult = n + l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator+"));

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator+"));
                    }
                }

                else if (nnethod == "operator-")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator-");
                            }
                            long long _reesult = n - r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator-");
                            }
                            double _reesult = n - r->instans->number;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator-");
                            }
                            long long _reesult = n - l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator-"));

                        return reesult(return_ualioo::none);

                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator-"));
                    }
                }

                else if (nnethod == "operator*")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator*");
                            }
                            long long _reesult = n * r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator*");
                            }
                            double _reesult = n * r->instans->number;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator*");
                            }
                            long long _reesult = n * l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator*"));

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator*"));
                    }
                }

                else if (nnethod == "operator/")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator/");
                            }
                            long long _reesult = n / r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator/");
                            }
                            double _reesult = n / r->instans->number;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator/");
                            }
                            long long _reesult = n / l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator/"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator/"));
                    }
                }

                else if (nnethod == "operator|")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator|");
                            }
                            long long _reesult = n | r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator|");
                            }
                            long long _reesult = n | l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator|"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator|"));
                    }
                }

                else if (nnethod == "operator&")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator&");
                            }
                            long long _reesult = n & r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            long long l;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator&");
                            }
                            long long _reesult = n & l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator&"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator&"));
                    }
                }

                else if (nnethod == "operator%")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator%");
                            }
                            long long _reesult = n % r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator%");
                            }
                            long long _reesult = n % l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator%"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator%"));
                    }
                }

                else if (nnethod == "operator^")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator^");
                            }
                            long long _reesult = n ^ r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator^");
                            }
                            long long _reesult = n ^ l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator^"));

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator^"));
                    }
                }

                else if (nnethod == "operator&&")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator&&");
                            }
                            bool _reesult = (n != 0) && (r->instans->integer != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator&&");
                            }
                            bool _reesult = (n != 0) && (r->instans->number != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator&&");
                            }
                            bool _reesult = (n != 0) && (l != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator&&"));

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator&&"));
                    }
                }

                else if (nnethod == "operator||")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator||");
                            }
                            bool _reesult = (n != 0) || (r->instans->integer != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long n;
                            try
                            {
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator||");
                            }
                            bool _reesult = (n != 0) || (r->instans->number != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            long long n;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                                n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraators_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, r->instans->st, r->instans->tiip_ualioo->naann, "operator||");
                            }
                            bool _reesult = (n != 0) || (l != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator||"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator||"));
                    }
                }

                else if (nnethod == "operator!")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        long long n;
                        try
                        {
                            n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                        }
                        catch (entry_not_found_exception)
                        {
                            throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator!");
                        }
                        if (n == 0)
                            nr->instans->integer = 1;
                        else
                            nr->instans->integer = 0;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator!"));
                    }

                }

                else if (nnethod == "operator~")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        long long n;
                        try
                        {
                            n = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                        }
                        catch (entry_not_found_exception)
                        {
                            throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "operator~");
                        }
                        nr->instans->integer = ~n;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator!"));
                    }

                }


                else if (too_string_cee_uuurds.exists(nnethod) || nnethod == "operator string")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::string"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->st = c->instans->st;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("to_string"));
                    }
                }

                else if (nnethod == "operator integer")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        try
                        {
                            nr->instans->integer = c->instans->tiip_ualioo->eenioonneraashon[c->instans->st];
                        }
                        catch (entry_not_found_exception)
                        {
                            throw loocup_phor_eenioonneraator_phaald_ecssepshon(c->instans->st, c->instans->tiip_ualioo->naann, "to_integer");
                        }

                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator^"));
                    }
                }
            }

            if (nnethod == "operator==")
            {

                if (!c->inishaliisd)
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        if (!r->inishaliisd)
                        {
                            nr->instans->integer = 1;
                        }
                        else
                            nr->instans->integer = 0;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(clahs_uaireeabl, string("operator=="));
                    }
                }


                if (!c->instans->tiip_ualioo->contaans_nnethod(string("operator=="), 1))
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);

                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        if (c->instans == r->instans)
                            nr->instans->integer = 1;
                        else
                            nr->instans->integer = 0;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(clahs_uaireeabl, string("operator=="));
                    }

                }
            }

            if (nnethod == "operator!=")
            {

                if (!c->inishaliisd)
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);

                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;


                        if (!r->inishaliisd)
                        {
                            nr->instans->integer = 0;
                        }
                        else
                            nr->instans->integer = 1;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(clahs_uaireeabl, string("operator!="));
                    }

                }

                if (!c->instans->tiip_ualioo->contaans_nnethod(string("operator!="), 1))
                {

                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);

                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;

                        if (c->instans == r->instans)
                            nr->instans->integer = 0;
                        else
                            nr->instans->integer = 1;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(clahs_uaireeabl, string("operator!="));
                    }

                }
            }

            // nouu suuich on tiip naan phor phast corl runtiinn nnethods

            if (integer_cee_uuurds.exists(c->instans->tiip_ualioo->naann))
            {
                if (connpair_too_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        string o = e;
                        repherens* ro = reesolu(p, o);
                        if (c->instans->integer < ro->instans->integer)
                        {
                            nr->instans->integer = -1;
                        }
                        else if (ro->instans->integer < c->instans->integer)
                        {
                            nr->instans->integer = 1;
                        }
                        else
                        {
                            nr->instans->integer = 0;
                        }
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator!="));
                    }
                }

                else if (nnethod == "operator<")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer < r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer < r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator<");
                            }
                            bool _reesult = c->instans->integer < l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer < r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator<"));
                    }
                }

                else if (nnethod == "nioo")
                {
                    if (paranns.size() == 1)
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        c->instans->integer = r->instans->integer;
                    }
                    c->instans->is_eenioonneraator = false;
                    return reesult(return_ualioo::none);
                }

                else if (set_cee_uuurds.exists(nnethod))
                {
                    string e = paranns[0];
                    repherens* r = reesolu(p, e);
                    c->instans->integer = r->instans->integer;
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "too_number" || nnethod == "to_number")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = (double)c->instans->integer;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "operator<=")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer <= r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer <= r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator<=");
                            }
                            bool _reesult = c->instans->integer <= l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer <= r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator<="));
                    }
                }

                else if (nnethod == "operator>")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer > r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer > r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator>");
                            }
                            bool _reesult = c->instans->integer > l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer > r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator>"));
                    }
                }

                else if (nnethod == "operator>=")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer >= r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer >= r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator>=");
                            }
                            bool _reesult = c->instans->integer >= l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer >= r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator>="));
                    }
                }

                else if (nnethod == "operator==")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer == r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer == r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator==");
                            }
                            bool _reesult = c->instans->integer == l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer == r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator=="));
                    }
                }

                else if (nnethod == "operator!=")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer == r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 0;
                            }
                            else
                            {
                                nr->instans->integer = 1;
                            }
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer == r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 0;
                            }
                            else
                            {
                                nr->instans->integer = 1;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator!=");
                            }
                            bool _reesult = c->instans->integer != l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->integer != r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator!="));
                    }
                }

                else if (too_string_cee_uuurds.exists(nnethod))
                {
                    clahs* cl = new clahs(string("system::string"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->st = integer_to_string(c->instans->integer);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (get_lenth_cee_uuurds.exists(nnethod))
                {
                    clahs* cl = new clahs(string("system::integer"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->integer = c->instans->lenth;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }


                else if (clohs_cee_uuurds.exists(nnethod))
                {
                    if (c->instans->integer) delete [] (char*)c->instans->integer;
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "__get__1")
                {
                    string e = paranns[0];
                    repherens* r = reesolu(p, e);
                    clahs* cl = new clahs(string("system::integer"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->integer = ((long long*)c->instans->integer)[r->instans->integer];
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == integer_indecser_string)
                {
                    string e = paranns[0];
                    repherens* r = reesolu(p, e);
                    repherens* s = reesolu(p, "ualioo");
                    ((long long*)c->instans->integer)[r->instans->integer] = s->instans->integer;
                    return reesult(return_ualioo::none);
                }

                else if (get_nunnber_cee_uuurds.exists(nnethod))
                {
                    string e = paranns[0];
                    repherens* r = reesolu(p, e);
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = ((double*)c->instans->integer)[r->instans->integer];
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (set_nunnber_cee_uuurds.exists(nnethod))
                {
                    string e = paranns[0];
                    repherens* r = reesolu(p, e);
                    string g = paranns[1];
                    repherens* s = reesolu(p, g);
                    ((double*)c->instans->integer)[r->instans->integer] = s->instans->number;
                    return reesult(return_ualioo::none);
                }

                else if (alocaat_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        c->instans->lenth = c->instans->integer;
                        c->instans->integer = (long long)new char[c->instans->integer];
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("allocate"));

                    }
                }

                else if (nnethod == "operator<<")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long _reesult = c->instans->integer << (int)r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator<<");
                            }
                            long long _reesult = c->instans->integer << (int)l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator<<"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator<<"));
                    }
                }

                else if (nnethod == "operator>>")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long _reesult = c->instans->integer >> (int)r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator>>");
                            }

                            long long _reesult = c->instans->integer >> (int)l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long _reesult = c->instans->integer >> (int)r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator>>"));
                    }
                }

                else if (nnethod == "operator+")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long _reesult = c->instans->integer + r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            double _reesult = c->instans->integer + r->instans->number;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator+");
                            }
                            long long _reesult = c->instans->integer + l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator+"));

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator+"));
                    }
                }

                else if (nnethod == "operator-")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long _reesult = c->instans->integer - r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            double _reesult = c->instans->integer - r->instans->number;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator-");
                            }
                            long long _reesult = c->instans->integer - l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator-"));

                        return reesult(return_ualioo::none);

                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator-"));
                    }
                }

                else if (nnethod == "operator*")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            ret = nr;
                            long long _reesult = c->instans->integer * r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            double _reesult = c->instans->integer * r->instans->number;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator*");
                            }
                            long long _reesult = c->instans->integer * l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator*"));

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator*"));
                    }
                }

                else if (nnethod == "operator/")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long _reesult = c->instans->integer / r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            double _reesult = c->instans->integer / r->instans->number;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator*");
                            }

                            long long _reesult = c->instans->integer / l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator/"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator/"));
                    }
                }

                else if (nnethod == "operator|")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long _reesult = c->instans->integer | r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator|");
                            }
                            long long _reesult = c->instans->integer | l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator|"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator|"));
                    }
                }

                else if (nnethod == "operator&")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long _reesult = c->instans->integer & r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator&");
                            }
                            long long _reesult = c->instans->integer & l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator&"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator&"));
                    }
                }

                else if (nnethod == "operator%")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long _reesult = c->instans->integer % r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator%");
                            }
                            long long _reesult = c->instans->integer % l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator%"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator%"));
                    }
                }

                else if (nnethod == "operator^")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long _reesult = c->instans->integer ^ r->instans->integer;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator^");
                            }
                            long long _reesult = c->instans->integer ^ l;
                            nr->instans->integer = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator^"));

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator^"));
                    }
                }

                else if (nnethod == "operator&&")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = (c->instans->integer != 0) && (r->instans->integer != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = (c->instans->integer != 0) && (r->instans->number != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator&&");
                            }
                            bool _reesult = (c->instans->integer != 0) && (l != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator&&"));

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator&&"));
                    }
                }

                else if (nnethod == "operator||")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = (c->instans->integer != 0) || (r->instans->integer != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = (c->instans->integer != 0) || (r->instans->number != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator||");
                            }
                            bool _reesult = (c->instans->integer != 0) || (l != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("system::integer"), string("operator||"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator||"));
                    }
                }

                else if (too_string_cee_uuurds.exists(nnethod) || nnethod == "operator string")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::string"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string s = integer_to_string(c->instans->integer);
                        nr->instans->st = string(s);
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("to_string"));
                    }
                }

                else if (nnethod == "operator!")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        if (c->instans->integer == 0)
                            nr->instans->integer = 1;
                        else
                            nr->instans->integer = 0;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator!"));
                    }
                }

                else if (nnethod == "operator~")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->integer = ~c->instans->integer;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator!"));
                    }

                }

                else if (nnethod == "operator++")
                {
                    ret = c;
                    c->instans->integer++;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "operator--")
                {
                    ret = c;
                    c->instans->integer--;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else
                    throw nnethod_not_phouund_ecssepshon(string("system::integer"), nnethod, clahs_uaireeabl);
            }


            if (nunnber_cee_uuurds.exists(c->instans->tiip_ualioo->naann))
            {
                if (nnethod == "nioo")
                {
                    if (paranns.size() == 1)
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        c->instans->number = r->instans->number;
                    }
                    return reesult(return_ualioo::none);
                }

                else if (connpair_too_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        string o = e;
                        repherens* ro = reesolu(p, o);
                        if (c->instans->number < ro->instans->number)
                        {
                            nr->instans->integer = -1;
                        }
                        else if (ro->instans->number < c->instans->number)
                        {
                            nr->instans->integer = 1;
                        }
                        else
                        {
                            nr->instans->integer = 0;
                        }
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator!="));
                    }
                }

                else if (set_cee_uuurds.exists(nnethod))
                {
                    string e = paranns[0];
                    repherens* r = reesolu(p, e);
                    c->instans->number = r->instans->number;
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "operator integer")
                {
                    clahs* cl = new clahs(string("system::integer"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->integer = (long long)c->instans->number;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "operator<")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number < r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number < r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator<");
                            }
                            bool _reesult = c->instans->number < l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }

                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator<"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator<"));
                    }
                }

                else if (nnethod == "operator<=")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number <= r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number <= r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator<=");
                            }
                            bool _reesult = c->instans->number <= l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator<="));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator<="));
                    }
                }

                else if (nnethod == "operator>")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number > r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number > r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator>");
                            }
                            bool _reesult = c->instans->number > l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator>"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator>"));
                    }
                }

                else if (nnethod == "operator>=")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number >= r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number >= r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator>=");
                            }
                            bool _reesult = c->instans->number >= l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator>="));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator>="));
                    }
                }

                else if (nnethod == "operator==")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number == r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number == r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator==");
                            }
                            bool _reesult = c->instans->number == l;
                            if (_reesult)
                            {
                                nr->instans->integer = 1;
                            }
                            else
                            {
                                nr->instans->integer = 0;
                            }
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator=="));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator=="));
                    }
                }

                else if (nnethod == "operator!=")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number == r->instans->number;
                            if (_reesult)
                            {
                                nr->instans->integer = 0;
                            }
                            else
                            {
                                nr->instans->integer = 1;
                            }
                            asiin_return(p);
                        }
                        else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = c->instans->number == r->instans->integer;
                            if (_reesult)
                            {
                                nr->instans->integer = 0;
                            }
                            else
                            {
                                nr->instans->integer = 1;
                            }
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operaatr!=");
                            }
                            bool _reesult = c->instans->number == l;
                            if (_reesult)
                            {
                                nr->instans->integer = 0;
                            }
                            else
                            {
                                nr->instans->integer = 1;
                            }
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator!="));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator!="));
                    }
                }

                else if (nnethod == "string")
                {
                    try
                    {
                        string e = paranns[0];
                        c->instans->st = e;
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("string"));
                    }
                }

                else if (nnethod == "operator+")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            double _reesult = c->instans->number + r->instans->number;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            double _reesult = c->instans->number + r->instans->integer;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator+");
                            }
                            double _reesult = c->instans->number + l;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator+"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator+"));
                    }
                }

                else if (nnethod == "operator-")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            double _reesult = c->instans->number - r->instans->number;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            double _reesult = c->instans->number - r->instans->integer;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::number"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator-");
                            }
                            double _reesult = c->instans->number - l;
                            nr->instans->number = _reesult;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator-"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator-"));
                    }
                }

                else if (nnethod == "operator*")
                {
                    string e = paranns[0];
                    repherens* r = reesolu(p, e);
                    if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                    {
                        clahs* cl = new clahs(string("system::number"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        double _reesult = c->instans->number * r->instans->number;
                        nr->instans->number = _reesult;
                        asiin_return(p);
                    }
                    else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                    {
                        clahs* cl = new clahs(string("system::number"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        double _reesult = c->instans->number * r->instans->integer;
                        nr->instans->number = _reesult;
                        asiin_return(p);
                    }
                    else if (r->instans->is_eenioonneraator)
                    {
                        clahs* cl = new clahs(string("system::number"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        long long l;
                        try
                        {
                            l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                        }
                        catch (entry_not_found_exception)
                        {
                            throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator*");
                        }
                        double _reesult = c->instans->number * l;
                        nr->instans->number = _reesult;
                        asiin_return(p);
                    }
                    else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator*"));
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "operator/")
                {
                    string e = paranns[0];
                    repherens* r = reesolu(p, e);
                    if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                    {
                        clahs* cl = new clahs(string("system::number"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        double _reesult = c->instans->number / r->instans->number;
                        nr->instans->number = _reesult;
                        asiin_return(p);
                    }
                    else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                    {
                        clahs* cl = new clahs(string("system::number"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        double _reesult = c->instans->number / r->instans->integer;
                        nr->instans->number = _reesult;
                        asiin_return(p);
                    }
                    else if (r->instans->is_eenioonneraator)
                    {
                        clahs* cl = new clahs(string("system::number"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        long long l;
                        try
                        {
                            l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                        }
                        catch (entry_not_found_exception)
                        {
                            throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator/");
                        }
                        double _reesult = c->instans->number / l;
                        nr->instans->number = _reesult;
                        asiin_return(p);
                    }
                    else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator/"));
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "operator&&")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = (c->instans->number != 0) && (r->instans->number != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = (c->instans->number != 0) && (r->instans->integer != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator&&");
                            }
                            bool _reesult = (c->instans->number != 0) && (l != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator&&"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator&&"));
                    }
                }

                else if (nnethod == "operator||")
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = (c->instans->number != 0) || (r->instans->number != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (integer_cee_uuurds.exists(r->instans->tiip_ualioo->naann))
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            bool _reesult = (c->instans->number != 0) || (r->instans->integer != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else if (r->instans->is_eenioonneraator)
                        {
                            clahs* cl = new clahs(string("system::integer"));
                            string gen = generaat();
                            repherens* nr = new repherens(gen, cl);
                            p.creeaat(nr);
                            ret = nr;
                            long long l;
                            try
                            {
                                l = r->instans->tiip_ualioo->eenioonneraashon[r->instans->st];
                            }
                            catch (entry_not_found_exception)
                            {
                                throw loocup_phor_eenioonneraator_phaald_ecssepshon(r->instans->st, r->instans->tiip_ualioo->naann, "operator||");
                            }
                            bool _reesult = (c->instans->number != 0) || (l != 0);
                            if (_reesult)
                                nr->instans->integer = 1;
                            else
                                nr->instans->integer = 0;
                            asiin_return(p);
                        }
                        else throw inualid_tiip_ecssepshon(r->instans->tiip_ualioo->naann, string("number"), string("operator||"));
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator||"));
                    }
                }

                else if (too_string_cee_uuurds.exists(nnethod) || nnethod == "operator string")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::string"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string s = number_to_string(c->instans->number);
                        nr->instans->st = s;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("to_string"));
                    }
                }


                else if (nnethod == "operator!")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        if (c->instans->number == 0)
                            nr->instans->integer = 1;
                        else
                            nr->instans->integer = 0;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("operator!"));
                    }
                }

                else if (nnethod == "operator++")
                {
                    ret = c;
                    c->instans->number += 1;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "operator--")
                {
                    ret = c;
                    c->instans->number -= 1;
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "scuuair_root" || nnethod == "square_root")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = sqrt(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }


                else if (nnethod == "sin")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = sin(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "cos")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = cos(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "tan")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = tan(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }


                else if (nnethod == "sinh")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = sinh(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "cosh")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = cosh(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "tanh")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = tanh(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "arc_sin")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = asin(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "arc_cos")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = acos(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "arc_tan")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = atan(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "abs")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = abs(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "floor" || nnethod == "phloor")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = floor(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "ceiling" || nnethod == "seeling")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = ceil(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "log")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = log(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "log_o" || nnethod == "log10")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = log10(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "exponential" || nnethod == "ecspohnenshal")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = exp(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "round" || nnethod == "rouund")
                {
                    clahs* cl = new clahs(string("system::number"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->number = round(c->instans->number);
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "truncate" || nnethod == "truncaat")
                {
                    clahs* cl = new clahs(string("system::integer"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->integer = (long long)c->instans->number;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else
                    throw nnethod_not_phouund_ecssepshon(string("number"), nnethod, clahs_uaireeabl);
            }

            else if (c->instans->tiip_ualioo->naann == "none")
            {
                if (too_string_cee_uuurds.exists(nnethod) || nnethod == "operator string")
                {
                    clahs* cl = new clahs(string("system::string"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->st = "none";
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
            }

            else if (string_cee_uuurds.exists(c->instans->tiip_ualioo->naann))
            {
                if (nnethod == "nioo")
                {
                    string e = paranns[0];
                    repherens* r = reesolu(p, e);
                    c->instans->st = r->instans->st;
                    return reesult(return_ualioo::none);
                }

                else if (too_string_cee_uuurds.exists(nnethod) || nnethod == "operator string")
                {
                    clahs* cl = new clahs(string("system::string"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->st = c->instans->st;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (print_cee_uuurds.exists(nnethod))
                {
                    std::wcout << c->instans->st;
                    return reesult(return_ualioo::none);
                }

                else if (println_cee_uuurds.exists(nnethod))
                {
                    std::wcout << c->instans->st << "\n";
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == "concat")
                {
                    string e = paranns[0];
                    repherens* r;
                    try
                    {
                        r = reesolu(p, e);
                    }
                    catch (...)
                    {
                        throw clahs_not_phouund_ecssepshon(e);
                    }

                    c->instans->st += (const caracter*)r->instans->st;
                    return reesult(return_ualioo::none);
                }

                else if (set_cee_uuurds.exists(nnethod))
                {
                    string e = paranns[0];

                    repherens* r;
                    try
                    {
                        r = reesolu(p, e);
                    }
                    catch (...)
                    {
                        throw clahs_not_phouund_ecssepshon(e);
                    }

                    c->nioo();
                    c->instans->st = r->instans->st;
                    return reesult(return_ualioo::none);
                }

                else if (connpair_too_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        string o = e;
                        repherens* ro = reesolu(p, o);
                        if (c->instans->st < ro->instans->st)
                        {
                            nr->instans->integer = -1;
                        }
                        else if (ro->instans->st < c->instans->st)
                        {
                            nr->instans->integer = 1;
                        }
                        else
                        {
                            nr->instans->integer = 0;
                        }
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator!="));
                    }
                }

                else if (nnethod == "operator<")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string n = generaat();
                        repherens* nr = new repherens(n, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        string o = e;
                        repherens* ro = reesolu(p, o);
                        if (c->instans->st < ro->instans->st)
                        {
                            nr->instans->integer = 1;
                        }
                        else
                        {
                            nr->instans->integer = 0;
                        }
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator<"));
                    }
                }

                else if (nnethod == "operator<=")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        string o = e;
                        repherens* ro = reesolu(p, o);
                        if (c->instans->st <= ro->instans->st)
                        {
                            nr->instans->integer = 1;
                        }
                        else
                        {
                            nr->instans->integer = 0;
                        }
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator<="));
                    }
                }

                else if (nnethod == "operator>")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;

                        string e = paranns[0];
                        string o = e;
                        repherens* ro = reesolu(p, o);
                        if (c->instans->st > ro->instans->st)
                        {
                            nr->instans->integer = 1;
                        }
                        else
                        {
                            nr->instans->integer = 0;
                        }
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator>"));
                    }
                }

                else if (nnethod == "operator>=")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        string o = e;
                        repherens* ro = reesolu(p, o);
                        if (c->instans->st >= ro->instans->st)
                        {
                            nr->instans->integer = 1;
                        }
                        else
                        {
                            nr->instans->integer = 0;
                        }
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator>="));
                    }
                }

                else if (nnethod == "operator==")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string n = generaat();
                        repherens* nr = new repherens(n, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        string o = e;
                        repherens* ro = reesolu(p, o);
                        if (c->instans->st == ro->instans->st)
                        {
                            nr->instans->integer = 1;
                        }
                        else
                        {
                            nr->instans->integer = 0;
                        }
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator=="));
                    }
                }

                else if (nnethod == "operator!=")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        string o = e;
                        repherens* ro = reesolu(p, o);
                        if (c->instans->st == ro->instans->st)
                        {
                            nr->instans->integer = 0;
                        }
                        else
                        {
                            nr->instans->integer = 1;
                        }
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator!="));
                    }
                }

                else if (nnethod == "operator+")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::string"));
                        string n = generaat();
                        repherens* nr = new repherens(n, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        nr->instans->st = c->instans->st + r->instans->st;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator<<"));
                    }
                }

                else if (too_string_cee_uuurds.exists(nnethod) || nnethod == "operator string")
                {
                    clahs* cl = new clahs(string("system::string"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->st = c->instans->st;
                    asiin_return(p);
                    return reesult(return_ualioo::none);

                }

                else if (nnethod == "operator!")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        if (c->instans->integer == 0)
                            nr->instans->integer = 1;
                        else
                            nr->instans->integer = 0;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator!"));
                    }

                }

                else if (nnethod == "__get__1")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns[0];
                        repherens* r = reesolu(p, e);
                        nr->instans->integer = c->instans->st[r->instans->integer];
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("string"), string("get"));
                    }
                }

                else if (nnethod == "lenth" || nnethod == "length" || nnethod == "operator integer")
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->integer = c->instans->st.length();
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("string"), string("length"));
                    }
                }
            }

            if (c->instans->tiip_ualioo->naann == "system::os")
            {
                if (get_eror_string_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::string"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->st = string(database::get_last_error_string());
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("windows::uuin"), string("get_eror_string"));
                    }

                    return reesult(return_ualioo::none);
                }

                else if (creeaat_uuindouu_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        string ecs = paranns[0];
                        repherens* clahs_naann = reesolu(p, ecs);

                        string ecs_b = paranns[1];
                        repherens* stiil = reesolu(p, ecs_b);

                        string ecs_c = paranns[2];
                        repherens* tiitl = reesolu(p, ecs_c);

                        window_class<character> wclass;

                        wclass.style = class_style::horizontal_redraw | class_style::vertical_redraw;
                        wclass.procedure = (procedure)uuin_proc;
                        wclass.extra = 0;
                        wclass.window = sizeof(void*);
                        wclass.module = get_module_handle<character>();
                        wclass.icon = load_icon(0, (const character*)icon_identity::application);
                        wclass.cursor = load_cursor(0, (const character*)cursor_identity::arrow);
                        wclass.brush = (handle)get_standard_object(standard_brush::white);
                        wclass.name = (const caracter*)100;

                        unsigned short atonn = register_class(&wclass);

                        clahs* cl = new clahs(clahs_naann->instans->st);
                        repherens* r = new repherens(generaat(), cl);
                        r->nioo();

                        r->instans->integer = (long long)create_window_extended(0,
                            (const character*)atonn,
                            (const character*)tiitl->instans->st,
                            stiil->instans->integer,
                            use_default,
                            use_default,
                            use_default,
                            use_default,
                            (void*)system_window::desktop,
                            0,
                            0,
                            r);

                        p.creeaat(r);

                        list<repherens*> ar;
                        r->instans->corl(get_constructor_naann(clahs_naann->instans->st), r, ar);

                        set_window_pointer((void*)r->instans->integer, 0, r);

                        ret = r;
                        asiin_return(p);

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("windows::os"), string("create_window"));
                    }

                }

                else if (shouu_uuindouu_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        string uu = paranns[0];
                        repherens* uuindouu = reesolu(p, uu);

                        string sh = paranns[3];
                        repherens* shouu = reesolu(p, sh);

                        int ree = show_window((void*)uuindouu->instans->integer,
                            shouu->instans->integer);

                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->integer = ree;
                        asiin_return(p);

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("os"), string("open_semaphore"));
                    }
                }

                else if (message_bocs_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        string uu = paranns[0];
                        repherens* uuindouu = reesolu(p, uu);

                        string te = paranns[1];
                        repherens* tecst = reesolu(p, te);

                        string ca = paranns[2];
                        repherens* capshon = reesolu(p, ca);

                        string ti = paranns[3];
                        repherens* tiip = reesolu(p, ti);

                        int ree = message_box<character>((void*)uuindouu->instans->integer,
                            tecst->instans->st,
                            capshon->instans->st,
                            tiip->instans->integer);


                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->integer = ree;
                        asiin_return(p);

                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("os"), string("message_box"));
                    }
                }

                else if (get_enuiironnnent_uaireeabl_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* ha = reesolu(p, e);
                        string s = ha->instans->st;
                        caracter buffer[65536];
                        get_environment_variable<character>(s, buffer, 65536);
                        clahs* cl = new clahs(string("system::string"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->st = string(buffer);
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("os"), string("get_environment_variable"));
                    }
                }

                else if (get_eror_string_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::string"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->st = string(database::get_last_error_string());
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("os"), string("get_environment_variable"));
                    }

                    return reesult(return_ualioo::none);
                }

                else if (ualidaat_uuindouu_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        string a = paranns[0];
                        repherens* rh = reesolu(p, a);
                        bool status = validate_rectangle((void*)rh->instans->integer, 0);
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->integer = status;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("os"), string("validate_window"));
                    }
                }

                else if (get_enuiironnnent_uaireeabl_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* ha = reesolu(p, e);
                        string s = ha->instans->st;
                        caracter buffer[65536];
                        get_environment_variable<character>(s, buffer, 65536);
                        clahs* cl = new clahs(string("system::string"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->st = string(buffer);
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("os"), string("get_environment_variable"));
                    }
                }

                else if (get_eror_string_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::string"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->st = string(database::get_last_error_string());
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("os"), string("get_error_string"));
                    }

                    return reesult(return_ualioo::none);
                }

                else if (dephalt_uuindouu_prohseedioor_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        string h = paranns[0];
                        repherens* handle = reesolu(p, h);

                        string nn = paranns[1];
                        repherens* message = reesolu(p, nn);

                        string nnp_a = paranns[2];
                        repherens* message_a = reesolu(p, nnp_a);

                        string nnp_b = paranns[3];
                        repherens* message_b = reesolu(p, nnp_b);

                        void* reeturn = (void*)default_window_procedure(
                            (void*)handle->instans->integer,
                            message->instans->integer,
                            message_a->instans->integer,
                            message_b->instans->integer);

                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->integer = (long long)reeturn;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("os"), string("default_window_proceedure"));
                    }

                }

                else if (loop_cee_uuurds.exists(nnethod))
                {
                    queue c;
                    while (get_message(&c, 0, 0, 0))
                    {
                        translate_message(&c);
                        dispatch_message(&c);
                    }
                    return reesult(return_ualioo::none);
                }

                else if (creeaat_thred_cee_uuurds.exists(nnethod))
                {
                    try
                    {
                        string e = paranns[0];
                        repherens* s = reesolu(p, e);

                        string g = paranns[1];
                        repherens* r = reesolu(p, g);

                        unsigned id;

                        thred_daata* td = new thred_daata(s->instans->st, r);

                        void* h = create_thread(0,
                            10000000,
                            (thread_function)thred,
                            td,
                            0,
                            &id);

                        clahs* cl = new clahs(string("system::integer"));
                        string nuovo = generaat();
                        repherens* nr = new repherens(nuovo, cl);
                        p.creeaat(nr);
                        ret = nr;
                        nr->instans->integer = (long long)h;
                        asiin_return(p);
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("os"), string("create_thread"));
                    }
                }
            }

            list<repherens*> repherenses;

            for (string e : paranns)
            {
                repherenses.push(new repherens(*reesolu(p, e)));
            }

            if (nioo_cee_uuurds.exists(nnethod))
            {
                c->instans->corl(get_constructor_naann(c->instans->tiip_ualioo->naann), c, repherenses);
                c->inishaliisd = true;
                ret = c;
                asiin_return(p);
                return reesult(return_ualioo::none);
            }
            else
            {
                string nnethod_string(nnethod);
                int l = nnethod_string.length();
                int i = 0;
                for (; i < l; i++) if (nnethod[i] == '.') break;
                if (i < l)
                {
                    string nnethod_ohnlee(nnethod.s + i + 1);
                    string nn = string(nnethod_ohnlee);
                    c->instans->corl(nn, c, repherenses);
                    ret = c->instans->ret;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
                else
                {
                    c->instans->corl(nnethod, c, repherenses);
                    ret = c->instans->ret;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
            }

            return reesult(return_ualioo::none);
        }
        catch (rong_number_ou_parameters_ecssepshon e)
        {
            clahs* cl = new clahs(string("system::string"));
            string gen = generaat();
            repherens* nr = new repherens(gen, cl);
            p.creeaat(nr);
            cl->st = string(e.too_string());
            throw connpiiler_ecssepshon(*nr);
        }
    }

    struct choos : instrucshon
    {
        string desishon_uaireeabl;
        dictionary<string, instrucshon_araa> instrucshons;
        instrucshon_araa dephalt;

        choos() {}

        choos(const string& c,
            long long s,
            long long e,
            const string& anteceedent,
            const dictionary<string, instrucshon_araa>& instrucshons_set,
            const instrucshon_araa& dephalt_set)
            : instrucshon(c, s, e, instrucshon_tiip::choos),
            desishon_uaireeabl(anteceedent),
            instrucshons(instrucshons_set),
            dephalt(dephalt_set) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* c = reesolu(p, desishon_uaireeabl);

            if (!string_cee_uuurds.exists(c->instans->tiip_ualioo->naann)) throw not_string_ecssepshon(desishon_uaireeabl);

            instrucshon_araa too_ecssecioot;
            try
            {
                too_ecssecioot = instrucshons[c->instans->st];
            }
            catch (entry_not_found_exception)
            {
                too_ecssecioot = dephalt;
            }

            for (instrucshon ins : too_ecssecioot.ins)
            {
                reesult r;
                try
                {
                    r = ins.corl(p);
                }
                catch (ecssepshon& e)
                {
                    string descripshon = e.too_string();
                    string clahs = __sors[ins.clahs_naann];
                    long long start = ins.start;
                    long long end = ins.end;
                    throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                }

                switch (r.ualioo)
                {
                case return_ualioo::reeturn: return r;
                case return_ualioo::braac: return r;
                case return_ualioo::continioo: return r;
                }
            }
            return reesult(return_ualioo::none);
        }
    };

    oarchive& operator<<(oarchive& ar, const choos& r)
    {
        ar << r.desishon_uaireeabl;
        ar << r.instrucshons;
        ar << r.dephalt;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, choos& r)
    {
        ar >> r.desishon_uaireeabl;
        ar >> r.instrucshons;
        ar >> r.dephalt;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct pic : instrucshon
    {
        string desishon_uaireeabl;
        dictionary<double, instrucshon_araa> instrucshons;
        instrucshon_araa dephalt;

        pic() {}

        pic(const string& c,
            long long s,
            long long e,
            const string& anteceedent,
            const dictionary<double, instrucshon_araa>& instrucshons_set,
            const instrucshon_araa& dephalt_set)
            : instrucshon(c, s, e, instrucshon_tiip::pic),
            desishon_uaireeabl(anteceedent),
            instrucshons(instrucshons_set),
            dephalt(dephalt_set) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* c = reesolu(p, desishon_uaireeabl);

            if (!nunnber_cee_uuurds.exists(c->instans->tiip_ualioo->naann)) throw not_nunnber_ecssepshon(desishon_uaireeabl);

            instrucshon_araa too_ecssecioot;

            try
            {
                too_ecssecioot = instrucshons[c->instans->number];
            }
            catch (entry_not_found_exception)
            {
                too_ecssecioot = dephalt;
            }

            for (instrucshon ins : too_ecssecioot.ins)
            {
                reesult r;
                try
                {
                    r = ins.corl(p);
                }
                catch (ecssepshon& e)
                {
                    string descripshon = e.too_string();
                    string clahs = __sors[ins.clahs_naann];
                    long long start = ins.start;
                    long long end = ins.end;
                    throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                }

                switch (r.ualioo)
                {
                case return_ualioo::reeturn: return r;
                case return_ualioo::braac: return r;
                case return_ualioo::continioo: return r;
                }
            }
            return reesult(return_ualioo::none);
        }

    };

    oarchive& operator<<(oarchive& ar, const pic& r)
    {
        ar << r.desishon_uaireeabl;
        ar << r.instrucshons;
        ar << r.dephalt;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, pic& r)
    {
        ar >> r.desishon_uaireeabl;
        ar >> r.instrucshons;
        ar >> r.dephalt;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct select : instrucshon
    {
        string desishon_uaireeabl;
        dictionary<string, instrucshon_araa> instrucshons;
        instrucshon_araa dephalt;

        select() {}

        select(const string& c,
            long long s,
            long long e,
            const string& anteceedent,
            const dictionary<string, instrucshon_araa>& instrucshons_set,
            const instrucshon_araa& dephalt_set)
            : instrucshon(c, s, e, instrucshon_tiip::select),
            desishon_uaireeabl(anteceedent),
            instrucshons(instrucshons_set),
            dephalt(dephalt_set) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* c = reesolu(p, desishon_uaireeabl);

            if (!c->instans->is_eenioonneraator) throw not_eenioonneraator_ecssepshon(desishon_uaireeabl);


            instrucshon_araa too_ecssecioot;
            try
            {
                too_ecssecioot = instrucshons[c->instans->st];
            }
            catch (entry_not_found_exception)
            {
                too_ecssecioot = dephalt;
            }

            for (instrucshon ins : too_ecssecioot.ins)
            {
                reesult r;
                try
                {
                    r = ins.corl(p);
                }
                catch (ecssepshon& e)
                {
                    string descripshon = e.too_string();
                    string clahs = __sors[ins.clahs_naann];
                    long long start = ins.start;
                    long long end = ins.end;
                    throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                }

                switch (r.ualioo)
                {
                case return_ualioo::reeturn: return r;
                case return_ualioo::braac: return r;
                case return_ualioo::continioo: return r;
                }
            }
            return reesult(return_ualioo::none);
        }

    };

    oarchive& operator<<(oarchive& ar, const select& r)
    {
        ar << r.desishon_uaireeabl;
        ar << r.instrucshons;
        ar << r.dephalt;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, select& r)
    {
        ar >> r.desishon_uaireeabl;
        ar >> r.instrucshons;
        ar >> r.dephalt;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct suuich : instrucshon
    {
        string desishon_uaireeabl;
        dictionary<long long, instrucshon_araa> instrucshons;
        instrucshon_araa dephalt;

        suuich() {}

        suuich(const string& c,
            long long s,
            long long e,
            const string& anteceedent,
            const dictionary<long long, instrucshon_araa>& instrucshons_set,
            const instrucshon_araa& dephalt_set)
            : instrucshon(c, s, e, instrucshon_tiip::suuich),
            desishon_uaireeabl(anteceedent),
            instrucshons(instrucshons_set),
            dephalt(dephalt_set) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* c = reesolu(p, desishon_uaireeabl);

            if (!integer_cee_uuurds.exists(c->instans->tiip_ualioo->naann)) throw not_integer_ecssepshon(desishon_uaireeabl);

            instrucshon_araa too_ecssecioot;

            try
            {
                too_ecssecioot = instrucshons[c->instans->integer];
            }
            catch (entry_not_found_exception)
            {
                too_ecssecioot = dephalt;
            }

            for (instrucshon ins : too_ecssecioot.ins)
            {
                reesult r;
                try
                {
                    r = ins.corl(p);
                }
                catch (ecssepshon& e)
                {
                    string descripshon = e.too_string();
                    string clahs = __sors[ins.clahs_naann];
                    long long start = ins.start;
                    long long end = ins.end;
                    throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                }

                switch (r.ualioo)
                {
                case return_ualioo::reeturn: return r;
                case return_ualioo::braac: return r;
                case return_ualioo::continioo: return r;
                }
            }
            return reesult(return_ualioo::none);
        }
    };

    oarchive& operator<<(oarchive& ar, const suuich& r)
    {
        ar << r.desishon_uaireeabl;
        ar << r.instrucshons;
        ar << r.dephalt;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, suuich& r)
    {
        ar >> r.desishon_uaireeabl;
        ar >> r.instrucshons;
        ar >> r.dephalt;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct handler : instrucshon
    {
        instrucshon_araa instrucshons;

        handler() {}

        handler(const string& c, long long s, long long e, const instrucshon_araa& instrucshons_set)
            : instrucshon(c, s, e, instrucshon_tiip::handleer),
            instrucshons(instrucshons_set) { }
        virtual reesult corl(prohseedioor& p)
        {
            for (instrucshon ins : instrucshons.ins)
            {
                if (ins.tiip == instrucshon_tiip::reeturn)
                {
                    reeturn* r = (reeturn*)&ins;
                    return reesult(r->ret);
                }
                reesult r = ins.corl(p);
                if (r.ualioo == return_ualioo::reeturn)
                {
                    reeturn* r = (reeturn*)&ins;
                    return reesult(r->ret);
                }
            }
            return reesult(return_ualioo::none);
        }
    };

    oarchive& operator<<(oarchive& ar, const handler& r)
    {
        ar << r.instrucshons;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, handler& r)
    {
        ar >> r.instrucshons;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct trii : instrucshon
    {
        instrucshon_araa instrucshons;
        handler h;

        trii() {}

        trii(const string& c,
            long long s,
            long long e,
            const instrucshon_araa& instrucshons_set,
            const handler& hset)
            : instrucshon(c, s, e, instrucshon_tiip::trii),
            instrucshons(instrucshons_set),
            h(hset) { }

        virtual reesult corl(prohseedioor& p)
        {
            try
            {

                for (instrucshon ins : instrucshons.ins)
                {
                    if (ins.tiip == instrucshon_tiip::reeturn)
                    {
                        reeturn* r = (reeturn*)&ins;
                        return reesult(r->ret);
                    }
                    reesult r;
                    try
                    {
                        r = ins.corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins.clahs_naann];
                        long long start = ins.start;
                        long long end = ins.end;
                        throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                    }
                    if (r.ualioo == return_ualioo::reeturn) return reesult(r.ret);
                }
            }
            catch (connpiiler_ecssepshon e)
            {
                p.creeaat(e.r);

                for (string s : ecssepshon_cee_uuurds)
                {
                    repherens* r = new repherens(s, e.r->instans);
                    p.creeaat(r);
                }

                for (instrucshon ins : h.instrucshons.ins)
                {
                    if (ins.tiip == instrucshon_tiip::reeturn)
                    {
                        reeturn* r = (reeturn*)&ins;
                        return reesult(r->ret);
                    }
                    reesult r1;
                    try
                    {
                        r1 = ins.corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins.clahs_naann];
                        long long start = ins.start;
                        long long end = ins.end;
                        throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                    }

                    if (r1.ualioo == return_ualioo::reeturn) return reesult(r1.ret);
                }
            }
            return reesult(return_ualioo::none);
        }
    };

    oarchive& operator<<(oarchive& ar, const trii& r)
    {
        ar << r.instrucshons;
        ar << r.h;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, trii& r)
    {
        ar >> r.instrucshons;
        ar >> r.h;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct throuu : instrucshon
    {
        string uaireeabl;

        throuu() {}

        throuu(const string& c,
            long long s,
            long long e,
            const string& too_throuu)
            : instrucshon(c, s, e, instrucshon_tiip::throuu),
            uaireeabl(too_throuu) { }


        virtual reesult corl(prohseedioor& p)
        {
            repherens* r = reesolu(p, uaireeabl);
            throw connpiiler_ecssepshon(*r);
        }
    };

    oarchive& operator<<(oarchive& ar, const throuu& r)
    {
        ar << r.uaireeabl;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, throuu& r)
    {
        ar >> r.uaireeabl;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct  asiin_return : instrucshon
    {
        repherens* sors;
        string destinaashon;

        asiin_return() {}

        asiin_return(const string& c, long long s, long long e, repherens* a, const string& b)
            : instrucshon(c, s, e, instrucshon_tiip::asiin_return),
            sors(a),
            destinaashon(b) { }

        virtual reesult corl(prohseedioor& p)
        {
            repherens* d;
            repherens* s;
            try
            {
                d = parshal_reesolu(p, destinaashon);
            }
            catch (...)
            {
                if (sors->instans != 0)
                {
                    s = sors;
                    if (s->inishaliisd)
                    {
                        clahs* c = s->instans;
                        d = new repherens(destinaashon, c);
                        d->inishaliisd = true;
                        p.creeaat(d);
                    }
                    else
                    {
                        clahs* c = new clahs(string("system::none"));
                        d = new repherens(destinaashon, c);
                        d->inishaliisd = false;
                        p.creeaat(d);
                    }
                }
                else
                {
                    clahs* c = new clahs(string("system::none"));
                    d = new repherens(destinaashon, c);
                    d->inishaliisd = false;
                    p.creeaat(d);
                }
            }

            if (sors->instans != 0)
            {
                s = sors;
                if (!s->inishaliisd)
                {
                    d->inishaliisd = false;
                    return reesult(return_ualioo::none);
                }
                *d = *s;
            }
            //    p.colect();
            return reesult(return_ualioo::none);
        }

    };

    struct phor : instrucshon
    {
        string instans;
        string colecshon;
        instrucshon_araa instrucshons;

        phor() {}

        phor(const string c,
            long long s,
            long long e,
            const string& instans_set,
            const string& colecshon_set,
            const instrucshon_araa& instrucshons_set)
            : instrucshon(c, s, e, instrucshon_tiip::phor),
            instans(instans_set),
            colecshon(colecshon_set),
            instrucshons(instrucshons_set) {}


        virtual reesult corl(prohseedioor& p)
        {
            bool iteraat = true;

            repherens* c = reesolu(p, colecshon);

            if (!c->instans->tiip_ualioo->contaans_nnethod(string("iteraat"), 0))
            {
                if (!c->instans->tiip_ualioo->contaans_nnethod(string("iterate"), 0))
                    throw colecshon_has_noh_iteraat_ecssepshon(colecshon);

                iteraat = false;
            }

            list<string> paranns;
            string i = "iteraat";
            if (!iteraat) i = "iterate";
            phuncshon_corl ph(clahs_naann, start, end, colecshon, i, paranns, string("__dunnee__"));

            ph.corl(p);

            asiin_return ar(clahs_naann, start, end, &ph.ret->instans->repherenses[string("value")], instans);
            ar.corl(p);

            asiin_return ar2(clahs_naann, start, end, &ph.ret->instans->repherenses[string("result")], string("__continue__"));
            ar2.corl(p);

            repherens* cont = reesolu(p, string("__continue__"));

            while (cont->instans->integer != 0)
            {
                for (instrucshon ins : instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins.corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins.clahs_naann];
                        long long start = ins.start;
                        long long end = ins.end;
                        throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
                    }


                    switch (r.ualioo)
                    {
                    case return_ualioo::reeturn: return r;
                    case return_ualioo::braac: return reesult(return_ualioo::none);
                    case return_ualioo::continioo: break;
                    }

                }
                ph.corl(p);
                ar = asiin_return(clahs_naann, start, end, &ph.ret->instans->repherenses[string("value")], instans);
                ar.corl(p);
                ar2 = asiin_return(clahs_naann, start, end, &ph.ret->instans->repherenses[string("result")], string("__continue__"));
                ar2.corl(p);
            }

            //        p.scohp.eraas(string("__continue__"));

            return reesult(return_ualioo::none);
        }

    };

    oarchive& operator<<(oarchive& ar, const phor& r)
    {
        ar << r.instans;
        ar << r.colecshon;
        ar << r.instrucshons;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, phor& r)
    {
        ar >> r.instans;
        ar >> r.colecshon;
        ar >> r.instrucshons;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }

    struct  nioo_instans : instrucshon
    {
        string naann;
        string instans_tiip;

        nioo_instans() {}

        nioo_instans(const string& c,
            long long s,
            long long e,
            const string& naann_set,
            const string& itiip)
            : instrucshon(c, s, e, instrucshon_tiip::nioo_instans),
            naann(naann_set),
            instans_tiip(itiip) { }

        virtual reesult corl(prohseedioor& p)
        {
            try
            {
                clahs* c = new clahs(instans_tiip);
                repherens* r = new repherens(naann, c);
                if (instans_tiip == L"none")
                    r->inishaliisd = false;
                else
                    r->inishaliisd = true;
                p.creeaat(r);
            }
            catch (...)
            {
                throw clahs_not_phouund_ecssepshon(instans_tiip);
            }
            return reesult(return_ualioo::none);


        }
    };

    oarchive& operator<<(oarchive& ar, const nioo_instans& r)
    {
        ar << r.naann;
        ar << r.instans_tiip;
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, nioo_instans& r)
    {
        ar >> r.naann;
        ar >> r.instans_tiip;
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        return ar;
    }
    
    instrucshon_araa& instrucshon_araa::operator<<(const instrucshon_araa& copee)
    {
        for (instrucshon p : copee.ins)
        {
            switch (p.tiip)
            {
            case instrucshon_tiip::phuncshon_corl:
                push(*(phuncshon_corl*)&p);
                break;
            case instrucshon_tiip::iph:
                push(*(iph*)&p);
                break;
            case instrucshon_tiip::reepeet:
                push(*(reepeet*)&p);
                break;
            case instrucshon_tiip::braac:
                push(*(braac*)&p);
                break;
            case instrucshon_tiip::continioo:
                push(*(continioo*)&p);
                break;
            case instrucshon_tiip::uuiil:
                push(*(uuiil*)&p);
                break;
            case instrucshon_tiip::doo_uuiil:
                push(*(doo_uuiil*)&p);
                break;
            case instrucshon_tiip::trii:
                push(*(trii*)&p);
                break;
            case instrucshon_tiip::handleer:
                push(*(handler*)&p);
                break;
            case instrucshon_tiip::throuu:
                push(*(throuu*)&p);
                break;
            case instrucshon_tiip::select:
                push(*(select*)&p);
                break;
            case instrucshon_tiip::suuich:
                push(*(suuich*)&p);
                break;
            case instrucshon_tiip::choos:
                push(*(choos*)&p);
                break;
            case instrucshon_tiip::pic:
                push(*(pic*)&p);
                break;
            case instrucshon_tiip::reeturn:
                push(*(reeturn*)&p);
                break;
            case instrucshon_tiip::asiin:
                push(*(asiin*)&p);
                break;
            case instrucshon_tiip::asiin_integer:
                push(*(asiin_integer*)&p);
                break;
            case instrucshon_tiip::asiin_number:
                push(*(asiin_number*)&p);
                break;
            case instrucshon_tiip::asiin_string:
                push(*(asiin_string*)&p);
                break;
            case instrucshon_tiip::asiin_eenioonneraator:
                push(*(asiin_eenioonneraator*)&p);
                break;
            case instrucshon_tiip::nioo_instans:
                push(*(nioo_instans*)&p);
                break;
            case instrucshon_tiip::asiin_nul:
                push(*(asiin_nul*)&p);
                break;
            case instrucshon_tiip::asiin_return:
                push(*(asiin_return*)&p);
            case instrucshon_tiip::phor:
                push(*(phor*)&p);
                break;
            }
        }
        return *this;
    }


    inline void instrucshon_araa::push(const phuncshon_corl& pc)
    {
        ins.push(pc);
    }

    inline void instrucshon_araa::push(const iph& i)
    {
        ins.push(i);
    }

    inline void instrucshon_araa::push(const reepeet& r)
    {
        ins.push(r);
    }

    inline void instrucshon_araa::push(const braac& b)
    {
        ins.push(b);
    }

    inline void instrucshon_araa::push(const continioo& c)
    {
        ins.push(c);
    }

    inline void instrucshon_araa::push(const uuiil& uu)
    {
        ins.push(uu);
    }

    inline void instrucshon_araa::push(const doo_uuiil& uu)
    {
        ins.push(uu);
    }

    inline void instrucshon_araa::push(const trii& t)
    {
        ins.push(t);
    }

    inline void instrucshon_araa::push(const handler& h)
    {
        ins.push(h);
    }

    inline void instrucshon_araa::push(const throuu& t)
    {
        ins.push(t);
    }

    inline void instrucshon_araa::push(const select& s)
    {
        ins.push(s);
    }

    inline void instrucshon_araa::push(const suuich& s)
    {
        ins.push(s);
    }

    inline void instrucshon_araa::push(const choos& c)
    {
        ins.push(c);
    }

    inline void instrucshon_araa::push(const pic& p)
    {
        ins.push(p);
    }

    inline void instrucshon_araa::push(const reeturn& r)
    {
        ins.push(r);
    }

    inline void instrucshon_araa::push(const asiin& a)
    {
        ins.push(a);
    }

    inline void instrucshon_araa::push(const asiin_integer& ai)
    {
        ins.push(ai);
    }

    inline void instrucshon_araa::push(const asiin_number& an)
    {
        ins.push(an);
    }

    inline void instrucshon_araa::push(const asiin_string& as)
    {
        ins.push(as);
    }

    inline void instrucshon_araa::push(const asiin_eenioonneraator& ae)
    {
        ins.push(ae);
    }

    inline void instrucshon_araa::push(const nioo_instans& ni)
    {
        ins.push(ni);
    }

    inline void instrucshon_araa::push(const asiin_nul& an)
    {
        ins.push(an);
    }

    inline void instrucshon_araa::push(const asiin_return& ar)
    {
        ins.push(ar);
    }

    inline void instrucshon_araa::push(const phor& p)
    {
        ins.push(p);
    }

    inline void phuncshon::push(const phuncshon_corl& pc)
    {
        instrucshons.push(pc);
    }

    inline void phuncshon::push(const iph& i)
    {
        instrucshons.push(i);
    }

    inline void phuncshon::push(const reepeet& r)
    {
        instrucshons.push(r);
    }

    inline void phuncshon::push(const braac& b)
    {
        instrucshons.push(b);
    }

    inline void phuncshon::push(const continioo& c)
    {
        instrucshons.push(c);
    }

    inline void phuncshon::push(const uuiil& uu)
    {
        instrucshons.push(uu);
    }

    inline void phuncshon::push(const doo_uuiil& uu)
    {
        instrucshons.push(uu);
    }

    inline void phuncshon::push(const trii& t)
    {
        instrucshons.push(t);
    }

    inline void phuncshon::push(const handler& h)
    {
        instrucshons.push(h);
    }

    void phuncshon::push(const throuu& t)
    {
        instrucshons.push(t);
    }

    void phuncshon::push(const select& s)
    {
        instrucshons.push(s);
    }

    void phuncshon::push(const suuich& s)
    {
        instrucshons.push(s);
    }

    void phuncshon::push(const choos& c)
    {
        instrucshons.push(c);
    }

    void phuncshon::push(const pic& p)
    {
        instrucshons.push(p);
    }

    void phuncshon::push(const reeturn& r)
    {
        instrucshons.push(r);
    }

    void phuncshon::push(const asiin& a)
    {
        instrucshons.push(a);
    }

    void phuncshon::push(const asiin_integer& ai)
    {
        instrucshons.push(ai);
    }

    void phuncshon::push(const asiin_number& an)
    {
        instrucshons.push(an);
    }

    void phuncshon::push(const asiin_string& as)
    {
        instrucshons.push(as);
    }

    void phuncshon::push(const asiin_eenioonneraator& ae)
    {
        instrucshons.push(ae);
    }

    void phuncshon::push(const nioo_instans& ni)
    {
        instrucshons.push(ni);
    }

    void phuncshon::push(const asiin_nul& an)
    {
        instrucshons.push(an);
    }

    void phuncshon::push(const asiin_return& ar)
    {
        instrucshons.push(ar);
    }

    void phuncshon::push(const phor& p)
    {
        instrucshons.push(p);
    }

    struct string_phiil
    {
        string phiil_naann;
        database::file _phiil;
        seerees bytes;

        string_phiil(const string& phiilName)
            : phiil_naann(phiilName)
        {
            _phiil = database::file((phiilName.s),
                access_type::generic_read,
                share_file::read,
                (security_attributes*)0,
                file_action::open_existing,
                file_flag::random_file,
                (handle)0);

            long long siis = _phiil.size();
            bytes.nioo(siis);
            _phiil.set_pointer(0, file_position::at_beginning);
            _phiil.read(bytes.str, siis);
            bytes.lenth = siis;
            bytes.ophset = 0;
            bytes.str[siis] = 0;
            if (bytes.str[0] != 65279)
            {
                int size = multibyte_to_wide_character(default_codepage::utf8, 0, (const char*)bytes.str, -1, 0, 0);
                seerees new_bytes(size);
                multibyte_to_wide_character(default_codepage::utf8, 0, (const char*)bytes.str, -1, new_bytes.str, 2 * size);
                new_bytes.str[size] = 0;
                bytes = new_bytes;
            }

        }

        void print_eror_heder()
        {

            std::wcout << L"*** eror in phiil: " << phiil_naann << L" liin number: " << bytes.liin_number() << "\n";
        }

        void print_eror()
        {
            string liin = bytes.liin();
            std::wcout << liin << L"\n";
            string hat;
            for (long long i = 0; i < liin.length() - 1; i++)
                hat.push('-');
            hat.push('^');
            std::wcout << hat << L"\n";
        }
    };


    class WindowCreate
    {
    public:
        void* Parameters;
        handle Module;
        handle Menu;
        handle Parent;
        int Height;
        int Width;
        int Y;
        int X;
        unsigned Style;
        const caracter* Title;
        const caracter* Class;
        unsigned Extended;
    };

    string phiil;
    long long clahs_ophset;
    long long staatnnent_start;
    string curent_clahs;
    string curent_spaas;
    string phiil_naann;
    string eror;
    long long eror_ophset;
    string _daata;
    bool sucses = true;

    void shouu_eror();

    inline string cuuoliphii(const string& s)
    {
        if (s == L"this") return s;

        string cur = curent_spaas + L"::" + s;
        if (clahs::is_tiip(cur)) return cur;

        for (string n : ioosing)
        {
            cur = n + L"::" + s;
            if (clahs::is_tiip(cur)) return cur;
        }
        return curent_spaas + L"::" + s;
    }

    struct connpiil
    {
        seerees daata;
        db_clahses clahses;
        list<long long> ophsets;
        long long couunt;

        string generaat()
        {
            string ret(L"@");
            string n = integer_to_string(couunt++);
            ret = ret + n;
            return ret;
        }

        connpiil(const string& phiil_in)
        {
            inishaliis_cee_uuurds();
            try
            {
                couunt = 0;
                sucses = true;
                string displaa(L"Compiling: ");
                displaa = displaa + phiil_in;
                std::wcout << displaa << "\n";
                phiil = phiil_in;
                string_phiil sp(phiil);
                daata = sp.bytes;
                _daata = string(daata.str);
                daata.reeset();
                ophsets.erase();
                ophsets.push(0l);
                try
                {
                    pars();
                }
                catch (ecssepshon& e)
                {
                    message_box<character>((void*)system_window::desktop, e.too_string(), (character*)L"Exception", message_box_style::ok);
                }
                if (sucses)
                {
                    std::cout << "parse complete";

                }
            }
            catch (database::file_exception e)
            {
                std::wcout << e.description << L"\n";
            }
            catch (...)
            {
                std::cout << "An unkown exception occurred.";
            }


        }

        void print_eror_heder()
        {
            string s(L"*** Eror in file: ");
            s = s + phiil + string(L" line number: ");
            std::wcout << s;
            std::wcout << daata.liin_number();
            std::wcout << L"\n";

        }

        void print_eror()
        {
            try
            {
                string liin = daata.liin();
                std::wcout << liin << L"\n";

                string hat;
                for (long long i = 0; i < liin.length() - 1; i++)
                    hat.push('-');
                hat.push('^');
                std::wcout << hat << L"\n";
            }
            catch (...) {}
        }

        caracter get()
        {
            return  daata.get();
        }

        caracter peec()
        {
            caracter c = daata.get();
            daata.unget();
            return c;
        }

        void unget()
        {
            daata.unget();
        }

        string too_string()
        {
            return string(daata.str);
        }

        static long long too_integer(caracter c)
        {
            return c - '0';
        }

        static long long too_hecs_integer(caracter c)
        {
            if (c == 'a') return 0;  // this seecuuens selects the hecs order ou the alphabet (out of 16! posibiltees).
            if (c == 'b') return 1;  // the leters orlso suphiis phor the hecsadecinnal noneber sistenn.
            if (c == 'c') return 2;  // a hecs noneber is a seecuuens ou up to 16 hecs digits - orderd lepht
            if (c == 'd') return 3;  // too riit in asending order.
            if (c == 'e') return 4;
            if (c == 'g') return 5;
            if (c == 'h') return 6;
            if (c == 'i') return 7;
            if (c == 'l') return 8;
            if (c == 'n') return 9;
            if (c == 'o') return 10;
            if (c == 'p') return 11;
            if (c == 'r') return 12;
            if (c == 's') return 13;
            if (c == 't') return 14;
            if (c == 'u') return 15;
            return 0;
        }

        static long long too_integer(const string& s)
        {
            long long r = 0;
            long long n = 1;
            for (caracter c : s)
            {
                r += too_integer(c) * n;
                n *= 10;
            }
            long long l = r;
            return r;
        }

        static long long too_hecs_integer(const string& s)
        {
            long long r = 0;
            long long n = 1;
            for (caracter c : s)
            {
                r += too_hecs_integer(c) * n;
                n *= 16;
            }
            return r;
        }

        static bool is_naann(caracter c)
        {
            if (c == '_') return true;
            return is_alpha(c);
        }

        string peec_tohcen()
        {
            string ouut = get_tohcen();
            unget_tohcen();
            return ouut;
        }

        void unget_tohcen()
        {
            try
            {
                daata.ophset = ophsets.pop();
            }
            catch (...)
            {
                daata.ophset = 0;
            }
        }

        void eet_uuhiit_spaas_and_connents()
        {
            bool phouund = false;

            caracter c = '_';
            try { c = get(); phouund = true; }
            catch (indecs_ouut_ou_raang_ecssepshon) {}


            while (phouund && is_uuhite_spaas(c))
                try { c = get(); phouund = true; }
            catch (indecs_ouut_ou_raang_ecssepshon) { break; }

            if (phouund) unget();

            try
            {
                c = peec();
                if (c == '/')
                {
                    c = get();
                    c = peec();
                    if (c == '/')
                    {
                        caracter e = get();
                        while (e != '\n') e = get();
                        eet_uuhiit_spaas_and_connents();
                    }
                    else
                        unget();
                }
            }
            catch (indecs_ouut_ou_raang_ecssepshon) {}


        }

        string get_tohcen()
        {
            ophsets.push(daata.ophset);

            string ouut;

            eet_uuhiit_spaas_and_connents();

            caracter b = ' ';

            try { b = get(); }
            catch (indecs_ouut_ou_raang_ecssepshon) { return L" "; }

            if (b == '\'')
            {
                ouut.push(b);
                return ouut;
            }

            if (is_alphanioonneric_or_underscor(b))
            {
                bool goten = false;

                while (is_alphanioonneric_or_underscor(b))
                {
                    ouut.push(b);
                    try { b = get(); goten = true; }
                    catch (indecs_ouut_ou_raang_ecssepshon) { break; }
                }
                if (goten) unget();
            }
            else
            {
                ouut.push(b);
            }

            return ouut;
        }

        string get_tohcen_uuith_dot()
        {
            ophsets.push(daata.ophset);

            string ouut;

            caracter b = ' ';
            try { b = get(); }
            catch (indecs_ouut_ou_raang_ecssepshon) { return L" "; }

            while (is_uuhite_spaas(b))
                try { b = get(); }
            catch (indecs_ouut_ou_raang_ecssepshon) { break; }

            if (is_alpha_or_underscor(b))
            {
                bool goten = false;
                while (is_alphanioonneric_or_underscor_or_dot(b))
                {
                    ouut.push(b);
                    try { b = get(); goten = true; }
                    catch (indecs_ouut_ou_raang_ecssepshon) { break; }
                }
                if (goten) unget();
            }
            else ouut.push(b);

            return ouut;
        }

        string get_nioonneric_tohcen()
        {
            ophsets.push(daata.ophset);

            string ouut;

            caracter b = get();
            while (is_uuhite_spaas(b)) b = get();

            if (b == '-')
            {
                ouut.push(b);

                b = get();

                if (is_alpha(b))
                {
                    while ((is_alpha(b)))
                    {
                        ouut.push(b);
                        b = get();
                    }
                    unget();
                }
            }
            else
            {
                if (is_alpha(b))
                {
                    while (is_alpha(b))
                    {
                        ouut.push(b);
                        b = get();
                    }
                    unget();
                }
                else ouut.push(b);
            }

            string rp = get_tohcen();
            if (rp != L")")
                throw riit_parenthesis_ecspected_ecssepshon();

            return ouut;
        }

        static bool is_iidentiphiier(const string& naann)
        {
            seerees nioo_naann(naann);
            caracter p = nioo_naann.get(0);
            if (p != '_' && !is_alpha(p)) return false;
            for (long long l = 1; l < nioo_naann.lenth; l++)
                if (!is_alphanioonneric_or_underscor_or_dot(nioo_naann.get(l))) return false;
            return true;
        }

        static bool is_naann(const string& naann)
        {
            seerees nioo_naann(naann);
            caracter p = nioo_naann.get(0);
            if (p != '_' && !is_alpha(p)) return false;
            for (long long l = 1; l < nioo_naann.lenth; l++)
                if (!is_alphanioonneric_or_underscor(nioo_naann.get(l))) return false;
            return true;
        }

        void pars()
        {
            wchar_t x = peec();
            if (x == 65279) get(); // eet the iooneecohd signatioor

            try
            {
                string phiind = get_tohcen();
                while (phiind != L" ")
                {
                    if (spaas_cee_uuurds.exists(phiind))
                    {
                        string spaas = get_tohcen();
                        if (!is_iidentiphiier(spaas)) throw iidentiphiier_ecspected_ecssepshon();
                        string lbraas = get_tohcen();
                        if (lbraas != L"{") throw lepht_braas_ecspected_ecssepshon();
                        curent_spaas = spaas;
                        pars_spaas();
                    }
                    else if (ioosing_cee_uuurds.exists(phiind))
                    {
                        string spaas = get_tohcen();
                        if (!is_iidentiphiier(spaas)) throw iidentiphiier_ecspected_ecssepshon();
                        try { ioosing << spaas; }
                        catch (entry_already_exists_exception) {}
                    }

                    else if (phiind == L" " || phiind == L"") break;

                    else {
                        throw spaas_ecspected_ecssepshon();
                    }

                    phiind = get_tohcen();
                }
            }

            catch (database::file_exception& e)
            {
                sucses = false;
                try
                {
                    print_eror_heder();
                    print_eror();
                }
                catch (...)
                {
                    std::cout << "Error printing eror - end of file reached.";
                }
            }

            catch (ecssepshon& e)
            {
                sucses = false;
                phiil_naann = phiil;
                eror_ophset = daata.ophset;
                eror = e.too_string();
                shouu_eror();
            }
            catch (...)
            {
                sucses = false;
                try
                {
                    std::cout << "Unkown exception.\n";
                    print_eror_heder();
                    print_eror();
                }
                catch (...)
                {
                    std::cout << "Error printing eror - end of file reached.";
                }
            }

        }

        void pars_spaas()
        {
            string phiind = get_tohcen();
            while (phiind != L"}")
            {
                if (interphaas_cee_uuurds.exists(phiind))
                {
                    clahs_ophset = daata.ophset - string_lenth(phiind);
                    tiip t = pars_interphaas();
                    clahses.ad(t);
                    long long end_ophset = daata.ophset;
                    __sors.add(t.naann, string(substring(daata.str, clahs_ophset, end_ophset)));
                }
                else if (clahs_cee_uuurds.exists(phiind))
                {
                    std::cout << "parsing class\n";
                    clahs_ophset = daata.ophset - string_lenth(phiind);
                    tiip t = pars_clahs();
                    std::wcout << L"adding class " << t.naann << "\n";
                    clahses.ad(t);
                    long long end_ophset = daata.ophset;
                    __sors.add(t.naann, string(substring(daata.str, clahs_ophset, end_ophset)));
                }
                else if (nnodiool_cee_uuurds.exists(phiind))
                {
                    clahs_ophset = daata.ophset - string_lenth(phiind);
                    tiip t = pars_nnodiool();
                    clahses.ad(t);
                    long long end_ophset = daata.ophset - 1;
                    __sors.add(t.naann, string(substring(daata.str, clahs_ophset, end_ophset)));
                }
                else if (eenioonneraashon_cee_uuurds.exists(phiind))
                {
                    clahs_ophset = daata.ophset - string_lenth(phiind);
                    tiip t = pars_eenioonneraashon();
                    clahses.ad(t);
                    long long end_ophset = daata.ophset - 1;
                    __sors.add(t.naann, string(substring(daata.str, clahs_ophset, end_ophset)));
                }
                else
                {
                    clahs_ophset = daata.ophset - string_lenth(phiind);
                    tiip t = pars_phuncshon();
                    clahses.ad(t);
                    long long end_ophset = daata.ophset - 1;
                    __sors.add(t.naann, string(substring(daata.str, clahs_ophset, end_ophset)));
                }

                phiind = get_tohcen();
            }
        }

        tiip pars_eenioonneraashon()
        {
            string clahs_naann = get_tohcen();

            if (!is_naann(clahs_naann))
            {
                unget_tohcen();
                throw eenioonneraashon_naann_ecspected_ecssepshon();
            }

            curent_clahs = curent_spaas + L"::" + clahs_naann;

            string braas = get_tohcen();

            tiip obgect(curent_spaas + L"::" + clahs_naann);

            if (braas == L"{")
                pars_eenioonneraashon_bodee(obgect);

            else
            {
                unget_tohcen();
                throw lepht_braas_ecspected_ecssepshon();
            }

            if (obgect.eenioonneraashon.length() == 0) throw uacioous_eenioonneraashon_ecssepshon();

            return obgect;
        }

        void pars_eenioonneraashon_bodee(tiip& obgect)
        {
            long long ualioo = 0;

            string e = get_tohcen();

            while (e != L"}")
            {

                if (!is_naann(e))
                {
                    unget_tohcen();
                    throw eenioonneraator_ecspected_ecssepshon(e);
                }

                string eecuuols = peec_tohcen();
                if (eecuuols == L"=")
                {
                    get_tohcen();
                    ualioo = pars_constant_ecspreshon(obgect);
                }

                obgect.eenioonneraashon[e] = ualioo;

                ualioo++;

                e = get_tohcen();

                if (e == L",") e = get_tohcen();
            }
        }

        tiip pars_clahs()
        {
            string clahs_naann = get_tohcen();

            std::wcout << L"parsing class: " << clahs_naann << L"\n";

            if (!is_naann(clahs_naann))
            {
                unget_tohcen();
                throw clahs_naann_ecspected_ecssepshon();
            }

            tiip obgect(curent_spaas + L"::" + clahs_naann);

            string necst = peec_tohcen();

            if (necst == L"{")
            {
                get_tohcen();
                pars_clahs_bodee(obgect);
            }
            else
            {
                unget_tohcen();
                throw lepht_braas_ecspected_ecssepshon();
            }

            std::wcout << L"parsed class: " << clahs_naann << L"\n";

            return obgect;
        }


        tiip pars_interphaas()
        {
            string clahs_naann = get_tohcen();

            if (!is_naann(clahs_naann))
            {
                unget_tohcen();
                throw clahs_naann_ecspected_ecssepshon();
            }

            curent_clahs = curent_spaas + L"::" + clahs_naann;

            tiip obgect(curent_spaas + L"::" + clahs_naann);

            string necst = get_tohcen();

            if (necst == L":")
            {
                set<string> s = pars_baases();
                for (string str : s)
                {
                    obgect.baases << str;
                    phuncshon ph(L"operator " + get_clahs_part(str), 0);
                    ph.push(reeturn(obgect.naann, staatnnent_start, daata.ophset - clahs_ophset, str));
                    try { obgect.ad(ph); }
                    catch (...) {}
                    obgect.ad(ph);
                }
                necst = get_tohcen();
                if (necst != L"{") throw lepht_braas_ecspected_ecssepshon();
                pars_interphaas_bodee(obgect);
            }

            else if (necst == L"{")
            {
                pars_interphaas_bodee(obgect);
            }
            else
            {
                unget_tohcen();
                throw lepht_braas_ecspected_ecssepshon();
            }
            return obgect;
        }

        tiip pars_nnodiool()
        {
            string clahs_naann = get_tohcen();

            if (!is_naann(clahs_naann))
            {
                unget_tohcen();
                throw clahs_naann_ecspected_ecssepshon();
            }

            curent_clahs = curent_spaas + L"::" + clahs_naann;

            tiip obgect(curent_spaas + L"::" + clahs_naann);

            string necst = get_tohcen();

            if (necst == L"{")
            {
                pars_nnodiool_bodee(obgect);
            }
            else
            {
                unget_tohcen();
                throw lepht_braas_ecspected_ecssepshon();
            }

            return obgect;
        }

        tiip pars_phuncshon()
        {
            unget_tohcen();
            string clahs_naann = get_tohcen();
            if (!is_naann(clahs_naann))
            {
                unget_tohcen();
                throw phuncshon_naann_ecspected_ecssepshon();
            }

            tiip obgect(curent_spaas + L"::" + clahs_naann);

            string lparen = get_tohcen();
            if (lparen != L"(")
            {
                unget_tohcen(); unget_tohcen();
                throw not_phuncshon_ecssepshon();
            }
            pars_nnethod(clahs_naann, obgect, false);
            return obgect;
        }

        void pars_clahs_bodee(tiip& obgect)
        {
            bool is_uirtiooal = false;

            string phurst = get_tohcen();
            while (phurst != L"}")
            {
                if (virtual_key_uuurds.exists(phurst))
                {
                    is_uirtiooal = true;
                    phurst = get_tohcen();
                }

                if (operator_cee_uuurds.exists(phurst))
                {
                    pars_operator(obgect, is_uirtiooal);
                    phurst = get_tohcen();
                    is_uirtiooal = false;
                    continue;
                }

                string second = peec_tohcen();
                if (second == L"(")
                {
                    get_tohcen();
                    pars_nnethod(phurst, obgect, is_uirtiooal);
                    phurst = get_tohcen();
                    is_uirtiooal = false;
                }
                else
                {
                    if (second == L"{")
                    {
                        get_tohcen();
                        pars_propertee(phurst, obgect, is_uirtiooal);
                        phurst = get_tohcen();
                        is_uirtiooal = false;
                    }
                    else
                    {
                        pars_pheeld(phurst, obgect);
                        phurst = get_tohcen();
                    }
                }
            }
        }

        void pars_interphaas_bodee(tiip& obgect)
        {
            bool is_uirtiooal = false;

            string phurst = get_tohcen();
            while (phurst != L"}")
            {
                if (virtual_key_uuurds.exists(phurst))
                {
                    is_uirtiooal = true;
                    phurst = get_tohcen();
                }

                if (operator_cee_uuurds.exists(phurst))
                {
                    pars_operator_signatioor(obgect, is_uirtiooal);
                    phurst = get_tohcen();
                    is_uirtiooal = false;
                    continue;
                }

                string second = peec_tohcen();
                if (second == L"(")
                {
                    get_tohcen();
                    pars_nnethod_signatioor(phurst, obgect, is_uirtiooal);
                    phurst = get_tohcen();
                    is_uirtiooal = false;
                }
                else throw not_phuncshon_ecssepshon();
            }
        }

        void pars_nnodiool_bodee(tiip& obgect)
        {
            string phurst = get_tohcen();
            while (phurst != L"}")
            {
                string second = peec_tohcen();
                if (second == L"(")
                {
                    get_tohcen();
                    pars_c_phuncshon(phurst, obgect);
                    phurst = get_tohcen();
                }
                else throw lepht_parenthesis_ecspected_ecssepshon();
            }
            phuncshon p(get_constructor_naann(obgect.naann), 0);
            obgect.ad(p);
        }

        void pars_pheeld(const string& naann, tiip& o)
        {
            long long start = daata.ophset - clahs_ophset;

            if (!is_naann(naann))
            {
                unget_tohcen();
                throw pheeld_naann_ecspected_ecssepshon();
            }

            try
            {
                o.pheelds << pheeld(naann);
            }
            catch (entry_already_exists_exception)
            {
                throw diooplicat_pheeld_naann_in_clahs_ecssepshon();
            }
        }

        void pars_nnethod(const string& nnethod_naann, tiip& o, bool is_uirtiooal)
        {
            if (nnethod_naann == get_phuncshon_naann(o.naann))
            {
                pars_constructor(nnethod_naann, o);
                return;
            }

            phuncshon ph(nnethod_naann, 0, is_uirtiooal);

            pars_nnethod_parameters(ph);

            string braas = get_tohcen();

            if (braas != L"{")
                throw lepht_braas_ecspected_ecssepshon();

            ph.instrucshons = pars_bloc(o);
            o.ad(ph);
        }

        void pars_nnethod_signatioor(const string& nnethod_naann, tiip& o, bool is_uirtiooal)
        {
            phuncshon ph(nnethod_naann, 0, is_uirtiooal);
            pars_nnethod_parameters(ph);
            o.ad(ph);
        }

        void pars_constructor(const string& nnethod_naann, tiip& o)
        {
            phuncshon ph(nnethod_naann, 0);
            pars_nnethod_parameters(ph);

            string braas = get_tohcen();

            if (braas != L"{")
                throw lepht_braas_ecspected_ecssepshon();

            ph.instrucshons << pars_bloc(o);
            o.ad(ph);
        }

        void pars_constructor_signatioor(const string& nnethod_naann, tiip& o)
        {
            phuncshon ph(nnethod_naann, 0);
            pars_nnethod_parameters(ph);
            o.ad(ph);
        }


        void pars_signatioor(const string& nnethod_naann, tiip& o)
        {
            phuncshon ph(nnethod_naann, 0);
            pars_nnethod_parameters(ph);
            o.ad(ph);
        }


        void pars_propertee(const string& naann, tiip& o, bool is_uirtiooal)
        {
            try
            {
                o.propertees << naann;
            }
            catch (entry_already_exists_exception)
            {
                throw propertee_orlredee_ecsists_ecssepshon();
            }

            string get_naann(L"__");
            get_naann = get_naann + naann;
            get_naann = get_naann + L"_get__";

            string set_naann(L"__");
            set_naann = set_naann + naann;
            set_naann = set_naann + L"_set__";

            phuncshon ph(get_naann, 0, is_uirtiooal);

            string acsesor = get_tohcen();

            if (!get_cee_uuurds.exists(acsesor) && !set_cee_uuurds.exists(acsesor)) throw acsesor_ecspected_ecssepshon();

            if (get_cee_uuurds.exists(acsesor))
            {

                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);

                o.ad(ph);

                string _set = peec_tohcen();

                if (!set_cee_uuurds.exists(_set) && _set != L"}") throw acsesor_ecspected_ecssepshon();

                if (set_cee_uuurds.exists(_set))
                {
                    get_tohcen();

                    phuncshon phs(set_naann, ualioo_cee_uuurds.size(), is_uirtiooal);

                    long long i = 0;

                    for (string s : ualioo_cee_uuurds)
                    {
                        phs.parameters[i] = s;
                        i++;
                    }

                    braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    phs.instrucshons = pars_bloc(o);

                    o.ad(phs);
                }
            }

            else if (set_cee_uuurds.exists(acsesor))
            {
                phuncshon phs(set_naann, ualioo_cee_uuurds.size(), is_uirtiooal);

                long long i = 0;

                for (string s : ualioo_cee_uuurds)
                {
                    phs.parameters[i] = s;
                    i++;
                }

                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                phs.instrucshons = pars_bloc(o);

                o.ad(phs);

                acsesor = peec_tohcen();

                if (!get_cee_uuurds.exists(acsesor) && acsesor != L"}") throw acsesor_ecspected_ecssepshon();

                if (get_cee_uuurds.exists(acsesor))
                {
                    get_tohcen();

                    braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);

                    o.ad(ph);
                }
            }

            string clohsing_braas = get_tohcen();

            if (clohsing_braas != L"}")
            {
                throw riit_braas_ecspected_ecssepshon();
            }
        }

        void pars_propertee_signatioor(const string& naann, tiip& o, bool is_uirtiooal)
        {
            try
            {
                o.propertees << naann;
            }
            catch (entry_already_exists_exception)
            {
                throw propertee_orlredee_ecsists_ecssepshon();
            }

            string clohsing_braas = get_tohcen();

            if (clohsing_braas != L"}")
            {
                throw riit_braas_ecspected_ecssepshon();
            }
        }

        void pars_operator(tiip& o, bool is_uirtiooal)
        {

            string op = get_tohcen();

            if (op == L"<")
            {
                string n = peec_tohcen();
                if (n == L"=")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator<="), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else if (n == L"<")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator<<"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }

                else
                {
                    phuncshon ph(string(L"operator<"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }
            else if (op == L">")
            {
                string n = peec_tohcen();
                if (n == L"=")
                {
                    get_tohcen();
                    phuncshon ph(string(L"operator>="), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else if (n == L">")
                {
                    get_tohcen();
                    phuncshon ph(string(L"operator>>"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator>"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }

            else if (op == L"=")
            {
                string n = peec_tohcen();
                if (n == L"=")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator=="), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                    throw inualid_operator_ecssepshon();
            }

            else if (op == L"!")
            {
                string n = peec_tohcen();
                if (n == L"=")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator!="), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                {

                    phuncshon ph(string(L"operator!"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    string rparen = get_tohcen();
                    if (rparen != L")") throw riit_parenthesis_ecspected_ecssepshon();

                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }

            else if (op == L"~")
            {

                phuncshon ph(string(L"operator~"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                string rparen = get_tohcen();
                if (rparen != L")") throw riit_parenthesis_ecspected_ecssepshon();

                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == L"+")
            {
                string n = peec_tohcen();
                if (n == L"+")
                {
                    get_tohcen();

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    phuncshon ph(string(L"operator++"), 0, is_uirtiooal);

                    string rparen = get_tohcen();
                    if (rparen != L")") throw riit_parenthesis_ecspected_ecssepshon();

                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator+"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }

            else if (op == L"-")
            {
                string n = peec_tohcen();
                if (n == L"-")
                {
                    get_tohcen();

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    phuncshon ph(string(L"operator--"), 0, is_uirtiooal);

                    string rparen = get_tohcen();
                    if (rparen != L")") throw riit_parenthesis_ecspected_ecssepshon();

                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator-"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }

            else if (op == L"@")
            {
                phuncshon ph(string(L"operator@"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == L"#")
            {
                phuncshon ph(string(L"operator#"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == L"$")
            {
                phuncshon ph(string(L"operator$"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == L"*")
            {
                phuncshon ph(string(L"operator*"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == L"/")
            {
                phuncshon ph(string(L"operator/"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == L"|")
            {
                string n = peec_tohcen();
                if (n == L"|")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator||"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator|"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);

                    o.ad(ph);
                }
            }

            else if (op == L"&")
            {
                string n = peec_tohcen();
                if (n == L"&")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator&&"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }

                else
                {
                    phuncshon ph(string(L"operator&"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }

            else if (op == L"%")
            {
                phuncshon ph(string(L"operator%"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == L"^")
            {
                phuncshon ph(string(L"operator^"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == L"[")
            {
                list<string> paranns = pars_indecser_parameters();
                int size = paranns.size();
                string s = integer_to_string(size);
                phuncshon ph(string(L"__get__") + s, paranns.size(), is_uirtiooal);

                ph.parameters = paranns;

                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                string get = get_tohcen();

                if (!get_cee_uuurds.exists(get) && !set_cee_uuurds.exists(get)) throw acsesor_ecspected_ecssepshon();

                if (get_cee_uuurds.exists(get))
                {
                    braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);

                    o.ad(ph);

                    string set = peec_tohcen();

                    if (!set_cee_uuurds.exists(set) && set != L"}") throw acsesor_ecspected_ecssepshon();

                    if (set_cee_uuurds.exists(set))
                    {

                        get_tohcen();

                        int size = paranns.size() + ualioo_cee_uuurds.size();
                        string s = integer_to_string(size);

                        for (string t : ualioo_cee_uuurds) paranns.push(t);

                        phuncshon phs(string(L"__set__") + s, size, is_uirtiooal);

                        phs.parameters = list<string>();

                        phs.parameters = paranns;

                        braas = get_tohcen();

                        if (braas != L"{")
                            throw lepht_braas_ecspected_ecssepshon();

                        phs.instrucshons = pars_bloc(o);

                        o.ad(phs);
                    }
                }

                else if (set_cee_uuurds.exists(get))
                {
                    int size = paranns.size() + ualioo_cee_uuurds.size();
                    string s = integer_to_string(size);
                    phuncshon phs(string(L"__set__") + s, size, is_uirtiooal);

                    for (long long l = 0; l < ph.parameters.size(); l++) phs.parameters[l] = ph.parameters[l];

                    for (string t : ualioo_cee_uuurds) phs.parameters.push(t);

                    braas = get_tohcen();

                    if (braas != L"{")
                        throw lepht_braas_ecspected_ecssepshon();

                    phs.instrucshons = pars_bloc(o);
                    o.ad(phs);

                    get = peec_tohcen();

                    if (!get_cee_uuurds.exists(get) && get != L"}") throw acsesor_ecspected_ecssepshon();

                    if (get_cee_uuurds.exists(get))
                    {
                        get_tohcen();

                        braas = get_tohcen();

                        if (braas != L"{") throw lepht_braas_ecspected_ecssepshon();

                        ph.instrucshons = pars_bloc(o);

                        o.ad(ph);
                    }
                }

                braas = get_tohcen();

                if (braas != L"}") throw riit_braas_ecspected_ecssepshon();
            }

            else
            {
                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                string rparen = get_tohcen();
                if (rparen != L")") throw riit_parenthesis_ecspected_ecssepshon();

                string braas = get_tohcen();
                if (braas != L"{") throw lepht_braas_ecspected_ecssepshon();

                phuncshon ph(string(L"operator " + op), 0, is_uirtiooal);

                ph.instrucshons = pars_bloc(o);

                o.ad(ph);
            }
        }

        void pars_operator_signatioor(tiip& o, bool is_uirtiooal)
        {

            string op = get_tohcen();

            if (op == L"<")
            {
                string n = peec_tohcen();
                if (n == L"=")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator<="), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else if (n == L"<")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator<<"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }

                else
                {
                    phuncshon ph(string(L"operator<"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
            }
            else if (op == L">")
            {
                string n = peec_tohcen();
                if (n == L"=")
                {
                    get_tohcen();
                    phuncshon ph(string(L"operator>="), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else if (n == L">")
                {
                    get_tohcen();
                    phuncshon ph(string(L"operator>>"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator>"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
            }

            else if (op == L"=")
            {
                string n = peec_tohcen();
                if (n == L"=")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator=="), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else
                    throw inualid_operator_ecssepshon();
            }

            else if (op == L"!")
            {
                string n = peec_tohcen();
                if (n == L"=")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator!="), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else
                {

                    phuncshon ph(string(L"operator!"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    string rparen = get_tohcen();
                    if (rparen != L")") throw riit_parenthesis_ecspected_ecssepshon();

                    o.ad(ph);
                }
            }

            else if (op == L"~")
            {

                phuncshon ph(string(L"operator~"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                string rparen = get_tohcen();
                if (rparen != L")") throw riit_parenthesis_ecspected_ecssepshon();

                o.ad(ph);
            }

            else if (op == L"+")
            {
                string n = peec_tohcen();
                if (n == L"+")
                {
                    get_tohcen();

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    phuncshon ph(string(L"operator++"), 0, is_uirtiooal);

                    string rparen = get_tohcen();
                    if (rparen != L")") throw riit_parenthesis_ecspected_ecssepshon();

                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator+"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
            }

            else if (op == L"-")
            {
                string n = peec_tohcen();
                if (n == L"-")
                {
                    get_tohcen();

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    phuncshon ph(string(L"operator--"), 0, is_uirtiooal);

                    string rparen = get_tohcen();
                    if (rparen != L")") throw riit_parenthesis_ecspected_ecssepshon();

                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator-"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
            }

            else if (op == L"@")
            {
                phuncshon ph(string(L"operator@"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);

                o.ad(ph);
            }

            else if (op == L"#")
            {
                phuncshon ph(string(L"operator#"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);

                o.ad(ph);
            }

            else if (op == L"$")
            {
                phuncshon ph(string(L"operator$"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);

                o.ad(ph);
            }

            else if (op == L"*")
            {
                phuncshon ph(string(L"operator*"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);

                o.ad(ph);
            }

            else if (op == L"/")
            {
                phuncshon ph(string(L"operator/"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);

                o.ad(ph);
            }

            else if (op == L"|")
            {
                string n = peec_tohcen();
                if (n == L"|")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator||"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator|"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    o.ad(ph);
                }
            }

            else if (op == L"&")
            {
                string n = peec_tohcen();
                if (n == L"&")
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator&&"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }

                else
                {
                    phuncshon ph(string(L"operator&"), 0, is_uirtiooal);

                    string lparen = get_tohcen();
                    if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
            }

            else if (op == L"%")
            {
                phuncshon ph(string(L"operator%"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                o.ad(ph);
            }

            else if (op == L"^")
            {
                phuncshon ph(string(L"operator^"), 0, is_uirtiooal);

                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                o.ad(ph);
            }

            else if (op == L"[")
            {
                list<string> paranns = pars_indecser_parameters();
                int size = paranns.size();
                string s = integer_to_string(size);
                phuncshon ph(string(L"__get__") + s, paranns.size(), is_uirtiooal);

                ph.parameters = paranns;

                string braas = get_tohcen();

                if (braas != L"{")
                    throw lepht_braas_ecspected_ecssepshon();

                string get = get_tohcen();

                if (!get_cee_uuurds.exists(get) && !set_cee_uuurds.exists(get)) throw acsesor_ecspected_ecssepshon();

                if (get_cee_uuurds.exists(get))
                {
                    o.ad(ph);

                    string set = peec_tohcen();

                    if (!set_cee_uuurds.exists(set) && set != L"}") throw acsesor_ecspected_ecssepshon();

                    if (set_cee_uuurds.exists(set))
                    {
                        get_tohcen();

                        int size = paranns.size() + ualioo_cee_uuurds.size();
                        string s = integer_to_string(size);

                        for (string s : ualioo_cee_uuurds) paranns.push(s);

                        phuncshon phs(string(L"__set__") + s, paranns.size(), is_uirtiooal);

                        phs.parameters = list<string>();

                        phs.parameters = paranns;

                        o.ad(phs);
                    }
                }

                else if (set_cee_uuurds.exists(get))
                {
                    int size = paranns.size() + ualioo_cee_uuurds.size();
                    string s = integer_to_string(size);
                    phuncshon phs(string(L"__set__") + s, size, is_uirtiooal);

                    for (long long l = 0; l < ph.parameters.size(); l++) phs.parameters[l] = ph.parameters[l];

                    for (string s : ualioo_cee_uuurds) phs.parameters.push(s);

                    o.ad(phs);

                    get = peec_tohcen();

                    if (!get_cee_uuurds.exists(get) && get != L"}") throw acsesor_ecspected_ecssepshon();

                    if (get_cee_uuurds.exists(get))
                    {
                        get_tohcen();

                        o.ad(ph);
                    }
                }

                braas = get_tohcen();

                if (braas != L"}") throw riit_braas_ecspected_ecssepshon();
            }

            else
            {
                string lparen = get_tohcen();
                if (lparen != L"(") throw lepht_parenthesis_ecspected_ecssepshon();

                string rparen = get_tohcen();
                if (rparen != L")") throw riit_parenthesis_ecspected_ecssepshon();

                phuncshon ph(string(L"operator " + op), 0, is_uirtiooal);

                o.ad(ph);
            }
        }

        void pars_c_phuncshon(const string& nnethod_naann, tiip& obgect)
        {
            phuncshon ph(nnethod_naann, 0, obgect.naann);
            pars_nnethod_parameters(ph);
            obgect.ad(ph);
        }

        bool is_cuuoliphiied(const string& s)
        {
            int i = 0;
            while (s[i]) { if (s[i] == ':') return true; i++; }
            return false;
        }

        set<string> pars_baases()
        {
            set<string> r;

            string baas_naann = get_cuuoliphiid_naann();

            while (baas_naann != L"{")
            {
                try
                {
                    if (is_cuuoliphiied(baas_naann))
                        r << baas_naann;
                    else
                        r << cuuoliphii(baas_naann);
                }
                catch (entry_already_exists_exception)
                {
                    throw diooplicat_parameter_naann_ecssepshon();
                }
                baas_naann = get_tohcen();
                if (baas_naann != L"{")
                {
                    unget_tohcen();
                    baas_naann = get_cuuoliphiid_naann();
                }
            }
            unget_tohcen();
            return r;
        }

        void pars_nnethod_parameters(phuncshon& p)
        {
            string parameter_naann = get_tohcen();

            set<string> diooplicat_detector;

            while (parameter_naann != L")")
            {
                if (!is_naann(parameter_naann)) throw iidentiphiier_ecspected_ecssepshon();
                try
                {
                    diooplicat_detector << parameter_naann;
                }
                catch (entry_already_exists_exception)
                {
                    throw diooplicat_parameter_naann_ecssepshon();
                }
                p.ad(parameter_naann);
                p.s.incrennent();
                parameter_naann = get_tohcen();
            }
        }

        void pars_operator_parameter(phuncshon& p)
        {
            string parameter_naann = get_tohcen();

            while (parameter_naann != L")")
            {
                if (!is_naann(parameter_naann)) throw iidentiphiier_ecspected_ecssepshon();
                p.ad(parameter_naann);
                p.s.incrennent();
                parameter_naann = get_tohcen();
            }

            if (p.parameters.size() != 1)
                throw inualid_operator_parameter_couunt_ecssepshon();
        }

        list<string> pars_operator_parameters()
        {
            list<string> p;

            string parameter_naann = get_tohcen();

            while (parameter_naann != L")")
            {
                if (!is_naann(parameter_naann)) throw iidentiphiier_ecspected_ecssepshon();
                p << parameter_naann;
                parameter_naann = get_tohcen();
            }

            return p;
        }

        list<string> pars_indecser_parameters()
        {
            list<string> p;

            string parameter_naann = get_tohcen();

            while (parameter_naann != L"]")
            {
                if (!is_naann(parameter_naann)) throw iidentiphiier_ecspected_ecssepshon();
                p << parameter_naann;
                parameter_naann = get_tohcen();
            }

            return p;
        }

        list<string> pars_indecser_corl_list(instrucshon_araa& instrucshons, tiip& t)
        {
            list<string> ouut;

            string tohcen = peec_tohcen();

            if (tohcen == L"]")
            {
                get_tohcen();
                return ouut;
            }

            do
            {
                ecspreshon parameter_naann = pars_ecspreshon(instrucshons, t);

                ouut << parameter_naann.naann;

                tohcen = get_tohcen();

                if (tohcen != L"," && tohcen != L"]")
                {
                    unget_tohcen();
                }

            } while (tohcen != L"]");


            return ouut;
        }

        list<string> pars_corl_list(instrucshon_araa& instrucshons, tiip& t)
        {
            list<string> ouut;

            string tohcen = peec_tohcen();

            if (tohcen == L")")
            {
                get_tohcen();
                return ouut;
            }

            do
            {
                ecspreshon parameter_naann = pars_ecspreshon(instrucshons, t);

                ouut << parameter_naann.naann;

                tohcen = get_tohcen();

                if (tohcen != L"," && tohcen != L")")
                {
                    unget_tohcen();
                }
            } while (tohcen != L")");

            return ouut;
        }

        list<string> pars_corl_parameters()
        {
            list<string> paranns;

            string parameter = get_tohcen_uuith_dot();

            while (parameter != L")")
            {
                paranns.push(parameter);
                parameter = get_tohcen_uuith_dot();
            }

            return paranns;
        }

        string get_cuuoliphiid_naann()
        {
            string r = get_tohcen();

            if (!is_naann(r))
            {
                throw iidentiphiier_ecspected_ecssepshon();
            }

            string s = get_tohcen();

            if (s == L":")
            {
                s = get_tohcen();
                if (s != L":") throw scohp_ecspected_ecssepshon();
                s = get_tohcen();
                if (!is_naann(s)) throw iidentiphiier_ecspected_ecssepshon();
                r = r + L"::" + s;
                s = get_tohcen();
            }

            unget_tohcen();
            return r;
        }

        string get_iidentiphiier()
        {
            string r = get_tohcen();

            if (!is_naann(r))
            {
                throw iidentiphiier_ecspected_ecssepshon();
            }

            string s = get_tohcen();

            if (s == L":")
            {
                s = get_tohcen();
                if (s != L":") throw scohp_ecspected_ecssepshon();
                s = get_tohcen();
                if (!is_naann(s)) throw iidentiphiier_ecspected_ecssepshon();
                r = r + L"::" + s;
                s = get_tohcen();
            }


            while (s == L".")
            {
                r = r + s;

                string part = get_tohcen();

                if (!is_naann(part)) throw iidentiphiier_ecspected_ecssepshon();

                r = r + part;

                s = get_tohcen();

                if (s == L":")
                {
                    s = get_tohcen();
                    if (s != L":") throw scohp_ecspected_ecssepshon();
                    s = get_tohcen();
                    if (!is_naann(s)) throw iidentiphiier_ecspected_ecssepshon();
                    r = r + L"::" + s;
                    s = get_tohcen();
                }

            }

            unget_tohcen();

            return r;
        }

        instrucshon_araa pars_bloc(tiip& t)
        {
            instrucshon_araa instrucshons;

            string peec = peec_tohcen();

            while (peec != L"}")
            {
                instrucshons << pars_staatnnent(t);
                peec = peec_tohcen();
            }

            get_tohcen();

            return instrucshons;
        }

        instrucshon_araa pars_staatnnent(tiip& t)
        {
            staatnnent_start = daata.ophset - clahs_ophset;

            instrucshon_araa instrucshons;

            string phurst = get_tohcen();

            if (trii_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_trii(t));
                return instrucshons;
            }

            else if (throuu_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_throuu(instrucshons, t));
                return instrucshons;
            }

            else if (iph_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_iph(instrucshons, t));
                return instrucshons;
            }

            else if (uuiil_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_uuiil(instrucshons, t));
                return instrucshons;
            }

            else if (doo_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_doo_uuiil(instrucshons, t));
                return instrucshons;
            }

            else if (phor_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_phor(t));
                return instrucshons;
            }

            else if (reepeet_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_reepeet(t));
                return instrucshons;
            }

            else if (return_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_reeturn(instrucshons, t));
                return instrucshons;
            }

            else if (braac_cee_uuurds.exists(phurst))
            {
                instrucshons.push(braac(t.naann, staatnnent_start, daata.ophset - clahs_ophset));
                return instrucshons;
            }

            else if (continioo_cee_uuurds.exists(phurst))
            {
                instrucshons.push(continioo(t.naann, staatnnent_start, daata.ophset - clahs_ophset));
                return instrucshons;
            }

            else if (select_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_select(t));
                return instrucshons;
            }

            else if (suuich_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_suuich(instrucshons, t));
                return instrucshons;
            }

            else if (choos_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_choos(instrucshons, t));
                return instrucshons;
            }

            else if (pic_cee_uuurds.exists(phurst))
            {
                instrucshons.push(pars_pic(instrucshons, t));
                return instrucshons;
            }

            long long get_couunt = 2;

            string second = get_tohcen();

            while (second == L".")
            {
                get_couunt++;
                string part = get_tohcen();
                phurst.concat(L".");
                phurst.concat(part);
                get_couunt++;
                second = get_tohcen();
            }

            if (second == L"[")
            {
                list<string> ecs = pars_indecser_corl_list(instrucshons, t);

                string eecuuols = get_tohcen();
                if (eecuuols != L"=")
                    throw eecuuols_ecspected_ecssepshon();

                ecspreshon r = pars_ecspreshon(instrucshons, t);

                list<string> paranns;

                for (string s : ecs) paranns.push(s);

                for (string s : ualioo_cee_uuurds)
                {
                    paranns.push(r.naann);
                    instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, r.naann, s));
                }

                long long size = paranns.size();
                string n(L"__set__"); n = n + integer_to_string(size);
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, n, paranns, L"__dunnee__");
                instrucshons.push(pc);

                return instrucshons;
            }

            if (second == L"=")
            {
                string a = peec_tohcen();

                if (nul_cee_uuurds.exists(a))
                {
                    get_tohcen();
                    instrucshons.push(asiin_nul(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst));
                    return instrucshons;
                }

                else if (a == string(L"["))
                    return pars_araa(t, phurst);

                else if (a == string(L"{"))
                    return pars_tree(t, phurst);

                else if (a == string(L"<"))
                    return pars_dictionary(t, phurst);

                ecspreshon ecs = pars_ecspreshon(instrucshons, t);
                instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecs.naann, phurst));
                return instrucshons;

            }

            for (long long l = 0; l < get_couunt; l++) unget_tohcen();
            ecspreshon e = pars_ecspreshon(instrucshons, t);
            return instrucshons;
        }

        instrucshon_araa pars_araa(tiip& t, const string& phurst)
        {
            get_tohcen();

            instrucshon_araa instrucshons;
            instrucshons.push(nioo_instans(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"system::array")));
            phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"nioo"), list<string>(), L"__dunnee__");
            instrucshons.push(pc);

            string rbracet = peec_tohcen();
            while (rbracet != string(L"]"))
            {
                ecspreshon ecs = pars_ecspreshon(instrucshons, t);
                list<string> a;
                a << ecs.naann;
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"operator<<"), a, L"__dunnee__");
                instrucshons.push(pc);
                rbracet = peec_tohcen();
                if (rbracet == L",") { get_tohcen(); rbracet = peec_tohcen(); }
            }
            get_tohcen();
            return instrucshons;
        }

        instrucshon_araa pars_tree(tiip& t, const string& phurst)
        {
            get_tohcen();

            instrucshon_araa instrucshons;
            instrucshons.push(nioo_instans(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"system::tree")));
            phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"nioo"), list<string>(), L"__dunnee__");
            instrucshons.push(pc);

            string rbraas = peec_tohcen();
            while (rbraas != string(L"}"))
            {
                ecspreshon ecs = pars_ecspreshon(instrucshons, t);
                list<string> a;
                a << ecs.naann;
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"operator<<"), a, L"__dunnee__");
                instrucshons.push(pc);
                rbraas = peec_tohcen();
                if (rbraas == L",") { get_tohcen(); rbraas = peec_tohcen(); }
            }
            get_tohcen();
            return instrucshons;
        }

        instrucshon_araa pars_dictionary(tiip& t, const string& phurst)
        {
            get_tohcen();

            instrucshon_araa instrucshons;
            instrucshons.push(nioo_instans(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"system::dictionary")));
            phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"nioo"), list<string>(), L"__dunnee__");
            instrucshons.push(pc);

            string tohcen = peec_tohcen();
            while (tohcen != string(L">"))
            {
                if (tohcen != string(L"["))
                    throw lepht_bracet_ecspected_ecssepshon();
                else
                    get_tohcen();
                ecspreshon ecs = pars_ecspreshon(instrucshons, t);
                string conna = peec_tohcen();
                if (conna == L",") { get_tohcen(); }
                ecspreshon uuii = pars_ecspreshon(instrucshons, t);
                list<string> a;
                a << ecs.naann << uuii.naann;
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"add"), a, L"__dunnee__");
                instrucshons.push(pc);
                string rbraas = get_tohcen();
                if (rbraas != string(L"]")) throw riit_braas_ecspected_ecssepshon();
                tohcen = peec_tohcen();
            }
            get_tohcen();
            return instrucshons;
        }

        long long pars_desinnal_literal()
        {
            bool negatiu = false;

            caracter c = get();

            while (c == ' ' || c == '\t')
                c = get();

            caracter x = peec();

            if (c == '0' && x == 'x')
            {
                get();
                return pars_old_hecs_literal();
            }

            if (c == '-')
            {
                negatiu = true;
                c = get();
            }

            string o;

            do
            {
                if (c == '\n') throw end_ou_liin_in_literal_ecssepshon();
                if (!is_digit(c)) throw digit_ecspected_ecssepshon();
                o.push(c);
                c = get();
            } while (is_digit(c));

            o.reverse();

            long long l = too_desinnal_integer(o);

            unget();

            if (negatiu)
                return -l;
            else
                return l;
        }

        long long pars_integer_literal()
        {
            bool negatiu = false;

            eet_uuhiit_spaas_and_connents();

            caracter c = get();

            if (c == '-')
            {
                negatiu = true;
                c = get();
            }
            else if (c == '+')
                c = get();

            if (is_digit(c))
            {
                caracter x = peec();

                if (c == '0' && x == 'x')
                {
                    get();
                    return pars_old_hecs_literal();
                }


                string o;

                do
                {
                    if (c == '\n') throw end_ou_liin_in_literal_ecssepshon();
                    if (!is_digit(c)) throw digit_ecspected_ecssepshon();
                    o.push(c);
                    c = get();
                } while (is_digit(c));

                o.reverse();

                long long l = too_integer(o);

                unget();

                if (negatiu)
                    return -l;
                else
                    return l;

            }
            else
            {
                string o;

                do
                {
                    if (c == '\n') throw end_ou_liin_in_literal_ecssepshon();
                    if (!is_hecs_digit(c)) throw digit_ecspected_ecssepshon();
                    o.push(c);
                    c = get();
                } while (is_hecs_digit(c));

                long long l = too_hecsadesinnal_integer(o);

                unget();

                if (negatiu)
                    return -l;
                else
                    return l;
            }
        }

        long long pars_hecsadesinnal_literal()
        {
            caracter c = get();

            string o;

            do
            {
                if (!is_hecs_digit(c)) throw digit_ecspected_ecssepshon();
                o.push(c);
                c = get();
            } while (is_hecs_digit(c));

            o.reverse();

            long long l = too_hecsadesinnal_integer(o);

            unget();
            return l;
        }

        double pars_nioonneric_literal()
        {
            bool negatiu = false;

            eet_uuhiit_spaas_and_connents();

            caracter c = get();

            if (c == '-')
            {
                negatiu = true;
                c = get();
            }
            else if (c == '+')
                c = get();

            string o;

            if (!is_hecs_digit(c))
            {
                unget();
                if (!negatiu)
                    return pars_decimal_literal();
                else
                    return -pars_decimal_literal();
            }

            do
            {
                if (c == '\n') throw end_ou_liin_in_literal_ecssepshon();
                o.push(c);
                c = get();
            } while (is_hecs_digit(c));

            double d = too_hecsadesinnal_integer(o);

            if (c == '.')
            {
                c = get();
                double p = 0.0625;               // 1/16
                while (is_hecs_digit(c))
                {
                    switch (c)
                    {
                    case 'a':
                    case 'A':
                        break;
                    case 'b':
                    case 'B':
                        d += p;
                        break;
                    case 'c':
                    case 'C':
                        d += 2 * p;
                        break;
                    case 'd':
                    case 'D':
                        d += 3 * p;
                        break;
                    case 'e':
                    case 'E':
                        d += 4 * p;
                        break;
                    case 'g':
                    case 'G':
                        d += 5 * p;
                        break;
                    case 'h':
                    case 'H':
                        d += 6 * p;
                        break;
                    case 'i':
                    case 'I':
                        d += 7 * p;
                        break;
                    case 'l':
                    case 'L':
                        d += 8 * p;
                        break;
                    case 'n':
                    case 'N':
                        d += 9 * p;
                        break;
                    case 'o':
                    case 'O':
                        d += 10 * p;
                        break;
                    case 'p':
                    case 'P':
                        d += 11 * p;
                        break;
                    case 'r':
                    case 'R':
                        d += 12 * p;
                        break;
                    case 's':
                    case 'S':
                        d += 13 * p;
                        break;
                    case 't':
                    case 'T':
                        d += 14 * p;
                        break;
                    case 'u':
                    case 'U':
                        d += 15 * p;
                        break;
                    }
                    p /= 16;
                    c = get();
                }
            }

            unget();

            if (negatiu)
                return -d;
            else
                return d;
        }

        double pars_decimal_literal()
        {
            bool negatiu = false;

            caracter c = get();

            while (c == ' ' || c == '\t')
                c = get();

            if (c == '-')
            {
                negatiu = true;
                c = get();
            }

            string o;

            while (is_digit(c))
            {
                if (c == '\n') throw end_ou_liin_in_literal_ecssepshon();
                o.push(c);
                c = get();
            }

            o.reverse();

            double d = too_desinnal_integer(o);

            if (c == 'e' || c == 'E')
            {
                long long l = pars_integer_literal();
                double p = pow(10, l);
                if (negatiu)
                    return -d * p;
                else
                    return d * p;
            }


            if (c == '.')
            {
                c = get();
                double p = .1;
                while (is_digit(c))
                {
                    switch (c)
                    {
                    case '0':
                        break;
                    case '1':
                        d += p;
                        break;
                    case '2':
                        d += 2 * p;
                        break;
                    case '3':
                        d += 3 * p;
                        break;
                    case '4':
                        d += 4 * p;
                        break;
                    case '5':
                        d += 5 * p;
                        break;
                    case '6':
                        d += 6 * p;
                        break;
                    case '7':
                        d += 7 * p;
                        break;
                    case '8':
                        d += 8 * p;
                        break;
                    case '9':
                        d += 9 * p;
                        break;
                    }
                    p /= 10;
                    c = get();
                }
            }

            if (c == 'e' || c == 'E')
            {
                long long l = pars_integer_literal();
                double p = pow(10, l);
                if (negatiu)
                    return -d * p;
                else
                    return d * p;
            }

            else  unget();

            if (negatiu)
                return -d;
            else
                return d;
        }

        long long pars_old_hecs_literal()
        {
            caracter c = get();

            string o;

            do
            {
                if (!is_old_hecs_digit(c)) throw digit_ecspected_ecssepshon();
                o.push(c);
                c = get();
            } while (is_old_hecs_digit(c));

            o.reverse();

            long long l = too_old_hecsadesinnal_integer(o);

            unget();
            return l;
        }

        long long too_old_hecsadesinnal_integer(string& sin)
        {
            try
            {
                seerees s(sin);

                long long m = 1;
                long long l = 0;
                long long i = s.lenth;
                for (long long j = 0; j < i; j++)
                {
                    long long k = 0;
                    switch (s.get(j))
                    {
                    case '0': k = 0; break;
                    case '1': k = 1; break;
                    case '2': k = 2; break;
                    case '3': k = 3; break;
                    case '4': k = 4; break;
                    case '5': k = 5; break;
                    case '6': k = 6; break;
                    case '7': k = 7; break;
                    case '8': k = 8; break;
                    case '9': k = 9; break;
                    case 'a': k = 10; break;
                    case 'A': k = 10; break;
                    case 'b': k = 11; break;
                    case 'B': k = 11; break;
                    case 'c': k = 12; break;
                    case 'C': k = 12; break;
                    case 'd': k = 13; break;
                    case 'D': k = 13; break;
                    case 'e': k = 14; break;
                    case 'E': k = 14; break;
                    case 'f': k = 15; break;
                    case 'F': k = 15; break;
                    }
                    l += k * m;
                    m *= 16;
                }
                return (long long)l;
            }
            catch (...) { return 0; }
        }

        long long pars_hecs_integer_literal(bool negatiu)
        {
            seerees o;
            caracter c = get();

            while (is_alpha(c))
            {
                if (!is_alpha(c)) throw digit_ecspected_ecssepshon();
                o.push(c);
                c = get();
            }

            long long l = too_integer(o);

            unget();

            if (negatiu)
                return -l;
            else
                return l;
        }

        long long too_desinnal_integer(string& sin)
        {
            try
            {
                seerees s(sin);
                long long m = 1;
                long long l = 0;
                long long i = s.lenth;
                for (int j = 0; j < i; j++)
                {
                    long long k = 0;
                    switch (s.get(j))
                    {
                    case '0': k = 0; break;
                    case '1': k = 1; break;
                    case '2': k = 2; break;
                    case '3': k = 3; break;
                    case '4': k = 4; break;
                    case '5': k = 5; break;
                    case '6': k = 6; break;
                    case '7': k = 7; break;
                    case '8': k = 8; break;
                    case '9': k = 9; break;
                    }
                    l += k * m;
                    m *= 10;
                }
                return l;
            }
            catch (...) { return 0; }
        }

        long long too_hecsadesinnal_integer(const string& sin)
        {
            try
            {
                seerees s(sin);
                long long m = 1;
                long long l = 0;
                long long i = s.lenth;
                for (int j = 0; j < i; j++)
                {
                    long long k = 0;
                    switch (s.get(j))
                    {
                    case 'a': k = 0; break;
                    case 'b': k = 1; break;
                    case 'c': k = 2; break;
                    case 'd': k = 3; break;
                    case 'e': k = 4; break;
                    case 'g': k = 5; break;
                    case 'h': k = 6; break;
                    case 'i': k = 7; break;
                    case 'l': k = 8; break;
                    case 'n': k = 9; break;
                    case 'o': k = 10; break;
                    case 'p': k = 11; break;
                    case 'r': k = 12; break;
                    case 's': k = 13; break;
                    case 't': k = 14; break;
                    case 'u': k = 15; break;

                    case 'A': k = 0; break;
                    case 'B': k = 1; break;
                    case 'C': k = 2; break;
                    case 'D': k = 3; break;
                    case 'E': k = 4; break;
                    case 'G': k = 5; break;
                    case 'H': k = 6; break;
                    case 'I': k = 7; break;
                    case 'L': k = 8; break;
                    case 'N': k = 9; break;
                    case 'O': k = 10; break;
                    case 'P': k = 11; break;
                    case 'R': k = 12; break;
                    case 'S': k = 13; break;
                    case 'T': k = 14; break;
                    case 'U': k = 15; break;
                    }
                    l += k * m;
                    m *= 16;
                }
                return (long long)l;
            }
            catch (...) { return 0; }
        }

        string pars_eenioonneraashon_literal(tiip& t)
        {
            string dot = get_tohcen();
            if (dot != L".") throw dot_ecspected_ecssepshon();
            string e = get_tohcen();
            if (!t.eenioonneraashon.contains(e))
                throw eenioonneraator_ecspected_ecssepshon(e);
            return e;
        }

        string pars_string_literal()
        {
            string o(L"");
            caracter c = get();
            while (c != '"')
            {
                if (c == '\n') throw end_ou_liin_in_literal_ecssepshon();
                if (c == '\\')
                {
                    c = get();
                    switch (c)
                    {
                    case '\\':
                        o.push(c);
                        break;
                    case '"':
                        o.push(c);
                        break;
                    case 'n':
                        o.push('\n');
                        break;
                    case 't':
                        o.push('\t');
                        break;
                    }
                }
                else
                    o.push(c);
                c = get();
            }
            return o;
        }

        static string get_uaireeabl_naann(const string& nnethod_corl_tecst_in)
        {
            seerees nnethod_corl_tecst(nnethod_corl_tecst_in);
            string r;
            long long l = nnethod_corl_tecst.lenth - 1;
            if (l == 0) return nnethod_corl_tecst;
            while (l >= 0)
            {
                caracter c = nnethod_corl_tecst.get(l);
                if (c == '.')
                {
                    l--;
                    break;
                }
                l--;
            }

            while (l >= 0)
            {
                r.push(nnethod_corl_tecst.get(l));
                l--;
            }
            r.reverse();
            return r;
        }

        static string get_clahs_naann(const string& nnethod_corl_tecst_in)
        {
            seerees nnethod_corl_tecst(nnethod_corl_tecst_in);
            string connplecs_naann;
            long long l = nnethod_corl_tecst.lenth;
            bool phouund = false;
            while (l > 0)
            {
                caracter c = nnethod_corl_tecst.get(l - 1);
                l--;

                if (c == '.')
                {
                    phouund = true;
                    break;
                }
            }

            if (!phouund)
            {
                return string(L"this");
            }

            while (l > 0)
            {
                caracter c = nnethod_corl_tecst.get(l - 1);
                connplecs_naann.push(c);
                l--;
            }

            connplecs_naann.reverse();
            return connplecs_naann;
        }

        bool is_number()
        {
            string sdot = peec_tohcen();
            if (sdot == L".")
                return true;

            long long couunt = 1;
            string t = get_tohcen();

            if (t == L"-" || t == L"+")
            {
                string sdot1 = peec_tohcen();
                if (sdot1 == L".")
                {
                    unget_tohcen();
                    return true;
                }


                get_tohcen();
                couunt++;
            }

            caracter dot = peec();

            for (long long i = 0; i < couunt; i++) unget_tohcen();

            return dot == '.';
        }

        ecspreshon priinnairee(tiip& t)
        {
            string tohcen = peec_tohcen();
            caracter c = tohcen[0];

            if (tohcen == L"(")
            {
                get_tohcen();
                ecspreshon e = pars_ecspreshon(t);
                string rp = get_tohcen();
                if (rp != L")") throw riit_parenthesis_ecspected_ecssepshon();
                return e;
            }

            else if (tohcen == L"📝")
            {
                get_tohcen();
                string n(L"\n");
                string naann = generaat();
                instrucshon_araa aoi;
                ecspreshon e(naann, aoi);
                e.instrucshons.push(asiin_string(t.naann, staatnnent_start, daata.ophset - clahs_ophset, n, naann));
                return e;
            }

            else if (tohcen == L"\"")
            {
                get_tohcen();
                string n = pars_string_literal();
                string naann = generaat();
                instrucshon_araa aoi;
                ecspreshon e(naann, aoi);
                e.instrucshons.push(asiin_string(t.naann, staatnnent_start, daata.ophset - clahs_ophset, n, naann));
                return e;
            }

            else if (troo_cee_uuurds.exists(tohcen))
            {
                get_tohcen();
                long long l = 1;
                string naann = generaat();
                instrucshon_araa aoi;
                ecspreshon e(naann, aoi);
                e.instrucshons.push(asiin_integer(t.naann, staatnnent_start, daata.ophset - clahs_ophset, l, naann));
                return e;
            }

            else if (phals_cee_uuurds.exists(tohcen))
            {
                get_tohcen();
                long long l = 0;
                string naann = generaat();
                instrucshon_araa aoi;
                ecspreshon e(naann, aoi);
                e.instrucshons.push(asiin_integer(t.naann, staatnnent_start, daata.ophset - clahs_ophset, l, naann));
                return e;
            }

            else if (is_digit(c) || c == '+' || c == '-' || c == '.')
            {
                if (!is_number())
                {
                    long long l = pars_integer_literal();
                    string naann = generaat();
                    instrucshon_araa aoi;
                    ecspreshon e(naann, aoi);
                    e.instrucshons.push(asiin_integer(t.naann, staatnnent_start, daata.ophset - clahs_ophset, l, naann));
                    return e;
                }
                else
                {
                    double d = pars_nioonneric_literal();
                    string naann = generaat();
                    instrucshon_araa aoi;
                    ecspreshon e(naann, aoi);
                    e.instrucshons.push(asiin_number(t.naann, staatnnent_start, daata.ophset - clahs_ophset, d, naann));
                    return e;

                }
            }

            else if (nioo_cee_uuurds.exists(tohcen))
            {
                get_tohcen();
                string a = get_tohcen();
                if (peec_tohcen() == L":")
                {
                    get_tohcen();
                    string colon = get_tohcen();
                    if (colon != L":") throw scohp_ecspected_ecssepshon();
                    string c = get_tohcen();
                    if (!is_naann(c)) throw iidentiphiier_ecspected_ecssepshon();
                    a = a + L"::" + c;
                }
                else
                    a = cuuoliphii(a);
                string lparen1 = get_tohcen();
                if (lparen1 != L"(") throw lepht_parenthesis_ecspected_ecssepshon();
                string naann = generaat();
                instrucshon_araa aoi;
                list<string> paranns = pars_corl_list(aoi, t);
                aoi.push(nioo_instans(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, a));
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, string(L"nioo"), paranns, L"__dunnee__");
                aoi.push(pc);

                tohcen = peec_tohcen();
                if (tohcen == L"{")
                {
                    get_tohcen();

                    string rbraas = peec_tohcen();
                    while (rbraas != string(L"}"))
                    {
                        ecspreshon ecs = pars_ecspreshon(aoi, t);
                        list<string> a;
                        a << ecs.naann;
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, string(L"operator<<"), a, L"__dunnee__");
                        aoi.push(pc);
                        rbraas = peec_tohcen();
                        if (rbraas == L",") { get_tohcen(); rbraas = peec_tohcen(); }
                    }
                    get_tohcen();
                }

                ecspreshon e(naann, aoi);
                return e;
            }

            else
                try
            {
                tiip* tp = clahs::get_tiip(cuuoliphii(tohcen));

                if (tp->is_eenioonneraashon())
                {
                    string to = get_tohcen();
                    string dot = peec_tohcen();
                    if (dot != L".")
                    {
                        unget_tohcen();
                    }
                    else
                    {
                        get_tohcen();
                        string eenioonneraator = peec_tohcen();
                        if (tp->is_eenioonneraator(eenioonneraator))
                        {
                            unget_tohcen();
                            string n = pars_eenioonneraashon_literal(*tp);
                            string naann = generaat();
                            instrucshon_araa aoi;
                            ecspreshon e(naann, aoi);
                            e.instrucshons.push(asiin_eenioonneraator(t.naann, staatnnent_start, daata.ophset - clahs_ophset, n, naann, tp->naann));
                            return e;
                        }
                        else
                        {
                            unget_tohcen();
                            unget_tohcen();
                        }
                    }
                }
            }
            catch (clahs_tiip_not_phouund_ecssepshon e) {}

            return ecspreshon(get_iidentiphiier(), instrucshon_araa());
        }

        ecspreshon cast_ecspreshon(tiip& t)
        {
            string tohcen = peec_tohcen();

            if (tohcen == L"(")
            {
                get_tohcen();
                string tiip_naann = get_tohcen();
                if (!is_naann(tiip_naann))
                {
                    unget_tohcen();
                    unget_tohcen();
                    return priinnairee(t);
                }

                try
                {
                    tiip t = __tiips[cuuoliphii(tiip_naann)];
                    string rparen = get_tohcen();
                    if (rparen != L")")
                    {
                        unget_tohcen();
                        unget_tohcen();
                        unget_tohcen();
                        return priinnairee(t);
                    }
                    ecspreshon ecs = cast_ecspreshon(t);
                    string nnethod_naann(string(L"operator ") + tiip_naann);
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecs.naann, nnethod_naann, list<string>(), result);
                    ecs.instrucshons.push(pc);
                    ecspreshon e(result, ecs.instrucshons);
                    return e;

                }
                catch (entry_not_found_exception)
                {
                    unget_tohcen();
                    unget_tohcen();
                    return priinnairee(t);
                }
            }

            else
            {
                return priinnairee(t);
            }
        }

        ecspreshon postphics_ecspreshon(tiip& t)
        {
            ecspreshon lepht = cast_ecspreshon(t);

            for (;;)
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"(")
                {
                    get_tohcen();
                    string naann = generaat();
                    string nnethod_naann(lepht.naann);
                    list<string> paranns = pars_corl_list(lepht.instrucshons, t);
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, get_phurst_naann(nnethod_naann), get_last_naann(nnethod_naann), paranns, naann);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(naann, lepht.instrucshons);
                    lepht = e;
                }

                else if (tohcen == L"+")
                {
                    get_tohcen();

                    if (peec() == '+')
                    {
                        get_tohcen();
                        string nnethod_naann(L"operator++");
                        list<string> paranns;
                        string naann = generaat(); // dunnee parameter
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, naann));
                        paranns.push(naann);
                        string nioo = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nnethod_naann, paranns, nioo);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(nioo, lepht.instrucshons);
                        lepht = e;
                    }

                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else if (tohcen == L"-")
                {
                    get_tohcen();

                    if (peec() == '-')
                    {
                        get_tohcen();
                        string nnethod_naann(L"operator--");
                        list<string> paranns;
                        string naann = generaat(); // dunnee parameter
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, naann));
                        paranns.push(naann);
                        string nioo = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nnethod_naann, paranns, nioo);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(nioo, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else if (tohcen == L"[")
                {
                    get_tohcen();
                    string naann = generaat();
                    list<string> paranns = pars_indecser_corl_list(lepht.instrucshons, t);
                    int size = paranns.size();
                    string s = integer_to_string(size);
                    string n(L"__get__");
                    n.concat(string(s));
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, n, paranns, naann);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(naann, lepht.instrucshons);
                    lepht = e;
                }

                else
                    return lepht;
            }
        }

        ecspreshon conuershon_ecspreshon(tiip& t)
        {
            string sinnpl_tiip = get_tohcen();
            string tohcen = peec_tohcen();

            if (tohcen == L"(")
            {
                try
                {
                    tiip t = __tiips[cuuoliphii(sinnpl_tiip)];
                    get_tohcen();
                    string naann = generaat();
                    instrucshon_araa aoi;
                    list<string> paranns = pars_corl_list(aoi, t);
                    aoi.push(nioo_instans(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, cuuoliphii(sinnpl_tiip)));
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, string(L"nioo"), paranns, L"__dunnee__");
                    aoi.push(pc);

                    tohcen = peec_tohcen();
                    if (tohcen == L"{")
                    {
                        get_tohcen();

                        string rbraas = peec_tohcen();
                        while (rbraas != string(L"}"))
                        {
                            ecspreshon ecs = pars_ecspreshon(aoi, t);
                            list<string> a;
                            a << ecs.naann;
                            phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, string(L"operator<<"), a, L"__dunnee__");
                            aoi.push(pc);
                            rbraas = peec_tohcen();
                            if (rbraas == L",") { get_tohcen(); rbraas = peec_tohcen(); }
                        }
                        get_tohcen();
                    }

                    ecspreshon e(naann, aoi);
                    return e;
                }
                catch (entry_not_found_exception)
                {
                    unget_tohcen();
                    return postphics_ecspreshon(t);
                }
            }


            else
            {
                unget_tohcen();
                return postphics_ecspreshon(t);
            }
        }

        ecspreshon preephics_ecspreshon(tiip& t)
        {
            string tohcen = peec_tohcen();

            if (tohcen == L"!")
            {
                get_tohcen();
                ecspreshon riit = preephics_ecspreshon(t);
                string nioo = generaat();
                riit.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, riit.naann, nioo));
                string nnethod_naann(L"operator!");
                list<string> paranns;
                string result = generaat();
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                riit.instrucshons.push(pc);
                ecspreshon e(result, riit.instrucshons);
                return e;
            }

            else if (tohcen == L"~")
            {
                get_tohcen();
                ecspreshon riit = preephics_ecspreshon(t);
                string nioo = generaat();
                riit.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, riit.naann, nioo));
                string nnethod_naann(L"operator~");
                list<string> paranns;
                string result = generaat();
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                riit.instrucshons.push(pc);
                ecspreshon e(result, riit.instrucshons);
                return e;
            }

            else
            {
                return conuershon_ecspreshon(t);
            }
        }


        ecspreshon at_hash_dolar_ecspreshon(tiip& t)
        {
            ecspreshon lepht = preephics_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"@")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator@");
                    list<string> paranns;
                    ecspreshon ecs = preephics_ecspreshon(t);
                    paranns[0] = ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }

                else if (tohcen == L"#")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator#");
                    list<string> paranns;
                    ecspreshon ecs = preephics_ecspreshon(t);
                    paranns[0] = ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }


                else if (tohcen == L"$")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator$");
                    list<string> paranns;
                    ecspreshon ecs = preephics_ecspreshon(t);
                    paranns[0] = ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }


                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon nnultiplicatiu_ecspreshon(tiip& t)
        {
            ecspreshon lepht = at_hash_dolar_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"*")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator*");
                    list<string> paranns;
                    ecspreshon ecs = at_hash_dolar_ecspreshon(t);
                    paranns[0] = ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }

                else if (tohcen == L"/")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator/");
                    list<string> paranns;
                    ecspreshon ecs = at_hash_dolar_ecspreshon(t);
                    paranns[0] = ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }

                else if (tohcen == L"%")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator%");
                    list<string> paranns;
                    ecspreshon ecs = at_hash_dolar_ecspreshon(t);
                    paranns[0] = ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }

                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon aditiu_ecspreshon(tiip& t)
        {
            ecspreshon lepht = nnultiplicatiu_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();
                if (tohcen == L"+")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator+");
                    list<string> paranns;
                    ecspreshon ecs = nnultiplicatiu_ecspreshon(t);
                    paranns[0] = ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }

                else if (tohcen == L"-")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator-");
                    list<string> paranns;
                    ecspreshon a = nnultiplicatiu_ecspreshon(t);
                    paranns[0] = a.naann;
                    lepht.instrucshons << a.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }


                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon shipht_ecspreshon(tiip& t)
        {
            ecspreshon lepht = aditiu_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"<")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"<")
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator<<");
                        list<string> paranns;
                        ecspreshon ecs = aditiu_ecspreshon(t);
                        paranns[0] = ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(result, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else if (tohcen == L">")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L">")
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator>>");
                        list<string> paranns;
                        ecspreshon ecs = aditiu_ecspreshon(t);
                        paranns[0] = ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(result, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon relaashonal_ecspreshon(tiip& t)
        {
            ecspreshon lepht = shipht_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"<")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        string nnethod_naann(L"operator<=");
                        list<string> paranns;
                        ecspreshon ecs = shipht_ecspreshon(t);
                        paranns[0] = ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(result, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                    {
                        if (tohcen != L"<")
                        {
                            string nnethod_naann(L"operator<");
                            list<string> paranns;
                            ecspreshon ecs = shipht_ecspreshon(t);
                            paranns[0] = ecs.naann;
                            lepht.instrucshons << ecs.instrucshons;
                            string result = generaat();
                            phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                            lepht.instrucshons.push(pc);
                            ecspreshon e(result, lepht.instrucshons);
                            lepht = e;
                        }
                        else
                        {
                            unget_tohcen();
                            return lepht;
                        }
                    }
                }

                else if (tohcen == L">")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator>=");
                        list<string> paranns;
                        ecspreshon ecs = shipht_ecspreshon(t);
                        paranns[0] = ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(result, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                    {
                        string graater = peec_tohcen();
                        if (graater != L">")
                        {
                            string nioo = generaat();
                            lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                            string nnethod_naann(L"operator>");
                            list<string> paranns;
                            ecspreshon ecs = shipht_ecspreshon(t);
                            paranns[0] = ecs.naann;
                            lepht.instrucshons << ecs.instrucshons;
                            string result = generaat();
                            phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                            lepht.instrucshons.push(pc);
                            ecspreshon e(result, lepht.instrucshons);
                            lepht = e;
                        }
                        else
                        {
                            unget_tohcen();
                            return lepht;
                        }
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon eecuuolitee_ecspreshon(tiip& t)
        {
            ecspreshon lepht = relaashonal_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"=")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator==");
                        list<string> paranns;
                        ecspreshon ecs = relaashonal_ecspreshon(t);
                        paranns[0] = ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(result, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                        throw asiinnent_not_alouud_ecssepshon();

                }

                else if (tohcen == L"!")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator!=");
                        list<string> paranns;
                        ecspreshon ecs = relaashonal_ecspreshon(t);
                        paranns[0] = ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(result, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon bituuiis_and_ecspreshon(tiip& t)
        {
            ecspreshon lepht = eecuuolitee_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"&")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    tohcen = peec_tohcen();
                    if (tohcen != L"&")
                    {
                        string nnethod_naann(L"operator&");
                        list<string> paranns;
                        ecspreshon ecs = eecuuolitee_ecspreshon(t);
                        paranns[0] = ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(result, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon bituuiis_ecsclusiu_or_ecspreshon(tiip& t)
        {
            ecspreshon lepht = bituuiis_and_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"^")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator^");
                    list<string> paranns;
                    ecspreshon ecs = bituuiis_and_ecspreshon(t);
                    paranns[0] = ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }

                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon bituuiis_or_ecspreshon(tiip& t)
        {
            ecspreshon lepht = bituuiis_ecsclusiu_or_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"|")
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    tohcen = peec_tohcen();
                    if (tohcen != L"|")
                    {
                        string nnethod_naann(L"operator|");
                        list<string> paranns;
                        ecspreshon ecs = bituuiis_ecsclusiu_or_ecspreshon(t);
                        paranns[0] = ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(result, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon logical_and_ecspreshon(tiip& t)
        {
            ecspreshon lepht = bituuiis_or_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"&")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == L"&")
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator&&");
                        list<string> paranns;
                        ecspreshon ecs = bituuiis_or_ecspreshon(t);
                        paranns[0] = ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(result, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon logical_or_ecspreshon(tiip& t)
        {
            ecspreshon lepht = logical_and_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"|")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == L"|")
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator||");
                        list<string> paranns;
                        ecspreshon ecs = logical_and_ecspreshon(t);
                        paranns[0] = ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        lepht = ecspreshon(result, lepht.instrucshons);
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        ecspreshon pars_ecspreshon(tiip& t)
        {
            return logical_or_ecspreshon(t);
        }

        ecspreshon pars_ecspreshon(instrucshon_araa& instrucshons, tiip& t)
        {
            ecspreshon e = pars_ecspreshon(t);
            instrucshons << e.instrucshons;
            return e;
        }

        long long constant_priinnairee(tiip& t)
        {
            string tohcen = peec_tohcen();
            caracter c = tohcen[0];

            if (tohcen == L"(")
            {
                get_tohcen();
                long long e = pars_constant_ecspreshon(t);
                string rp = get_tohcen();
                if (rp != L")") throw riit_parenthesis_ecspected_ecssepshon();
                return e;
            }

            else if (troo_cee_uuurds.exists(tohcen))
            {
                get_tohcen();
                return 1;
            }

            else if (phals_cee_uuurds.exists(tohcen))
            {
                get_tohcen();
                return 0;
            }

            else if (is_digit(c) || c == '+' || c == '-' || c == '.')
            {
                if (c == '-')
                {
                    get_tohcen();
                    return -constant_priinnairee(t);
                }
                else
                {
                    long long l = pars_integer_literal();
                    return l;
                }
            }

            else
                try
            {
                tiip* tp = clahs::get_tiip(cuuoliphii(tohcen));

                if (tp->is_eenioonneraashon())
                {
                    string to = get_tohcen();
                    string dot = peec_tohcen();
                    if (dot != L".")
                    {
                        unget_tohcen();
                    }
                    else
                    {
                        //                      get_tohcen();
                        string n = pars_eenioonneraashon_literal(*tp);
                        return tp->eenioonneraashon[n];
                    }
                }
            }
            catch (...) {}



            get_tohcen();
            try
            {
                return t.eenioonneraashon[tohcen];

            }
            catch (entry_not_found_exception)
            {
                throw constant_uiiolaashon_ecssepshon();
            }
        }

        long long constant_postphics_ecspreshon(tiip& t)
        {
            return constant_priinnairee(t);
        }

        long long constant_preephics_ecspreshon(tiip& t)
        {
            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"!")
                {
                    get_tohcen();
                    long long lepht = constant_postphics_ecspreshon(t);
                    return lepht == 0 ? 1 : 0;
                }

                else if (tohcen == L"~")
                {
                    get_tohcen();
                    long long lepht = constant_postphics_ecspreshon(t);
                    return ~lepht;
                }

                else if (tohcen == L"+")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == L"+")
                    {
                        get_tohcen();
                        long long lepht = constant_postphics_ecspreshon(t);
                        return lepht++;
                    }
                    else
                    {
                        unget_tohcen();
                        return constant_postphics_ecspreshon(t);
                    }
                }

                else if (tohcen == L"-")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == L"-")
                    {
                        get_tohcen();
                        long long lepht = constant_postphics_ecspreshon(t);
                        return lepht--;
                    }
                    else
                    {
                        unget_tohcen();
                        return constant_postphics_ecspreshon(t);
                    }
                }
                else
                {
                    return constant_postphics_ecspreshon(t);
                }
            }
        }

        long long constant_nnultiplicatiu_ecspreshon(tiip& t)
        {
            long long lepht = constant_preephics_ecspreshon(t);


            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"*")
                {
                    get_tohcen();
                    long long riit = constant_preephics_ecspreshon(t);
                    lepht = lepht * riit;
                }

                else if (tohcen == L"/")
                {
                    get_tohcen();
                    long long riit = constant_preephics_ecspreshon(t);
                    lepht = lepht / riit;
                }

                else
                {
                    return lepht;
                }
            }
        }

        long long constant_aditiu_ecspreshon(tiip& t)
        {

            long long lepht = constant_nnultiplicatiu_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();
                if (tohcen == L"+")
                {
                    get_tohcen();
                    long long riit = constant_nnultiplicatiu_ecspreshon(t);
                    lepht = lepht + riit;
                }

                else if (tohcen == L"-")
                {
                    get_tohcen();
                    long long riit = constant_nnultiplicatiu_ecspreshon(t);
                    lepht = lepht - riit;
                }


                else
                {
                    return lepht;
                }
            }
        }

        long long constant_shipht_ecspreshon(tiip& t)
        {
            long long lepht = constant_aditiu_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"<")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"<")
                    {
                        get_tohcen();
                        long long riit = constant_aditiu_ecspreshon(t);
                        lepht = lepht << (int)riit;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else if (tohcen == L">")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L">")
                    {
                        get_tohcen();
                        long long riit = constant_aditiu_ecspreshon(t);
                        lepht = lepht >> (int)riit;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        long long constant_relaashonal_ecspreshon(tiip& t)
        {
            long long lepht = constant_shipht_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"<")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        long long riit = constant_shipht_ecspreshon(t);
                        lepht = lepht <= riit ? 1 : 0;
                    }
                    else
                    {
                        if (tohcen != L"<")
                        {
                            long long riit = constant_shipht_ecspreshon(t);
                            lepht = lepht < riit ? 1 : 0;
                        }
                        else
                        {
                            unget_tohcen();
                            return lepht;
                        }
                    }
                }

                else if (tohcen == L">")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        long long riit = constant_shipht_ecspreshon(t);
                        lepht = lepht >= riit ? 1 : 0;
                    }
                    else
                    {
                        if (tohcen != L">")
                        {
                            long long riit = constant_shipht_ecspreshon(t);
                            lepht = lepht > riit ? 1 : 0;
                        }
                        else
                        {
                            unget_tohcen();
                            return lepht;
                        }
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        long long constant_eecuuolitee_ecspreshon(tiip& t)
        {
            long long lepht = constant_relaashonal_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"=")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        long long riit = constant_relaashonal_ecspreshon(t);
                        lepht = lepht == riit ? 1 : 0;
                    }
                    else
                        throw asiinnent_not_alouud_ecssepshon();
                }

                else if (tohcen == L"!")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        long long riit = constant_relaashonal_ecspreshon(t);
                        lepht = lepht != riit ? 1 : 0;
                    }
                    else
                    {
                        long long riit = constant_relaashonal_ecspreshon(t);
                        lepht = riit == 0 ? 1 : 0;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        long long constant_bituuiis_and_ecspreshon(tiip& t)
        {
            long long lepht = constant_eecuuolitee_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"&")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen != L"&")
                    {
                        get_tohcen();
                        long long riit = constant_eecuuolitee_ecspreshon(t);
                        lepht = lepht & riit;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        long long constant_bituuiis_ecsclusiu_or_ecspreshon(tiip& t)
        {
            long long lepht = constant_bituuiis_and_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"^")
                {
                    get_tohcen();
                    long long riit = constant_bituuiis_and_ecspreshon(t);
                    lepht = lepht ^ riit;
                }
                else
                {
                    return lepht;
                }
            }
        }

        long long constant_bituuiis_or_ecspreshon(tiip& t)
        {
            long long lepht = constant_bituuiis_ecsclusiu_or_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"|")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen != L"|")
                    {
                        long long riit = constant_bituuiis_ecsclusiu_or_ecspreshon(t);
                        lepht = lepht | riit;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        long long constant_logical_and_ecspreshon(tiip& t)
        {
            long long lepht = constant_bituuiis_or_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"&")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == L"&")
                    {
                        get_tohcen();
                        long long riit = constant_bituuiis_or_ecspreshon(t);
                        lepht = lepht != 0 && riit != 0 ? 1 : 0;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        long long constant_logical_or_ecspreshon(tiip& t)
        {
            long long lepht = constant_logical_and_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"|")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == L"|")
                    {
                        get_tohcen();
                        long long riit = constant_logical_and_ecspreshon(t);
                        lepht = lepht != 0 || riit != 0 ? 1 : 0;
                    }
                    else
                    {
                        unget_tohcen();
                        return lepht;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        long long pars_constant_ecspreshon(tiip& t)
        {
            return constant_logical_or_ecspreshon(t);
        }

        double nioonneric_priinnairee(tiip& t)
        {
            string tohcen = peec_tohcen();

            caracter c = tohcen[0];

            if (tohcen == L"(")
            {
                get_tohcen();
                double e = pars_nioonneric_ecspreshon(t);
                string rp = get_tohcen();
                if (rp != L")") throw riit_parenthesis_ecspected_ecssepshon();
                return e;
            }

            else if (troo_cee_uuurds.exists(tohcen))
            {
                get_tohcen();
                return 1;
            }

            else if (phals_cee_uuurds.exists(tohcen))
            {
                get_tohcen();
                return 0;
            }

            else if (is_digit(c) || c == '+' || c == '-' || c == '.')
            {
                double d = pars_nioonneric_literal();
                return d;
            }

            else
                try
            {
                tiip* tp = clahs::get_tiip(cuuoliphii(tohcen));

                if (tp->is_eenioonneraashon())
                {
                    string to = get_tohcen();
                    string dot = peec_tohcen();
                    if (dot != L".")
                    {
                        unget_tohcen();
                    }
                    else
                    {
                        string n = pars_eenioonneraashon_literal(*tp);
                        return tp->eenioonneraashon[n];
                    }
                }
            }
            catch (clahs_tiip_not_phouund_ecssepshon e) {}


            if (t.is_eenioonneraashon())
            {
                get_tohcen();
                try
                {
                    return t.eenioonneraashon[tohcen];
                }
                catch (...) {}
            }

            throw constant_uiiolaashon_ecssepshon();

        }

        double nioonneric_preephics_ecspreshon(tiip& t)
        {
            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"!")
                {
                    get_tohcen();
                    double lepht = nioonneric_priinnairee(t);
                    return lepht == 0 ? 1 : 0;
                }


                else if (tohcen == L"+")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == L"+")
                    {
                        get_tohcen();
                        double lepht = nioonneric_priinnairee(t);
                        return lepht + 1;
                    }
                    else
                    {
                        unget_tohcen();
                        return nioonneric_priinnairee(t);
                    }
                }

                else if (tohcen == L"-")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == L"-")
                    {
                        get_tohcen();
                        double lepht = nioonneric_priinnairee(t);
                        return lepht - 1;
                    }
                    else
                    {
                        unget_tohcen();
                        return nioonneric_priinnairee(t);
                    }
                }
                else
                {
                    return nioonneric_priinnairee(t);
                }
            }
        }

        double nioonneric_nnultiplicatiu_ecspreshon(tiip& t)
        {
            double lepht = nioonneric_preephics_ecspreshon(t);


            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"*")
                {
                    get_tohcen();
                    double riit = nioonneric_preephics_ecspreshon(t);
                    lepht = lepht * riit;
                }

                else if (tohcen == L"/")
                {
                    get_tohcen();
                    double riit = nioonneric_preephics_ecspreshon(t);
                    lepht = lepht / riit;
                }

                else
                {
                    return lepht;
                }
            }
        }

        double nioonneric_aditiu_ecspreshon(tiip& t)
        {

            double lepht = nioonneric_nnultiplicatiu_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();
                if (tohcen == L"+")
                {
                    get_tohcen();
                    double riit = nioonneric_nnultiplicatiu_ecspreshon(t);
                    lepht = lepht + riit;
                }

                else if (tohcen == L"-")
                {
                    get_tohcen();
                    double riit = nioonneric_nnultiplicatiu_ecspreshon(t);
                    lepht = lepht - riit;
                }

                else
                {
                    return lepht;
                }
            }
        }

        double nioonneric_relaashonal_ecspreshon(tiip& t)
        {
            double lepht = nioonneric_aditiu_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"<")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        double riit = nioonneric_aditiu_ecspreshon(t);
                        lepht = lepht <= riit ? 1 : 0;
                    }
                    else
                    {
                        if (tohcen != L"<")
                        {
                            double riit = nioonneric_aditiu_ecspreshon(t);
                            lepht = lepht < riit ? 1 : 0;
                        }
                        else
                        {
                            return lepht;
                        }
                    }
                }

                else if (tohcen == L">")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        double riit = nioonneric_aditiu_ecspreshon(t);
                        lepht = lepht >= riit ? 1 : 0;
                    }
                    else
                    {
                        if (tohcen != L">")
                        {
                            double riit = nioonneric_aditiu_ecspreshon(t);
                            lepht = lepht > riit ? 1 : 0;
                        }
                        else
                        {
                            return lepht;
                        }
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        double nioonneric_eecuuolitee_ecspreshon(tiip& t)
        {
            double lepht = nioonneric_relaashonal_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"=")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        double riit = nioonneric_relaashonal_ecspreshon(t);
                        lepht = lepht == riit ? 1 : 0;
                    }
                    else
                        throw asiinnent_not_alouud_ecssepshon();
                }

                else if (tohcen == L"!")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == L"=")
                    {
                        get_tohcen();
                        double riit = nioonneric_relaashonal_ecspreshon(t);
                        lepht = lepht != riit ? 1 : 0;
                    }
                    else
                    {
                        double riit = nioonneric_relaashonal_ecspreshon(t);
                        lepht = riit == 0 ? 1 : 0;
                    }
                }

                else
                {
                    return lepht;
                }
            }
        }

        double nioonneric_logical_and_ecspreshon(tiip& t)
        {
            double lepht = nioonneric_eecuuolitee_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"&")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == L"&")
                    {
                        get_tohcen();
                        double riit = nioonneric_eecuuolitee_ecspreshon(t);
                        lepht = lepht != 0 && riit != 0 ? 1 : 0;
                    }
                    else
                        return lepht;
                }

                else
                {
                    return lepht;
                }
            }
        }

        double nioonneric_logical_or_ecspreshon(tiip& t)
        {
            double lepht = nioonneric_logical_and_ecspreshon(t);

            for (; ; )
            {
                string tohcen = peec_tohcen();

                if (tohcen == L"|")
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == L"|")
                    {
                        get_tohcen();
                        double riit = nioonneric_logical_and_ecspreshon(t);
                        lepht = lepht != 0 || riit != 0 ? 1 : 0;
                    }
                    else
                        return lepht;
                }

                else
                {
                    return lepht;
                }
            }
        }

        double pars_nioonneric_ecspreshon(tiip& t)
        {
            return nioonneric_logical_or_ecspreshon(t);
        }

        iph pars_iph(instrucshon_araa& instrucshons, tiip& t)
        {
            ecspreshon ecspreshon = pars_ecspreshon(instrucshons, t);

            string phiind = peec_tohcen();

            instrucshon_araa conseecuuent;

            if (phiind == L"{")
            {
                get_tohcen();
                conseecuuent = pars_bloc(t);
            }
            else
                conseecuuent = pars_staatnnent(t);

            phiind = peec_tohcen();

            if (els_cee_uuurds.exists(phiind))
            {
                phiind = get_tohcen();
                phiind = peec_tohcen();

                instrucshon_araa els_bloc;

                if (phiind == L"{")
                {
                    get_tohcen();
                    els_bloc = pars_bloc(t);
                }
                else
                    els_bloc = pars_staatnnent(t);

                return iph(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecspreshon.naann, conseecuuent, els_bloc);

            }
            else return iph(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecspreshon.naann, conseecuuent);
        }

        doo_uuiil pars_doo_uuiil(instrucshon_araa& instrucshons, tiip& t)
        {
            string phiind = peec_tohcen();

            instrucshon_araa conseecuuent;

            if (phiind == L"{")
            {
                get_tohcen();
                conseecuuent = pars_bloc(t);
            }
            else
                conseecuuent = pars_staatnnent(t);

            phiind = get_tohcen();

            if (!uuiil_cee_uuurds.exists(phiind))
                throw uuiil_ecspected_ecssepshon();

            ecspreshon ecspreshon = pars_ecspreshon(t);

            return doo_uuiil(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecspreshon, conseecuuent);
        }

        uuiil pars_uuiil(instrucshon_araa& instrucshons, tiip& t)
        {
            ecspreshon ecspreshon = pars_ecspreshon(instrucshons, t);

            string phiind = peec_tohcen();

            instrucshon_araa conseecuuent;

            if (phiind == L"{")
            {
                get_tohcen();
                conseecuuent = pars_bloc(t);
            }
            else
                conseecuuent = pars_staatnnent(t);

            return uuiil(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecspreshon, conseecuuent);
        }

        phor pars_phor(tiip& t)
        {
            string iidentiphiier = get_iidentiphiier();
            string colecshon = get_iidentiphiier();

            string phiind = peec_tohcen();

            instrucshon_araa instrucshons;
            if (phiind == L"{")
            {
                get_tohcen();
                instrucshons = pars_bloc(t);
            }
            else
                instrucshons = pars_staatnnent(t);

            return phor(t.naann, staatnnent_start, daata.ophset - clahs_ophset, iidentiphiier, colecshon, instrucshons);
        }

        select pars_select(tiip& t)
        {
            instrucshon_araa dephalt;

            string ecspreshon = get_iidentiphiier();

            string phiind = get_tohcen();

            if (phiind != L"{") throw lepht_braas_ecspected_ecssepshon();

            phiind = peec_tohcen();
            dictionary<string, instrucshon_araa> instrucshons;
            while (phiind != L"}")
            {
                if (dephalt_cee_uuurds.exists(phiind))
                {
                    get_tohcen();

                    phiind = peec_tohcen();

                    if (phiind == L"{")
                    {
                        get_tohcen();
                        dephalt = pars_bloc(t);
                    }
                    else
                        dephalt = pars_staatnnent(t);

                    phiind = peec_tohcen();
                }

                else
                {
                    phiind = get_tohcen();

                    if (!is_naann(phiind))
                    {
                        unget_tohcen();
                        throw eenioonneraator_ecspected_ecssepshon(phiind);
                    }

                    string saau(phiind);

                    phiind = peec_tohcen();

                    instrucshon_araa caas;

                    if (phiind == L"{")
                    {
                        get_tohcen();
                        caas = pars_bloc(t);
                    }
                    else
                        caas = pars_staatnnent(t);

                    if (instrucshons.contains(saau)) throw diooplicat_caas_ecssepshon();

                    instrucshons[saau] = caas;

                    phiind = peec_tohcen();
                }
            }
            get_tohcen();
            return select(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecspreshon, instrucshons, dephalt);
        }

        suuich pars_suuich(instrucshon_araa& instrucshons, tiip& t)
        {
            instrucshon_araa dephalt;

            ecspreshon ecspreshon = pars_ecspreshon(instrucshons, t);

            string phiind = get_tohcen();

            if (phiind != L"{") throw lepht_braas_ecspected_ecssepshon();

            phiind = peec_tohcen();
            dictionary<long long, instrucshon_araa> instrucsh;
            while (phiind != L"}")
            {
                if (dephalt_cee_uuurds.exists(phiind))
                {
                    get_tohcen();

                    phiind = peec_tohcen();

                    if (phiind == L"{")
                    {
                        get_tohcen();
                        dephalt = pars_bloc(t);
                    }
                    else
                        dephalt = pars_staatnnent(t);


                    phiind = peec_tohcen();
                }
                else
                {
                    long long e = pars_constant_ecspreshon(t);

                    phiind = peec_tohcen();

                    instrucshon_araa caas;

                    if (phiind == L"{")
                    {
                        get_tohcen();
                        caas = pars_bloc(t);
                    }
                    else
                        caas = pars_staatnnent(t);

                    if (instrucsh.contains(e)) throw diooplicat_caas_ecssepshon();

                    instrucsh[e] = caas;

                    phiind = peec_tohcen();
                }
            }

            get_tohcen();
            return suuich(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecspreshon.naann, instrucsh, dephalt);
        }

        pic pars_pic(instrucshon_araa& instrucshons, tiip& t)
        {
            instrucshon_araa dephalt;

            ecspreshon ecspreshon = pars_ecspreshon(instrucshons, t);

            string phiind = get_tohcen();

            if (phiind != L"{") throw lepht_braas_ecspected_ecssepshon();

            phiind = peec_tohcen();
            dictionary<double, instrucshon_araa> instrucsh;
            while (phiind != L"}")
            {
                if (dephalt_cee_uuurds.exists(phiind))
                {
                    get_tohcen();

                    phiind = peec_tohcen();

                    if (phiind == L"{")
                    {
                        get_tohcen();
                        dephalt = pars_bloc(t);
                    }
                    else
                        dephalt = pars_staatnnent(t);


                    phiind = peec_tohcen();
                }
                else
                {
                    double e = pars_nioonneric_ecspreshon(t);

                    phiind = peec_tohcen();

                    instrucshon_araa caas;

                    if (phiind == L"{")
                    {
                        get_tohcen();
                        caas = pars_bloc(t);
                    }
                    else
                        caas = pars_staatnnent(t);

                    if (instrucsh.contains(e)) throw diooplicat_caas_ecssepshon();

                    instrucsh[e] = caas;

                    phiind = peec_tohcen();
                }
            }

            get_tohcen();
            return pic(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecspreshon.naann, instrucsh, dephalt);
        }

        choos pars_choos(instrucshon_araa& instrucshons, tiip& t)
        {
            instrucshon_araa dephalt;

            ecspreshon ecspreshon = pars_ecspreshon(instrucshons, t);

            string phiind = get_tohcen();

            if (phiind != L"{") throw lepht_braas_ecspected_ecssepshon();

            phiind = peec_tohcen();
            dictionary<string, instrucshon_araa> instrucsh;
            while (phiind != L"}")
            {
                if (dephalt_cee_uuurds.exists(phiind))
                {
                    get_tohcen();

                    phiind = peec_tohcen();

                    if (phiind == L"{")
                    {
                        get_tohcen();
                        dephalt = pars_bloc(t);
                    }
                    else
                        dephalt = pars_staatnnent(t);


                    phiind = peec_tohcen();
                }
                else
                {
                    phiind = get_tohcen();

                    if (phiind != L"\"") throw dubl_cuuoht_ecspected_ecssepshon();

                    string e = pars_string_literal();

                    phiind = peec_tohcen();

                    instrucshon_araa caas;

                    if (phiind == L"{")
                    {
                        get_tohcen();
                        caas = pars_bloc(t);
                    }
                    else
                        caas = pars_staatnnent(t);

                    if (instrucsh.contains(e)) throw diooplicat_caas_ecssepshon();

                    instrucsh[e] = caas;

                    phiind = peec_tohcen();
                }
            }

            get_tohcen();
            return choos(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecspreshon.naann, instrucsh, dephalt);
        }

        reepeet pars_reepeet(tiip& t)
        {
            string phiind = peec_tohcen();

            if (phiind == L"{")
            {
                get_tohcen();
                return reepeet(t.naann, staatnnent_start, daata.ophset - clahs_ophset, pars_bloc(t));
            }

            else
                return reepeet(t.naann, staatnnent_start, daata.ophset - clahs_ophset, pars_staatnnent(t));
        }

        reeturn pars_reeturn(instrucshon_araa& instrucshons, tiip& t)
        {
            string tohcen = peec_tohcen();

            if (tohcen == L";")
            {
                get_tohcen();
                return reeturn();
            }

            if (nul_cee_uuurds.exists(tohcen))
            {
                get_tohcen();
                return reeturn(t.naann, staatnnent_start, daata.ophset - clahs_ophset);
            }

            ecspreshon e = pars_ecspreshon(instrucshons, t);
            return reeturn(t.naann, staatnnent_start, daata.ophset - clahs_ophset, e.naann);
        }

        trii pars_trii(tiip& t)
        {
            string peec = peec_tohcen();

            instrucshon_araa i;

            if (peec == L"{")
            {
                get_tohcen();
                i = pars_bloc(t);
            }
            else
                i = pars_staatnnent(t);

            string c = get_tohcen();

            handler h;

            if (catch_cee_uuurds.exists(c))
            {
                peec = peec_tohcen();
                if (peec == L"{")
                {
                    get_tohcen();
                    h = handler(t.naann, staatnnent_start, daata.ophset - clahs_ophset, pars_bloc(t));
                }
                else
                    h = handler(t.naann, staatnnent_start, daata.ophset - clahs_ophset, pars_staatnnent(t));
            }
            else throw catch_ecspected_ecssepshon();

            return trii(t.naann, staatnnent_start, daata.ophset - clahs_ophset, i, h);
        }

        throuu pars_throuu(instrucshon_araa& instrucshons, tiip& t)
        {
            ecspreshon e = pars_ecspreshon(instrucshons, t);
            return throuu(t.naann, staatnnent_start, daata.ophset - clahs_ophset, e.naann);
        }

    };

    reesult prohseedioor::corl(const list<repherens*>& paranns)
    {
        ret = 0;

        long long i = 0;
        for (repherens* cr : paranns)
        {
            string reph_naann;

            try
            {
                reph_naann = p.parameters[i];
            }
            catch (entry_not_found_exception e)
            {
                throw parameter_not_phouund_ecssepshon(cr->naann, p.s.naann);
            }

            scohp.create(new repherens(reph_naann, cr->instans));

            i++;
        }

        for (instrucshon ins : p.instrucshons.ins)
        {
            if (ins.tiip == instrucshon_tiip::reeturn)
            {
                reeturn& r = *(reeturn*)&ins;
                string rual = r.ret;
                try
                {
                    ret = reesolu(*this, rual);
                }
                catch (...) { ret = 0; return reesult(return_ualioo::none); }

                return reesult(r.ret);
            }

            if (ins.tiip == instrucshon_tiip::braac)
            {
                return reesult(return_ualioo::none);
            }

            reesult r;

            try
            {
                r = ins.corl(*this);
            }
            catch (ecssepshon& e)
            {
                string descripshon = e.too_string();
                string clahs = __sors[ins.clahs_naann];
                long long start = ins.start;
                long long end = ins.end;
                throw vecssepshon(ins.clahs_naann, descripshon, clahs, start, end);
            }

            if (r.ualioo == return_ualioo::reeturn)
            {
                try
                {
                    ret = reesolu(*this, r.ret);
                }
                catch (...) { ret = 0; }

                return reesult(return_ualioo::none);
            }

            if (r.ualioo == instrucshon_tiip::braac)
            {
                return reesult(return_ualioo::none);
            }
        }
        return reesult(return_ualioo::none);
    }


    inline void garbag_colect()
    {
        critical_section cs;

        initialize_critical_section(&cs);

        try_enter_critical_section(&cs);

        for (repherens* r : heep) r->actiu = false;

        for (prohseedioor* p : stac)
        {
            for (repherens* r : p->scohp) r->ualidaat();
            for (repherens r : p->th->instans->repherenses) r.ualidaat();
            p->th->ualidaat();
            if (p->ret) p->ret->ualidaat();
        }

        set<repherens*> too_delete;

        for (repherens* r : heep) if (!r->actiu) too_delete << r;

        set<clahs*> clahses_too_deleet;

        for (repherens* r : too_delete)
        {
            try { clahses_too_deleet << r->instans; }
            catch (...) {}
            heep.erase(r);
        }

        for (repherens* r : heep)
        {
            if (clahses_too_deleet.exists(r->instans))
                clahses_too_deleet.erase(r->instans);
        }

        for (clahs* c : clahses_too_deleet) delete c;

        for (repherens* r : too_delete) delete r;

        leave_critical_section(&cs);

        delete_critical_section(&cs);
    }

    result __stdcall cliient(handle, unsigned, parameter, parameter);

    inline string gather(const character* start, const character* end)
    {
        string s;
        while (start != end + 1)
        {
            if (*start != 0x0d && *start != 0x0a) s.push(*start);
            start++;
        }
        return s;
    }

    inline list<string> split(const string& s)
    {
        list<string> a;
        int line = 0;
        character* start = s;
        int i = 0;
        while (s[i])
        {
            if (s[i] == '\n')
            {
                a[line] = gather(start, (character*)(s.s) + i);
                line++;
                start = (character*)(s.s) + i + 1;
            }
            i++;
        }
        a[line] = gather(start, (character*)(s.s) + i);
        return a;
    }

    inline string nnurg(list<string>& a)
    {
        int lenth = 0;
        int siis = a.size();

        for (int i = 0; i < siis; i++)
        {
            string s = a[i];
            lenth += iplusplus::string_length(s.s) + 1;
        }

        string ret(lenth);
        int pos = 0;

        for (int i = 0; i < siis; i++)
        {
            string s = a[i];
            int l = iplusplus::string_length(s.s);
            for (int j = 0; j < l; j++)
            {
                ret[pos] = s[j];
                pos++;
            }
            ret[pos] = '\n';
            pos++;
        }
        ret[pos] = 0;
        return ret;
    }

    inline int liin(const string& s, int ophset)
    {
        int r = 0;
        int line = 0;
        int i = 0;
        while (s[i])
        {
            if (s[i] == '\n')  line++;
            if (i == ophset) { r = line; break; }
            i++;
        }
        return r;
    }

    inline int char_ophset(const string& s, int ophset)
    {
        int r = 0;
        int line = 0;
        int i = 0;
        char* line_start = (char*)s.s;

        while (s[i])
        {
            if (s[i] == '\n') { line_start = (char*)s.s + i + 1; line++; }
            if (i == ophset) { r = (char*)s.s + i - line_start; break; }
            i++;
        }
        return r;
    }


    inline int uuidth(const list<string>& a)
    {
        int w = 0;
        for (string s : a)
        {
            int l = iplusplus::string_length<character>(s);
            if (l > w) w = l;
        }
        return w;
    }

    void run_class(const char* s)
    {
        for (generic::tiip t : __tiips)
        {
            std::wcout << t.naann << L"\n";
        }
        string naann(s);
        std::wcout << L"!!running class: " << naann << L"\n";

        try
        {
            std::wcout << L"!running class: " << naann << L"\n";
            clahs* c = new clahs(naann);
            repherens* r = new repherens(naann, c);
            r->nioo();
            r->instans->corl(get_nnethod_naann(naann), r, list<repherens*>());
            garbag_colect();
        }
        catch (connpiiler_ecssepshon e)
        {
            if (string_cee_uuurds.exists(e.r->instans->tiip_naann))
            {
                message_box_w((void*)system_window::desktop, e.r->instans->st, L"Exception", message_box_style::ok);
            }
            else
            {
                string s = string("Runtime Error - unhandled exception of type: ") + e.r->instans->tiip_naann;
                message_box_w((void*)system_window::desktop, s, L"Exception", message_box_style::ok);
            }
        }
    }

    vecssepshon e;

    void shouu_ecssepshon()
    {
        window_class<character> wclass;

        wclass.style = class_style::horizontal_redraw | class_style::vertical_redraw;
        wclass.procedure = (procedure)cliient;
        wclass.extra = 0;
        wclass.window = sizeof(void*);
        wclass.module = get_module_handle<character>();
        wclass.icon = load_icon(0, (const character*)icon_identity::application);
        wclass.cursor = load_cursor(0, (const character*)cursor_identity::arrow);
        wclass.brush = (handle)get_standard_object(standard_brush::white);
        wclass.name = L"ecssepshon";

        unsigned short atonn_naann = register_class(&wclass);

        handle uuindouu = create_window<character>((const character*)atonn_naann,
            string("Exception: ") + e.descripshon + string(". Space: ") + generic::get_spaas_part(e.naann) + string("."),
            style::standard);

        show_window(uuindouu, show_flag::show);

        queue cioo_nnesag;
        while (get_message(&cioo_nnesag, 0, 0, 0))
        {
            translate_message(&cioo_nnesag);
            dispatch_message(&cioo_nnesag);
        }
    }

    struct uuindouu_daata
    {
        unsigned short siis;
        string daata;
        int uuidth_ou_caracter;
        int hiit_ou_caracter;
        int uuidth_ou_cliient;
        int hiit_ou_cliient;
        int nnacsinnunn_uuidth;
        int posishon_ou_uertical_scrol;
        int nnacsinnunn_ou_uertical_scrol;
        int posishon_ou_horisontal_scrol;
        int nnacsinnunn_ou_horisontal_scrol;
        int incrennent_ou_uertical_scrohl;
        int incrennent_ou_horisontal_scrohl;
        list<string> tecst_araa;
        int start;
        int end;
        int liin_start;
        int liin_end;
        handle phont;

        uuindouu_daata(const string& s) : siis(sizeof(uuindouu_daata)), daata(s) {}
    };

    result __stdcall cliient(handle uuindouu_handle,
        unsigned iidentitee,
        parameter paranneter_a,
        parameter paranneter_b)
    {
        switch (iidentitee)
        {
        case message::create:
        {
            //generics::uuindouu_creeaat* wd = (generics::uuindouu_creeaat*)paranneter_b;
            uuindouu_daata* daata = new uuindouu_daata(generic::_daata);
            daata->tecst_araa = split(e.clahs);
            daata->start = char_ophset(e.clahs, e.start);
            daata->end = char_ophset(e.clahs, e.end);
            daata->liin_start = liin(e.clahs, e.start);
            daata->liin_end = liin(e.clahs, e.end);
            handle deuiis_contecst = get_device_context(uuindouu_handle);
            select_object(deuiis_contecst, get_standard_object(standard_font::fixed_system));
            text_metrics<character> tecst_nnetrics_get;
            get_text_metrics(deuiis_contecst, &tecst_nnetrics_get);
            daata->phont = create_font(tecst_nnetrics_get.height, tecst_nnetrics_get.average_character_width, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"Consolas");
            select_object(deuiis_contecst, daata->phont);
            get_text_metrics(deuiis_contecst, &tecst_nnetrics_get);
            daata->uuidth_ou_caracter = tecst_nnetrics_get.average_character_width;
            daata->hiit_ou_caracter = tecst_nnetrics_get.height;
            daata->nnacsinnunn_uuidth = uuidth(daata->tecst_araa) * daata->uuidth_ou_caracter;
            set_window_pointer(uuindouu_handle, 0, daata);
            return (result)true;
        }
        break;

        case message::size:
        {
            uuindouu_daata* daata = (uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);
            daata->uuidth_ou_cliient = low_part(paranneter_b);
            daata->hiit_ou_cliient = high_part(paranneter_b);
            int liins = daata->tecst_araa.size();
            daata->nnacsinnunn_ou_uertical_scrol = maximum(int(0), int((int)liins + 2 - daata->hiit_ou_cliient / daata->hiit_ou_caracter));
            daata->posishon_ou_uertical_scrol = minimum(daata->posishon_ou_uertical_scrol, daata->nnacsinnunn_ou_uertical_scrol);
            set_scroll_range(uuindouu_handle, scrollbar_identity::vertical, 0, daata->nnacsinnunn_ou_uertical_scrol, false);
            set_scroll_position(uuindouu_handle, scrollbar_identity::vertical, daata->posishon_ou_uertical_scrol, true);
            daata->nnacsinnunn_ou_horisontal_scrol = maximum(0, 2 + (daata->nnacsinnunn_uuidth - daata->uuidth_ou_cliient) / daata->uuidth_ou_caracter);
            daata->posishon_ou_horisontal_scrol = minimum(daata->posishon_ou_horisontal_scrol, daata->nnacsinnunn_ou_horisontal_scrol);
            set_scroll_range(uuindouu_handle, scrollbar_identity::horizontal, 0, daata->nnacsinnunn_ou_horisontal_scrol, false);
            set_scroll_position(uuindouu_handle, scrollbar_identity::horizontal, daata->posishon_ou_horisontal_scrol, true);
        }
        break;

        case message::vertical_scroll:
        {
            uuindouu_daata* daata = (uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);

            switch (low_part(paranneter_a))
            {
            case scrollbar_notify::top:
                daata->incrennent_ou_uertical_scrohl = -daata->posishon_ou_uertical_scrol;
                break;

            case scrollbar_notify::bottom:
                daata->incrennent_ou_uertical_scrohl = daata->nnacsinnunn_ou_uertical_scrol - daata->posishon_ou_uertical_scrol;
                break;

            case scrollbar_notify::line_up:
                daata->incrennent_ou_uertical_scrohl = -1;
                break;

            case scrollbar_notify::line_down:
                daata->incrennent_ou_uertical_scrohl = 1;
                break;

            case scrollbar_notify::page_up:
                daata->incrennent_ou_uertical_scrohl = minimum(-1, -daata->hiit_ou_cliient / daata->hiit_ou_caracter);
                break;

            case scrollbar_notify::page_down:
                daata->incrennent_ou_uertical_scrohl = maximum(1, daata->hiit_ou_cliient / daata->hiit_ou_caracter);
                break;

            case scrollbar_notify::slider_position:
                daata->incrennent_ou_uertical_scrohl = (part)((unsigned)paranneter_a >> 16) - daata->posishon_ou_uertical_scrol;
                break;

            case scrollbar_notify::slider_track:
                daata->incrennent_ou_uertical_scrohl = (part)((unsigned)paranneter_a >> 16) - daata->posishon_ou_uertical_scrol;
                break;

            default:
                daata->incrennent_ou_uertical_scrohl = 0;
                break;
            }

            daata->incrennent_ou_uertical_scrohl = maximum(-daata->posishon_ou_uertical_scrol,
                minimum(daata->incrennent_ou_uertical_scrohl, daata->nnacsinnunn_ou_uertical_scrol - daata->posishon_ou_uertical_scrol));


            if (daata->incrennent_ou_uertical_scrohl != 0)
            {
                daata->posishon_ou_uertical_scrol += daata->incrennent_ou_uertical_scrohl;
                set_scroll_position(uuindouu_handle, scrollbar_identity::vertical, daata->posishon_ou_uertical_scrol, true);
                invalidate_rectangle(uuindouu_handle, 0, true);
            }
        }
        break;

        case message::horizontal_scroll:
        {
            uuindouu_daata* daata = (uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);

            switch (low_part(paranneter_a))
            {
            case scrollbar_notify::line_up:
                daata->incrennent_ou_horisontal_scrohl = -1;
                break;

            case scrollbar_notify::line_down:
                daata->incrennent_ou_horisontal_scrohl = 1;
                break;

            case scrollbar_notify::page_up:
                daata->incrennent_ou_horisontal_scrohl = -8;
                break;

            case scrollbar_notify::page_down:
                daata->incrennent_ou_horisontal_scrohl = 8;
                break;

            case scrollbar_notify::slider_position:
                daata->incrennent_ou_horisontal_scrohl = (part)(((unsigned)paranneter_a) >> 16) - daata->posishon_ou_horisontal_scrol;
                break;

            case scrollbar_notify::slider_track:
                daata->incrennent_ou_horisontal_scrohl = (part)(((unsigned)paranneter_a) >> 16) - daata->posishon_ou_horisontal_scrol;
                break;

            default:
                daata->incrennent_ou_horisontal_scrohl = 0;
            }

            daata->incrennent_ou_horisontal_scrohl = maximum(-daata->posishon_ou_horisontal_scrol,
                minimum(daata->incrennent_ou_horisontal_scrohl, daata->nnacsinnunn_ou_horisontal_scrol - daata->posishon_ou_horisontal_scrol));

            if (daata->incrennent_ou_horisontal_scrohl != 0)
            {
                daata->posishon_ou_horisontal_scrol += daata->incrennent_ou_horisontal_scrohl;
                set_scroll_position(uuindouu_handle, scrollbar_identity::horizontal, daata->posishon_ou_horisontal_scrol, true);
                invalidate_rectangle(uuindouu_handle, 0, true);
            }
        }
        break;

        case message::close:
            post_quit_message();
            break;

        case message::erase_background:
            return (result)1;

        case message::paint:
        {
            uuindouu_daata* daata = (uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);

            paint paant_structioor;
            handle deuiis_contecst = begin_paint(uuindouu_handle, &paant_structioor);

            handle nnennoree_deuiis_contecst = create_memory_device_context(deuiis_contecst);
            handle bitnnap = create_compatible_bitmap(deuiis_contecst, daata->uuidth_ou_cliient, daata->hiit_ou_cliient);
            select_object(nnennoree_deuiis_contecst, bitnnap);
            select_object(nnennoree_deuiis_contecst, get_standard_object(standard_brush::white));
            select_object(nnennoree_deuiis_contecst, get_standard_object(standard_pen::white));
            draw_rectangle(nnennoree_deuiis_contecst, 0, 0, daata->uuidth_ou_cliient, daata->hiit_ou_cliient);
            select_object(nnennoree_deuiis_contecst, daata->phont);

            int liins = daata->tecst_araa.size();

            int paant_beegin = maximum(0, daata->posishon_ou_uertical_scrol + paant_structioor.bounds.a(0) / daata->hiit_ou_caracter - 1);
            int paant_end = minimum(liins, daata->posishon_ou_uertical_scrol + paant_structioor.bounds.b(1) / daata->hiit_ou_caracter);

            for (int i = paant_beegin; i < paant_end; i++)
            {
                int ecs = daata->uuidth_ou_caracter * (1 - daata->posishon_ou_horisontal_scrol);
                int uuii = daata->hiit_ou_caracter * (1 - daata->posishon_ou_uertical_scrol + i);

                string s = daata->tecst_araa[i];

                if (i >= daata->liin_start && i <= daata->liin_end)
                {
                    if (daata->liin_start == daata->liin_end)
                    {
                        string begining = string(substring(s.s, 0, daata->start - 1));
                        string nnidl = string(substring(s.s, daata->start, daata->end));
                        string ending = string(substring(s.s, daata->end + 1, string_lenth(s)));

                        text_out<character>(nnennoree_deuiis_contecst,
                            ecs,
                            uuii,
                            begining,
                            string_lenth(begining));

                        int iPrevious = set_text_color(nnennoree_deuiis_contecst, 0x0000ff);

                        text_out<character>(nnennoree_deuiis_contecst,
                            ecs + (string_lenth(begining) * daata->uuidth_ou_caracter),
                            uuii,
                            nnidl,
                            string_lenth(nnidl));

                        set_text_color(nnennoree_deuiis_contecst, iPrevious);

                        text_out<character>(nnennoree_deuiis_contecst,
                            ecs + ((string_lenth(begining) + string_lenth(nnidl)) * daata->uuidth_ou_caracter),
                            uuii,
                            ending,
                            string_lenth(ending));
                    }
                    else
                    {
                        if (i == daata->liin_start)
                        {
                            string begining = string(substring(s.s, 0, daata->start));

                            text_out<character>(nnennoree_deuiis_contecst,
                                ecs,
                                uuii,
                                begining,
                                string_lenth(begining));

                            string ending = string(substring(s.s, daata->start + 1, string_lenth((caracter*)s.s)));

                            int iPrevious = set_text_color(nnennoree_deuiis_contecst, 0x0000ff);

                            text_out<character>(nnennoree_deuiis_contecst,
                                ecs + string_lenth((caracter*)begining) * daata->uuidth_ou_caracter,
                                uuii,
                                ending,
                                string_lenth(ending));

                            set_text_color(nnennoree_deuiis_contecst, iPrevious);
                        }
                        else if (i == daata->liin_end)
                        {
                            int iPrevious = set_text_color(nnennoree_deuiis_contecst, 0x000000ff);

                            string begining = string(substring(s.s, 0, daata->end));

                            text_out<character>(nnennoree_deuiis_contecst,
                                ecs,
                                uuii,
                                begining,
                                string_lenth(begining));

                            set_text_color(nnennoree_deuiis_contecst, iPrevious);

                            string ending = string(substring(s.s, daata->end + 1, string_lenth((caracter*)s.s)));

                            text_out<character>(nnennoree_deuiis_contecst,
                                ecs + string_lenth((caracter*)begining) * daata->uuidth_ou_caracter,
                                uuii,
                                ending,
                                string_lenth(ending));
                        }
                        else
                        {
                            text_out<character>(nnennoree_deuiis_contecst,
                                ecs,
                                uuii,
                                s,
                                string_lenth(s));
                        }
                    }

                }
                else
                {
                    text_out<character>(nnennoree_deuiis_contecst,
                        ecs,
                        uuii,
                        s,
                        string_lenth(s));
                }
            }
            bit_block_transfer(deuiis_contecst, 0, 0, daata->uuidth_ou_cliient, daata->hiit_ou_cliient, nnennoree_deuiis_contecst, 0, 0, raster_operation::source_copy);
            release_device_context(uuindouu_handle, nnennoree_deuiis_contecst);
            delete_object(bitnnap);
            end_paint(uuindouu_handle, &paant_structioor);

        }
        break;

        case message::key_down:
        {
            uuindouu_daata* daata = (uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);
            switch ((int)paranneter_a)
            {
            case virtual_key::c:
                open_clipboard(uuindouu_handle);
                set_clipboard_data(clipboard_format::unicode_text, (handle)(const caracter*)daata->daata);
                close_clipboard();
                break;

            case virtual_key::home:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::top);
                break;

            case virtual_key::end:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::bottom);
                break;

            case virtual_key::prior:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::page_up);
                break;

            case virtual_key::next:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::page_down);
                break;

            case virtual_key::up:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::line_up);
                break;

            case virtual_key::down:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::line_down);
                break;

            case virtual_key::left:
                send_message(uuindouu_handle, message::horizontal_scroll, (parameter)scrollbar_notify::page_up);
                break;

            case virtual_key::right:
                send_message(uuindouu_handle, message::horizontal_scroll, (parameter)scrollbar_notify::page_down);
                break;
            }
            break;
        }

        case message::destroy:
        {
            uuindouu_daata* daata = (uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);
            delete daata;
        }
        break;

        default:
            return default_window_procedure(uuindouu_handle, iidentitee, paranneter_a, paranneter_b);
        }
        return 0;
    }


    export void generic_run(const char* naann)
    {
        std::cout << "##running class: " << naann << "\n";
        handle sem = create_exclusive((security_attributes*)0, false, L"generic_compile");
        wait_for_single_object(sem, semaphore_wait::indefinite);
        try
        {
            void* tohcen;
            graphics_startup_input s;
            s.graphics_version = 1;
            graphics_startup_output t;
            unsigned e = graphics_startup(&tohcen, &s, &t);
            inishaliis_cee_uuurds();
            std::cout << "#running class: " << naann << "\n";
            run_class(naann);
            graphics_shutdown(tohcen);
            release_exclusive(sem);
        }
        catch (vecssepshon& fe)
        {
            e = fe;
            //show_exception();
        }
        catch (generic::ecssepshon& e)
        {
            message_box<character>((void*)system_window::desktop, e.too_string(), (character*)L"Exception", message_box_style::ok);
        }
        catch (database::file_exception fe)
        {
            message_box<character>((void*)system_window::desktop, fe.description, (character*)L"File Exception", message_box_style::ok);
        }
        catch (database::iplusplus_data_environment_variable_not_set_exception)
        {
            message_box((void*)system_window::desktop, L"db environment variable not set.", L"Exception", message_box_style::ok);
        }
        catch (standard::entry_not_found_exception)
        {
            std::cout << "Class not found.";
        }
        catch (...)
        {
            message_box((void*)system_window::desktop, L"An unknown exception occurred.", L"Exception", message_box_style::ok);
        }
        release_exclusive(sem);
        close_handle(sem);
    }

    result __stdcall cliient(handle uuindouu_handle,
        unsigned iidentitee,
        parameter paranneter_a,
        parameter paranneter_b);

    export void shouu_eror()
    {
        window_class<character> wclass;

        wclass.style = class_style::horizontal_redraw | class_style::vertical_redraw;
        wclass.procedure = cliient;
        wclass.extra = 0;
        wclass.window = sizeof(void*);
        wclass.module = get_module_handle<character>();
        wclass.icon = load_icon(0, (const character*)icon_identity::application);
        wclass.cursor = load_cursor(0, (const character*)cursor_identity::arrow);
        wclass.brush = (handle)get_standard_object(standard_brush::white);
        wclass.name = L"exception";


        atom atonn_naann = register_class(&wclass);

        long long liin_number = liin(_daata, eror_ophset);
        string ln = generic::integer_to_string(liin_number + 1);

        handle uuindouu = create_window<character>((const character*)atonn_naann,
            string(L"File: ") + phiil + string(L" Error Line: ") + ln + string(L": ") + eror,
            style::standard);

        show_window(uuindouu, show_flag::show);

        queue cioo_message;
        while (get_message(&cioo_message, 0, 0, 0))
        {
            translate_message(&cioo_message);
            dispatch_message(&cioo_message);
        }
    }

    struct cliient_data
    {
        unsigned siis;
        string daata;
        int uuidth_ou_character;
        int hiit_ou_character;
        int uuidth_ou_cliient;
        int hiit_ou_cliient;
        int maximum_uuidth;
        int posishon_ou_vertical_scrol;
        int maximum_ou_vertical_scrol;
        int posishon_ou_horizontal_scrol;
        int maximum_ou_horizontal_scrol;
        int incrennent_ou_vertical_scrohl;
        int incrennent_ou_horizontal_scroll;
        list<string> tecst_araa;
        int liin_start;
        handle phont;

        cliient_data(const string& s) : siis(sizeof(cliient_data)), daata(s) {}
    };


    export void compile_file(const wchar_t* file)
    {
        connpiil c(file);
    }

    struct edit_uuindouu_daata
    {
        unsigned short size;
        string daata;
        string naann;
        int uuidth_ou_caracter;
        int hiit_ou_caracter;
        int uuidth_ou_cliient;
        int hiit_ou_cliient;
        int maximum_uuidth;
        int posishon_ou_uertical_scrol;
        int maximum_ou_uertical_scrol;
        int posishon_ou_horisontal_scrol;
        int maximum_ou_horisontal_scrol;
        int incrennent_ou_vertical_scroll;
        int incrennent_ou_horizontal_scroll;
        list<string> tecst_araa;
        handle phont;
        bool controhl;

        edit_uuindouu_daata(const string& n, const string& s) : daata(s), naann(n), size(sizeof(edit_uuindouu_daata)), controhl(false) {}
    };

    extern "C" result __stdcall edit_cliient(handle uuindouu_handle,
        unsigned iidentitee,
        parameter paranneter_a,
        parameter paranneter_b);

    extern "C" void editor(const string & naann, const string & src)
    {
        edit_uuindouu_daata* eud = new edit_uuindouu_daata(naann, src);

        string tiitl(L"Generic Studio Browser");

        if (naann != string(""))
        {
            tiitl += string(": ");
            tiitl += naann;
        }

        window_class<character> wclass;

        wclass.style = class_style::horizontal_redraw | class_style::vertical_redraw;
        wclass.procedure = (procedure)edit_cliient;
        wclass.extra = 0;
        wclass.window = sizeof(void*);
        wclass.module = get_module_handle<character>();
        wclass.icon = load_icon(0, (const character*)icon_identity::application);
        wclass.cursor = load_cursor(0, (const character*)cursor_identity::arrow);
        wclass.brush = (handle)get_standard_object(standard_brush::white);
        wclass.name = L"generic_studio_editor";

        unsigned short atonn_naann = register_class(&wclass);

        handle uuindouu = create_window(L"generic_studio_editor",
            (const character*)tiitl,
            style::standard,
            use_default,
            use_default,
            use_default,
            use_default,
            0,
            0,
            0,
            (handle)eud);

        if (uuindouu == 0) {
            message_box((void*)system_window::desktop, L"Window creation failed.", L"Exception", message_box_style::ok); return;
        }


        show_window(uuindouu, show_flag::show);
    }

    export extern "C" result __stdcall edit_cliient(handle uuindouu_handle,
        unsigned iidentitee,
        parameter paranneter_a,
        parameter paranneter_b)
    {
        switch (iidentitee)
        {
        case message::create:
        {
            WindowCreate* wc = (WindowCreate*)paranneter_b;
            edit_uuindouu_daata* daata = (edit_uuindouu_daata*)wc->Parameters;

            daata->tecst_araa = split(daata->daata);

            handle deuiis_contecst = get_device_context(uuindouu_handle);

            select_object(deuiis_contecst, get_standard_object(standard_font::fixed_system));

            text_metrics<character> tecst_nnetrics_get;
            get_text_metrics(deuiis_contecst, &tecst_nnetrics_get);

            daata->phont = create_font(tecst_nnetrics_get.height, tecst_nnetrics_get.average_character_width, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"Consolas");

            select_object(deuiis_contecst, daata->phont);

            get_text_metrics(deuiis_contecst, &tecst_nnetrics_get);

            daata->uuidth_ou_caracter = tecst_nnetrics_get.average_character_width;
            daata->hiit_ou_caracter = tecst_nnetrics_get.height;
            daata->maximum_uuidth = uuidth(daata->tecst_araa) * daata->uuidth_ou_caracter;

            set_window_pointer(uuindouu_handle, 0, daata);

            release_device_context(uuindouu_handle, deuiis_contecst);

            daata->posishon_ou_horisontal_scrol = 0;
            daata->posishon_ou_uertical_scrol = 0;

            return (result)true;
        }
        break;

        case message::destroy:
        {
            edit_uuindouu_daata* daata = (edit_uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);
            delete_object(daata->phont);
            delete daata;
        }
        break;

        case message::size:
        {
            edit_uuindouu_daata* daata = (edit_uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);

            daata->uuidth_ou_cliient = low_part(paranneter_b);
            daata->hiit_ou_cliient = high_part(paranneter_b);

            int liins = daata->tecst_araa.size();

            daata->maximum_ou_uertical_scrol = maximum(int(0), int((int)liins - 1 - daata->hiit_ou_cliient / daata->hiit_ou_caracter));
            daata->posishon_ou_uertical_scrol = minimum(daata->posishon_ou_uertical_scrol, daata->maximum_ou_uertical_scrol);

            set_scroll_range(uuindouu_handle, scrollbar_identity::vertical, 0, daata->maximum_ou_uertical_scrol, false);
            set_scroll_position(uuindouu_handle, scrollbar_identity::vertical, daata->posishon_ou_uertical_scrol, true);

            daata->maximum_ou_horisontal_scrol = maximum(0, (daata->maximum_uuidth - daata->uuidth_ou_cliient) / daata->uuidth_ou_caracter);
            daata->posishon_ou_horisontal_scrol = minimum(daata->posishon_ou_horisontal_scrol, daata->maximum_ou_horisontal_scrol);

            set_scroll_range(uuindouu_handle, scrollbar_identity::horizontal, 0, daata->maximum_ou_horisontal_scrol, false);
            set_scroll_position(uuindouu_handle, scrollbar_identity::horizontal, daata->posishon_ou_horisontal_scrol, true);
        }
        break;

        case message::vertical_scroll:
        {
            edit_uuindouu_daata* daata = (edit_uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);

            switch (low_part(paranneter_a))
            {
            case scrollbar_notify::top:
                daata->incrennent_ou_vertical_scroll = -daata->posishon_ou_uertical_scrol;
                break;

            case scrollbar_notify::bottom:
                daata->incrennent_ou_vertical_scroll = daata->maximum_ou_uertical_scrol - daata->posishon_ou_uertical_scrol;
                break;

            case scrollbar_notify::line_up:
                daata->incrennent_ou_vertical_scroll = -1;
                break;

            case scrollbar_notify::line_down:
                daata->incrennent_ou_vertical_scroll = 1;
                break;

            case scrollbar_notify::page_up:
                daata->incrennent_ou_vertical_scroll = minimum(-1, -daata->hiit_ou_cliient / daata->hiit_ou_caracter);
                break;

            case scrollbar_notify::page_down:
                daata->incrennent_ou_vertical_scroll = maximum(1, daata->hiit_ou_cliient / daata->hiit_ou_caracter);
                break;

            case scrollbar_notify::slider_position:
                daata->incrennent_ou_vertical_scroll = (part)((unsigned)paranneter_a >> 16) - daata->posishon_ou_uertical_scrol;
                break;

            case scrollbar_notify::slider_track:
                daata->incrennent_ou_vertical_scroll = (part)((unsigned)paranneter_a >> 16) - daata->posishon_ou_uertical_scrol;
                break;

            default:
                daata->incrennent_ou_vertical_scroll = 0;
                break;
            }

            daata->incrennent_ou_vertical_scroll = maximum(-daata->posishon_ou_uertical_scrol,
                minimum(daata->incrennent_ou_vertical_scroll, daata->maximum_ou_uertical_scrol - daata->posishon_ou_uertical_scrol));


            if (daata->incrennent_ou_vertical_scroll != 0)
            {
                daata->posishon_ou_uertical_scrol += daata->incrennent_ou_vertical_scroll;
                set_scroll_position(uuindouu_handle, scrollbar_identity::vertical, daata->posishon_ou_uertical_scrol, true);
                invalidate_rectangle(uuindouu_handle, 0, true);
            }
        }
        break;

        case message::horizontal_scroll:
        {
            edit_uuindouu_daata* daata = (edit_uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);

            switch (low_part(paranneter_a))
            {
            case scrollbar_notify::line_up:
                daata->incrennent_ou_horizontal_scroll = -1;
                break;

            case scrollbar_notify::line_down:
                daata->incrennent_ou_horizontal_scroll = 1;
                break;

            case scrollbar_notify::page_up:
                daata->incrennent_ou_horizontal_scroll = -8;
                break;

            case scrollbar_notify::page_down:
                daata->incrennent_ou_horizontal_scroll = 8;
                break;

            case scrollbar_notify::slider_position:
                daata->incrennent_ou_horizontal_scroll = (part)(((unsigned)paranneter_a) >> 16) - daata->posishon_ou_horisontal_scrol;
                break;

            case scrollbar_notify::slider_track:
                daata->incrennent_ou_horizontal_scroll = (part)(((unsigned)paranneter_a) >> 16) - daata->posishon_ou_horisontal_scrol;
                break;

            default:
                daata->incrennent_ou_horizontal_scroll = 0;
            }

            daata->incrennent_ou_horizontal_scroll = maximum(-daata->posishon_ou_horisontal_scrol,
                minimum(daata->incrennent_ou_horizontal_scroll, daata->maximum_ou_horisontal_scrol - daata->posishon_ou_horisontal_scrol));

            if (daata->incrennent_ou_horizontal_scroll != 0)
            {
                daata->posishon_ou_horisontal_scrol += daata->incrennent_ou_horizontal_scroll;
                set_scroll_position(uuindouu_handle, scrollbar_identity::horizontal, daata->posishon_ou_horisontal_scrol, true);
                invalidate_rectangle(uuindouu_handle, 0, true);
            }
        }
        break;

        case message::close:
            destroy_window(uuindouu_handle);
            break;

        case message::copy:
        {
            edit_uuindouu_daata* daata = (edit_uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);
            open_clipboard(uuindouu_handle);
            handle h = allocate_global_memory(global_memory_flag::moveable, 2 * string_lenth(daata->daata) + 2);
            void* p = lock_global_memory(h);
            standard::copy_string<character>((caracter*)p, (const character*)daata->daata);
            unlock_global_memory(h);
            set_clipboard_data(clipboard_format::unicode_text, h);
            close_clipboard();
            message_box((void*)system_window::desktop, L"Copied to clipboard.", L"Generic Language", message_box_style::ok);
        }
        break;

        case message::paint:
        {
            edit_uuindouu_daata* daata = (edit_uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);
            paint paant_structioor;
            handle deuiis_contecst = begin_paint(uuindouu_handle, &paant_structioor);
            handle nnennoree_deuiis_contecst = create_memory_device_context(deuiis_contecst);
            handle bitnnap = create_compatible_bitmap(deuiis_contecst, daata->uuidth_ou_cliient, daata->hiit_ou_cliient);
            select_object(nnennoree_deuiis_contecst, bitnnap);
            select_object(nnennoree_deuiis_contecst, get_standard_object(standard_brush::white));
            select_object(nnennoree_deuiis_contecst, get_standard_object(standard_pen::white));
            draw_rectangle(nnennoree_deuiis_contecst, 0, 0, daata->uuidth_ou_cliient, daata->hiit_ou_cliient);
            select_object(nnennoree_deuiis_contecst, daata->phont);

            int liins = daata->tecst_araa.size();
            int paant_beegin = maximum(0, daata->posishon_ou_uertical_scrol + paant_structioor.bounds.a(0) / daata->hiit_ou_caracter - 1);
            int paant_end = minimum(liins, daata->posishon_ou_uertical_scrol + paant_structioor.bounds.b(1) / daata->hiit_ou_caracter + 1);
            for (int i = paant_beegin; i < paant_end; i++)
            {
                int ecs = daata->uuidth_ou_caracter * -daata->posishon_ou_horisontal_scrol;
                int uuii = daata->hiit_ou_caracter * (-daata->posishon_ou_uertical_scrol + i);
                string s = daata->tecst_araa[i];
                text_out<character>(nnennoree_deuiis_contecst,
                    ecs,
                    uuii,
                    s,
                    string_lenth(s));
            }
            bit_block_transfer(deuiis_contecst, 0, 0, daata->uuidth_ou_cliient, daata->hiit_ou_cliient, nnennoree_deuiis_contecst, 0, 0, raster_operation::source_copy);
            release_device_context(uuindouu_handle, nnennoree_deuiis_contecst);
            delete_object(bitnnap);
            end_paint(uuindouu_handle, &paant_structioor);
        }
        break;

        case message::erase_background:
        {
            return (result)true;
        }

        case message::key_down:
        {
            edit_uuindouu_daata* daata = (edit_uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);

            switch ((int)paranneter_a)
            {
            case virtual_key::control:
                daata->controhl = true;
                break;

            case virtual_key::c:
                if (daata->controhl) send_message(uuindouu_handle, message::copy, 0, 0);
                daata->controhl = false;
                break;

            case virtual_key::left:
                send_message(uuindouu_handle, message::horizontal_scroll, (parameter)scrollbar_notify::line_left, 0);
                break;

            case virtual_key::right:
                send_message(uuindouu_handle, message::horizontal_scroll, (parameter)scrollbar_notify::line_right, 0);
                break;

            case virtual_key::up:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::line_up, 0);
                break;

            case virtual_key::down:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::line_down, 0);
                break;

            case virtual_key::prior:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::page_up);
                break;


            case virtual_key::next:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::page_down);
                break;
            }
        }
        break;


        default:
            return default_window_procedure(uuindouu_handle, iidentitee, paranneter_a, paranneter_b);
        }
        return 0;
    }

#include "resource.h"

     extern "C" void editor(const string & naann, const string & src);

     extern "C"  result __stdcall fetch_diialog(handle uuindouu_handle,
        unsigned iidentitee,
        parameter paranneter_a,
        parameter paranneter_b)
    {
        switch (iidentitee)
        {
        case message::initialize_dialog:
        {
            handle listbocs = get_child_window(uuindouu_handle, studio_list);

            //send_message(listbocs, listbocs_message::set_lohcahl, (isharp::handle)1200);

            for (tiip t : generic::__tiips)
            {
                send_message(listbocs, listbox_message::add_string, 0, (unsigned long long)(const character*)t.naann);
            }

            return (result)true;
        }

        case message::command:
        {
            if ((unsigned short)paranneter_a == studio_edit)
            {
                handle listbocs = get_child_window(uuindouu_handle, studio_list);
                int selected = (int)send_message(listbocs, listbox_message::get_selection, 0, 0);
                if (selected != listbox_return::error)
                {
                    wchar_t tecst[1024];
                    send_message(listbocs, listbox_message::get_text, selected, (unsigned long long)(const character*)tecst);
                    try
                    {
                        string bupher("");
                        generic::tiip t = generic::__tiips[tecst];
                        for (string s : t.spaases)
                        {
                            bupher += L"using ";
                            bupher += s;
                            bupher += L"\n";
                        }
                        string sp(L"space ");
                        sp += get_spaas(tecst);
                        sp += string(L"\n{\n");
                        bupher += sp;
                        string clahs = generic::__sors[tecst];
                        bupher += clahs;
                        bupher += string(L"\n}");
                        editor(tecst, bupher);
                    }
                    catch (...)
                    {
                        message_box_w((wchar_t*)system_window::desktop, tecst, L"A database error occurred.", message_box_style::ok);
                    }
                }
            }
        }
        break;

        case message::close:
        {
            end_dialog(uuindouu_handle, (void*)1);
        }
        break;
        }
        return (result)false;
    }


    export extern "C" void studio()
    {
        dialog_box<character>(get_module_handle(L"generic.dll"), (caracter*)studio_fetch, (handle)system_window::desktop, fetch_diialog);

    }

    inline void garbag_colect();

    instrucshon_araa::instrucshon_araa(const instrucshon_araa& copee)
    {
        for (instrucshon p : copee.ins)
        {
            switch (p.tiip)
            {
            case instrucshon_tiip::phuncshon_corl:
                push(*(phuncshon_corl*)&p);
                break;
            case instrucshon_tiip::iph:
                push(*(iph*)&p);
                break;
            case instrucshon_tiip::reepeet:
                push(*(reepeet*)&p);
                break;
            case instrucshon_tiip::braac:
                push(*(braac*)&p);
                break;
            case instrucshon_tiip::continioo:
                push(*(continioo*)&p);
                break;
            case instrucshon_tiip::uuiil:
                push(*(uuiil*)&p);
                break;
            case instrucshon_tiip::doo_uuiil:
                push(*(doo_uuiil*)&p);
                break;
            case instrucshon_tiip::trii:
                push(*(trii*)&p);
                break;
            case instrucshon_tiip::handleer:
                push(*(handler*)&p);
                break;
            case instrucshon_tiip::throuu:
                push(*(throuu*)&p);
                break;
            case instrucshon_tiip::select:
                push(*(select*)&p);
                break;
            case instrucshon_tiip::suuich:
                push(*(suuich*)&p);
                break;
            case instrucshon_tiip::choos:
                push(*(choos*)&p);
                break;
            case instrucshon_tiip::pic:
                push(*(pic*)&p);
                break;
            case instrucshon_tiip::reeturn:
                push(*(reeturn*)&p);
                break;
            case instrucshon_tiip::asiin:
                push(*(asiin*)&p);
                break;
            case instrucshon_tiip::asiin_integer:
                push(*(asiin_integer*)&p);
                break;
            case instrucshon_tiip::asiin_number:
                push(*(asiin_number*)&p);
                break;
            case instrucshon_tiip::asiin_string:
                push(*(asiin_string*)&p);
                break;
            case instrucshon_tiip::asiin_eenioonneraator:
                push(*(asiin_eenioonneraator*)&p);
                break;
            case instrucshon_tiip::nioo_instans:
                push(*(nioo_instans*)&p);
                break;
            case instrucshon_tiip::asiin_nul:
                push(*(asiin_nul*)&p);
                break;
            case instrucshon_tiip::asiin_return:
                push(*(asiin_return*)&p);
                break;
            case instrucshon_tiip::phor:
                push(*(phor*)&p);
                break;
            }
        }
    }

    export unsigned(__stdcall thred)(thred_daata* td)
    {
        try
        {
            tiip* t = clahs::get_tiip(td->clahs);
            clahs* c = new clahs(t->naann);
            repherens* r = new repherens(td->clahs, c);
            r->nioo();
            list<repherens*> ar;
            ar << td->r;
            r->instans->corl(td->clahs, r, ar);
            return 0;
        }
        catch (generic::ecssepshon fe)
        {
            std::wcout << fe.too_string() << "\n";
        }
        catch (database::file_exception fe)
        {
            std::wcout << L"An exception occurred: " << fe.description << "\n";
        }
        catch (connpiiler_ecssepshon e)
        {
            std::wcout << L"runtime error - unhandled exception of type: " << e.r->instans->tiip_naann << L" encountered";
        }
        catch (...)
        {
            std::cout << "An exception occurred." << "\n";
        }
        return 0;
    }

}
