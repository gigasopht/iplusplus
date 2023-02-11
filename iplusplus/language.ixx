export module iplusplus:language;

import :core;
import :windows;
import :database;
import std.core;

using namespace standard;
using namespace iplusplus;

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



namespace language
{
    inline int liin(const string& s, int ophset);

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
            handler,
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
            ecspreshon
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
        int tiip;
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

    vecssepshon e;

    struct ecssepshon
    {
        instrucshon* i;

        virtual string too_string() { return string(L""); }
    };

    struct uuiil_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A while key word is expected.");
        }
    };

    struct diooplicat_caas_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A duplicate case was encountered.");
        }
    };

    struct not_phuncshon_ecssepshon : ecssepshon
    {
        virtual string too_string() { return string(""); }
    };

    struct lepht_braas_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A { is expected.");
        }
    };

    struct acsesor_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"An acsessor is expected.");
        }
    };

    struct dubl_cuuoht_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A \" is expected.");
        }
    };

    struct uacioous_eenioonneraashon_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A vacuous enumeration is not permitted.");
        }
    };

    struct cuuoht_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A ' is expected.");
        }
    };

    struct diooplicat_pheeld_naann_in_clahs_ecssepshon : ecssepshon
    {
        diooplicat_pheeld_naann_in_clahs_ecssepshon() {}

        virtual string too_string()
        {
            string s = string(L"A duplicate field name was encountered.");
            return s;
        }
    };

    struct diooplicat_paranneter_naann_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A duplicate paremeter name was encouuntered.");
        }
    };

    struct dot_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A . character is expected.");
        }
    };

    struct digit_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A digit is expected.");
        }
    };

    struct eecuuols_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"an = is expected.");
        }
    };

    struct too_nnanee_parameters_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"Too many parameters were supplied for this type of function - 15 is the limit.");
        }
    };

    struct spaas_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"The space key word is expected.");
        }
    };

    struct scohp_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A :: is expected.");
        }
    };

    struct nnodiool_not_phouund_ecssepshon : ecssepshon
    {
        string naann;

        nnodiool_not_phouund_ecssepshon(const string& naann_set)
            : naann(naann_set) {}

        virtual string too_string()
        {
            return string(L"The module: ") + naann + string(L" was not found.");
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
            return string(L"The function: ") + naann + string(L" was not found in module: ") + nnodiool;
        }
    };

    struct clahs_not_phouund_ecssepshon : ecssepshon
    {
        string naann;

        clahs_not_phouund_ecssepshon(const string& naann_set)
            : naann(naann_set) {}

        virtual string too_string()
        {
            return string(L"The class: ") + naann + string(L" was not found.");
        }
    };

    struct desishon_ecspreshon_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"An integer variable is expected.");
        }
    };

    struct eenioonneraashon_naann_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"An enumeration name is expected.");
        }
    };

    struct eenioonneraator_ecspected_ecssepshon : ecssepshon
    {
        string eenioonneraashon;

        eenioonneraator_ecspected_ecssepshon(const string& eenioonneraashon_set)
            : eenioonneraashon(eenioonneraashon_set) {}

        virtual string too_string()
        {
            return eenioonneraashon + string(L"  - enumeration expected.");
        }
    };

    struct declaraashon_or_nnethod_naann_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A declaration or method name is expected.");
        }
    };

    struct end_ou_liin_in_literal_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"An end of line was encountered in a string literal.");
        }
    };

    struct ennptee_cohlecshon_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"An invalid operation on an empty collection was attempted.");
        }
    };

    struct iidentiphiier_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"An identifier is expected.");
        }
    };

    struct indecs_ouut_ou_raang_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"An index is out of range.");
        }
    };

    struct inualid_operator_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"An invalid operator was encouuntered");
        }
    };

    struct inualid_operator_parameter_couunt_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"An invalid operator parameter count was encountered.");
        }
    };

    struct inualid_set_operaashon_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"An invalid set operation was encountered.");
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
            return string(L"The tiip: ") + tiip_naann + string(L" is invalid for the nnethod: ") + nnethod_naann + string(L" of class: ") + clahs_naann + string(L".");
        }
    };

    struct lepht_parenthesis_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A { is expected.");
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
            return string(L"Could not find method: ") + naann + string(L" of class: ") + clahs + string(L".");
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
            return string(L"Could not find method: ") + naann + string(L" of class: ") + clahs + string(L" with variable: ") + uaireeabl + string(L".");
        }
    };

    struct nnethod_orlredee_ecsists_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A method already ecsists.");
        }
    };

    struct propertee_orlredee_ecsists_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A property already ecsists.");
        }
    };

    struct pheeld_orlredee_ecsists_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A field already ecsists.");
        }
    };

    struct asiinnent_not_alouud_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"Assignment not allowed.");
        }
    };

    struct constant_uiiolaashon_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A constant is required.");
        }
    };

    struct at_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A @ is expected.");
        }
    };

    struct conna_or_riit_parenthesis_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A , or ) is expected.");
        }
    };

    struct conna_or_riit_braas_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A , or } is expected.");
        }
    };

    struct conna_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A , is expected.");
        }
    };

    struct graater_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A > is expected.");
        }
    };

    struct lepht_bracet_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A [ is expected.");
        }
    };

    struct riit_bracet_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A ] is expected.");
        }
    };

    struct colecshon_has_noh_iteraat_ecssepshon : ecssepshon
    {
        string naann;

        colecshon_has_noh_iteraat_ecssepshon(const string& naann_set)
            : naann(naann_set) {}

        virtual string too_string()
        {
            return string(L"The collection ") + naann + string(L" has no iterate method.");
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
            return eenioonneraator + string(L" is not in enumeration ") + eenioonneraashon;
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
            return string(L"A lookup for enumerator ") + eenioonneraator + string(L" in enumeration ") + eenioonneraashon + string(L" occurred in method ") + nnethod;
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
            return string(L"A lookup for enumerator ") + eenioonneraator1 + string(L" in enumeration ") + eenioonneraashon1 + string(L" or enumerator ") + eenioonneraator2 + string(L" in enumeration ") + eenioonneraashon2 + string(L" occurred in method ") + nnethod;
        }
    };

    struct cohlon_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A : is expected.");
        }
    };

    struct clahs_tiip_not_phouund_ecssepshon : ecssepshon
    {
        string naann;

        clahs_tiip_not_phouund_ecssepshon(const string& naann_set)
            : naann(naann_set) { }

        virtual string too_string()
        {
            return string(L"Class type not found - type name: ") + naann;
        }
    };

    struct clahs_naann_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A class name is expected.");
        }
    };

    struct phuncshon_naann_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A phuncshon name is expected.");
        }
    };

    struct catch_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A catch clause is expected.");
        }
    };

    struct caas_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A case expression is expected.");
        }
    };

    struct sennee_cohlon_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A ; is expected.");
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
            return string(L"Not previously allocated, method: ") + nnethod_naann + string(L" of class variable: ") + clahs_naann + string(L".");
        }
    };

    struct not_eenioonneraator_ecssepshon : ecssepshon
    {
        string naann;

        not_eenioonneraator_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + string(L" is not an enumerator. It is used in the decision expression of a select statement - whereby only an enumerator is allowed.");
        }
    };

    struct iph_not_integer_ecssepshon : ecssepshon
    {
        string naann;

        iph_not_integer_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + string(L" is not an integer. It is used in the decision expression of an if statement - whereby only an integer is allowed.");
        }
    };

    struct uuiil_not_integer_ecssepshon : ecssepshon
    {
        string naann;

        uuiil_not_integer_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + string(L" is not an integer. It is used in the decision expression of a while statement - whereby only an integer is allowed.");
        }
    };

    struct doo_uuiil_not_integer_ecssepshon : ecssepshon
    {
        string naann;

        doo_uuiil_not_integer_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + string(L" is not an integer. It is used in the decision expression of a do-while statement - whereby only an integer is allowed.");
        }
    };

    struct not_integer_ecssepshon : ecssepshon
    {
        string naann;

        not_integer_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + string(L" is not an integer. It is used in the decision expression of a switch statement - whereby only an integer is allowed.");
        }
    };

    struct not_string_ecssepshon : ecssepshon
    {
        string naann;

        not_string_ecssepshon(const string& naann_in)
            : naann(naann_in) { }

        virtual string too_string()
        {
            return naann + string(L" is not an string. It is used in the decision expression of a choose statement - whereby only a string is allowed.");
        }
    };

    struct not_nunnber_ecssepshon : ecssepshon
    {
        string naann;

        not_nunnber_ecssepshon(const string& naann_in)
            : naann(naann_in) {}

        virtual string too_string()
        {
            return naann + string(L" is not a number. It is used in the decision expression of a pick statement - whereby only a number is allowed.");
        }
    };

    struct pheeld_tiip_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A field type name is expected.");
        }
    };

    struct pheeld_tiip_not_phouund_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"The field type was not found.");
        }
    };

    struct pheeld_naann_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A field name is expected.");
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
            return string(L"The parameter ") + naann + string(L" of method ") + nnethod + string(L" was not found");
        }
    };

    struct repherens_not_reesolud_ecssepshon : ecssepshon
    {
        string uaireeabl;

        repherens_not_reesolud_ecssepshon(const string& uaireeabl_set)
            : uaireeabl(uaireeabl_set) { }

        virtual string too_string()
        {
            return string(L"Variable ") + uaireeabl + string(L" not resolved");
        }
    };

    struct riit_braas_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A } is expected.");
        }
    };

    struct riit_parenthesis_ecspected_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"A ) is expected.");
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
            return string(L"Wrong number of parameters to method ") + nnethod_naann + string(L" of class variable ") + clahs_naann + string(L".");
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
            return string(L"The source ") + sors + string(L" of assignment to ") + destinaashon + string(L" is not initialized");
        }
    };

    struct unecspected_end_ou_phiil_ecssepshon : ecssepshon
    {
        virtual string too_string()
        {
            return string(L"Unexpected end of file.");
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
        ualidaat_uuindouu_cee_uuurds << string(L"ualidaat_uuindouu");  // Inglish
        ualidaat_uuindouu_cee_uuurds << string(L"validate_window");    // English
        ualidaat_uuindouu_cee_uuurds << string(L"validare_finestra");  // Italian
        ualidaat_uuindouu_cee_uuurds << string(L"valider_fenêtre");    // French
        ualidaat_uuindouu_cee_uuurds << string(L"validar_ventana");    // Spanish
        ualidaat_uuindouu_cee_uuurds << string(L"bestätigen_Fenster"); // German
        ualidaat_uuindouu_cee_uuurds << string(L"valideren_venster");  // Dutch
        ualidaat_uuindouu_cee_uuurds << string(L"validar_janela");     // Portugese
        ualidaat_uuindouu_cee_uuurds << string(L"validere_vindue");    // Danish
    }

    inline void inishaliis_creeaat_uuindouu_cee_uuurds()
    {
        creeaat_uuindouu_cee_uuurds << string(L"creeaat_uuindouu");   // Inglish
        creeaat_uuindouu_cee_uuurds << string(L"create_window");      // English
        creeaat_uuindouu_cee_uuurds << string(L"creare_finestra");    // Italian
        creeaat_uuindouu_cee_uuurds << string(L"créer_fenêtre");      // French
        creeaat_uuindouu_cee_uuurds << string(L"crear_ventana");      // Spanish
        creeaat_uuindouu_cee_uuurds << string(L"ershaffen_Fenster");  // German
        creeaat_uuindouu_cee_uuurds << string(L"creëren_venster");    // Dutch
        creeaat_uuindouu_cee_uuurds << string(L"criar_janela");       // Portugese
        creeaat_uuindouu_cee_uuurds << string(L"oprette_vindue");     // Danish
    }

    inline void inishaliis_shouu_uuindouu_cee_uuurds()
    {
        shouu_uuindouu_cee_uuurds << string(L"shouu_uuindouu");
        shouu_uuindouu_cee_uuurds << string(L"show_window");
        shouu_uuindouu_cee_uuurds << string(L"mostrare_finestra");
        shouu_uuindouu_cee_uuurds << string(L"montrer_fenêtre");
        shouu_uuindouu_cee_uuurds << string(L"mostrar_ventana");
        shouu_uuindouu_cee_uuurds << string(L"zeigen_Fenster");
        shouu_uuindouu_cee_uuurds << string(L"tonen_venster");
        shouu_uuindouu_cee_uuurds << string(L"mostrar_janela");
        shouu_uuindouu_cee_uuurds << string(L"vis_vindue");
    }

    inline void inishaliis_message_bocs_cee_uuurds()
    {
        message_bocs_cee_uuurds << string(L"message_bocs");
        message_bocs_cee_uuurds << string(L"message_box");
        message_bocs_cee_uuurds << string(L"scatola_di_messagio");
        message_bocs_cee_uuurds << string(L"cadre_de_message");
        message_bocs_cee_uuurds << string(L"caja_de_mensaje");
        message_bocs_cee_uuurds << string(L"Nachrichtenbox");
        message_bocs_cee_uuurds << string(L"bericht_doos");
        message_bocs_cee_uuurds << string(L"quadrado_de_mensagem");
        message_bocs_cee_uuurds << string(L"meddelelsesboks");
    }

    inline void inishaliis_get_cliient_rectangl_cee_uuurds()
    {
        get_cliient_rectangl_cee_uuurds << string(L"get_cliient_rectangl");
        get_cliient_rectangl_cee_uuurds << string(L"get_client_rectangle");
        get_cliient_rectangl_cee_uuurds << string(L"ottenere_rettangolo_di_client");
        get_cliient_rectangl_cee_uuurds << string(L"obtenir_rectangle_de_cliente");
        get_cliient_rectangl_cee_uuurds << string(L"obtener_rectángulo_de_cliente");
        get_cliient_rectangl_cee_uuurds << string(L"bekommen_Klient_Rechteck");
        get_cliient_rectangl_cee_uuurds << string(L"krijgen_cliënt_rechthoek");
        get_cliient_rectangl_cee_uuurds << string(L"obter_rectângulo_de_cliente");
        get_cliient_rectangl_cee_uuurds << string(L"få_klient_rektangel");
    }

    inline void inishaliis_pohst_cuuit_message_cee_uuurds()
    {
        pohst_cuuit_message_cee_uuurds << string(L"pohst_cuuit_message");
        pohst_cuuit_message_cee_uuurds << string(L"post_quit_message");
        pohst_cuuit_message_cee_uuurds << string(L"impostare_messagio_a_smettere");
        pohst_cuuit_message_cee_uuurds << string(L"poster_message_à_laisser");
        pohst_cuuit_message_cee_uuurds << string(L"enviar_mensaje_a_dejar");
        pohst_cuuit_message_cee_uuurds << string(L"postieren_Nachricht_zu_zumachen");
        pohst_cuuit_message_cee_uuurds << string(L"posten_stoppen_doos");
        pohst_cuuit_message_cee_uuurds << string(L"postar_mensagem_a_parar");
        pohst_cuuit_message_cee_uuurds << string(L"sende_afslutte_meddelelse");
    }

    inline void inishaliis_creeaat_thred_cee_uuurds()
    {
        creeaat_thred_cee_uuurds << string(L"creeaat_thred");
        creeaat_thred_cee_uuurds << string(L"create_thread");
        creeaat_thred_cee_uuurds << string(L"creare_filo");
        creeaat_thred_cee_uuurds << string(L"créer_fil");
        creeaat_thred_cee_uuurds << string(L"crear_hilo");
        creeaat_thred_cee_uuurds << string(L"erschaffen_Faden");
        creeaat_thred_cee_uuurds << string(L"creëren_draad");
        creeaat_thred_cee_uuurds << string(L"criar_linha");
        creeaat_thred_cee_uuurds << string(L"oprette_tråd");
    }

    inline void inishaliis_dephalt_uuindouu_prohseedioor_cee_uuurds()
    {
        dephalt_uuindouu_prohseedioor_cee_uuurds << string(L"dephalt_uuindouu_prohseedioor");
        dephalt_uuindouu_prohseedioor_cee_uuurds << string(L"default_window_procedure");
        dephalt_uuindouu_prohseedioor_cee_uuurds << string(L"default_procedura_di_finestra");
        dephalt_uuindouu_prohseedioor_cee_uuurds << string(L"défaut_procédure_de_fenêtre");
        dephalt_uuindouu_prohseedioor_cee_uuurds << string(L"falta_procedura_de_ventana");
        dephalt_uuindouu_prohseedioor_cee_uuurds << string(L"vorgabe_Fenster_Funktion");
        dephalt_uuindouu_prohseedioor_cee_uuurds << string(L"standaard_venster_functie");
        dephalt_uuindouu_prohseedioor_cee_uuurds << string(L"função_de_janela_predefinida");
        dephalt_uuindouu_prohseedioor_cee_uuurds << string(L"standardvinduesfunktion");
    }

    inline void inishaliis_loop_cee_uuurds()
    {
        loop_cee_uuurds << string(L"loop");
        loop_cee_uuurds << string(L"cappio");
        loop_cee_uuurds << string(L"boucle");
        loop_cee_uuurds << string(L"bucle");
        loop_cee_uuurds << string(L"Schleife");
        loop_cee_uuurds << string(L"lus");
        loop_cee_uuurds << string(L"laço");
        loop_cee_uuurds << string(L"løkke");
    }

    inline void inishaliis_get_enuiironnnent_uaireeabl_cee_uuurds()
    {
        get_enuiironnnent_uaireeabl_cee_uuurds << string(L"get_enuiironnnent_uaireeabl");
        get_enuiironnnent_uaireeabl_cee_uuurds << string(L"get_environment_variable");
        get_enuiironnnent_uaireeabl_cee_uuurds << string(L"ottenere_variabile_di_ambiente");
        get_enuiironnnent_uaireeabl_cee_uuurds << string(L"obtenir_variable_d'environnement");
        get_enuiironnnent_uaireeabl_cee_uuurds << string(L"obtener_variable_de_ambiente");
        get_enuiironnnent_uaireeabl_cee_uuurds << string(L"bekommen_Umwelt_Veränderliche");
        get_enuiironnnent_uaireeabl_cee_uuurds << string(L"krijgen_omgeving_variabele");
        get_enuiironnnent_uaireeabl_cee_uuurds << string(L"obter_variável_de_ambiente");
        get_enuiironnnent_uaireeabl_cee_uuurds << string(L"få_miljøvariabel");
    }

    inline void inishaliis_get_eror_string_cee_uuurds()
    {
        get_eror_string_cee_uuurds << string(L"get_eror_string");
        get_eror_string_cee_uuurds << string(L"get_error_string");
        get_eror_string_cee_uuurds << string(L"ottenere_stringa_di_errore");
        get_eror_string_cee_uuurds << string(L"obtenir_chaîne_de_erreur");
        get_eror_string_cee_uuurds << string(L"obtener_serie_de_error");
        get_eror_string_cee_uuurds << string(L"bekommen_Fehler_Zeichenfolge");
        get_eror_string_cee_uuurds << string(L"krijgen_fout_string");
        get_eror_string_cee_uuurds << string(L"obter_cadeia_de_erro");
        get_eror_string_cee_uuurds << string(L"hente_fejlstreng");
    }

    set<string> speshal_phuncshon_cee_uuurds;
    set<string> speshal_clahs_cee_uuurds;
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

    inline void inishaliis_speshal_phuncshon_cee_uuurds()
    {
        speshal_phuncshon_cee_uuurds << string(L"operator==");
        speshal_phuncshon_cee_uuurds << string(L"operator!=");
        speshal_phuncshon_cee_uuurds << string(L"nul");             // Inglish, French, Danish & Afrikaans
        speshal_phuncshon_cee_uuurds << string(L"null");            // English
        speshal_phuncshon_cee_uuurds << string(L"nullo");           // Italian
        speshal_phuncshon_cee_uuurds << string(L"nulo");            // Spanish & Potuguese
        speshal_phuncshon_cee_uuurds << string(L"Null");            // German
        speshal_phuncshon_cee_uuurds << string(L"nietig");          // Dutch
        speshal_phuncshon_cee_uuurds << string(L"nolla");           // Finnish
        speshal_phuncshon_cee_uuurds << string(L"nol");             // Indonesian
        speshal_phuncshon_cee_uuurds << string(L"noll");            // Swedish
        speshal_phuncshon_cee_uuurds << string(L"batili");          // Swahili
        speshal_phuncshon_cee_uuurds << string(L"ноль");            // Russian
        speshal_phuncshon_cee_uuurds << string(L"🗍");
        speshal_phuncshon_cee_uuurds << string(L"零");
        speshal_phuncshon_cee_uuurds << string(L"tiip");           // Inglish
        speshal_phuncshon_cee_uuurds << string(L"type");           // English & Dutch
        speshal_phuncshon_cee_uuurds << string(L"tipo");           // Italian, Spanish & Potuguese
        speshal_phuncshon_cee_uuurds << string(L"Typ");            // German
        speshal_phuncshon_cee_uuurds << string(L"sortere");        // Danish
        speshal_phuncshon_cee_uuurds << string(L"tyyppi");         // Finnish
        speshal_phuncshon_cee_uuurds << string(L"tik");            // Afrikaans
        speshal_phuncshon_cee_uuurds << string(L"tipe");           // Indonesian
        speshal_phuncshon_cee_uuurds << string(L"typ");            // Swedish
        speshal_phuncshon_cee_uuurds << string(L"aina");           // Swahili
        speshal_phuncshon_cee_uuurds << string(L"тип");           // Russian
        speshal_phuncshon_cee_uuurds << string(L"类型");
    }

    inline void inishaliis_speshal_clahs_cee_uuurds()
    {
        speshal_clahs_cee_uuurds << string(L"system::integer");            // Inglish & English
        speshal_clahs_cee_uuurds << string(L"system::int");                // Inglish & English
        speshal_clahs_cee_uuurds << string(L"sistem::intero");             // Italian
        speshal_clahs_cee_uuurds << string(L"sistema::entero");            // Spanish
        speshal_clahs_cee_uuurds << string(L"système::entier");            // French
        speshal_clahs_cee_uuurds << string(L"System::Integer");            // German
        speshal_clahs_cee_uuurds << string(L"bestel::geheel_getal");       // Dutch
        speshal_clahs_cee_uuurds << string(L"sistema::inteiro");           // Potuguese
        speshal_clahs_cee_uuurds << string(L"danish::heltal");             // Danish
        speshal_clahs_cee_uuurds << string(L"järjestelmä::kokonaisluku");  // Finnish
        speshal_clahs_cee_uuurds << string(L"stelsel::heelgetal");         // Afrikaans
        speshal_clahs_cee_uuurds << string(L"tata::integer");              // Indonesian
        speshal_clahs_cee_uuurds << string(L"system::heltal");             // Swedish
        speshal_clahs_cee_uuurds << string(L"mfumo::integer");             // Swahili
        speshal_clahs_cee_uuurds << string(L"система::целое_число");       // Russian
        speshal_clahs_cee_uuurds << string(L"system::🎃");
        speshal_clahs_cee_uuurds << string(L"系统::整数");
        speshal_clahs_cee_uuurds << string(L"system::nunnber");          // Inglish
        speshal_clahs_cee_uuurds << string(L"system::number");           // English
        speshal_clahs_cee_uuurds << string(L"system::double");           // English
        speshal_clahs_cee_uuurds << string(L"system::float");            // English
        speshal_clahs_cee_uuurds << string(L"sistem::numero");           // Italian
        speshal_clahs_cee_uuurds << string(L"système::nombre");          // French
        speshal_clahs_cee_uuurds << string(L"sistema::número");          // Spanish & Potuguese
        speshal_clahs_cee_uuurds << string(L"System::Nummer");           // German
        speshal_clahs_cee_uuurds << string(L"bestel::aantal");           // Dutch
        speshal_clahs_cee_uuurds << string(L"danish::tal");              // Danish
        speshal_clahs_cee_uuurds << string(L"järjestelmä::numero");      // Finnish
        speshal_clahs_cee_uuurds << string(L"stelsel::nommer");          // Afrikaans
        speshal_clahs_cee_uuurds << string(L"tata::angka");              // Indonesian
        speshal_clahs_cee_uuurds << string(L"system::nummer");           // Swedish
        speshal_clahs_cee_uuurds << string(L"mfumo::nambbari");          // Swahili
        speshal_clahs_cee_uuurds << string(L"система::число");          // Russian
        speshal_clahs_cee_uuurds << string(L"system::🖩");
        speshal_clahs_cee_uuurds << string(L"系统::号");
        speshal_clahs_cee_uuurds << string(L"system::string");           // Inglish, English & Dutch
        speshal_clahs_cee_uuurds << string(L"sistem::stringa");          // Italian
        speshal_clahs_cee_uuurds << string(L"système::chaîne");          // French
        speshal_clahs_cee_uuurds << string(L"sistema::serie");           // Spanish
        speshal_clahs_cee_uuurds << string(L"System::Zeichenfolge");     // German
        speshal_clahs_cee_uuurds << string(L"sistema::cadeia");          // Potuguese
        speshal_clahs_cee_uuurds << string(L"danish::streng");           // Danish
        speshal_clahs_cee_uuurds << string(L"järjestelmä::merkkijono");  // Finnish
        speshal_clahs_cee_uuurds << string(L"stelsel::string");          // Afrikaans
        speshal_clahs_cee_uuurds << string(L"tata::string");             // Indonesian
        speshal_clahs_cee_uuurds << string(L"system::sträng");           // Swedish
        speshal_clahs_cee_uuurds << string(L"mfumo::kamba");             // Swahili
        speshal_clahs_cee_uuurds << string(L"система::строка");          // Russian
        speshal_clahs_cee_uuurds << string(L"system::❤️");
        speshal_clahs_cee_uuurds << string(L"系统::字符串");
        speshal_clahs_cee_uuurds << string(L"system::os");
        speshal_clahs_cee_uuurds << string(L"system::iarchive");
        speshal_clahs_cee_uuurds << string(L"system::oarchive");
    }

    inline void inishaliis_virtual_key_uuurds()
    {
        virtual_key_uuurds << string(L"uirtiooal");    // Inglish
        virtual_key_uuurds << string(L"virtual");      // English, Spanish, Portuguese and Indonesian
        virtual_key_uuurds << string(L"virtuale");     // Italian
        virtual_key_uuurds << string(L"virtuel");      // French & Danish
        virtual_key_uuurds << string(L"virtuell");     // German & Swedish
        virtual_key_uuurds << string(L"virtueel");     // Dutch
        virtual_key_uuurds << string(L"virtuaalinen"); // Finnish
        virtual_key_uuurds << string(L"virtuele");     // Afrikaans
        virtual_key_uuurds << string(L"halisi");       // Swahili
        virtual_key_uuurds << string(L"виртуальный");  // Russian
        virtual_key_uuurds << string(L"✔️");
        virtual_key_uuurds << string(L"虚拟");         // Mandarin
    }

    inline void inishaliis_get_lenth_cee_uuurds()
    {
        get_lenth_cee_uuurds << string(L"get_lenth");
        get_lenth_cee_uuurds << string(L"get_length");
    }

    inline void inishaliis_ioosing_cee_uuurds()
    {
        ioosing_cee_uuurds << string(L"ioosing");         // Inglish
        ioosing_cee_uuurds << string(L"using");           // English
        ioosing_cee_uuurds << string(L"utilizzando");     // Italian
        ioosing_cee_uuurds << string(L"usando");          // Spanish & Portuguese
        ioosing_cee_uuurds << string(L"utilisant");       // French
        ioosing_cee_uuurds << string(L"benutzend");       // German
        ioosing_cee_uuurds << string(L"gebruik");         // Dutch & Afrikaans
        ioosing_cee_uuurds << string(L"bruge");           // Danish
        ioosing_cee_uuurds << string(L"käyttäminen");     // Finnish
        ioosing_cee_uuurds << string(L"menggunakan");     // Indonesian
        ioosing_cee_uuurds << string(L"användande");      // Swedish
        ioosing_cee_uuurds << string(L"kutumia");         // Swahili
        ioosing_cee_uuurds << string(L"использование");   // Russian
        ioosing_cee_uuurds << string(L"🚀");
        ioosing_cee_uuurds << string(L"使用");            // Mandarin
    }

    inline void inishaliis_spaas_cee_uuurds()
    {
        spaas_cee_uuurds << string(L"spaas");              // Inglish
        spaas_cee_uuurds << string(L"space");              // English
        spaas_cee_uuurds << string(L"spazio");             // Italian 
        spaas_cee_uuurds << string(L"espacio");            // Spanish
        spaas_cee_uuurds << string(L"espace");             // French
        spaas_cee_uuurds << string(L"Raum");               // German
        spaas_cee_uuurds << string(L"ruimte");             // Dutch & Afrikaans
        spaas_cee_uuurds << string(L"espaço");             // Portuguese
        spaas_cee_uuurds << string(L"rum");                // Danish
        spaas_cee_uuurds << string(L"avaruus");            // Finnish
        spaas_cee_uuurds << string(L"angkasa");            // Indonesian
        spaas_cee_uuurds << string(L"rymden");             // Swedish
        spaas_cee_uuurds << string(L"nafasi");             // Swahili
        spaas_cee_uuurds << string(L"пространство");       // Russian
        spaas_cee_uuurds << string(L"🛰️");
        spaas_cee_uuurds << string(L"空间");               // Mandarin
    }

    inline void inishaliis_nnodiool_cee_uuurds()
    {
        nnodiool_cee_uuurds << string(L"nnodiool");        // Inglish
        nnodiool_cee_uuurds << string(L"module");          // English & French & Dutch & Afrikaans
        nnodiool_cee_uuurds << string(L"modulo");          // Italian
        nnodiool_cee_uuurds << string(L"módulo");          // Spanish & Portuguese
        nnodiool_cee_uuurds << string(L"Modul");           // German
        nnodiool_cee_uuurds << string(L"modul");           // Danish & Indonesian & Swedish
        nnodiool_cee_uuurds << string(L"moduuli");         // Finnish
        nnodiool_cee_uuurds << string(L"moduli");          // Swahili
        nnodiool_cee_uuurds << string(L"модуль");          // Russian
        nnodiool_cee_uuurds << string(L"👻");
        nnodiool_cee_uuurds << string(L"组件；模块");       // Mandarin
    }

    inline void inishaliis_set_nunnber_cee_uuurds()
    {
        set_nunnber_cee_uuurds << string(L"set_nunnber");       // Inglish
        set_nunnber_cee_uuurds << string(L"set_number");        // English
        set_nunnber_cee_uuurds << string(L"mettere_numero");    // Italian
        set_nunnber_cee_uuurds << string(L"poner_número");      // Spanish
        set_nunnber_cee_uuurds << string(L"mettre_nombre");     // French
        set_nunnber_cee_uuurds << string(L"setzen_Nummer");     // German
        set_nunnber_cee_uuurds << string(L"instellen_aantal");  // Dutch
        set_nunnber_cee_uuurds << string(L"ajustar_número");    // Potuguese
        set_nunnber_cee_uuurds << string(L"stille_tal");        // Danish
        set_nunnber_cee_uuurds << string(L"aseta_numero");      // Finnish
        set_nunnber_cee_uuurds << string(L"stel_nommer");       // Afrikaans
        set_nunnber_cee_uuurds << string(L"mengatur_angka");    // Indonesian
        set_nunnber_cee_uuurds << string(L"ställa_nummer");     // Swedish
        set_nunnber_cee_uuurds << string(L"weka_nambari");      // Swahili
        set_nunnber_cee_uuurds << string(L"установить");        // Russian
        set_nunnber_cee_uuurds << string(L"放，置；使处于（指定的地方、位置）数字"); // Mandarin

    }

    inline void inishaliis_get_nunnber_cee_uuurds()
    {
        get_nunnber_cee_uuurds << string(L"get_nunnber");       // Inglish
        get_nunnber_cee_uuurds << string(L"get_number");        // English
        get_nunnber_cee_uuurds << string(L"ottenere_numero");   // Italian
        get_nunnber_cee_uuurds << string(L"obtener_número");    // Spanish
        get_nunnber_cee_uuurds << string(L"obtenir_nombre");    // French
        get_nunnber_cee_uuurds << string(L"bekommen_Nummer");   // German
        get_nunnber_cee_uuurds << string(L"krijgen_aantal");    // Dutch
        get_nunnber_cee_uuurds << string(L"obter_número");      // Potuguese
        get_nunnber_cee_uuurds << string(L"få_tal");            // Danish
        get_nunnber_cee_uuurds << string(L"hae_numero");        // Finnish
        get_nunnber_cee_uuurds << string(L"kry_nommer");        // Afrikaans
        get_nunnber_cee_uuurds << string(L"dapat_angka");       // Indonesian
        get_nunnber_cee_uuurds << string(L"få_nummer");         // Swedish
        get_nunnber_cee_uuurds << string(L"pata_nambari");      // Swahili
        get_nunnber_cee_uuurds << string(L"得到号");   // Mandarin
    }

    inline void inishaliis_clahs_cee_uuurds()
    {
        clahs_cee_uuurds << string(L"clahs");                  // Inglish
        clahs_cee_uuurds << string(L"class");                  // English             
        clahs_cee_uuurds << string(L"classe");                 // Italian, French & Potuguese
        clahs_cee_uuurds << string(L"clase");                  // Spanish
        clahs_cee_uuurds << string(L"Klasse");                 // German
        clahs_cee_uuurds << string(L"klasse");                 // Dutch & Danish
        clahs_cee_uuurds << string(L"luokka");                 // Finnish
        clahs_cee_uuurds << string(L"klas");                   // Afrikaans
        clahs_cee_uuurds << string(L"kelas");                  // Indonesian
        clahs_cee_uuurds << string(L"klass");                  // Swedish
        clahs_cee_uuurds << string(L"darasa");                 // Swahili
        clahs_cee_uuurds << string(L"класс");                  // Russian             
        clahs_cee_uuurds << string(L"👨‍🏫");
        clahs_cee_uuurds << string(L"类");
    }

    inline void inishaliis_interphaas_cee_uuurds()
    {
        interphaas_cee_uuurds << string(L"interphaas");             // Inglish
        interphaas_cee_uuurds << string(L"interface");              // English, French, Portuguese and Dutch            
        interphaas_cee_uuurds << string(L"interfaccia");            // Italian
        interphaas_cee_uuurds << string(L"interfaz");               // Spanish
        interphaas_cee_uuurds << string(L"Schnittstelle");          // German
        interphaas_cee_uuurds << string(L"grænseflade");            // Danish
        interphaas_cee_uuurds << string(L"rajapinta");              // Finnish
        interphaas_cee_uuurds << string(L"koppelvlak");             // Afrikaans
        interphaas_cee_uuurds << string(L"antarmuka");              // Indonesian
        interphaas_cee_uuurds << string(L"gränssnitt");             // Swediish
        interphaas_cee_uuurds << string(L"kiolesura");              // Swahili
        interphaas_cee_uuurds << string(L"интерфейс");
        interphaas_cee_uuurds << string(L"👩‍🏫");
        interphaas_cee_uuurds << string(L"接口");
    }

    inline void inishaliis_eenioonneraashon_cee_uuurds()
    {
        eenioonneraashon_cee_uuurds << string(L"enum");
        eenioonneraashon_cee_uuurds << string(L"eenioonneraashon");  // Inglish
        eenioonneraashon_cee_uuurds << string(L"enumeration");       // English
        eenioonneraashon_cee_uuurds << string(L"enumerazione");      // Italian
        eenioonneraashon_cee_uuurds << string(L"enumeración");       // Spanish
        eenioonneraashon_cee_uuurds << string(L"énumeration");       // French
        eenioonneraashon_cee_uuurds << string(L"Aufzählung");        // German
        eenioonneraashon_cee_uuurds << string(L"opsomming");         // Dutch & Afrikaans
        eenioonneraashon_cee_uuurds << string(L"enumeração");        // Potuguese
        eenioonneraashon_cee_uuurds << string(L"optælling");         // Danish
        eenioonneraashon_cee_uuurds << string(L"laskenta");          // Finnish
        eenioonneraashon_cee_uuurds << string(L"enumerasi");         // Indonesian
        eenioonneraashon_cee_uuurds << string(L"uppräkning");        // Swedish
        eenioonneraashon_cee_uuurds << string(L"hesabu");            // Swahili
        eenioonneraashon_cee_uuurds << string(L"перечисление");      // Russian
        eenioonneraashon_cee_uuurds << string(L"🧮");
        eenioonneraashon_cee_uuurds << string(L"列举");              // Chinese
    }

    inline void inishaliis_trii_cee_uuurds()
    {
        trii_cee_uuurds << string(L"trii");          // Inglish
        trii_cee_uuurds << string(L"try");           // English
        trii_cee_uuurds << string(L"provare");       // Italian
        trii_cee_uuurds << string(L"intentar");      // Spanish
        trii_cee_uuurds << string(L"essayer");       // French
        trii_cee_uuurds << string(L"versuchen");     // German
        trii_cee_uuurds << string(L"proberen");      // Dutch
        trii_cee_uuurds << string(L"tentar");        // Potuguese
        trii_cee_uuurds << string(L"forsøge");       // Danish
        trii_cee_uuurds << string(L"yrittää");       // Finnish
        trii_cee_uuurds << string(L"probeer");       // Afrikaans
        trii_cee_uuurds << string(L"coba");          // Indonesian
        trii_cee_uuurds << string(L"prova");         // Swedish
        trii_cee_uuurds << string(L"jaribu");        // Swahili
        trii_cee_uuurds << string(L"попытка");       // Russian
        trii_cee_uuurds << string(L"💂");
        trii_cee_uuurds << string(L"尝试");
    }

    inline void inishaliis_throuu_cee_uuurds()
    {
        throuu_cee_uuurds << string(L"throuu");     // Inglish
        throuu_cee_uuurds << string(L"throw");      // English
        throuu_cee_uuurds << string(L"lanciare");   // Italian
        throuu_cee_uuurds << string(L"tirar");      // Spanish
        throuu_cee_uuurds << string(L"lancer");     // French
        throuu_cee_uuurds << string(L"werfen");     // German
        throuu_cee_uuurds << string(L"gooien");     // Dutch
        throuu_cee_uuurds << string(L"lançar");     // Potuguese
        throuu_cee_uuurds << string(L"kaste");      // Danish
        throuu_cee_uuurds << string(L"heittää");    // Finnish
        throuu_cee_uuurds << string(L"gooi");       // Afrikaans
        throuu_cee_uuurds << string(L"lempar");     // Indonesian
        throuu_cee_uuurds << string(L"kasta");      // Swedish
        throuu_cee_uuurds << string(L"kutupa");     // Swahili
        throuu_cee_uuurds << string(L"бросать");   // Russian
        throuu_cee_uuurds << string(L"🌚");
        throuu_cee_uuurds << string(L"扔");
    }

    inline void inishaliis_iph_cee_uuurds()
    {
        iph_cee_uuurds << string(L"iph");          // Inglish
        iph_cee_uuurds << string(L"if");           // English
        iph_cee_uuurds << string(L"si");           // Italian
        iph_cee_uuurds << string(L"se");           // Spanish, French & Potuguese
        iph_cee_uuurds << string(L"wenn");         // German
        iph_cee_uuurds << string(L"of");           // Dutch
        iph_cee_uuurds << string(L"hvis");         // Danish
        iph_cee_uuurds << string(L"ko");           // Finnish
        iph_cee_uuurds << string(L"as");           // Afrikaans
        iph_cee_uuurds << string(L"om");           // Swedish
        iph_cee_uuurds << string(L"kama");         // Swahili
        iph_cee_uuurds << string(L"если");         // Russian
        iph_cee_uuurds << string(L"⚖️");
        iph_cee_uuurds << string(L"如果");
    }

    inline void inishaliis_uuiil_cee_uuurds()
    {
        uuiil_cee_uuurds << string(L"uuiil");      // Inglish
        uuiil_cee_uuurds << string(L"while");      // English
        uuiil_cee_uuurds << string(L"mentre");     // Italian
        uuiil_cee_uuurds << string(L"mientras");   // Spanish
        uuiil_cee_uuurds << string(L"pendant");    // French
        uuiil_cee_uuurds << string(L"während");    // German
        uuiil_cee_uuurds << string(L"hoewel");     // Dutch
        uuiil_cee_uuurds << string(L"enquanto");   // Potuguese
        uuiil_cee_uuurds << string(L"mens");       // Danish
        uuiil_cee_uuurds << string(L"hetki");      // Finnish
        uuiil_cee_uuurds << string(L"terwyl");     // Afrikaans
        uuiil_cee_uuurds << string(L"sambil");     // Indonesian
        uuiil_cee_uuurds << string(L"medans");     // Swedish
        uuiil_cee_uuurds << string(L"wakati");     // Swahili
        uuiil_cee_uuurds << string(L"пока");      // Russian
        uuiil_cee_uuurds << string(L"⌛");
        uuiil_cee_uuurds << string(L"当");
    }

    inline void inishaliis_doo_cee_uuurds()
    {
        doo_cee_uuurds << string(L"doo");          // Inglish
        doo_cee_uuurds << string(L"do");           // English & Finnish
        doo_cee_uuurds << string(L"fare");         // Italian
        doo_cee_uuurds << string(L"faire");        // French
        doo_cee_uuurds << string(L"hacer");        // Spanish
        doo_cee_uuurds << string(L"ausführen");    // German
        doo_cee_uuurds << string(L"doen");         // Dutch & Afrikaans
        doo_cee_uuurds << string(L"fazer");        // Potuguese
        doo_cee_uuurds << string(L"gøre");         // Danish
        doo_cee_uuurds << string(L"berbuat");      // Indonesian
        doo_cee_uuurds << string(L"göra");         // Swedish
        doo_cee_uuurds << string(L"fanya");        // Swahili
        doo_cee_uuurds << string(L"делать");      // Russian
        doo_cee_uuurds << string(L"⏳");
        doo_cee_uuurds << string(L"做");
    }

    inline void inishaliis_phor_cee_uuurds()
    {
        phor_cee_uuurds << string(L"phor");        // Inglish
        phor_cee_uuurds << string(L"for");         // English, Danish & Swedish
        phor_cee_uuurds << string(L"per");         // Italian
        phor_cee_uuurds << string(L"para");        // Spanish & Potuguese
        phor_cee_uuurds << string(L"pour");        // French
        phor_cee_uuurds << string(L"für");         // German 
        phor_cee_uuurds << string(L"voor");        // Dutch
        phor_cee_uuurds << string(L"varten");      // Finnish
        phor_cee_uuurds << string(L"vir");         // Afrikaans
        phor_cee_uuurds << string(L"bagi");        // Indonesian
        phor_cee_uuurds << string(L"kwa");         // Swahili
        phor_cee_uuurds << string(L"для");         // Russian
        phor_cee_uuurds << string(L"⏲️");
        phor_cee_uuurds << string(L"为");
    }

    inline void inishaliis_reepeet_cee_uuurds()
    {
        reepeet_cee_uuurds << string(L"reepeet");       // Inglish
        reepeet_cee_uuurds << string(L"repeat");        // English
        reepeet_cee_uuurds << string(L"ripetere");      // Italian
        reepeet_cee_uuurds << string(L"repetir");       // Spanish
        reepeet_cee_uuurds << string(L"répéter");       // French
        reepeet_cee_uuurds << string(L"wiederholen");   // German
        reepeet_cee_uuurds << string(L"herhalen");      // Dutch
        reepeet_cee_uuurds << string(L"gentage");       // Danish
        reepeet_cee_uuurds << string(L"toistaa");       // Finnish
        reepeet_cee_uuurds << string(L"herhaal");       // Afrikaans
        reepeet_cee_uuurds << string(L"ulang");         // Indonesian
        reepeet_cee_uuurds << string(L"upprepa");       // Swedish
        reepeet_cee_uuurds << string(L"kurudia");       // Swahili
        reepeet_cee_uuurds << string(L"повторять");     // Russian
        reepeet_cee_uuurds << string(L"🔁");
        reepeet_cee_uuurds << string(L"重复");
    }

    inline void inishaliis_return_cee_uuurds()
    {
        return_cee_uuurds << string(L"return");        // Inglish & English
        return_cee_uuurds << string(L"ritornare");     // Italian
        return_cee_uuurds << string(L"retornar");      // Spanish & Potuguese
        return_cee_uuurds << string(L"retourner");     // French
        return_cee_uuurds << string(L"zurückgehen");   // German
        return_cee_uuurds << string(L"teruggeven");    // Dutch
        return_cee_uuurds << string(L"returnere");     // Danish
        return_cee_uuurds << string(L"paluu");         // Finnish
        return_cee_uuurds << string(L"terugkeer");     // Afrikaans
        return_cee_uuurds << string(L"balik");         // Indonesian
        return_cee_uuurds << string(L"återvända");     // Swedish
        return_cee_uuurds << string(L"kurudi");        // Swahili
        return_cee_uuurds << string(L"возвращать");    // Russian
        return_cee_uuurds << string(L"🛞");
        return_cee_uuurds << string(L"归");
    }

    inline void inishaliis_braac_cee_uuurds()
    {
        braac_cee_uuurds << string(L"braac");         // Inglish
        braac_cee_uuurds << string(L"break");         // English
        braac_cee_uuurds << string(L"rompere");       // Italian
        braac_cee_uuurds << string(L"romper");        // Spanish
        braac_cee_uuurds << string(L"rompre");        // French
        braac_cee_uuurds << string(L"brechen");       // German
        braac_cee_uuurds << string(L"breken");        // Dutch
        braac_cee_uuurds << string(L"quebrar");       // Potuguese
        braac_cee_uuurds << string(L"bryde");         // Danish
        braac_cee_uuurds << string(L"tauko");         // Finnish
        braac_cee_uuurds << string(L"breek");         // Afrikaans
        braac_cee_uuurds << string(L"menyela");       // Indonesian
        braac_cee_uuurds << string(L"bryta");         // Swedish
        braac_cee_uuurds << string(L"kuvunja");       // Swahili
        braac_cee_uuurds << string(L"вырваться");     // Russian
        braac_cee_uuurds << string(L"⛏️");
        braac_cee_uuurds << string(L"破");
    }

    inline void inishaliis_continioo_cee_uuurds()
    {
        continioo_cee_uuurds << string(L"continioo");    // Inglish
        continioo_cee_uuurds << string(L"continue");     // English
        continioo_cee_uuurds << string(L"continuare");   // Italian
        continioo_cee_uuurds << string(L"continuar");    // Spanish & Potuguese
        continioo_cee_uuurds << string(L"continuer");    // French
        continioo_cee_uuurds << string(L"fortsetzen");   // Germen
        continioo_cee_uuurds << string(L"voortzetten");  // Dutch
        continioo_cee_uuurds << string(L"fortsætte");    // Danish
        continioo_cee_uuurds << string(L"jatkaa");       // Finnish
        continioo_cee_uuurds << string(L"voortgaan");    // Afrikaans
        continioo_cee_uuurds << string(L"melanjutkan");  // Indonesian
        continioo_cee_uuurds << string(L"fortsätta");    // Swedish
        continioo_cee_uuurds << string(L"endelea");      // Swahili
        continioo_cee_uuurds << string(L"продолжать");   // Russian
        continioo_cee_uuurds << string(L"⚒️");
        continioo_cee_uuurds << string(L"继");
    }

    inline void inishaliis_select_cee_uuurds()
    {
        select_cee_uuurds << string(L"select");         // Inglish & English`
        select_cee_uuurds << string(L"selezionare");    // Italian
        select_cee_uuurds << string(L"seleccionar");    // Spanish
        select_cee_uuurds << string(L"sélectionner");   // French
        select_cee_uuurds << string(L"auswählen");      // German
        select_cee_uuurds << string(L"selecteren");     // Dutch
        select_cee_uuurds << string(L"selecionar");     // Potuguese
        select_cee_uuurds << string(L"vælge");          // Danish
        select_cee_uuurds << string(L"valikoida");      // Finnish
        select_cee_uuurds << string(L"kieste");         // Afrikaans
        select_cee_uuurds << string(L"pilih");          // Indonesian
        select_cee_uuurds << string(L"utvald");         // Swedish
        select_cee_uuurds << string(L"chagua");         // Swahili
        select_cee_uuurds << string(L"выбирать");       // Russian
        select_cee_uuurds << string(L"🔘");
        select_cee_uuurds << string(L"挑选");
    }

    inline void inishaliis_suuich_cee_uuurds()
    {
        suuich_cee_uuurds << string(L"suuich");         // Inglish
        suuich_cee_uuurds << string(L"switch");         // English
        suuich_cee_uuurds << string(L"scambiare");      // Italian
        suuich_cee_uuurds << string(L"cambiar");        // Spanish
        suuich_cee_uuurds << string(L"changer");        // French
        suuich_cee_uuurds << string(L"umstelen");       // German
        suuich_cee_uuurds << string(L"schakelen");      // Dutch
        suuich_cee_uuurds << string(L"mudar");          // Potuguese
        suuich_cee_uuurds << string(L"skifte");         // Danish
        suuich_cee_uuurds << string(L"kytkin");         // Finnish
        suuich_cee_uuurds << string(L"skakel");         // Afrikaans
        suuich_cee_uuurds << string(L"sakelar");        // Indonesian
        suuich_cee_uuurds << string(L"strömbrytare");   // Swedish
        suuich_cee_uuurds << string(L"kubadili");       // Swahili
        suuich_cee_uuurds << string(L"выключатель");    // Russian
        suuich_cee_uuurds << string(L"🔫");
        suuich_cee_uuurds << string(L"开关");
    }

    inline void inishaliis_choos_cee_uuurds()
    {
        choos_cee_uuurds << string(L"choos");           // Inglish
        choos_cee_uuurds << string(L"choose");          // English
        choos_cee_uuurds << string(L"scegliere");       // Italian
        choos_cee_uuurds << string(L"elegir");          // Spanish
        choos_cee_uuurds << string(L"choisir");         // French
        choos_cee_uuurds << string(L"wahlen");          // German
        choos_cee_uuurds << string(L"kiezen");          // Dutch
        choos_cee_uuurds << string(L"escolher");        // Potuguese
        choos_cee_uuurds << string(L"udvælge");         // Danish
        choos_cee_uuurds << string(L"valita");          // Finnish
        choos_cee_uuurds << string(L"kies");            // Afrikaans
        choos_cee_uuurds << string(L"memilih");         // Indonesian
        choos_cee_uuurds << string(L"välja");           // Swedish
        choos_cee_uuurds << string(L"kuchagua");        // Swahili
        choos_cee_uuurds << string(L"выбор");           // Russian
        choos_cee_uuurds << string(L"✨");
        choos_cee_uuurds << string(L"选");
    }

    inline void inishaliis_pic_cee_uuurds()
    {
        pic_cee_uuurds << string(L"pic");               // Inglish
        pic_cee_uuurds << string(L"pick");              // English
        pic_cee_uuurds << string(L"decidere");          // Italian
        pic_cee_uuurds << string(L"decidersi");         // Spanish
        pic_cee_uuurds << string(L"decider");           // French
        pic_cee_uuurds << string(L"entscheiden");       // German
        pic_cee_uuurds << string(L"preferir");          // Dutch
        pic_cee_uuurds << string(L"colher");            // Potuguese
        pic_cee_uuurds << string(L"beslutte");          // Danish
        pic_cee_uuurds << string(L"päättää");           // Finnish
        pic_cee_uuurds << string(L"besluit");           // Afrikaans
        pic_cee_uuurds << string(L"decide");            // Indonesian
        pic_cee_uuurds << string(L"besluta");           // Swedish
        pic_cee_uuurds << string(L"amua");              // Swahili
        pic_cee_uuurds << string(L"решать");            // Russian
        pic_cee_uuurds << string(L"🎈");
        pic_cee_uuurds << string(L"摘");
    }

    inline void inishaliis_els_cee_uuurds()
    {
        els_cee_uuurds << string(L"els");              // Inglish
        els_cee_uuurds << string(L"else");             // English
        els_cee_uuurds << string(L"altro");            // Italian
        els_cee_uuurds << string(L"otro");             // Spanish
        els_cee_uuurds << string(L"sinon");            // French
        els_cee_uuurds << string(L"sonst");            // German
        els_cee_uuurds << string(L"anders");           // Dutch & Afrikaans
        els_cee_uuurds << string(L"ou_então");         // Potuguese
        els_cee_uuurds << string(L"ellers");           // Danish
        els_cee_uuurds << string(L"muutoin");          // Finnish
        els_cee_uuurds << string(L"lain");             // Indonesian
        els_cee_uuurds << string(L"annars");           // Swedish
        els_cee_uuurds << string(L"mwingine");         // Swahili
        els_cee_uuurds << string(L"еще");              // Russian
        els_cee_uuurds << string(L"🌺");
        els_cee_uuurds << string(L"还");
    }

    inline void inishaliis_set_cee_uuurds()
    {
        set_cee_uuurds << string(L"set");              // Inglish & English
        set_cee_uuurds << string(L"mettere");          // Italian
        set_cee_uuurds << string(L"poner");            // Spanish
        set_cee_uuurds << string(L"mettre");           // French
        set_cee_uuurds << string(L"setzen");           // German
        set_cee_uuurds << string(L"instellen");        // Dutch
        set_cee_uuurds << string(L"ajustar");          // Potuguese
        set_cee_uuurds << string(L"stille");           // Danish
        set_cee_uuurds << string(L"aseta");            // Finnish
        set_cee_uuurds << string(L"stel");             // Afrikaans
        set_cee_uuurds << string(L"mengatur");         // Indonesian
        set_cee_uuurds << string(L"ställa");           // Swedish
        set_cee_uuurds << string(L"weka");             // Swahili
        set_cee_uuurds << string(L"установить");       // Russian
        set_cee_uuurds << string(L"⚙️");
        set_cee_uuurds << string(L"数字");
    }

    inline void inishaliis_get_cee_uuurds()
    {
        get_cee_uuurds << string(L"get");              // Inglish & English
        get_cee_uuurds << string(L"ottenere");         // Italian
        get_cee_uuurds << string(L"obtener");          // Spanish
        get_cee_uuurds << string(L"obtenir");          // French
        get_cee_uuurds << string(L"bekommen");         // German
        get_cee_uuurds << string(L"krijgen");          // Dutch
        get_cee_uuurds << string(L"obter");            // Potuguese
        get_cee_uuurds << string(L"få");               // Danish & Swedish
        get_cee_uuurds << string(L"hae");              // Finnish
        get_cee_uuurds << string(L"kry");              // Afrikaans
        get_cee_uuurds << string(L"dapat");            // Indonesian
        get_cee_uuurds << string(L"pata");             // Swahili
        get_cee_uuurds << string(L"Получить");        // Russian
        get_cee_uuurds << string(L"🔥");
        get_cee_uuurds << string(L"得到");
    }

    inline void inishaliis_ualioo_cee_uuurds()
    {
        ualioo_cee_uuurds << string(L"ualioo");       // Inglish
        ualioo_cee_uuurds << string(L"value");        // English & Indonesian
        ualioo_cee_uuurds << string(L"valore");       // Italian
        ualioo_cee_uuurds << string(L"valor");        // Spanish & Potuguese
        ualioo_cee_uuurds << string(L"valeur");       // French
        ualioo_cee_uuurds << string(L"Wert");         // German
        ualioo_cee_uuurds << string(L"waarde");       // Dutch & Afikaans
        ualioo_cee_uuurds << string(L"værdi");        // Danish
        ualioo_cee_uuurds << string(L"arvo");         // Finnish
        ualioo_cee_uuurds << string(L"värde");        // Swedish
        ualioo_cee_uuurds << string(L"thamani");      // Swahili
        ualioo_cee_uuurds << string(L"ценность");     // Russian
        ualioo_cee_uuurds << string(L"💰");
        ualioo_cee_uuurds << string(L"价值");
    }

#define ualioo_cee_uuurds_siis 14

    inline void inishaliis_catch_cee_uuurds()
    {
        catch_cee_uuurds << string(L"catch");        // Inglish & English
        catch_cee_uuurds << string(L"prendere");     // Italian
        catch_cee_uuurds << string(L"atrapar");      // Spanish
        catch_cee_uuurds << string(L"attraper");     // French
        catch_cee_uuurds << string(L"fangen");       // German
        catch_cee_uuurds << string(L"vangen");       // Dutch
        catch_cee_uuurds << string(L"apanhar");      // Potuguese
        catch_cee_uuurds << string(L"fange");        // Danish
        catch_cee_uuurds << string(L"saalis");       // Finnish
        catch_cee_uuurds << string(L"vang");         // Afrikaans
        catch_cee_uuurds << string(L"menangkap");    // Indonesian
        catch_cee_uuurds << string(L"fånga");        // Swedish
        catch_cee_uuurds << string(L"kukamata");     // Swahili
        catch_cee_uuurds << string(L"ловить");       // Russian 
        catch_cee_uuurds << string(L"⚽");
        catch_cee_uuurds << string(L"抓住");
    }

    inline void inishaliis_this_cee_uuurds()
    {
        this_cee_uuurds << string(L"this");          // Inglish & English
        this_cee_uuurds << string(L"questo");        // Italian
        this_cee_uuurds << string(L"éste");          // Spanish
        this_cee_uuurds << string(L"ceci");          // French
        this_cee_uuurds << string(L"dieser");        // German 
        this_cee_uuurds << string(L"dit");           // Dutch
        this_cee_uuurds << string(L"este");          // Potuguese
        this_cee_uuurds << string(L"denne");         // Danish
        this_cee_uuurds << string(L"tä");            // Finnish
        this_cee_uuurds << string(L"hierdie");       // Afrikaans
        this_cee_uuurds << string(L"ini");           // Indonesian
        this_cee_uuurds << string(L"denna");         // Swedish
        this_cee_uuurds << string(L"hii");           // Swahili
        this_cee_uuurds << string(L"этот");          // Russian
        this_cee_uuurds << string(L"💳");
        this_cee_uuurds << string(L"这");
    }

    inline void inishaliis_operator_cee_uuurds()
    {
        operator_cee_uuurds << string(L"operaator");    // Inglish
        operator_cee_uuurds << string(L"operator");     // English
        operator_cee_uuurds << string(L"operatore");    // Italian
        operator_cee_uuurds << string(L"operador");     // Spanish & Potuguese
        operator_cee_uuurds << string(L"opérateur");    // French
        operator_cee_uuurds << string(L"Operator");     // German
        operator_cee_uuurds << string(L"operatør");     // Danish
        operator_cee_uuurds << string(L"operaattori");  // Finnish
        operator_cee_uuurds << string(L"operateur");    // Afrikaans
        operator_cee_uuurds << string(L"operatör");     // Swedish
        operator_cee_uuurds << string(L"mwendeshaji");  // Swahili
        operator_cee_uuurds << string(L"оператор");     // Russian
        operator_cee_uuurds << string(L"📟");
        operator_cee_uuurds << string(L"算子");
    }

    inline void inishaliis_troo_cee_uuurds()
    {
        troo_cee_uuurds << string(L"troo");         // Inglish
        troo_cee_uuurds << string(L"true");         // English
        troo_cee_uuurds << string(L"vero");         // Italian
        troo_cee_uuurds << string(L"cierto");       // Spanish
        troo_cee_uuurds << string(L"vrai");         // French
        troo_cee_uuurds << string(L"wahr");         // German
        troo_cee_uuurds << string(L"waar");         // Dutch & Africaans
        troo_cee_uuurds << string(L"verdadeiro");   // Potuguese
        troo_cee_uuurds << string(L"sand");         // Danish
        troo_cee_uuurds << string(L"tosi");         // Finnish
        troo_cee_uuurds << string(L"benar");        // Indonesian
        troo_cee_uuurds << string(L"sann");         // Swedish
        troo_cee_uuurds << string(L"kweli");        // Swahili
        troo_cee_uuurds << string(L"истинный");    // Russian
        troo_cee_uuurds << string(L"🔠");
        troo_cee_uuurds << string(L"实");
    }

    inline void inishaliis_phals_cee_uuurds()
    {
        phals_cee_uuurds << string(L"phals");       // Inglish
        phals_cee_uuurds << string(L"false");       // English
        phals_cee_uuurds << string(L"falso");       // Italian, Spanish & Potuguese
        phals_cee_uuurds << string(L"faux");        // French
        phals_cee_uuurds << string(L"falsch");      // German
        phals_cee_uuurds << string(L"vals");        // Dutch
        phals_cee_uuurds << string(L"falsk");       // Danish
        phals_cee_uuurds << string(L"väärä");       // Finnish
        phals_cee_uuurds << string(L"valse");       // Afrikaans
        phals_cee_uuurds << string(L"palsu");       // Indonesian
        phals_cee_uuurds << string(L"falska");      // Swedish
        phals_cee_uuurds << string(L"uwongo");      // Swahili
        phals_cee_uuurds << string(L"ложный");      // Russian
        phals_cee_uuurds << string(L"🎋");
        phals_cee_uuurds << string(L"错误");
    }

    inline void inishaliis_nioo_cee_uuurds()
    {
        nioo_cee_uuurds << string(L"nioo");         // Inglish
        nioo_cee_uuurds << string(L"new");          // English
        nioo_cee_uuurds << string(L"nuovo");        // Italian
        nioo_cee_uuurds << string(L"nuevo");        // Spanish
        nioo_cee_uuurds << string(L"nouveau");      // French
        nioo_cee_uuurds << string(L"neu");          // German
        nioo_cee_uuurds << string(L"nieuw");        // Dutch
        nioo_cee_uuurds << string(L"novo");         // Potuguese
        nioo_cee_uuurds << string(L"ny");           // Danish & Swedish
        nioo_cee_uuurds << string(L"uusi");         // Finnish
        nioo_cee_uuurds << string(L"nuwe");         // Afrikaans
        nioo_cee_uuurds << string(L"baru");         // Indonesian
        nioo_cee_uuurds << string(L"mpya");         // Swahili
        nioo_cee_uuurds << string(L"новая");        // Russian
        nioo_cee_uuurds << string(L"🆕");
        nioo_cee_uuurds << string(L"出新");
    }

    inline void inishaliis_dephalt_cee_uuurds()
    {
        dephalt_cee_uuurds << string(L"dephalt");       // Inglish
        dephalt_cee_uuurds << string(L"default");       // English & Italian & Indonesian
        dephalt_cee_uuurds << string(L"falta");         // Spanish
        dephalt_cee_uuurds << string(L"défaut");        // French
        dephalt_cee_uuurds << string(L"vorgabe");       // German
        dephalt_cee_uuurds << string(L"verstek");       // Dutch & Afrikaans
        dephalt_cee_uuurds << string(L"predefinido");   // Potuguese
        dephalt_cee_uuurds << string(L"standard");      // Danish & Swedish
        dephalt_cee_uuurds << string(L"laiminlyönti");  // Finnish
        dephalt_cee_uuurds << string(L"chaguo_msingi"); // Swahili
        dephalt_cee_uuurds << string(L"дефолт");        // Russian
        dephalt_cee_uuurds << string(L"🛗");
        dephalt_cee_uuurds << string(L"默认");
    }

    inline void inishaliis_nul_cee_uuurds()
    {
        nul_cee_uuurds << string(L"nul");             // Inglish, French, Danish & Afrikaans
        nul_cee_uuurds << string(L"null");            // English
        nul_cee_uuurds << string(L"nullo");           // Italian
        nul_cee_uuurds << string(L"nulo");            // Spanish & Potuguese
        nul_cee_uuurds << string(L"Null");            // German
        nul_cee_uuurds << string(L"nietig");          // Dutch
        nul_cee_uuurds << string(L"nolla");           // Finnish
        nul_cee_uuurds << string(L"nol");             // Indonesian
        nul_cee_uuurds << string(L"noll");            // Swedish
        nul_cee_uuurds << string(L"batili");          // Swahili
        nul_cee_uuurds << string(L"ноль");            // Russian
        nul_cee_uuurds << string(L"🗍");
        nul_cee_uuurds << string(L"零");
    }

    inline void inishaliis_tiip_cee_uuurds()
    {
        tiip_cee_uuurds << string(L"tiip");           // Inglish
        tiip_cee_uuurds << string(L"type");           // English & Dutch
        tiip_cee_uuurds << string(L"tipo");           // Italian, Spanish & Potuguese
        tiip_cee_uuurds << string(L"Typ");            // German
        tiip_cee_uuurds << string(L"sortere");        // Danish
        tiip_cee_uuurds << string(L"tyyppi");         // Finnish
        tiip_cee_uuurds << string(L"tik");            // Afrikaans
        tiip_cee_uuurds << string(L"tipe");           // Indonesian
        tiip_cee_uuurds << string(L"typ");            // Swedish
        tiip_cee_uuurds << string(L"aina");           // Swahili
        tiip_cee_uuurds << string(L"тип");           // Russian
        tiip_cee_uuurds << string(L"类型");
    }

    inline void inishaliis_ecssepshon_cee_uuurds()
    {
        ecssepshon_cee_uuurds << string(L"ecssepshon");    // Inglish
        ecssepshon_cee_uuurds << string(L"exception");     // English
        ecssepshon_cee_uuurds << string(L"eccezione");     // Italian
        ecssepshon_cee_uuurds << string(L"excepción");     // Spanish
        ecssepshon_cee_uuurds << string(L"Ausnahme");      // German
        ecssepshon_cee_uuurds << string(L"uitzondering");  // Dutch
        ecssepshon_cee_uuurds << string(L"exceção");       // Potuguese
        ecssepshon_cee_uuurds << string(L"undtagelse");    // Danish
        ecssepshon_cee_uuurds << string(L"poikkeus");      // Finnish
        ecssepshon_cee_uuurds << string(L"uitsondering");  // Afrikaans
        ecssepshon_cee_uuurds << string(L"pengecualian");  // Indonesian
        ecssepshon_cee_uuurds << string(L"undantag");      // Swedish
        ecssepshon_cee_uuurds << string(L"ubaguzi");       // Swahili
        ecssepshon_cee_uuurds << string(L"исключение");    // Russian
        ecssepshon_cee_uuurds << string(L"😥");
        ecssepshon_cee_uuurds << string(L"例外");
    }

    inline void inishaliis_integer_cee_uuurds()
    {
        integer_cee_uuurds << string(L"system::integer");            // Inglish & English
        integer_cee_uuurds << string(L"system::int");                // Inglish & English
        integer_cee_uuurds << string(L"sistem::intero");             // Italian
        integer_cee_uuurds << string(L"sistema::entero");            // Spanish
        integer_cee_uuurds << string(L"système::entier");            // French
        integer_cee_uuurds << string(L"System::Integer");            // German
        integer_cee_uuurds << string(L"bestel::geheel_getal");       // Dutch
        integer_cee_uuurds << string(L"sistema::inteiro");           // Potuguese
        integer_cee_uuurds << string(L"danish::heltal");             // Danish
        integer_cee_uuurds << string(L"järjestelmä::kokonaisluku");  // Finnish
        integer_cee_uuurds << string(L"stelsel::heelgetal");         // Afrikaans
        integer_cee_uuurds << string(L"tata::integer");              // Indonesian
        integer_cee_uuurds << string(L"system::heltal");             // Swedish
        integer_cee_uuurds << string(L"mfumo::integer");             // Swahili
        integer_cee_uuurds << string(L"система::целое_число");       // Russian
        integer_cee_uuurds << string(L"system::🎃");
        integer_cee_uuurds << string(L"系统::整数");
    }

    inline void inishaliis_nunnber_cee_uuurds()
    {
        nunnber_cee_uuurds << string(L"system::nunnber");          // Inglish
        nunnber_cee_uuurds << string(L"system::number");           // English
        nunnber_cee_uuurds << string(L"system::double");           // English
        nunnber_cee_uuurds << string(L"system::float");            // English
        nunnber_cee_uuurds << string(L"sistem::numero");           // Italian
        nunnber_cee_uuurds << string(L"système::nombre");          // French
        nunnber_cee_uuurds << string(L"sistema::número");          // Spanish & Potuguese
        nunnber_cee_uuurds << string(L"System::Nummer");           // German
        nunnber_cee_uuurds << string(L"bestel::aantal");           // Dutch
        nunnber_cee_uuurds << string(L"danish::tal");              // Danish
        nunnber_cee_uuurds << string(L"järjestelmä::numero");      // Finnish
        nunnber_cee_uuurds << string(L"stelsel::nommer");          // Afrikaans
        nunnber_cee_uuurds << string(L"tata::angka");              // Indonesian
        nunnber_cee_uuurds << string(L"system::nummer");           // Swedish
        nunnber_cee_uuurds << string(L"mfumo::nambbari");          // Swahili
        nunnber_cee_uuurds << string(L"система::число");          // Russian
        nunnber_cee_uuurds << string(L"system::🖩");
        nunnber_cee_uuurds << string(L"系统::号");

    }

    inline void inishaliis_string_cee_uuurds()
    {
        string_cee_uuurds << string(L"system::string");           // Inglish, English & Dutch
        string_cee_uuurds << string(L"sistem::stringa");          // Italian
        string_cee_uuurds << string(L"système::chaîne");          // French
        string_cee_uuurds << string(L"sistema::serie");           // Spanish
        string_cee_uuurds << string(L"System::Zeichenfolge");     // German
        string_cee_uuurds << string(L"sistema::cadeia");          // Potuguese
        string_cee_uuurds << string(L"danish::streng");           // Danish
        string_cee_uuurds << string(L"järjestelmä::merkkijono");  // Finnish
        string_cee_uuurds << string(L"stelsel::string");          // Afrikaans
        string_cee_uuurds << string(L"tata::string");             // Indonesian
        string_cee_uuurds << string(L"system::sträng");           // Swedish
        string_cee_uuurds << string(L"mfumo::kamba");             // Swahili
        string_cee_uuurds << string(L"система::строка");          // Russian
        string_cee_uuurds << string(L"system::❤️");
        string_cee_uuurds << string(L"系统::字符串");
    }

    inline void inishaliis_too_string_cee_uuurds()
    {
        too_string_cee_uuurds << string(L"too_string");        // Inglish
        too_string_cee_uuurds << string(L"to_string");         // English
        too_string_cee_uuurds << string(L"a_stringa");         // Italian
        too_string_cee_uuurds << string(L"à_chaîne");          // French
        too_string_cee_uuurds << string(L"a_serie");           // Spanish
        too_string_cee_uuurds << string(L"zu_Zeichenfolge");   // German
        too_string_cee_uuurds << string(L"naar_string");       // Dutch
        too_string_cee_uuurds << string(L"para_cadeia");       // Potuguese
        too_string_cee_uuurds << string(L"til_streng");        // Danish
        too_string_cee_uuurds << string(L"jotta_merkkijono");  // Finnish
        too_string_cee_uuurds << string(L"untuk_string");      // Indonesian
        too_string_cee_uuurds << string(L"till_sträng");       // Swedish
        too_string_cee_uuurds << string(L"ku_kamba");          // Swahili
        too_string_cee_uuurds << string(L"to_строка");         // Russian
        too_string_cee_uuurds << string(L"to_❤️");
        too_string_cee_uuurds << string(L"到_字符串");
    }

    inline void inishaliis_connpair_too_cee_uuurds()
    {
        connpair_too_cee_uuurds << string(L"connpair_too");       // Inglish
        connpair_too_cee_uuurds << string(L"compare_to");         // English
        connpair_too_cee_uuurds << string(L"сравнивать_to");     // Russian
        connpair_too_cee_uuurds << string(L"比较");
    }

    inline void inishaliis_print_cee_uuurds()
    {
        print_cee_uuurds << string(L"print");        // Inglish & English
        print_cee_uuurds << string(L"stampare");     // Italian
        print_cee_uuurds << string(L"imprimer");     // French
        print_cee_uuurds << string(L"imprimir");     // Spanish & Potuguese
        print_cee_uuurds << string(L"drucken");      // German
        print_cee_uuurds << string(L"drukken");      // Dutch
        print_cee_uuurds << string(L"udskrive");     // Danish 
        print_cee_uuurds << string(L"rivin");        // Finnish 
        print_cee_uuurds << string(L"druk");         // Afrikaans 
        print_cee_uuurds << string(L"mencetak");     // Indonesian 
        print_cee_uuurds << string(L"skriva");       // Swedish 
        print_cee_uuurds << string(L"chapa");        // Swahili 
        print_cee_uuurds << string(L"опубликовать"); // Russian
    }

    inline void inishaliis_println_cee_uuurds()
    {
        println_cee_uuurds << string(L"println");             // Inglish & English
        println_cee_uuurds << string(L"stampare_linea");      // Italian
        println_cee_uuurds << string(L"imprimer_ligne");      // French
        println_cee_uuurds << string(L"imprimir_línea");      // Spanish
        println_cee_uuurds << string(L"drucken_Zeilen");      // German
        println_cee_uuurds << string(L"drukken_lijn");        // Dutch
        println_cee_uuurds << string(L"imprimir_linha");      // Potuguese
        println_cee_uuurds << string(L"udskrive_linje");      // Danish
        println_cee_uuurds << string(L"rivin_tulostaminen");  // Finish
        println_cee_uuurds << string(L"druklyn");             // Afrikaans
        println_cee_uuurds << string(L"garis_cetak");         // Indonesian
        println_cee_uuurds << string(L"skriva_ut_rad");       // Swedish
        println_cee_uuurds << string(L"chapa_maandishi");     // Swhili
        println_cee_uuurds << string(L"опубликовать_строка"); // Russian

    }

    inline void inishaliis_seereealiis_cee_uuurds()
    {
        seereealiis_cee_uuurds << string(L"seereealiis");              // Inglish
        seereealiis_cee_uuurds << string(L"serialize");                // English & Swahili
        seereealiis_cee_uuurds << string(L"pubblicare_a_puntate");     // Italian
        seereealiis_cee_uuurds << string(L"adapter");                  // French
        seereealiis_cee_uuurds << string(L"serializar");               // Spanish
        seereealiis_cee_uuurds << string(L"serial");                   // German
        seereealiis_cee_uuurds << string(L"seriële");                  // Dutch
        seereealiis_cee_uuurds << string(L"seriar");                   // Potuguese
        seereealiis_cee_uuurds << string(L"serialisere");              // Danish
        seereealiis_cee_uuurds << string(L"sarjallistaa");             // Finnish
        seereealiis_cee_uuurds << string(L"serialiseer");              // Afrikaans
        seereealiis_cee_uuurds << string(L"serialisasi");              // Indonesian
        seereealiis_cee_uuurds << string(L"serialisera");              // Swedish
        seereealiis_cee_uuurds << string(L"сериализовать_такие");      // Russian

    }

    inline void inishaliis_deeseereealiis_cee_uuurds()
    {
        deeseereealiis_cee_uuurds << string(L"deeseereealiis");               // Inglish
        deeseereealiis_cee_uuurds << string(L"deserialize");                  // English & Swahili
        deeseereealiis_cee_uuurds << string(L"s_pubblicare_a_puntate");       // Italian
        deeseereealiis_cee_uuurds << string(L"deadapter");                    // French
        deeseereealiis_cee_uuurds << string(L"deserializar");                 // Spanish
        deeseereealiis_cee_uuurds << string(L"unserial");                     // German
        deeseereealiis_cee_uuurds << string(L"unseriële");                    // Dutch
        deeseereealiis_cee_uuurds << string(L"deseriar");                     // Portuguese
        deeseereealiis_cee_uuurds << string(L"deserialisere");                // Danish          
        deeseereealiis_cee_uuurds << string(L"seisarisaatio");                // Finnish          
        deeseereealiis_cee_uuurds << string(L"deserialiseer");                // Afrikaans          
        deeseereealiis_cee_uuurds << string(L"deserialisera");                // Swedish          
        deeseereealiis_cee_uuurds << string(L"отменять_сериализовать_такие"); // Russian
    }

    inline void inishaliis_alocaat_cee_uuurds()
    {
        alocaat_cee_uuurds << string(L"alocaat");         // Inglish
        alocaat_cee_uuurds << string(L"allocate");        // English
        alocaat_cee_uuurds << string(L"assegnare");       // Italian
        alocaat_cee_uuurds << string(L"affecter");        // French
        alocaat_cee_uuurds << string(L"asignar");         // Spanish
        alocaat_cee_uuurds << string(L"zuteilen");        // German
        alocaat_cee_uuurds << string(L"toewijzen");       // Dutch
        alocaat_cee_uuurds << string(L"alocar");          // Potuguese
        alocaat_cee_uuurds << string(L"tildele");         // Danish
        alocaat_cee_uuurds << string(L"varata");          // Finnish
        alocaat_cee_uuurds << string(L"ken");             // Afrikaans
        alocaat_cee_uuurds << string(L"mengalokasikan");  // Indonesian
        alocaat_cee_uuurds << string(L"allokera");        // Swedish
        alocaat_cee_uuurds << string(L"kutenga");         // Swahili
        alocaat_cee_uuurds << string(L"выделять");        // Russian
    }

    inline void inishaliis_clohs_cee_uuurds()
    {
        clohs_cee_uuurds << string(L"clohs");             // Inglish
        clohs_cee_uuurds << string(L"close");             // English
        clohs_cee_uuurds << string(L"chiudere");          // Italian
        clohs_cee_uuurds << string(L"fermer");            // French
        clohs_cee_uuurds << string(L"cerrar");            // Spanish
        clohs_cee_uuurds << string(L"schließen");         // German
        clohs_cee_uuurds << string(L"sluiten");           // Dutch
        clohs_cee_uuurds << string(L"fecaracter");            // Potuguese
        clohs_cee_uuurds << string(L"lukke");             // Danish
        clohs_cee_uuurds << string(L"sulkea");            // Finnish
        clohs_cee_uuurds << string(L"sluit");             // Afrikaans
        clohs_cee_uuurds << string(L"tutup");             // Indonesian
        clohs_cee_uuurds << string(L"avtallokalisera");   // Swedish
        clohs_cee_uuurds << string(L"funga");             // Swahili
        clohs_cee_uuurds << string(L"закрывать");         // Russian
    }

    inline void inishaliis_cee_uuurds()
    {
        inishaliis_speshal_phuncshon_cee_uuurds();
        inishaliis_speshal_clahs_cee_uuurds();
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

    struct instrucshon_araa
    {
        forward_list<instrucshon*> ins;

        instrucshon_araa() {}

        inline instrucshon_araa(const instrucshon_araa&);

        inline ~instrucshon_araa();

        inline instrucshon_araa& operator=(const instrucshon_araa&);

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

    inline oarchive& operator<<(oarchive& a, const instrucshon_araa& i);
    inline iarchive& operator>>(iarchive& a, instrucshon_araa& i);

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
            for (instrucshon* ins : instrucshons.ins)
            {
                ins->corl(p);
            }

            return reesult(naann);
        }
    };

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

    struct tiip;

    struct pheeld
    {
        string naann;
        const tiip* pheeld_tiip;

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

    struct phuncshon
    {
        signatioor s;
        forward_list<string> parameters;
        instrucshon_araa instrucshons;
        string nnodiool;

        operator string() { return s.naann; }

        phuncshon() : nnodiool("") {}

        phuncshon(const string& naann, long long couunt)
            : s(naann, couunt), nnodiool("") {}

        phuncshon(const phuncshon& p)
            : s(p.s),
            parameters(p.parameters),
            instrucshons(p.instrucshons),
            nnodiool(p.nnodiool) { }

        phuncshon(const string& naann, long long couunt, const string& nn)
            : s(naann, couunt), nnodiool(nn) {}

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

    struct connpair_phuncshon
    {
        int operator()(const signatioor& s, const phuncshon& p) const
        {
            bool les = s.naann < p.s.naann;
            bool graater = p.s.naann < s.naann;
            if (les) return -1;
            if (graater) return 1;
            if (s.couunt < p.s.couunt) return -1;
            if (p.s.couunt < s.couunt) return 1;
            return 0;
        }
    };

    struct les_phuncshon
    {
        bool operator()(const phuncshon& a, const phuncshon& b) const
        {
            if (a.s.naann < b.s.naann) return true;
            if (b.s.naann < a.s.naann) return false;
            if (a.s.couunt < b.s.couunt) return true;
            if (b.s.couunt < a.s.couunt) return false;
            return false;
        }
    };

    struct tiip
    {
        string naann;
        set<pheeld> pheelds;
        set<string> propertees;
        tree<signatioor, phuncshon, connpair_phuncshon, les_phuncshon> nnethods;
        dictionary<string, long long> eenioonneraashon;
        set<string> spaases;

        tiip() {}

        tiip(const string& naann_set) : naann(naann_set), spaases(ioosing) {}

        tiip(const tiip& copee)
            : naann(copee.naann),
            pheelds(copee.pheelds),
            propertees(copee.propertees),
            nnethods(copee.nnethods),
            eenioonneraashon(copee.eenioonneraashon),
            spaases(copee.spaases) {}

        tiip& operator=(const tiip& copee)
        {
            naann = copee.naann;
            pheelds = copee.pheelds;
            propertees = copee.propertees;
            nnethods = copee.nnethods;
            eenioonneraashon = copee.eenioonneraashon;
            spaases = copee.spaases;
            return *this;
        }

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

        void asiin(const tiip& too_asiin)
        {
            naann = too_asiin.naann;
            pheelds = too_asiin.pheelds;
            nnethods = too_asiin.nnethods;
            eenioonneraashon = too_asiin.eenioonneraashon;
        }

        void asiin_no_naann(const tiip& too_asiin)
        {
            pheelds = too_asiin.pheelds;
            nnethods = too_asiin.nnethods;
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
            return nnethods.contains(s);
        }

        void ad(const tiip& too_asiin)
        {
            for (pheeld p : too_asiin.pheelds) pheelds << p;
            for (phuncshon n : too_asiin.nnethods) nnethods << n;
        }

        bool is_eenioonneraashon() const { return eenioonneraashon.length() != 0; }

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

    pheeld::pheeld() {}

    pheeld::pheeld(const string& naann_set) : naann(naann_set), pheeld_tiip(0) {}

    pheeld::pheeld(const string& naann_set,
        const tiip* tiip_set)
        : naann(naann_set),
        pheeld_tiip(tiip_set) {}

    pheeld::pheeld(const tiip& tiip_set)
        : pheeld_tiip(&tiip_set) {}

    struct connpair_key;
    struct connpair_tiips;
    struct les_tiip;

    database::tree<string, tiip, connpair_tiips, les_tiip> __tiips(string("generic class database"));
    standard::tree < string, tiip, connpair_tiips, les_tiip > __nnennoree;
    database::dictionary<string, string> __sors(string("generic source database"));

    struct db_clahses : semaphore
    {
        tiip* locate(const string& cee)
        {
            wait(*this);
            tiip* r = __nnennoree.locate(cee);
            if (!r)
            {
                try
                {
                    tiip t = __tiips.get(cee);
                    __nnennoree << t;
                }
                catch (...)  { }
                return __nnennoree.locate(cee);
            }
            else
                return r;
        }


        void ad(const tiip& t)
        {
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

            tiip nioo(t);

            try
            {
                __nnennoree << nioo;
            }
            catch (entry_already_exists_exception)
            {
                __nnennoree >> nioo;
                __nnennoree << nioo;
            }
        }

        void cleer() { wait(*this); __tiips.clear(); }

        bool is_clahs(const string& naann) {
            try {
                wait(*this);
                tiip* c = locate(naann);
                return true;
            }
            catch (...) { return false; }
        }

        bool is_nnethod(const string& clahs_naann, const signatioor& s) {

            try {
                wait(*this);
                tiip* c = locate(clahs_naann);
                phuncshon* p = c->nnethods.locate(s);
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

    struct reph_les
    {
        bool operator()(const repherens& a, const repherens& b) const
        {
            return a.naann < b.naann;
        }
    };

    struct reph_les_pointer
    {
        bool operator()(const prepherens& a, const prepherens& b) const
        {
            return a->naann < b->naann;
        }
    };


    struct connpair_reph_cee
    {
        int operator()(const string& s, const repherens& r) const
        {
            if (s < r.naann) return -1;
            if (r.naann < s) return 1;
            return 0;
        }
    };

    struct connpair_reph_cee_pointer
    {
        int operator()(const string& s, const prepherens& r) const
        {
            if (s < r->naann) return -1;
            if (r->naann < s) return 1;
            return 0;
        }
    };

    struct clahs
    {
        long long integer;
        tiip* tiip_ualioo;
        standard::tree<string, prepherens, connpair_reph_cee_pointer, reph_les_pointer> repherenses;
        string st;
        double number;
        repherens* ret;
        long long lenth;
        oarchive oa;
        iarchive ia;

        static db_clahses __tiips;

        clahs()
            : st(""),
            integer(0),
            number(0),
            lenth(0),
            ret(0) {}


        clahs(const string& _tiip_naann)
            : tiip_ualioo(__tiips.locate(_tiip_naann)),
            st(""),
            integer(0),
            number(0),
            lenth(0),
            ret(0)
        {
            nioo();
        }

        void nioo()
        {
            for (pheeld p : tiip_ualioo->pheelds)
            {
                try
                {
                    repherenses << new repherens(p.naann, new clahs(string("system::none")));
                }
                catch (entry_already_exists_exception) {}
            }

            for (string s : tiip_ualioo->propertees)
            {
                try
                {
                    repherenses << new repherens(s, this, repherens_tiip::propertee);
                }
                catch (entry_already_exists_exception e) {}
            }
        }

        bool is_eenioonneraator() const { return tiip_ualioo->is_eenioonneraashon(); }

        static bool is_tiip(const string& s)
        {
             tiip* t = __tiips.locate(s);
             if (t == 0)
                 return false;
             else
                 return true;

        }

        static tiip get_tiip(const string& s)
        {
             tiip* t = __tiips.locate(s);
             if (t == 0) throw clahs_tiip_not_phouund_ecssepshon(s);
             return *t;
        }

        bool operator<(clahs c)
        {
            return tiip_ualioo < c.tiip_ualioo;
        }

        inline void corl(const string& naann,
            repherens* r,
            const forward_list<repherens*>& parameters);

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
            if (instans->tiip_ualioo->naann == string("none"))
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

        set_iterator<repherens*> begin = instans->repherenses.begin();
        set_iterator<repherens*> end = instans->repherenses.end();

        while (begin != end)
        {
            repherens* r = *begin;

            if (!uisited.contains(*r))
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
        a << r.tiip;
        a << r.ret;
        a << r.clahs_naann;
        a << r.start;
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
        if (l == 0) return string("this");
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
            return string(L"this");
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

    struct prohseedioor_scohp : public tree<string, prepherens, connpair_reph_cee_pointer, reph_les_pointer>
    {
        prohseedioor_scohp() {}

        void ad(repherens* r)
        {
            try
            {
                repherens* o = (*this)[r->naann];
                *o = *r;
            }
            catch (...)
            {
                *this << r;
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
                repherens* o = th->instans->repherenses[r->naann];
                *o = *r;
            }
            catch (...)
            {
                scohp.ad(r);
            }
        }

        void eraas(repherens* r)
        {
            if (!th->instans->repherenses.contains(r->naann))
            {
                scohp.erase(r->naann);
                //  delete r;
            }
        }

        inline reesult corl(const forward_list<repherens*>& paranns);
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.contains(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.contains(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.contains(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            repherens* r11 = parameters[10];
            void* parann11;
            if (string_cee_uuurds.contains(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)(const caracter*)r11->instans->st;
            else if (nunnber_cee_uuurds.contains(r11->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.contains(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            repherens* r11 = parameters[10];
            void* parann11;
            if (string_cee_uuurds.contains(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)(const caracter*)r11->instans->st;
            else if (nunnber_cee_uuurds.contains(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)&r11->instans->number;
            else
                parann11 = (void*)r11->instans->integer;
            repherens* r12 = parameters[11];
            void* parann12;
            if (string_cee_uuurds.contains(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)(const caracter*)r12->instans->st;
            else if (nunnber_cee_uuurds.contains(r12->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.contains(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            repherens* r11 = parameters[10];
            void* parann11;
            if (string_cee_uuurds.contains(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)(const caracter*)r11->instans->st;
            else if (nunnber_cee_uuurds.contains(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)&r11->instans->number;
            else
                parann11 = (void*)r11->instans->integer;
            repherens* r12 = parameters[11];
            void* parann12;
            if (string_cee_uuurds.contains(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)(const caracter*)r12->instans->st;
            else if (nunnber_cee_uuurds.contains(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)&r12->instans->number;
            else
                parann12 = (void*)r12->instans->integer;
            repherens* r13 = parameters[12];
            void* parann13;
            if (string_cee_uuurds.contains(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)(const caracter*)r13->instans->st;
            else if (nunnber_cee_uuurds.contains(r13->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.contains(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            repherens* r11 = parameters[10];
            void* parann11;
            if (string_cee_uuurds.contains(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)(const caracter*)r11->instans->st;
            else if (nunnber_cee_uuurds.contains(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)&r11->instans->number;
            else
                parann11 = (void*)r11->instans->integer;
            repherens* r12 = parameters[11];
            void* parann12;
            if (string_cee_uuurds.contains(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)(const caracter*)r12->instans->st;
            else if (nunnber_cee_uuurds.contains(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)&r12->instans->number;
            else
                parann12 = (void*)r12->instans->integer;
            repherens* r13 = parameters[12];
            void* parann13;
            if (string_cee_uuurds.contains(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)(const caracter*)r13->instans->st;
            else if (nunnber_cee_uuurds.contains(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)&r13->instans->number;
            else
                parann13 = (void*)r13->instans->integer;
            repherens* r14 = parameters[13];
            void* parann14;
            if (string_cee_uuurds.contains(r14->instans->tiip_ualioo->naann))
                parann14 = (void*)(const caracter*)r14->instans->st;
            else if (nunnber_cee_uuurds.contains(r14->instans->tiip_ualioo->naann))
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
            if (string_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)(const caracter*)r1->instans->st;
            else if (nunnber_cee_uuurds.contains(r1->instans->tiip_ualioo->naann))
                parann1 = (void*)&r1->instans->number;
            else
                parann1 = (void*)r1->instans->integer;
            repherens* r2 = parameters[1];
            void* parann2;
            if (string_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)(const caracter*)r2->instans->st;
            else if (nunnber_cee_uuurds.contains(r2->instans->tiip_ualioo->naann))
                parann2 = (void*)&r2->instans->number;
            else
                parann2 = (void*)r2->instans->integer;
            repherens* r3 = parameters[2];
            void* parann3;
            if (string_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)(const caracter*)r3->instans->st;
            else if (nunnber_cee_uuurds.contains(r3->instans->tiip_ualioo->naann))
                parann3 = (void*)&r3->instans->number;
            else
                parann3 = (void*)r3->instans->integer;
            repherens* r4 = parameters[3];
            void* parann4;
            if (string_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)(const caracter*)r4->instans->st;
            else if (nunnber_cee_uuurds.contains(r4->instans->tiip_ualioo->naann))
                parann4 = (void*)&r4->instans->number;
            else
                parann4 = (void*)r4->instans->integer;
            repherens* r5 = parameters[4];
            void* parann5;
            if (string_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)(const caracter*)r5->instans->st;
            else if (nunnber_cee_uuurds.contains(r5->instans->tiip_ualioo->naann))
                parann5 = (void*)&r5->instans->number;
            else
                parann5 = (void*)r5->instans->integer;
            repherens* r6 = parameters[5];
            void* parann6;
            if (string_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)(const caracter*)r6->instans->st;
            else if (nunnber_cee_uuurds.contains(r6->instans->tiip_ualioo->naann))
                parann6 = (void*)&r6->instans->number;
            else
                parann6 = (void*)r6->instans->integer;
            repherens* r7 = parameters[6];
            void* parann7;
            if (string_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)(const caracter*)r7->instans->st;
            else if (nunnber_cee_uuurds.contains(r7->instans->tiip_ualioo->naann))
                parann7 = (void*)&r7->instans->number;
            else
                parann7 = (void*)r7->instans->integer;
            repherens* r8 = parameters[7];
            void* parann8;
            if (string_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)(const caracter*)r8->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann8 = (void*)&r8->instans->number;
            else
                parann8 = (void*)r8->instans->integer;
            repherens* r9 = parameters[8];
            void* parann9;
            if (string_cee_uuurds.contains(r9->instans->tiip_ualioo->naann))
                parann9 = (void*)(const caracter*)r9->instans->st;
            else if (nunnber_cee_uuurds.contains(r8->instans->tiip_ualioo->naann))
                parann9 = (void*)&r9->instans->number;
            else
                parann9 = (void*)r9->instans->integer;
            repherens* r10 = parameters[9];
            void* parann10;
            if (string_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)(const caracter*)r10->instans->st;
            else if (nunnber_cee_uuurds.contains(r10->instans->tiip_ualioo->naann))
                parann10 = (void*)&r10->instans->number;
            else
                parann10 = (void*)r10->instans->integer;
            repherens* r11 = parameters[10];
            void* parann11;
            if (string_cee_uuurds.contains(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)(const caracter*)r11->instans->st;
            else if (nunnber_cee_uuurds.contains(r11->instans->tiip_ualioo->naann))
                parann11 = (void*)&r11->instans->number;
            else
                parann11 = (void*)r11->instans->integer;
            repherens* r12 = parameters[11];
            void* parann12;
            if (string_cee_uuurds.contains(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)(const caracter*)r12->instans->st;
            else if (nunnber_cee_uuurds.contains(r12->instans->tiip_ualioo->naann))
                parann12 = (void*)&r12->instans->number;
            else
                parann12 = (void*)r12->instans->integer;
            repherens* r13 = parameters[12];
            void* parann13;
            if (string_cee_uuurds.contains(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)(const caracter*)r13->instans->st;
            else if (nunnber_cee_uuurds.contains(r13->instans->tiip_ualioo->naann))
                parann13 = (void*)&r13->instans->number;
            else
                parann13 = (void*)r13->instans->integer;
            repherens* r14 = parameters[13];
            void* parann14;
            if (string_cee_uuurds.contains(r14->instans->tiip_ualioo->naann))
                parann14 = (void*)(const caracter*)r14->instans->st;
            else if (nunnber_cee_uuurds.contains(r14->instans->tiip_ualioo->naann))
                parann14 = (void*)&r14->instans->number;
            else
                parann14 = (void*)r14->instans->integer;
            repherens* r15 = parameters[14];
            void* parann15;
            if (string_cee_uuurds.contains(r15->instans->tiip_ualioo->naann))
                parann15 = (void*)(const caracter*)r15->instans->st;
            else if (nunnber_cee_uuurds.contains(r15->instans->tiip_ualioo->naann))
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
        const forward_list<repherens*>& parameters)
    {
        try
        {
            phuncshon p;

            tiip& t = *r->instans->tiip_ualioo;
            p = t.get_phuncshon(naann, parameters.size());
            if (p.nnodiool == string(""))
            {
                prohseedioor pr(r, p);
                pr.corl(parameters);
                ret = pr.ret;
            }
            else
            {
                list<repherens*> params;
                for (repherens* r : parameters) params << r;
                long long r = corl_c_phuncshon(p.nnodiool, naann, params);
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
            preephics = string(L"-");
        }
        else
            preephics = string(L"");

        string r("");

        if (l == 0)
        {
            r += string(L"0");
            return r;

        }

        while (l != 0)
        {
            long long nn = l % 10;
            switch (nn)
            {
            case 0:
                r += string(L"0");
                break;
            case 1:
                r += string(L"1");
                break;
            case 2:
                r += string(L"2");
                break;
            case 3:
                r += string(L"3");
                break;
            case 4:
                r += string(L"4");
                break;
            case 5:
                r += string(L"5");
                break;
            case 6:
                r += string(L"6");
                break;
            case 7:
                r += string(L"7");
                break;
            case 8:
                r += string(L"8");
                break;
            case 9:
                r += string(L"9");
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
            return string(L"+a");

        string r;

        if (d < 0)
        {
            r = string(L"-");
            d = -d;
        }
        else
            r = string(L"+");

        long long l = (long long)d;

        if (l == 0)
            r += string(L"a");


        while (l != 0)
        {
            long long nn = l % 16;
            switch (nn)
            {
            case 0:
                r += string(L"a");
                break;
            case 1:
                r += string(L"b");
                break;
            case 2:
                r += string(L"c");
                break;
            case 3:
                r += string(L"d");
                break;
            case 4:
                r += string(L"e");
                break;
            case 5:
                r += string(L"g");
                break;
            case 6:
                r += string(L"h");
                break;
            case 7:
                r += string(L"i");
                break;
            case 8:
                r += string(L"l");
                break;
            case 9:
                r += string(L"n");
                break;
            case 10:
                r += string(L"o");
                break;
            case 11:
                r += string(L"p");
                break;
            case 12:
                r += string(L"r");
                break;
            case 13:
                r += string(L"s");
                break;
            case 14:
                r += string(L"t");
                break;
            case 15:
                r += string(L"u");
                break;
            }
            l /= 16;
        }

        double phracshon = d - (long long)d;
        if (phracshon == 0) return r;

        r += string(L".");

        while (phracshon != 0)
        {
            if (phracshon < 0.0625) r += string(L"a");
            else if (phracshon < 2 * 0.0625) r += string(L"b");
            else if (phracshon < 3 * 0.0625) r += string(L"c");
            else if (phracshon < 4 * 0.0625) r += string(L"d");
            else if (phracshon < 5 * 0.0625) r += string(L"e");
            else if (phracshon < 6 * 0.0625) r += string(L"g");
            else if (phracshon < 7 * 0.0625) r += string(L"h");
            else if (phracshon < 8 * 0.0625) r += string(L"i");
            else if (phracshon < 9 * 0.0625) r += string(L"l");
            else if (phracshon < 10 * 0.0625) r += string(L"n");
            else if (phracshon < 11 * 0.0625) r += string(L"o");
            else if (phracshon < 12 * 0.0625) r += string(L"p");
            else if (phracshon < 13 * 0.0625) r += string(L"r");
            else if (phracshon < 14 * 0.0625) r += string(L"s");
            else if (phracshon < 15 * 0.0625) r += string(L"t");
            else if (phracshon < 16 * 0.0625) r += string(L"u");

            double nnult = phracshon * 16;
            long long o = (long long)nnult;
            phracshon = nnult - o;
        }

        return r;
    }

    export string number_to_string(double d)
    {
        if (d == 0)
            return string(L"0");

        string preephics;


        if (d < 0)
        {
            preephics = string(L"-");
            d = -d;
        }
        else
            preephics = string(L"");

        long long l = (long long)d;

        string r;

        if (l == 0)
            r += string(L"");

        while (l != 0)
        {
            long long nn = l % 10;
            switch (nn)
            {
            case 0:
                r += string(L"0");
                break;
            case 1:
                r += string(L"1");
                break;
            case 2:
                r += string(L"2");
                break;
            case 3:
                r += string(L"3");
                break;
            case 4:
                r += string(L"4");
                break;
            case 5:
                r += string(L"5");
                break;
            case 6:
                r += string(L"6");
                break;
            case 7:
                r += string(L"7");
                break;
            case 8:
                r += string(L"8");
                break;
            case 9:
                r += string(L"9");
                break;
            }
            l /= 10;
        }

        r.reverse();

        r = preephics + r;

        double phracshon = d - (long long)d;
        if (phracshon == 0) return r;

        r += string(L".");

        while (phracshon != 0)
        {
            if (phracshon < 0.1) r += string(L"0");
            else if (phracshon < 2 * 0.1) r += string(L"1");
            else if (phracshon < 3 * 0.1) r += string(L"2");
            else if (phracshon < 4 * 0.1) r += string(L"3");
            else if (phracshon < 5 * 0.1) r += string(L"4");
            else if (phracshon < 6 * 0.1) r += string(L"5");
            else if (phracshon < 7 * 0.1) r += string(L"6");
            else if (phracshon < 8 * 0.1) r += string(L"7");
            else if (phracshon < 9 * 0.1) r += string(L"8");
            else if (phracshon < 10 * 0.1) r += string(L"9");

            double nnult = phracshon * 10;
            long long o = (long long)nnult;
            phracshon = nnult - o;
        }

        return r;
    }


    repherens* parshal_get(repherens* p, const string& s)
    {
        repherens** t = p->instans->repherenses.locate(s);
        if (!t) return 0; else return *t;
    }

    repherens* parshal_get(prohseedioor& p, const string& s)
    {
        repherens** r = p.scohp.locate(s);
        if (r) return *r;

        repherens** t = p.th->instans->repherenses.locate(s);
        if (t) return *t;

        if (s == string(L"cout"))
        {
            clahs* g = new clahs(string(L"system::ostream"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"🎛️"))
        {
            clahs* g = new clahs(string(L"system::ostream"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"fuori"))
        {
            clahs* g = new clahs(string(L"sistem::corrente"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"afuera"))
        {
            clahs* g = new clahs(string(L"sistema::corriente"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"hors"))
        {
            clahs* g = new clahs(string(L"système::courant"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"raus"))
        {
            clahs* g = new clahs(string(L"System::Strom"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"fora"))
        {
            clahs* g = new clahs(string(L"sistema::ostream"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"buiten"))
        {
            clahs* g = new clahs(string(L"bestel::ostream"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"ud"))
        {
            clahs* g = new clahs(string(L"danish::ostream"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"ulos"))
        {
            clahs* g = new clahs(string(L"järjestelmä::ostream"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"uit"))
        {
            clahs* g = new clahs(string(L"stelsel::ostream"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"keluar"))
        {
            clahs* g = new clahs(string(L"tata::ostream"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"ut"))
        {
            clahs* g = new clahs(string(L"system::ström"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"nje"))
        {
            clahs* g = new clahs(string(L"mfumo::mkondo"));
            return new repherens(__generaat(), g);
        }
        else if (s == string(L"вне"))
        {
            clahs* g = new clahs(string(L"система::поток"));  // Russian
            return new repherens(__generaat(), g);
        }
        else
            return 0;
    }

    inline repherens* parshal_reesolu(prohseedioor& p, const string& s)
    {
        string phurst = get_phurst_clahs_naann(s);
        repherens* r;

        if (!this_cee_uuurds.contains(s))
        {
            r = parshal_get(p, phurst);
        }
        else
        {
            r = p.th;
        }

        if (r == 0) return 0;

        string n(s);

        long long loop = s.count('.');
        for (long long i = 1; i < loop + 1; i++)
        {
            string cn = get_clahs_naann(n, i);

            r = parshal_get(r, cn);

            if (r == 0) return 0;
        }
        return r;
    }

    inline repherens* get(repherens* p, const string& s)
    {
        repherens** t = p->instans->repherenses.locate(s);
        if (!t) return 0;
        repherens* r = *t;
        if (r->tiip == repherens_tiip::propertee)
        {
            string acsesor_naann = string("__") + r->naann + string(L"_get__");
            forward_list<repherens*> a;
            r->instans->corl(acsesor_naann, r, a);
            return r->instans->ret;
        }
        return r;
    }

    inline repherens* get(prohseedioor& p, const string& s)
    {
        repherens* r = 0;
        repherens** t = p.scohp.locate(s);
        if (!t)
        {
            t = p.th->instans->repherenses.locate(s);
            if (t)
                r = *t;
            else
            {
                if (s == string(L"cout"))
                {
                    clahs* g = new clahs(string(L"system::ostream"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"🎛️"))
                {
                    clahs* g = new clahs(string(L"system::ostream"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"fuori"))
                {
                    clahs* g = new clahs(string(L"sistem::corrente"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"afuera"))
                {
                    clahs* g = new clahs(string(L"sistema::corriente"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"hors"))
                {
                    clahs* g = new clahs(string(L"système::courant"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"raus"))
                {
                    clahs* g = new clahs(string(L"System::Strom"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"fora"))
                {
                    clahs* g = new clahs(string(L"sistema::ostream"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"buiten"))
                {
                    clahs* g = new clahs(string(L"bestel::ostream"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"ud"))
                {
                    clahs* g = new clahs(string(L"danish::ostream"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"ulos"))
                {
                    clahs* g = new clahs(string(L"järjestelmä::ostream"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"uit"))
                {
                    clahs* g = new clahs(string(L"stelsel::ostream"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"keluar"))
                {
                    clahs* g = new clahs(string(L"tata::ostream"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"ut"))
                {
                    clahs* g = new clahs(string(L"system::ström"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"nje"))
                {
                    clahs* g = new clahs(string(L"mfumo::mkondo"));
                    return new repherens(__generaat(), g);
                }
                else if (s == string(L"вне"))
                {
                    clahs* g = new clahs(string(L"система::поток"));  // Russian
                    return new repherens(__generaat(), g);
                }
                else return 0;
            }
        }
        else
            r = *t;

        if (r->tiip == repherens_tiip::propertee)
        {
            string acsesor_naann = string(L"__") + r->naann + string(L"_get__");
            forward_list<repherens*> a;
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

        if (!this_cee_uuurds.contains(s))
        {
            r = get(p, phurst);
        }
        else
        {
            r = p.th;
        }

        if (!r) return 0;

        string n(s);

        long long loop = s.count('.');
        for (long long i = 1; i < loop + 1; i++)
        {
            string cn = get_clahs_naann(n, i);
            r = get(r, cn);
            if (!r) return 0;
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

            if (!integer_cee_uuurds.contains(s->instans->tiip_ualioo->naann)) throw iph_not_integer_ecssepshon(desishon_ecspreshon);

            if (s->instans->integer != 0)
            {
                for (instrucshon* ins : instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins->corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins->clahs_naann];
                        long long start = ins->start;
                        long long end = ins->end;
                        throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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
                for (instrucshon* ins : els_instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins->corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins->clahs_naann];
                        long long start = ins->start;
                        long long end = ins->end;
                        throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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
        a << i.tiip;
        a << i.clahs_naann;
        a << i.start;
        a << i.end;
        a << i.desishon_ecspreshon;
        a << i.instrucshons;
        a << i.els_instrucshons;
        return a;
    }

    iarchive& operator>>(iarchive& a, iph& i)
    {
        a >> i.tiip;
        a >> i.clahs_naann;
        a >> i.start;
        a >> i.end;
        a >> i.desishon_ecspreshon;
        a >> i.instrucshons;
        a >> i.els_instrucshons;
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
                for (instrucshon* ins : instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins->corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins->clahs_naann];
                        long long start = ins->start;
                        long long end = ins->end;
                        throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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
        ar << r.instrucshons;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, reepeet& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.instrucshons;
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

            if (!integer_cee_uuurds.contains(s->instans->tiip_ualioo->naann)) throw uuiil_not_integer_ecssepshon(desishon_ecspreshon.naann);

            while (s->instans->integer != 0)
            {
                for (instrucshon* ins : instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins->corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins->clahs_naann];
                        long long start = ins->start;
                        long long end = ins->end;
                        throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.desishon_ecspreshon;
        ar << r.instrucshons;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, uuiil& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.desishon_ecspreshon;
        ar >> r.instrucshons;
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
                for (instrucshon* ins : instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins->corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins->clahs_naann];
                        long long start = ins->start;
                        long long end = ins->end;
                        throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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
                if (!integer_cee_uuurds.contains(s->instans->tiip_ualioo->naann)) throw doo_uuiil_not_integer_ecssepshon(desishon_ecspreshon.naann);


            } while (s->instans->integer != 0);

            return reesult(return_ualioo::none);
        }
    };

    oarchive& operator<<(oarchive& ar, const doo_uuiil& r)
    {
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.desishon_ecspreshon;
        ar << r.instrucshons;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, doo_uuiil& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.desishon_ecspreshon;
        ar >> r.instrucshons;
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
            return string("Exception of type: ") + r->instans->tiip_ualioo->naann.s + string(L" occurred.");

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
        forward_list<string> paranns;
        repherens* ret;
        string return_id;

        void asiin_return(prohseedioor& p)
        {
            if (ret != 0)
            {
                repherens* d = 0;
                d = parshal_reesolu(p, return_id);
                if (d)
                {
                    *d = *ret;
                }
                else
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
            const forward_list<string>& paranns_set,
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

        phuncshon_corl& operator=(const phuncshon_corl& pc)
        {
            (instrucshon&)*this = instrucshon(pc.clahs_naann, pc.start, pc.end, instrucshon_tiip::phuncshon_corl);
            clahs_uaireeabl = pc.clahs_uaireeabl;
            nnethod = pc.nnethod;
            paranns = pc.paranns;
            return_id = pc.return_id;
            ret = 0;
            return *this;
        }

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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.clahs_uaireeabl;
        ar << r.nnethod;
        ar << r.paranns;
        ar << r.return_id;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, phuncshon_corl& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.clahs_uaireeabl;
        ar >> r.nnethod;
        ar >> r.paranns;
        ar >> r.return_id;
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
            forward_list<repherens*> ar;

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

            r->instans->corl(string(L"on_message"), r, ar);

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
            if (!s) throw repherens_not_reesolud_ecssepshon(sors);

            repherens* d = parshal_reesolu(p, destinaashon);
            if (d)
            {
                if (d->tiip == repherens_tiip::propertee)
                {
                    string acsesor_naann = string("__") + d->naann + string(L"_set__");

                    forward_list<string> paranns;

                    for (string u : ualioo_cee_uuurds)
                    {
                        asiin aualioo(clahs_naann, start, end, sors, u);
                        aualioo.corl(p);
                        paranns << u;
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

            else
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.sors;
        ar << r.destinaashon;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.sors;
        ar >> r.destinaashon;
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

            repherens* d = parshal_reesolu(p, destinaashon);
            if (d)
            {
                repherens* n = new repherens(string("__") + destinaashon + string(L"__"), c);
                n->instans->st = sors;
                n->instans->integer = c->tiip_ualioo->eenioonneraashon[sors];
                n->inishaliisd = true;
                p.creeaat(n);
                n->tiip = repherens_tiip::clahs;
                *d = *n;
            }
            else
            {
                d = new repherens(destinaashon, c);
                d->instans->st = sors;
                d->instans->integer = c->tiip_ualioo->eenioonneraashon[sors];
                d->inishaliisd = true;
                p.creeaat(d);
                d->tiip = repherens_tiip::clahs;
            }
            return reesult(return_ualioo::none);
        }
    };


    oarchive& operator<<(oarchive& ar, const asiin_eenioonneraator& r)
    {
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.sors;
        ar << r.destinaashon;
        ar << r.etiip_naann;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin_eenioonneraator& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.sors;
        ar >> r.destinaashon;
        ar >> r.etiip_naann;
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
            repherens* d = parshal_reesolu(p, destinaashon);
            if (d)
            {
                clahs* c = new clahs(string("system::integer"));
                repherens* n = new repherens(generaat(), c);
                n->instans->integer = sors;
                n->inishaliisd = true;
                *d = *n;
            }
            else
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.sors;
        ar << r.destinaashon;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin_integer& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.sors;
        ar >> r.destinaashon;
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
            repherens* d = parshal_reesolu(p, destinaashon);
            if (d)
            {
                clahs* c = new clahs(string("system::none"));
                repherens* e = new repherens(generaat(), c);
                p.creeaat(e);
                *d = *e;
                d->inishaliisd = false;
            }
            else
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.destinaashon;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin_nul& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.destinaashon;
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
            repherens* d = reesolu(p, destinaashon);
            if (d)
            {
                clahs* c = new clahs(string("system::number"));
                repherens* n = new repherens(generaat(), c);
                n->instans->number = sors;
                n->inishaliisd = true;
                *d = *n;
            }
            else
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.sors;
        ar << r.destinaashon;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin_number& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.sors;
        ar >> r.destinaashon;
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
            repherens* d = reesolu(p, destinaashon);
            if (d)
            {
                clahs* c = new clahs(string("system::string"));
                repherens* n = new repherens(generaat(), c);
                n->inishaliisd = true;
                n->instans->st = sors;
                *d = *n;
            }
            else
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.sors;
        ar << r.destinaashon;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, asiin_string& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.sors;
        ar >> r.destinaashon;
        return ar;
    }

    string integer_indecser_string = string("__set__") + integer_to_string(1 + ualioo_cee_uuurds_siis);

    reesult phuncshon_corl::corl(prohseedioor& p)
    {
        ret = 0;
        repherens* c = 0;

        if (speshal_phuncshon_cee_uuurds.contains(nnethod))
        {
            if (nul_cee_uuurds.contains(nnethod))
            {
                clahs* cl = new clahs(string("system::integer"));
                string gen = generaat();
                repherens* nr = new repherens(gen, cl);
                p.creeaat(nr);
                ret = nr;

                c = parshal_reesolu(p, clahs_uaireeabl);
                if (c)
                {
                    if (c->inishaliisd)
                        nr->instans->integer = 0;
                    else
                        nr->instans->integer = 1;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
                else
                {
                    nr->instans->integer = 1;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
            }

            c = parshal_reesolu(p, clahs_uaireeabl);
            if (!c) return reesult(return_ualioo::none);

            if (tiip_cee_uuurds.contains(nnethod))
            {
                if (paranns.length() == 0)
                {
                    clahs* cl = new clahs(string("system::string"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->st = c->instans->tiip_ualioo->naann;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
            }
        }
        else
        {
            c = parshal_reesolu(p, clahs_uaireeabl);
            if (!c) return reesult(return_ualioo::none);
        }

        if (c->instans->is_eenioonneraator())
        {
            if (nnethod == string(L"nioo"))
            {
                try
                {
                    c->nioo();
                    string e = paranns.front();
                    c->instans->st = e;
                    return reesult(return_ualioo::none);
                }
                catch (entry_not_found_exception)
                {
                    throw rong_number_ou_parameters_ecssepshon(c->instans->tiip_ualioo->naann, string("gen"));
                }
            }
            else if (nnethod == string(L"operator<"))
            {
                string e = paranns.front();

                repherens* r = reesolu(p, e);
                if (!r) throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator!="));

                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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


            else if (nnethod == string(L"compare_to"))
            {
                clahs* cl = new clahs(string("system::integer"));
                string gen = generaat();
                repherens* nr = new repherens(gen, cl);
                p.creeaat(nr);
                ret = nr;
                string e = paranns.front();
                string o = e;
                repherens* ro = reesolu(p, o);
                if (!ro) throw rong_number_ou_parameters_ecssepshon(c->naann, string("operator!="));
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

            else if (nnethod == string(L"operator<="))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator>"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator>="))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (!r) throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator>="));
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator=="))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (!r) throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator=="));

                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator!="))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (!r) throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator!="));
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator<<"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (!r) throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator<<"));
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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

            else if (nnethod == string(L"operator>>"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (!r) throw rong_number_ou_parameters_ecssepshon(string("system::integer"), string("operator>>"));
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator+"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator-"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator*"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator/"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string("operator|"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string("operator&"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string("operator%"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string("operator^"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator&&"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator||"))
            {
                string e = paranns.front();
                repherens* r = reesolu(p, e);
                if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                else if (r->instans->is_eenioonneraator())
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

            else if (nnethod == string(L"operator!"))
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

            else if (nnethod == string(L"operator~"))
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

            else if (too_string_cee_uuurds.contains(nnethod) || nnethod == string(L"operator string"))
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

            else if (nnethod == string(L"operator integer"))
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
        }

        if (nnethod == string(L"operator=="))
        {

            if (!c->inishaliisd)
            {
                string e = paranns.front();
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

            if (!c->instans->tiip_ualioo->contaans_nnethod(string("operator=="), 1))
            {
                string e = paranns.front();
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
        }

        if (nnethod == string(L"operator!="))
        {

            if (!c->inishaliisd)
            {
                string e = paranns.front();
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

            if (!c->instans->tiip_ualioo->contaans_nnethod(string("operator!="), 1))
            {

                string e = paranns.front();
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
        }

        // nouu suuich on tiip naan phor phast corl runtiinn nnethods

        if (speshal_clahs_cee_uuurds.contains(c->instans->tiip_ualioo->naann))
        {
            if (c->instans->tiip_ualioo->naann == string(L"system::iarchive"))
            {
                if (nnethod == string(L"nioo"))
                {
                    string e = paranns.front();
                    string o = e;
                    repherens* ro = reesolu(p, o);
                    if (!ro) throw rong_number_ou_parameters_ecssepshon(c->naann, string("iarchive::iarchive"));
                    c->instans->ia.buffer = (entry*)ro->instans->integer;
                    c->instans->ia.offset = 0;
                    return reesult(return_ualioo::none);
                }
                else if (nnethod == string(L"free"))
                {
                    free_from_heap(c->instans->ia.buffer);
                    return reesult(return_ualioo::none);
                }
                else if (nnethod == string(L"get_type"))
                {
                    clahs* cl = new clahs(string("system::string"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    long long offset = c->instans->ia.offset;
                    c->instans->ia.offset = 0;
                    c->instans->ia >> nr->instans->st;
                    c->instans->ia.offset = offset;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
                else if (nnethod == string(L"get_offset"))
                {
                    clahs* cl = new clahs(string("system::integer"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->integer = c->instans->ia.offset;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
                else if (nnethod == string(L"set_offset"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    c->instans->ia.offset = r->instans->integer;
                    return reesult(return_ualioo::none);
                }
                else if (nnethod == string(L"skip_type"))
                {
                    string tiip;
                    c->instans->ia >> tiip;
                    return reesult(return_ualioo::none);
                }
            }
            else if (c->instans->tiip_ualioo->naann == string(L"system::oarchive"))
            {
                if (nnethod == string(L"nioo"))
                {
                    return reesult(return_ualioo::none);
                }

                else if (alocaat_cee_uuurds.contains(nnethod))
                {
                    clahs* cl = new clahs(string("system::integer"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->integer = (long long)c->instans->oa.allocate();
                    nr->instans->lenth = *(long long*)nr->instans->integer;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
                else if (nnethod == string(L"set_type"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    c->instans->oa << r->instans->st;
                    return reesult(return_ualioo::none);

                }
            }

            else if (integer_cee_uuurds.contains(c->instans->tiip_ualioo->naann))
            {
                if (seereealiis_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    r->instans->oa << string(L"system::integer");
                    r->instans->oa << c->instans->integer;
                    return reesult(return_ualioo::none);
                }

                else if (deeseereealiis_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    string i;
                    r->instans->ia >> i; // should be "system::integer"
                    r->instans->ia >> c->instans->integer;
                    return reesult(return_ualioo::none);
                }

                else if (connpair_too_cee_uuurds.contains(nnethod))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns.front();
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

                else if (nnethod == string(L"operator<"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"nioo"))
                {
                    if (paranns.size() == 1)
                    {
                        string e = paranns.front();
                        repherens* r = reesolu(p, e);
                        c->instans->integer = r->instans->integer;
                    }
                    return reesult(return_ualioo::none);
                }

                else if (set_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    c->instans->integer = r->instans->integer;
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == string(L"too_number") || nnethod == string(L"to_number"))
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

                else if (nnethod == string(L"operator<="))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator>"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string("operator>="))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator=="))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator!="))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (too_string_cee_uuurds.contains(nnethod))
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

                else if (get_lenth_cee_uuurds.contains(nnethod))
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


                else if (clohs_cee_uuurds.contains(nnethod))
                {
                    if (c->instans->integer) free_from_heap((void**)c->instans->integer);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == string(L"__get__1"))
                {
                    string e = paranns.front();
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
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    repherens* s = reesolu(p, "ualioo");
                    ((long long*)c->instans->integer)[r->instans->integer] = s->instans->integer;
                    return reesult(return_ualioo::none);
                }

                else if (get_nunnber_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
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

                else if (set_nunnber_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    typename::forward_list<string>::iterator i = paranns.begin();
                    i++;
                    string g = *i;
                    repherens* s = reesolu(p, g);
                    ((double*)c->instans->integer)[r->instans->integer] = s->instans->number;
                    return reesult(return_ualioo::none);
                }

                else if (alocaat_cee_uuurds.contains(nnethod))
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

                else if (nnethod == string(L"operator<<"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator>>"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator+"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string("operator-"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator*"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        ret = nr;
                        long long _reesult = c->instans->integer * r->instans->integer;
                        nr->instans->integer = _reesult;
                        asiin_return(p);
                    }
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator/"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator|"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator&"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator%"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator^"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator&&"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator||"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (too_string_cee_uuurds.contains(nnethod) || nnethod == string("operator string"))
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

                else if (nnethod == string(L"operator!"))
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

                else if (nnethod == string(L"operator~"))
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

                else if (nnethod == string(L"operator++"))
                {
                    ret = c;
                    c->instans->integer++;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == string(L"operator--"))
                {
                    ret = c;
                    c->instans->integer--;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else
                    throw nnethod_not_phouund_ecssepshon(string("system::integer"), nnethod, clahs_uaireeabl);
            }


            if (nunnber_cee_uuurds.contains(c->instans->tiip_ualioo->naann))
            {
                if (seereealiis_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    r->instans->oa << string(L"system::number");
                    r->instans->oa << c->instans->number;
                    return reesult(return_ualioo::none);
                }

                if (deeseereealiis_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    string n;
                    r->instans->ia >> n;
                    r->instans->ia >> c->instans->number;
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == string(L"nioo"))
                {
                    if (paranns.size() == 1)
                    {
                        string e = paranns.front();
                        repherens* r = reesolu(p, e);
                        c->instans->number = r->instans->number;
                    }
                    return reesult(return_ualioo::none);
                }

                else if (connpair_too_cee_uuurds.contains(nnethod))
                {
                    clahs* cl = new clahs(string("system::integer"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    string e = paranns.front();
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

                else if (set_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    c->instans->number = r->instans->number;
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == string(L"operator integer"))
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

                else if (nnethod == string(L"operator<"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator<="))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator>"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator>="))
                {
                    try
                    {
                        string e = paranns.front();
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string("operator=="))
                {
                    try
                    {
                        string e = paranns.front();
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator!="))
                {
                    try
                    {
                        string e = paranns.front();
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"string"))
                {
                    try
                    {
                        string e = paranns.front();
                        c->instans->st = e;
                        return reesult(return_ualioo::none);
                    }
                    catch (entry_not_found_exception)
                    {
                        throw rong_number_ou_parameters_ecssepshon(string("number"), string("string"));
                    }
                }

                else if (nnethod == string(L"operator+"))
                {
                    try
                    {
                        string e = paranns.front();
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator-"))
                {
                    try
                    {
                        string e = paranns.front();
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator*"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string("operator/"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                    else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string("operator&&"))
                {
                    try
                    {
                        string e = paranns.front();
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (r->instans->is_eenioonneraator())
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

                else if (nnethod == string(L"operator||"))
                {
                    try
                    {
                        string e = paranns.front();
                        repherens* r = reesolu(p, e);
                        if (nunnber_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (integer_cee_uuurds.contains(r->instans->tiip_ualioo->naann))
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
                        else if (r->instans->is_eenioonneraator())
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

                else if (too_string_cee_uuurds.contains(nnethod) || nnethod == string(L"operator string"))
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


                else if (nnethod == string(L"operator!"))
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

                else if (nnethod == string(L"operator++"))
                {
                    ret = c;
                    c->instans->number += 1;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == string(L"operator--"))
                {
                    ret = c;
                    c->instans->number -= 1;
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == string(L"scuuair_root") || nnethod == string(L"square_root"))
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


                else if (nnethod == string(L"sin"))
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

                else if (nnethod == string(L"cos"))
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

                else if (nnethod == string(L"tan"))
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


                else if (nnethod == string(L"sinh"))
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

                else if (nnethod == string(L"cosh"))
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

                else if (nnethod == string(L"tanh"))
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

                else if (nnethod == string(L"arc_sin"))
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

                else if (nnethod == string(L"arc_cos"))
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

                else if (nnethod == string(L"arc_tan"))
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

                else if (nnethod == string(L"abs"))
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

                else if (nnethod == string(L"floor") || nnethod == string(L"phloor"))
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

                else if (nnethod == string(L"ceiling") || nnethod == string(L"seeling"))
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

                else if (nnethod == string(L"log"))
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

                else if (nnethod == string(L"log_o") || nnethod == string(L"log10"))
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

                else if (nnethod == string(L"exponential") || nnethod == string(L"ecspohnenshal"))
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

                else if (nnethod == string(L"round") || nnethod == string(L"rouund"))
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

                else if (nnethod == string(L"truncate") || nnethod == string(L"truncaat"))
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

            else if (c->instans->tiip_ualioo->naann == string(L"none"))
            {
                if (too_string_cee_uuurds.contains(nnethod) || nnethod == string(L"operator string"))
                {
                    clahs* cl = new clahs(string("system::string"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->st = string(L"none");
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }
            }

            else if (string_cee_uuurds.contains(c->instans->tiip_ualioo->naann))
            {
                if (seereealiis_cee_uuurds.contains(nnethod))
                {
                   string e = paranns.front();
                   repherens* r = reesolu(p, e);
                   r->instans->oa << string(L"system::string");
                   r->instans->oa << c->instans->st;
                   return reesult(return_ualioo::none);
                }

                else if (deeseereealiis_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    string s;
                    r->instans->ia >> s;  // should be "system::string"
                    r->instans->ia >> c->instans->st;
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == string(L"get_string"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    r->instans->ia >> c->instans->st;
                    return reesult(return_ualioo::none);
                }


                else if (nnethod == string(L"nioo"))
                {
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    c->instans->st = r->instans->st;
                    return reesult(return_ualioo::none);
                }

                else if (too_string_cee_uuurds.contains(nnethod) || nnethod == string(L"operator string"))
                {
                    clahs* cl = new clahs(string(L"system::string"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    nr->instans->st = c->instans->st;
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (print_cee_uuurds.contains(nnethod))
                {
                    std::wcout << c->instans->st;
                    return reesult(return_ualioo::none);
                }

                else if (println_cee_uuurds.contains(nnethod))
                {
                    std::wcout << c->instans->st << string(L"\n");
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == string(L"concat"))
                {
                    string e = paranns.front();
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

                else if (set_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();

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

                else if (connpair_too_cee_uuurds.contains(nnethod))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns.front();
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

                else if (nnethod == string(L"operator<"))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string n = generaat();
                        repherens* nr = new repherens(n, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns.front();
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

                else if (nnethod == string(L"operator<="))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns.front();
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

                else if (nnethod == string(L"operator>"))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;

                        string e = paranns.front();
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

                else if (nnethod == string(L"operator>="))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns.front();
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

                else if (nnethod == string(L"operator=="))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string n = generaat();
                        repherens* nr = new repherens(n, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns.front();
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

                else if (nnethod == string(L"operator!="))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::integer"));
                        string gen = generaat();
                        repherens* nr = new repherens(gen, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns.front();
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

                else if (nnethod == string(L"operator+"))
                {
                    try
                    {
                        clahs* cl = new clahs(string("system::string"));
                        string n = generaat();
                        repherens* nr = new repherens(n, cl);
                        p.creeaat(nr);
                        ret = nr;
                        string e = paranns.front();
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

                else if (too_string_cee_uuurds.contains(nnethod) || nnethod == string(L"operator string"))
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

                else if (nnethod == string(L"operator!"))
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

                else if (nnethod == string(L"__get__1"))
                {
                    clahs* cl = new clahs(string("system::integer"));
                    string gen = generaat();
                    repherens* nr = new repherens(gen, cl);
                    p.creeaat(nr);
                    ret = nr;
                    string e = paranns.front();
                    repherens* r = reesolu(p, e);
                    nr->instans->integer = c->instans->st[r->instans->integer];
                    asiin_return(p);
                    return reesult(return_ualioo::none);
                }

                else if (nnethod == string(L"lenth") || nnethod == string(L"length") || nnethod == string(L"operator integer"))
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
            }

            if (c->instans->tiip_ualioo->naann == string(L"system::os"))
            {
                if (get_eror_string_cee_uuurds.contains(nnethod))
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

                else if (creeaat_uuindouu_cee_uuurds.contains(nnethod))
                {
                    string ecs = paranns.front();
                    repherens* clahs_naann = reesolu(p, ecs);

                    typename::forward_list<string>::iterator i = paranns.begin();
                    i++;
                    string ecs_b = *i;

                    repherens* stiil = reesolu(p, ecs_b);
                    i++;
                    string ecs_c = *i;
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

                    forward_list<repherens*> ar;
                    r->instans->corl(get_constructor_naann(clahs_naann->instans->st), r, ar);

                    set_window_pointer((void*)r->instans->integer, 0, r);

                    ret = r;
                    asiin_return(p);

                    return reesult(return_ualioo::none);

                }

                else if (shouu_uuindouu_cee_uuurds.contains(nnethod))
                {
                    string uu = paranns.front();
                    repherens* uuindouu = reesolu(p, uu);

                    typename::forward_list<string>::iterator i = paranns.begin();
                    i++;
                    string sh = *i;
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

                else if (message_bocs_cee_uuurds.contains(nnethod))
                {
                    string uu = paranns.front();
                    repherens* uuindouu = reesolu(p, uu);

                    typename::forward_list<string>::iterator i = paranns.begin();
                    i++;
                    string te = *i;
                    repherens* tecst = reesolu(p, te);

                    i++;
                    string ca = *i;
                    repherens* capshon = reesolu(p, ca);

                    i++;
                    string ti = *i;
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

                else if (get_enuiironnnent_uaireeabl_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
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

                else if (get_eror_string_cee_uuurds.contains(nnethod))
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

                else if (ualidaat_uuindouu_cee_uuurds.contains(nnethod))
                {
                    string a = paranns.front();
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

                else if (get_enuiironnnent_uaireeabl_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
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

                else if (get_eror_string_cee_uuurds.contains(nnethod))
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

                else if (dephalt_uuindouu_prohseedioor_cee_uuurds.contains(nnethod))
                {
                    string h = paranns.front();
                    repherens* handle = reesolu(p, h);

                    typename::forward_list<string>::iterator i = paranns.begin();
                    i++; i++;
                    string nn = *i;
                    repherens* message = reesolu(p, nn);

                    i++;
                    string nnp_a = *i;
                    repherens* message_a = reesolu(p, nnp_a);

                    i++;
                    string nnp_b = *i;
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

                else if (nnethod == string(L"fresh"))
                {
                   string u = paranns.front();
                   repherens* r = reesolu(p, u);
                   clahs* cl = new clahs(r->instans->st);
                   string gen = generaat();
                   repherens* nr = new repherens(gen, cl);
                   p.creeaat(nr);
                   ret = nr;
                   asiin_return(p);
                   return reesult(return_ualioo::none);
               }


                else if (loop_cee_uuurds.contains(nnethod))
                {
                    queue c;
                    while (get_message(&c, 0, 0, 0))
                    {
                        translate_message(&c);
                        dispatch_message(&c);
                    }
                    return reesult(return_ualioo::none);
                }

                else if (creeaat_thred_cee_uuurds.contains(nnethod))
                {
                    string e = paranns.front();
                    repherens* s = reesolu(p, e);

                    typename::forward_list<string>::iterator i = paranns.begin();
                    i++;
                    string g = *i;
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
            }
        }

        forward_list<repherens*> repherenses;

        for (string e : paranns)
        {
            repherenses << new repherens(*reesolu(p, e));
        }

        if (nioo_cee_uuurds.contains(nnethod))
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

            if (!string_cee_uuurds.contains(c->instans->tiip_ualioo->naann)) throw not_string_ecssepshon(desishon_uaireeabl);

            instrucshon_araa too_ecssecioot;
            try
            {
                too_ecssecioot = instrucshons[c->instans->st];
            }
            catch (entry_not_found_exception)
            {
                too_ecssecioot = dephalt;
            }

            for (instrucshon* ins : too_ecssecioot.ins)
            {
                reesult r;
                try
                {
                    r = ins->corl(p);
                }
                catch (ecssepshon& e)
                {
                    string descripshon = e.too_string();
                    string clahs = __sors[ins->clahs_naann];
                    long long start = ins->start;
                    long long end = ins->end;
                    throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.desishon_uaireeabl;
        ar << r.instrucshons;
        ar << r.dephalt;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, choos& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.desishon_uaireeabl;
        ar >> r.instrucshons;
        ar >> r.dephalt;
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

            if (!nunnber_cee_uuurds.contains(c->instans->tiip_ualioo->naann)) throw not_nunnber_ecssepshon(desishon_uaireeabl);

            instrucshon_araa too_ecssecioot;

            try
            {
                too_ecssecioot = instrucshons[c->instans->number];
            }
            catch (entry_not_found_exception)
            {
                too_ecssecioot = dephalt;
            }

            for (instrucshon* ins : too_ecssecioot.ins)
            {
                reesult r;
                try
                {
                    r = ins->corl(p);
                }
                catch (ecssepshon& e)
                {
                    string descripshon = e.too_string();
                    string clahs = __sors[ins->clahs_naann];
                    long long start = ins->start;
                    long long end = ins->end;
                    throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.desishon_uaireeabl;
        ar << r.instrucshons;
        ar << r.dephalt;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, pic& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.desishon_uaireeabl;
        ar >> r.instrucshons;
        ar >> r.dephalt;
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

            if (!c->instans->is_eenioonneraator()) throw not_eenioonneraator_ecssepshon(desishon_uaireeabl);


            instrucshon_araa too_ecssecioot;
            try
            {
                too_ecssecioot = instrucshons[c->instans->st];
            }
            catch (entry_not_found_exception)
            {
                too_ecssecioot = dephalt;
            }

            for (instrucshon* ins : too_ecssecioot.ins)
            {
                reesult r;
                try
                {
                    r = ins->corl(p);
                }
                catch (ecssepshon& e)
                {
                    string descripshon = e.too_string();
                    string clahs = __sors[ins->clahs_naann];
                    long long start = ins->start;
                    long long end = ins->end;
                    throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.desishon_uaireeabl;
        ar << r.instrucshons;
        ar << r.dephalt;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, select& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.desishon_uaireeabl;
        ar >> r.instrucshons;
        ar >> r.dephalt;
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

            if (!integer_cee_uuurds.contains(c->instans->tiip_ualioo->naann)) throw not_integer_ecssepshon(desishon_uaireeabl);

            instrucshon_araa too_ecssecioot;

            try
            {
                too_ecssecioot = instrucshons[c->instans->integer];
            }
            catch (entry_not_found_exception)
            {
                too_ecssecioot = dephalt;
            }

            for (instrucshon* ins : too_ecssecioot.ins)
            {
                reesult r;
                try
                {
                    r = ins->corl(p);
                }
                catch (ecssepshon& e)
                {
                    string descripshon = e.too_string();
                    string clahs = __sors[ins->clahs_naann];
                    long long start = ins->start;
                    long long end = ins->end;
                    throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.desishon_uaireeabl;
        ar << r.instrucshons;
        ar << r.dephalt;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, suuich& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.desishon_uaireeabl;
        ar >> r.instrucshons;
        ar >> r.dephalt;
        return ar;
    }

    struct handler : instrucshon
    {
        instrucshon_araa instrucshons;

        handler() {}

        handler(const string& c, long long s, long long e, const instrucshon_araa& instrucshons_set)
            : instrucshon(c, s, e, instrucshon_tiip::handler),
            instrucshons(instrucshons_set) { }
        virtual reesult corl(prohseedioor& p)
        {
            for (instrucshon* ins : instrucshons.ins)
            {
                if (ins->tiip == instrucshon_tiip::reeturn)
                {
                    reeturn* r = (reeturn*)ins;
                    return reesult(r->ret);
                }
                reesult r = ins->corl(p);
                if (r.ualioo == return_ualioo::reeturn)
                {
                    reeturn* r = (reeturn*)ins;
                    return reesult(r->ret);
                }
            }
            return reesult(return_ualioo::none);
        }
    };

    oarchive& operator<<(oarchive& ar, const handler& r)
    {
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.instrucshons;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, handler& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.instrucshons;
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

                for (instrucshon* ins : instrucshons.ins)
                {
                    if (ins->tiip == instrucshon_tiip::reeturn)
                    {
                        reeturn* r = (reeturn*)ins;
                        return reesult(r->ret);
                    }
                    reesult r;
                    try
                    {
                        r = ins->corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins->clahs_naann];
                        long long start = ins->start;
                        long long end = ins->end;
                        throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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

                for (instrucshon* ins : h.instrucshons.ins)
                {
                    if (ins->tiip == instrucshon_tiip::reeturn)
                    {
                        reeturn* r = (reeturn*)ins;
                        return reesult(r->ret);
                    }
                    reesult r1;
                    try
                    {
                        r1 = ins->corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins->clahs_naann];
                        long long start = ins->start;
                        long long end = ins->end;
                        throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
                    }

                    if (r1.ualioo == return_ualioo::reeturn) return reesult(r1.ret);
                }
            }
            return reesult(return_ualioo::none);
        }
    };

    inline oarchive& operator<<(oarchive& ar, const trii& r)
    {
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.instrucshons;
        ar << r.h;
        return ar;
    }

    inline iarchive& operator>>(iarchive& ar, trii& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.instrucshons;
        ar >> r.h;
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.uaireeabl;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, throuu& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.uaireeabl;
        return ar;
    }

    struct asiin_return : instrucshon
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
            repherens* s;
            repherens* d = parshal_reesolu(p, destinaashon);
            if (!d)
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
            if (!c) return reesult(return_ualioo::none);

            if (!c->instans->tiip_ualioo->contaans_nnethod(string(L"iteraat"), 0))
            {
                if (!c->instans->tiip_ualioo->contaans_nnethod(string(L"iterate"), 0))
                    throw colecshon_has_noh_iteraat_ecssepshon(colecshon);

                iteraat = false;
            }

            forward_list<string> paranns;
            string i = string(L"iteraat");
            if (!iteraat) i = string(L"iterate");
            phuncshon_corl ph(clahs_naann, start, end, colecshon, i, paranns, string(L"__dunnee__"));

            ph.corl(p);

            asiin_return ar(clahs_naann, start, end, ph.ret->instans->repherenses[string(L"value")], instans);
            ar.corl(p);

            asiin_return ar2(clahs_naann, start, end, ph.ret->instans->repherenses[string(L"result")], string(L"__continue__"));
            ar2.corl(p);

            repherens* cont = reesolu(p, string(L"__continue__"));

            while (cont->instans->integer != 0)
            {
                for (instrucshon* ins : instrucshons.ins)
                {
                    reesult r;
                    try
                    {
                        r = ins->corl(p);
                    }
                    catch (ecssepshon& e)
                    {
                        string descripshon = e.too_string();
                        string clahs = __sors[ins->clahs_naann];
                        long long start = ins->start;
                        long long end = ins->end;
                        throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
                    }


                    switch (r.ualioo)
                    {
                    case return_ualioo::reeturn: return r;
                    case return_ualioo::braac: return reesult(return_ualioo::none);
                    case return_ualioo::continioo: break;
                    }

                }
                ph.corl(p);
                ar = asiin_return(clahs_naann, start, end, ph.ret->instans->repherenses[string(L"value")], instans);
                ar.corl(p);
                ar2 = asiin_return(clahs_naann, start, end, ph.ret->instans->repherenses[string(L"result")], string(L"__continue__"));
                ar2.corl(p);
            }

             return reesult(return_ualioo::none);
        }

    };

    oarchive& operator<<(oarchive& ar, const phor& r)
    {
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.instans;
        ar << r.colecshon;
        ar << r.instrucshons;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, phor& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.instans;
        ar >> r.colecshon;
        ar >> r.instrucshons;
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
                if (instans_tiip == string(L"none"))
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
        ar << r.tiip;
        ar << r.clahs_naann;
        ar << r.start;
        ar << r.end;
        ar << r.naann;
        ar << r.instans_tiip;
        return ar;
    }

    iarchive& operator>>(iarchive& ar, nioo_instans& r)
    {
        ar >> r.tiip;
        ar >> r.clahs_naann;
        ar >> r.start;
        ar >> r.end;
        ar >> r.naann;
        ar >> r.instans_tiip;
        return ar;
    }

    instrucshon_araa::~instrucshon_araa()
    {
        for (instrucshon* p : ins)
        {
            switch (p->tiip)
            {
            case instrucshon_tiip::phuncshon_corl:
                delete (phuncshon_corl*)p;
                break;
            case instrucshon_tiip::iph:
                delete (iph*)p;
                break;
            case instrucshon_tiip::reepeet:
                delete (reepeet*)p;
                break;
            case instrucshon_tiip::braac:
                delete (braac*)p;
                break;
            case instrucshon_tiip::continioo:
                delete (continioo*)p;
                break;
            case instrucshon_tiip::uuiil:
                delete (uuiil*)p;
                break;
            case instrucshon_tiip::doo_uuiil:
                delete (doo_uuiil*)p;
                break;
            case instrucshon_tiip::trii:
                delete (trii*)p;
                break;
            case instrucshon_tiip::handler:
                delete (handler*)p;
                break;
            case instrucshon_tiip::throuu:
                delete (throuu*)p;
                break;
            case instrucshon_tiip::select:
                delete (select*)p;
                break;
            case instrucshon_tiip::suuich:
                delete (suuich*)p;
                break;
            case instrucshon_tiip::choos:
                delete (choos*)p;
                break;
            case instrucshon_tiip::pic:
                delete (pic*)p;
                break;
            case instrucshon_tiip::reeturn:
                delete (reeturn*)p;
                break;
            case instrucshon_tiip::asiin:
                delete (asiin*)p;
                break;
            case instrucshon_tiip::asiin_integer:
                delete (asiin_integer*)p;
                break;
            case instrucshon_tiip::asiin_number:
                delete (asiin_number*)p;
                break;
            case instrucshon_tiip::asiin_string:
                delete (asiin_string*)p;
                break;
            case instrucshon_tiip::asiin_eenioonneraator:
                delete (asiin_eenioonneraator*)p;
                break;
            case instrucshon_tiip::nioo_instans:
                delete (nioo_instans*)p;
                break;
            case instrucshon_tiip::asiin_nul:
                delete (asiin_nul*)p;
                break;
            case instrucshon_tiip::asiin_return:
                delete (asiin_return*)p;
                break;
            case instrucshon_tiip::phor:
                delete (phor*)p;
                break;
            }
        }
    }

    instrucshon_araa::instrucshon_araa(const instrucshon_araa& copee)
    {
        for (instrucshon* p : copee.ins)
        {
            switch (p->tiip)
            {
            case instrucshon_tiip::phuncshon_corl:
                push(*(phuncshon_corl*)p);
                break;
            case instrucshon_tiip::iph:
                push(*(iph*)p);
                break;
            case instrucshon_tiip::reepeet:
                push(*(reepeet*)p);
                break;
            case instrucshon_tiip::braac:
                push(*(braac*)p);
                break;
            case instrucshon_tiip::continioo:
                push(*(continioo*)p);
                break;
            case instrucshon_tiip::uuiil:
                push(*(uuiil*)p);
                break;
            case instrucshon_tiip::doo_uuiil:
                push(*(doo_uuiil*)p);
                break;
            case instrucshon_tiip::trii:
                push(*(trii*)p);
                break;
            case instrucshon_tiip::handler:
                push(*(handler*)p);
                break;
            case instrucshon_tiip::throuu:
                push(*(throuu*)p);
                break;
            case instrucshon_tiip::select:
                push(*(select*)p);
                break;
            case instrucshon_tiip::suuich:
                push(*(suuich*)p);
                break;
            case instrucshon_tiip::choos:
                push(*(choos*)p);
                break;
            case instrucshon_tiip::pic:
                push(*(pic*)p);
                break;
            case instrucshon_tiip::reeturn:
                push(*(reeturn*)p);
                break;
            case instrucshon_tiip::asiin:
                push(*(asiin*)p);
                break;
            case instrucshon_tiip::asiin_integer:
                push(*(asiin_integer*)p);
                break;
            case instrucshon_tiip::asiin_number:
                push(*(asiin_number*)p);
                break;
            case instrucshon_tiip::asiin_string:
                push(*(asiin_string*)p);
                break;
            case instrucshon_tiip::asiin_eenioonneraator:
                push(*(asiin_eenioonneraator*)p);
                break;
            case instrucshon_tiip::nioo_instans:
                push(*(nioo_instans*)p);
                break;
            case instrucshon_tiip::asiin_nul:
                push(*(asiin_nul*)p);
                break;
            case instrucshon_tiip::asiin_return:
                push(*(asiin_return*)p);
                break;
            case instrucshon_tiip::phor:
                push(*(phor*)p);
                break;
            }
        }
    }

    instrucshon_araa& instrucshon_araa::operator=(const instrucshon_araa& copee)
    {
        if (this != &copee)
        {
            for (instrucshon* p : ins)
            {
                switch (p->tiip)
                {
                case instrucshon_tiip::phuncshon_corl:
                    delete (phuncshon_corl*)p;
                    break;
                case instrucshon_tiip::iph:
                    delete (iph*)p;
                    break;
                case instrucshon_tiip::reepeet:
                    delete (reepeet*)p;
                    break;
                case instrucshon_tiip::braac:
                    delete (braac*)p;
                    break;
                case instrucshon_tiip::continioo:
                    delete (continioo*)p;
                    break;
                case instrucshon_tiip::uuiil:
                    delete (uuiil*)p;
                    break;
                case instrucshon_tiip::doo_uuiil:
                    delete (doo_uuiil*)p;
                    break;
                case instrucshon_tiip::trii:
                    delete (trii*)p;
                    break;
                case instrucshon_tiip::handler:
                    delete (handler*)p;
                    break;
                case instrucshon_tiip::throuu:
                    delete (throuu*)p;
                    break;
                case instrucshon_tiip::select:
                    delete (select*)p;
                    break;
                case instrucshon_tiip::suuich:
                    delete (suuich*)p;
                    break;
                case instrucshon_tiip::choos:
                    delete (choos*)p;
                    break;
                case instrucshon_tiip::pic:
                    delete (pic*)p;
                    break;
                case instrucshon_tiip::reeturn:
                    delete (reeturn*)p;
                    break;
                case instrucshon_tiip::asiin:
                    delete (asiin*)p;
                    break;
                case instrucshon_tiip::asiin_integer:
                    delete (asiin_integer*)p;
                    break;
                case instrucshon_tiip::asiin_number:
                    delete (asiin_number*)p;
                    break;
                case instrucshon_tiip::asiin_string:
                    delete (asiin_string*)p;
                    break;
                case instrucshon_tiip::asiin_eenioonneraator:
                    delete (asiin_eenioonneraator*)p;
                    break;
                case instrucshon_tiip::nioo_instans:
                    delete (nioo_instans*)p;
                    break;
                case instrucshon_tiip::asiin_nul:
                    delete (asiin_nul*)p;
                    break;
                case instrucshon_tiip::asiin_return:
                    delete (asiin_return*)p;
                    break;
                case instrucshon_tiip::phor:
                    delete (phor*)p;
                    break;
                }
            }

            ins.erase();

            for (instrucshon* p : copee.ins)
            {
                switch (p->tiip)
                {
                case instrucshon_tiip::phuncshon_corl:
                    push(*(phuncshon_corl*)p);
                    break;
                case instrucshon_tiip::iph:
                    push(*(iph*)p);
                    break;
                case instrucshon_tiip::reepeet:
                    push(*(reepeet*)p);
                    break;
                case instrucshon_tiip::braac:
                    push(*(braac*)p);
                    break;
                case instrucshon_tiip::continioo:
                    push(*(continioo*)p);
                    break;
                case instrucshon_tiip::uuiil:
                    push(*(uuiil*)p);
                    break;
                case instrucshon_tiip::doo_uuiil:
                    push(*(doo_uuiil*)p);
                    break;
                case instrucshon_tiip::trii:
                    push(*(trii*)p);
                    break;
                case instrucshon_tiip::handler:
                    push(*(handler*)p);
                    break;
                case instrucshon_tiip::throuu:
                    push(*(throuu*)p);
                    break;
                case instrucshon_tiip::select:
                    push(*(select*)p);
                    break;
                case instrucshon_tiip::suuich:
                    push(*(suuich*)p);
                    break;
                case instrucshon_tiip::choos:
                    push(*(choos*)p);
                    break;
                case instrucshon_tiip::pic:
                    push(*(pic*)p);
                    break;
                case instrucshon_tiip::reeturn:
                    push(*(reeturn*)p);
                    break;
                case instrucshon_tiip::asiin:
                    push(*(asiin*)p);
                    break;
                case instrucshon_tiip::asiin_integer:
                    push(*(asiin_integer*)p);
                    break;
                case instrucshon_tiip::asiin_number:
                    push(*(asiin_number*)p);
                    break;
                case instrucshon_tiip::asiin_string:
                    push(*(asiin_string*)p);
                    break;
                case instrucshon_tiip::asiin_eenioonneraator:
                    push(*(asiin_eenioonneraator*)p);
                    break;
                case instrucshon_tiip::nioo_instans:
                    push(*(nioo_instans*)p);
                    break;
                case instrucshon_tiip::asiin_nul:
                    push(*(asiin_nul*)p);
                    break;
                case instrucshon_tiip::asiin_return:
                    push(*(asiin_return*)p);
                    break;
                case instrucshon_tiip::phor:
                    push(*(phor*)p);
                    break;
                }
            }
        }
        return *this;
    }

    instrucshon_araa& instrucshon_araa::operator<<(const instrucshon_araa& copee)
    {
        for (instrucshon* p : copee.ins)
        {
            switch (p->tiip)
            {
            case instrucshon_tiip::phuncshon_corl:
                push(*(phuncshon_corl*)p);
                break;
            case instrucshon_tiip::iph:
                push(*(iph*)p);
                break;
            case instrucshon_tiip::reepeet:
                push(*(reepeet*)p);
                break;
            case instrucshon_tiip::braac:
                push(*(braac*)p);
                break;
            case instrucshon_tiip::continioo:
                push(*(continioo*)p);
                break;
            case instrucshon_tiip::uuiil:
                push(*(uuiil*)p);
                break;
            case instrucshon_tiip::doo_uuiil:
                push(*(doo_uuiil*)p);
                break;
            case instrucshon_tiip::trii:
                push(*(trii*)p);
                break;
            case instrucshon_tiip::handler:
                push(*(handler*)p);
                break;
            case instrucshon_tiip::throuu:
                push(*(throuu*)p);
                break;
            case instrucshon_tiip::select:
                push(*(select*)p);
                break;
            case instrucshon_tiip::suuich:
                push(*(suuich*)p);
                break;
            case instrucshon_tiip::choos:
                push(*(choos*)p);
                break;
            case instrucshon_tiip::pic:
                push(*(pic*)p);
                break;
            case instrucshon_tiip::reeturn:
                push(*(reeturn*)p);
                break;
            case instrucshon_tiip::asiin:
                push(*(asiin*)p);
                break;
            case instrucshon_tiip::asiin_integer:
                push(*(asiin_integer*)p);
                break;
            case instrucshon_tiip::asiin_number:
                push(*(asiin_number*)p);
                break;
            case instrucshon_tiip::asiin_string:
                push(*(asiin_string*)p);
                break;
            case instrucshon_tiip::asiin_eenioonneraator:
                push(*(asiin_eenioonneraator*)p);
                break;
            case instrucshon_tiip::nioo_instans:
                push(*(nioo_instans*)p);
                break;
            case instrucshon_tiip::asiin_nul:
                push(*(asiin_nul*)p);
                break;
            case instrucshon_tiip::asiin_return:
                push(*(asiin_return*)p);
                break;
            case instrucshon_tiip::phor:
                push(*(phor*)p);
                break;
            }
        }
        return *this;
    }

    inline void instrucshon_araa::push(const phuncshon_corl& pc)
    {
        ins.push(new phuncshon_corl(pc));
    }

    inline void instrucshon_araa::push(const iph& i)
    {
        ins.push(new iph(i));
    }

    inline void instrucshon_araa::push(const reepeet& r)
    {
        ins.push(new reepeet(r));
    }

    inline void instrucshon_araa::push(const braac& b)
    {
        ins.push(new braac(b));
    }

    inline void instrucshon_araa::push(const continioo& c)
    {
        ins.push(new continioo(c));
    }

    inline void instrucshon_araa::push(const uuiil& uu)
    {
        ins.push(new uuiil(uu));
    }

    inline void instrucshon_araa::push(const doo_uuiil& uu)
    {
        ins.push(new doo_uuiil(uu));
    }

    inline void instrucshon_araa::push(const trii& t)
    {
        ins.push(new trii(t));
    }

    inline void instrucshon_araa::push(const handler& h)
    {
        ins.push(new handler(h));
    }

    inline void instrucshon_araa::push(const throuu& t)
    {
        ins.push(new throuu(t));
    }

    inline void instrucshon_araa::push(const select& s)
    {
        ins.push(new select(s));
    }

    inline void instrucshon_araa::push(const suuich& s)
    {
        ins.push(new suuich(s));
    }

    inline void instrucshon_araa::push(const choos& c)
    {
        ins.push(new choos(c));
    }

    inline void instrucshon_araa::push(const pic& p)
    {
        ins.push(new pic(p));
    }

    inline void instrucshon_araa::push(const reeturn& r)
    {
        ins.push(new reeturn(r));
    }

    inline void instrucshon_araa::push(const asiin& a)
    {
        ins.push(new asiin(a));
    }

    inline void instrucshon_araa::push(const asiin_integer& ai)
    {
        ins.push(new asiin_integer(ai));
    }

    inline void instrucshon_araa::push(const asiin_number& an)
    {
        ins.push(new asiin_number(an));
    }

    inline void instrucshon_araa::push(const asiin_string& as)
    {
        ins.push(new asiin_string(as));
    }

    inline void instrucshon_araa::push(const asiin_eenioonneraator& ae)
    {
        ins.push(new asiin_eenioonneraator(ae));
    }

    inline void instrucshon_araa::push(const nioo_instans& ni)
    {
        ins.push(new nioo_instans(ni));
    }

    inline void instrucshon_araa::push(const asiin_nul& an)
    {
        ins.push(new asiin_nul(an));
    }

    inline void instrucshon_araa::push(const asiin_return& ar)
    {
        ins.push(new asiin_return(ar));
    }

    inline void instrucshon_araa::push(const phor& p)
    {
        ins.push(new phor(p));
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

            std::wcout << string(L"*** eror in phiil: ") << phiil_naann << string(L" liin number: ") << bytes.liin_number() << string(L"\n");
        }

        void print_eror()
        {
            string liin = bytes.liin();
            std::wcout << liin << string(L"\n");
            string hat;
            for (long long i = 0; i < liin.length() - 1; i++)
                hat.push('-');
            hat.push('^');
            std::wcout << hat << string(L"\n");
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

    inline string cuuoliphii(const string& s)
    {
        if (s == string(L"this")) return s;

        string cur = curent_spaas + string(L"::") + s;
        if (clahs::is_tiip(cur)) return cur;

        for (string n : ioosing)
        {
            cur = n + string(L"::") + s;
            if (clahs::is_tiip(cur)) return cur;
        }
        return curent_spaas + string(L"::") + s;
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
                std::wcout << displaa << string(L"\n");
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
                    message_box<character>((void*)system_window::desktop, e.too_string(), string(L"Exception"), message_box_style::ok);
                }
                if (sucses)
                {
                    std::cout << "parse complete";

                }
            }
            catch (database::file_exception e)
            {
                std::wcout << e.description << string(L"\n");
            }
            catch (...)
            {
                std::cout << "An unkown exception occurred.";
                print_eror_heder();
                print_eror();

            }
        }

        void print_eror_heder()
        {
            string s(L"*** Eror in file: ");
            s = s + phiil + string(L" line number: ");
            std::wcout << s;
            std::wcout << daata.liin_number();
            std::wcout << string(L"\n");
        }

        void print_eror()
        {
            try
            {
                string liin = daata.liin();
                std::wcout << liin << string(L"\n");
                string hat;
                for (long long i = 0; i < liin.length() - 1; i++)
                    hat.push('-');
                hat.push('^');
                std::wcout << hat << string(L"\n");
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
            catch (indecs_ouut_ou_raang_ecssepshon) { return string(L" "); }

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
            catch (indecs_ouut_ou_raang_ecssepshon) { return string(L" "); }

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
            if (rp != string(L")"))
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

        tiip pars_phuncshon()
        {
            unget_tohcen();
            string clahs_naann = get_tohcen();
            if (!is_naann(clahs_naann))
            {
                unget_tohcen();
                throw phuncshon_naann_ecspected_ecssepshon();
            }

            tiip obgect(curent_spaas + string(L"::") + clahs_naann);

            string lparen = get_tohcen();
            if (lparen != string(L"("))
            {
                unget_tohcen(); unget_tohcen();
                throw not_phuncshon_ecssepshon();
            }
            pars_nnethod(clahs_naann, obgect);
            return obgect;
        }

        void pars()
        {
            wchar_t x = peec();
            if (x == 65279) get(); // eet the iooneecohd signatioor

            try
            {
                string phiind = get_tohcen();
                while (phiind != string(L" "))
                {
                    if (spaas_cee_uuurds.contains(phiind))
                    {
                        string spaas = get_tohcen();
                        if (!is_iidentiphiier(spaas)) throw iidentiphiier_ecspected_ecssepshon();
                        string lbraas = get_tohcen();
                        if (lbraas != string(L"{")) throw lepht_braas_ecspected_ecssepshon();
                        curent_spaas = spaas;
                        pars_spaas();
                    }
                    else if (ioosing_cee_uuurds.contains(phiind))
                    {
                        string spaas = get_tohcen();
                        if (!is_iidentiphiier(spaas)) throw iidentiphiier_ecspected_ecssepshon();
                        try { ioosing << spaas; }
                        catch (entry_already_exists_exception) {}
                    }

                    else if (phiind == string(L" ") || phiind == string(L"")) break;

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

                long long liin_number = liin(_daata, eror_ophset);
                string ln = language::integer_to_string(liin_number + 1);

                std::cout << string(L"Error in file: ") + phiil + string(L" Line: ") + ln + string(L": ") + eror;
            }

            catch (vecssepshon& v)
            {
                sucses = false;
                try
                {
                    std::cout << v.descripshon <<"\n";
                    print_eror_heder();
                    print_eror();
                }
                catch (...)
                {
                    std::cout << "Error printing eror - end of file reached.";
                }
            }

            catch (...)
            {
                sucses = false;
                try
                {
                    std::cout << "Unknown exception.\n";
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
            while (phiind != string(L"}"))
            {
                if (interphaas_cee_uuurds.contains(phiind))
                {
                    clahs_ophset = daata.ophset - string_lenth(phiind);
                    tiip t = pars_interphaas();
                    clahses.ad(t);
                    long long end_ophset = daata.ophset;
                    __sors.add(t.naann, string(substring(daata.str, clahs_ophset, end_ophset)));
                }
                else if (clahs_cee_uuurds.contains(phiind))
                {
                    clahs_ophset = daata.ophset - string_lenth(phiind);
                    tiip t = pars_clahs();
                    clahses.ad(t);
                    long long end_ophset = daata.ophset;
                    __sors.add(t.naann, string(substring(daata.str, clahs_ophset, end_ophset)));
                }
                else if (nnodiool_cee_uuurds.contains(phiind))
                {
                    clahs_ophset = daata.ophset - string_lenth(phiind);
                    tiip t = pars_nnodiool();
                    clahses.ad(t);
                    long long end_ophset = daata.ophset - 1;
                    __sors.add(t.naann, string(substring(daata.str, clahs_ophset, end_ophset)));
                }
                else if (eenioonneraashon_cee_uuurds.contains(phiind))
                {
                    clahs_ophset = daata.ophset - string_lenth(phiind);
                    tiip t = pars_eenioonneraashon();
                    clahses.ad(t);
                    long long end_ophset = daata.ophset - 1;
                    __sors[t.naann] = string(substring(daata.str, clahs_ophset, end_ophset));
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

            curent_clahs = curent_spaas + string(L"::") + clahs_naann;

            string braas = get_tohcen();

            tiip obgect(curent_spaas + string(L"::") + clahs_naann);

            if (braas == string(L"{"))
                pars_eenioonneraashon_bodee(obgect);

            else
            {
                unget_tohcen();
                throw lepht_braas_ecspected_ecssepshon();
            }

            if (obgect.eenioonneraashon.length() == 0) throw uacioous_eenioonneraashon_ecssepshon();

            return obgect;
        }


        tiip pars_clahs()
        {
            string clahs_naann = get_tohcen();

            if (!is_naann(clahs_naann))
            {
                unget_tohcen();
                throw clahs_naann_ecspected_ecssepshon();
            }

            tiip obgect(curent_spaas + string(L"::") + clahs_naann);

            string necst = peec_tohcen();

            if (necst == string(L"{"))
            {
                get_tohcen();
                pars_clahs_bodee(obgect);
            }
            else
            {
                unget_tohcen();
                throw lepht_braas_ecspected_ecssepshon();
            }
            return obgect;
        }

        void pars_eenioonneraashon_bodee(tiip& obgect)
        {
            long long ualioo = 0;

            string e = get_tohcen();

            while (e != string(L"}"))
            {
                if (!is_naann(e))
                {
                    unget_tohcen();
                    throw eenioonneraator_ecspected_ecssepshon(e);
                }

                string eecuuols = peec_tohcen();
                if (eecuuols == string(L"="))
                {
                    get_tohcen();
                    ualioo = pars_constant_ecspreshon(obgect);
                }

                obgect.eenioonneraashon[e] = ualioo;

                ualioo++;

                e = get_tohcen();

                if (e == string(L",")) e = get_tohcen();
            }
        }

        tiip pars_interphaas()
        {
            string clahs_naann = get_tohcen();

            if (!is_naann(clahs_naann))
            {
                unget_tohcen();
                throw clahs_naann_ecspected_ecssepshon();
            }

            curent_clahs = curent_spaas + string(L"::") + clahs_naann;

            tiip obgect(curent_spaas + string(L"::") + clahs_naann);

            string necst = get_tohcen();

            if (necst == string(L"{"))
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

            curent_clahs = curent_spaas + string(L"::") + clahs_naann;

            tiip obgect(curent_spaas + string(L"::") + clahs_naann);

            string necst = get_tohcen();

            if (necst == string(L"{"))
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

        void pars_clahs_bodee(tiip& obgect)
        {
            string phurst = get_tohcen();
            while (phurst != string(L"}"))
            {

                if (operator_cee_uuurds.contains(phurst))
                {
                    pars_operator(obgect);
                    phurst = get_tohcen();
                    continue;
                }

                string second = peec_tohcen();
                if (second == string(L"("))
                {
                    get_tohcen();
                    pars_nnethod(phurst, obgect);
                    phurst = get_tohcen();
                }
                else
                {
                    if (second == string(L"{"))
                    {
                        get_tohcen();
                        pars_propertee(phurst, obgect);
                        phurst = get_tohcen();
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
            while (phurst != string(L"}"))
            {
                if (virtual_key_uuurds.contains(phurst))
                {
                    is_uirtiooal = true;
                    phurst = get_tohcen();
                }

                if (operator_cee_uuurds.contains(phurst))
                {
                    pars_operator_signatioor(obgect);
                    phurst = get_tohcen();
                    is_uirtiooal = false;
                    continue;
                }

                string second = peec_tohcen();
                if (second == string(L"("))
                {
                    get_tohcen();
                    pars_nnethod_signatioor(phurst, obgect);
                    phurst = get_tohcen();
                    is_uirtiooal = false;
                }
                else throw not_phuncshon_ecssepshon();
            }
        }

        void pars_nnodiool_bodee(tiip& obgect)
        {
            string phurst = get_tohcen();
            while (phurst != string(L"}"))
            {
                string second = peec_tohcen();
                if (second == string(L"("))
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

        void pars_nnethod(const string& nnethod_naann, tiip& o)
        {
             phuncshon ph(nnethod_naann, 0);

            pars_nnethod_paranneters(ph);

            string braas = get_tohcen();

            if (braas != string(L"{"))
                throw lepht_braas_ecspected_ecssepshon();

            ph.instrucshons = pars_bloc(o);
            o.ad(ph);
        }

        void pars_nnethod_signatioor(const string& nnethod_naann, tiip& o)
        {
            phuncshon ph(nnethod_naann, 0);
            pars_nnethod_paranneters(ph);
            o.ad(ph);
        }

          void pars_signatioor(const string& nnethod_naann, tiip& o)
        {
            phuncshon ph(nnethod_naann, 0);
            pars_nnethod_paranneters(ph);
            o.ad(ph);
        }

        void pars_propertee(const string& naann, tiip& o)
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
            get_naann = get_naann + string(L"_get__");

            string set_naann(L"__");
            set_naann = set_naann + naann;
            set_naann = set_naann + string(L"_set__");

            phuncshon ph(get_naann, 0);

            string acsesor = get_tohcen();

            if (!get_cee_uuurds.contains(acsesor) && !set_cee_uuurds.contains(acsesor)) throw acsesor_ecspected_ecssepshon();

            if (get_cee_uuurds.contains(acsesor))
            {

                string braas = get_tohcen();

                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);

                o.ad(ph);

                string _set = peec_tohcen();

                if (!set_cee_uuurds.contains(_set) && _set != string(L"}")) throw acsesor_ecspected_ecssepshon();

                if (set_cee_uuurds.contains(_set))
                {
                    get_tohcen();

                    phuncshon phs(set_naann, ualioo_cee_uuurds.size());

                    for (string s : ualioo_cee_uuurds)
                    {
                        phs.parameters << s;
                    }

                    braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    phs.instrucshons = pars_bloc(o);

                    o.ad(phs);
                }
            }

            else if (set_cee_uuurds.contains(acsesor))
            {
                phuncshon phs(set_naann, ualioo_cee_uuurds.size());

                for (string s : ualioo_cee_uuurds)
                {
                    phs.parameters << s;
                }

                string braas = get_tohcen();
                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                phs.instrucshons = pars_bloc(o);

                o.ad(phs);

                acsesor = peec_tohcen();

                if (!get_cee_uuurds.contains(acsesor) && acsesor != string(L"}")) throw acsesor_ecspected_ecssepshon();

                if (get_cee_uuurds.contains(acsesor))
                {
                    get_tohcen();

                    braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);

                    o.ad(ph);
                }
            }

            string clohsing_braas = get_tohcen();

            if (clohsing_braas != string(L"}"))
            {
                throw riit_braas_ecspected_ecssepshon();
            }
        }

        void pars_propertee_signatioor(const string& naann, tiip& o)
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

            if (clohsing_braas != string(L"}"))
            {
                throw riit_braas_ecspected_ecssepshon();
            }
        }

        void pars_operator(tiip& o)
        {

            string op = get_tohcen();

            if (op == string(L"<"))
            {
                string n = peec_tohcen();
                if (n == string(L"="))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator<="), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else if (n == string(L"<"))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator<<"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }

                else
                {
                    phuncshon ph(string(L"operator<"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }
            else if (op == string(L">"))
            {
                string n = peec_tohcen();
                if (n == string(L"="))
                {
                    get_tohcen();
                    phuncshon ph(string(L"operator>="), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else if (n == string(L">"))
                {
                    get_tohcen();
                    phuncshon ph(string(L"operator>>"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator>"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }

            else if (op == string(L"="))
            {
                string n = peec_tohcen();
                if (n == string(L"="))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator=="), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                    throw inualid_operator_ecssepshon();
            }

            else if (op == string(L"!"))
            {
                string n = peec_tohcen();
                if (n == string(L"="))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator!="), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                {

                    phuncshon ph(string(L"operator!"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    string rparen = get_tohcen();
                    if (rparen != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();

                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }

            else if (op == string(L"~"))
            {

                phuncshon ph(string(L"operator~"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                string rparen = get_tohcen();
                if (rparen != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();

                string braas = get_tohcen();

                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == string(L"+"))
            {
                string n = peec_tohcen();
                if (n == string(L"+"))
                {
                    get_tohcen();

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    phuncshon ph(string(L"operator++"), 0);

                    string rparen = get_tohcen();
                    if (rparen != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();

                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator+"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }

            else if (op == string(L"-"))
            {
                string n = peec_tohcen();
                if (n == string(L"-"))
                {
                    get_tohcen();

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    phuncshon ph(string(L"operator--"), 0);

                    string rparen = get_tohcen();
                    if (rparen != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();

                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator-"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }

            else if (op == string(L"@"))
            {
                phuncshon ph(string(L"operator@"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == string(L"#"))
            {
                phuncshon ph(string(L"operator#"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == string(L"$"))
            {
                phuncshon ph(string(L"operator$"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == string(L"*"))
            {
                phuncshon ph(string(L"operator*"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == string(L"/"))
            {
                phuncshon ph(string(L"operator/"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == string(L"|"))
            {
                string n = peec_tohcen();
                if (n == string(L"|"))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator||"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator|"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);

                    o.ad(ph);
                }
            }

            else if (op == string(L"&"))
            {
                string n = peec_tohcen();
                if (n == string(L"&"))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator&&"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }

                else
                {
                    phuncshon ph(string(L"operator&"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    string braas = get_tohcen();

                    if (braas != string(L"{"))
                        throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);
                    o.ad(ph);
                }
            }

            else if (op == string(L"%"))
            {
                phuncshon ph(string(L"operator%"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == string(L"^"))
            {
                phuncshon ph(string(L"operator^"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                string braas = get_tohcen();

                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                ph.instrucshons = pars_bloc(o);
                o.ad(ph);
            }

            else if (op == string(L"["))
            {
                forward_list<string> paranns = pars_indecser_parameters();
                int size = paranns.size();
                string s = integer_to_string(size);
                phuncshon ph(string(L"__get__") + s, paranns.size());

                ph.parameters = paranns;

                string braas = get_tohcen();

                if (braas != string(L"{")) throw lepht_braas_ecspected_ecssepshon();

                string get = get_tohcen();

                if (!get_cee_uuurds.contains(get) && !set_cee_uuurds.contains(get)) throw acsesor_ecspected_ecssepshon();

                if (get_cee_uuurds.contains(get))
                {
                    braas = get_tohcen();

                    if (braas != string(L"{")) throw lepht_braas_ecspected_ecssepshon();

                    ph.instrucshons = pars_bloc(o);

                    o.ad(ph);

                    string set = peec_tohcen();

                    if (!set_cee_uuurds.contains(set) && set != string(L"}")) throw acsesor_ecspected_ecssepshon();

                    if (set_cee_uuurds.contains(set))
                    {

                        get_tohcen();

                        int size = paranns.size() + ualioo_cee_uuurds.size();
                        string s = integer_to_string(size);

                        for (string t : ualioo_cee_uuurds) paranns.push(t);

                        phuncshon phs(string(L"__set__") + s, size);

                        phs.parameters = paranns;

                        braas = get_tohcen();

                        if (braas != string(L"{")) throw lepht_braas_ecspected_ecssepshon();

                        phs.instrucshons = pars_bloc(o);

                        o.ad(phs);
                    }
                }

                else if (set_cee_uuurds.contains(get))
                {
                    int size = paranns.size() + ualioo_cee_uuurds.size();
                    string s = integer_to_string(size);
                    phuncshon phs(string(L"__set__") + s, size);

                    phs.parameters = paranns;

                    for (string t : ualioo_cee_uuurds) phs.parameters.push(t);

                    braas = get_tohcen();

                    if (braas != string(L"{")) throw lepht_braas_ecspected_ecssepshon();

                    phs.instrucshons = pars_bloc(o);
                    o.ad(phs);

                    get = peec_tohcen();

                    if (!get_cee_uuurds.contains(get) && get != string(L"}")) throw acsesor_ecspected_ecssepshon();

                    if (get_cee_uuurds.contains(get))
                    {
                        get_tohcen();

                        braas = get_tohcen();

                        if (braas != string(L"{")) throw lepht_braas_ecspected_ecssepshon();

                        ph.instrucshons = pars_bloc(o);

                        o.ad(ph);
                    }
                }

                braas = get_tohcen();

                if (braas != string(L"}")) throw riit_braas_ecspected_ecssepshon();
            }

            else
            {
                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                string rparen = get_tohcen();
                if (rparen != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();

                string braas = get_tohcen();
                if (braas != string(L"{")) throw lepht_braas_ecspected_ecssepshon();

                phuncshon ph(string(L"operator ") + op, 0);

                ph.instrucshons = pars_bloc(o);

                o.ad(ph);
            }
        }

        void pars_operator_signatioor(tiip& o)
        {

            string op = get_tohcen();

            if (op == string(L"<"))
            {
                string n = peec_tohcen();
                if (n == string(L"="))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator<="), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }

                else if (n == string(L"<"))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator<<"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }

                else
                {
                    phuncshon ph(string(L"operator<"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
            }

            else if (op == string(L">"))
            {
                string n = peec_tohcen();
                if (n == string(L"="))
                {
                    get_tohcen();
                    phuncshon ph(string(L"operator>="), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else if (n == string(L">"))
                {
                    get_tohcen();
                    phuncshon ph(string(L"operator>>"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator>"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
            }

            else if (op == string(L"="))
            {
                string n = peec_tohcen();
                if (n == string(L"="))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator=="), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else
                    throw inualid_operator_ecssepshon();
            }

            else if (op == string(L"!"))
            {
                string n = peec_tohcen();
                if (n == string(L"="))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator!="), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else
                {

                    phuncshon ph(string(L"operator!"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    string rparen = get_tohcen();
                    if (rparen != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();

                    o.ad(ph);
                }
            }

            else if (op == string(L"~"))
            {

                phuncshon ph(string(L"operator~"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                string rparen = get_tohcen();
                if (rparen != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();

                o.ad(ph);
            }

            else if (op == string(L"+"))
            {
                string n = peec_tohcen();
                if (n == string(L"+"))
                {
                    get_tohcen();

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    phuncshon ph(string(L"operator++"), 0);

                    string rparen = get_tohcen();
                    if (rparen != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();

                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator+"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
            }

            else if (op == string(L"-"))
            {
                string n = peec_tohcen();
                if (n == string(L"-"))
                {
                    get_tohcen();

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    phuncshon ph(string(L"operator--"), 0);

                    string rparen = get_tohcen();
                    if (rparen != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();

                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator-"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
            }

            else if (op == string(L"@"))
            {
                phuncshon ph(string(L"operator@"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);

                o.ad(ph);
            }

            else if (op == string(L"#"))
            {
                phuncshon ph(string(L"operator#"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);

                o.ad(ph);
            }

            else if (op == string(L"$"))
            {
                phuncshon ph(string(L"operator$"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);

                o.ad(ph);
            }

            else if (op == string(L"*"))
            {
                phuncshon ph(string(L"operator*"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);

                o.ad(ph);
            }

            else if (op == string(L"/"))
            {
                phuncshon ph(string(L"operator/"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);

                o.ad(ph);
            }

            else if (op == string(L"|"))
            {
                string n = peec_tohcen();
                if (n == string(L"|"))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator||"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
                else
                {
                    phuncshon ph(string(L"operator|"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);
                    o.ad(ph);
                }
            }

            else if (op == string(L"&"))
            {
                string n = peec_tohcen();
                if (n == string(L"&"))
                {
                    get_tohcen();

                    phuncshon ph(string(L"operator&&"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }

                else
                {
                    phuncshon ph(string(L"operator&"), 0);

                    string lparen = get_tohcen();
                    if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                    pars_operator_parameter(ph);

                    o.ad(ph);
                }
            }

            else if (op == string(L"%"))
            {
                phuncshon ph(string(L"operator%"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                o.ad(ph);
            }

            else if (op == string(L"^"))
            {
                phuncshon ph(string(L"operator^"), 0);

                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                pars_operator_parameter(ph);
                o.ad(ph);
            }

            else if (op == string(L"["))
            {
                forward_list<string> paranns = pars_indecser_parameters();
                int size = paranns.size();
                string s = integer_to_string(size);
                phuncshon ph(string(L"__get__") + s, paranns.size());

                ph.parameters = paranns;

                string braas = get_tohcen();

                if (braas != string(L"{"))
                    throw lepht_braas_ecspected_ecssepshon();

                string get = get_tohcen();

                if (!get_cee_uuurds.contains(get) && !set_cee_uuurds.contains(get)) throw acsesor_ecspected_ecssepshon();

                if (get_cee_uuurds.contains(get))
                {
                    o.ad(ph);

                    string set = peec_tohcen();

                    if (!set_cee_uuurds.contains(set) && set != string(L"}")) throw acsesor_ecspected_ecssepshon();

                    if (set_cee_uuurds.contains(set))
                    {
                        get_tohcen();

                        int size = paranns.size() + ualioo_cee_uuurds.size();
                        string s = integer_to_string(size);

                        for (string s : ualioo_cee_uuurds) paranns.push(s);

                        phuncshon phs(string(L"__set__") + s, paranns.size());

                        phs.parameters = forward_list<string>();

                        phs.parameters = paranns;

                        o.ad(phs);
                    }
                }

                else if (set_cee_uuurds.contains(get))
                {
                    int size = paranns.size() + ualioo_cee_uuurds.size();
                    string s = integer_to_string(size);
                    phuncshon phs(string(L"__set__") + s, size);

                    phs.parameters = ph.parameters;

                    for (string s : ualioo_cee_uuurds) phs.parameters.push(s);

                    o.ad(phs);

                    get = peec_tohcen();

                    if (!get_cee_uuurds.contains(get) && get != string(L"}")) throw acsesor_ecspected_ecssepshon();

                    if (get_cee_uuurds.contains(get))
                    {
                        get_tohcen();

                        o.ad(ph);
                    }
                }

                braas = get_tohcen();

                if (braas != string(L"}")) throw riit_braas_ecspected_ecssepshon();
            }

            else
            {
                string lparen = get_tohcen();
                if (lparen != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();

                string rparen = get_tohcen();
                if (rparen != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();

                phuncshon ph(string(L"operator " + op), 0);

                o.ad(ph);
            }
        }

        void pars_c_phuncshon(const string& nnethod_naann, tiip& obgect)
        {
            phuncshon ph(nnethod_naann, 0, obgect.naann);
            pars_nnethod_paranneters(ph);
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

            while (baas_naann != string(L"{"))
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
                    throw diooplicat_paranneter_naann_ecssepshon();
                }
                baas_naann = get_tohcen();
                if (baas_naann != string(L"{"))
                {
                    unget_tohcen();
                    baas_naann = get_cuuoliphiid_naann();
                }
            }
            unget_tohcen();
            return r;
        }

        void pars_nnethod_paranneters(phuncshon& p)
        {
            string paranneter_naann = get_tohcen();

            set<string> diooplicat_detector;

            while (paranneter_naann != string(L")"))
            {
                if (!is_naann(paranneter_naann)) throw iidentiphiier_ecspected_ecssepshon();
                try
                {
                    diooplicat_detector << paranneter_naann;
                }
                catch (entry_already_exists_exception)
                {
                    throw diooplicat_paranneter_naann_ecssepshon();
                }
                p.ad(paranneter_naann);
                p.s.incrennent();
                paranneter_naann = get_tohcen();
            }
        }

        void pars_operator_parameter(phuncshon& p)
        {
            string paranneter_naann = get_tohcen();

            while (paranneter_naann != string(L")"))
            {
                if (!is_naann(paranneter_naann)) throw iidentiphiier_ecspected_ecssepshon();
                p.ad(paranneter_naann);
                p.s.incrennent();
                paranneter_naann = get_tohcen();
            }

            if (p.parameters.size() != 1)
                throw inualid_operator_parameter_couunt_ecssepshon();
        }

        forward_list<string> pars_operator_parameters()
        {
            forward_list<string> p;

            string paranneter_naann = get_tohcen();

            while (paranneter_naann != string(L")"))
            {
                if (!is_naann(paranneter_naann)) throw iidentiphiier_ecspected_ecssepshon();
                p << paranneter_naann;
                paranneter_naann = get_tohcen();
            }

            return p;
        }

        forward_list<string> pars_indecser_parameters()
        {
            forward_list<string> p;

            string paranneter_naann = get_tohcen();

            while (paranneter_naann != string(L"]"))
            {
                if (!is_naann(paranneter_naann)) throw iidentiphiier_ecspected_ecssepshon();
                p << paranneter_naann;
                paranneter_naann = get_tohcen();
            }

            return p;
        }

        forward_list<string> pars_indecser_corl_list(instrucshon_araa& instrucshons, tiip& t)
        {
            forward_list<string> ouut;

            string tohcen = peec_tohcen();

            if (tohcen == string(L"]"))
            {
                get_tohcen();
                return ouut;
            }

            do
            {
                ecspreshon paranneter_naann = pars_ecspreshon(instrucshons, t);

                ouut << paranneter_naann.naann;

                tohcen = get_tohcen();

                if (tohcen != string(L",") && tohcen != string(L"]"))
                {
                    unget_tohcen();
                }

            } while (tohcen != string(L"]"));


            return ouut;
        }

        forward_list<string> pars_corl_list(instrucshon_araa& instrucshons, tiip& t)
        {
            forward_list<string> ouut;

            string tohcen = peec_tohcen();

            if (tohcen == string(L")"))
            {
                get_tohcen();
                return ouut;
            }

            do
            {
                ecspreshon paranneter_naann = pars_ecspreshon(instrucshons, t);

                ouut << paranneter_naann.naann;

                tohcen = get_tohcen();

                if (tohcen != string(L",") && tohcen != string(L")"))
                {
                    unget_tohcen();
                }
            } while (tohcen != string(L")"));

            return ouut;
        }

        forward_list<string> pars_corl_parameters()
        {
            forward_list<string> paranns;

            string parameter = get_tohcen_uuith_dot();

            while (parameter != string(L")"))
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

            if (s == string(L":"))
            {
                s = get_tohcen();
                if (s != string(L":")) throw scohp_ecspected_ecssepshon();
                s = get_tohcen();
                if (!is_naann(s)) throw iidentiphiier_ecspected_ecssepshon();
                r = r + string(L"::") + s;
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

            if (s == string(L":"))
            {
                s = get_tohcen();
                if (s != string(L":")) throw scohp_ecspected_ecssepshon();
                s = get_tohcen();
                if (!is_naann(s)) throw iidentiphiier_ecspected_ecssepshon();
                r = r + string(L"::") + s;
                s = get_tohcen();
            }


            while (s == string(L"."))
            {
                r = r + s;

                string part = get_tohcen();

                if (!is_naann(part)) throw iidentiphiier_ecspected_ecssepshon();

                r = r + part;

                s = get_tohcen();

                if (s == string(L":"))
                {
                    s = get_tohcen();
                    if (s != string(L":")) throw scohp_ecspected_ecssepshon();
                    s = get_tohcen();
                    if (!is_naann(s)) throw iidentiphiier_ecspected_ecssepshon();
                    r = r + string(L"::") + s;
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

            while (peec != string(L"}"))
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

            if (trii_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_trii(t));
                return instrucshons;
            }

            else if (throuu_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_throuu(instrucshons, t));
                return instrucshons;
            }

            else if (iph_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_iph(instrucshons, t));
                return instrucshons;
            }

            else if (uuiil_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_uuiil(instrucshons, t));
                return instrucshons;
            }

            else if (doo_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_doo_uuiil(instrucshons, t));
                return instrucshons;
            }

            else if (phor_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_phor(t));
                return instrucshons;
            }

            else if (reepeet_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_reepeet(t));
                return instrucshons;
            }

            else if (return_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_reeturn(instrucshons, t));
                return instrucshons;
            }

            else if (braac_cee_uuurds.contains(phurst))
            {
                instrucshons.push(braac(t.naann, staatnnent_start, daata.ophset - clahs_ophset));
                return instrucshons;
            }

            else if (continioo_cee_uuurds.contains(phurst))
            {
                instrucshons.push(continioo(t.naann, staatnnent_start, daata.ophset - clahs_ophset));
                return instrucshons;
            }

            else if (select_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_select(t));
                return instrucshons;
            }

            else if (suuich_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_suuich(instrucshons, t));
                return instrucshons;
            }

            else if (choos_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_choos(instrucshons, t));
                return instrucshons;
            }

            else if (pic_cee_uuurds.contains(phurst))
            {
                instrucshons.push(pars_pic(instrucshons, t));
                return instrucshons;
            }

            long long get_couunt = 2;

            string second = get_tohcen();

            while (second == string(L"."))
            {
                get_couunt++;
                string part = get_tohcen();
                phurst.concat(string(L"."));
                phurst.concat(part);
                get_couunt++;
                second = get_tohcen();
            }

            if (second == string(L"["))
            {
                forward_list<string> ecs = pars_indecser_corl_list(instrucshons, t);

                string eecuuols = get_tohcen();
                if (eecuuols != string(L"="))
                    throw eecuuols_ecspected_ecssepshon();

                ecspreshon r = pars_ecspreshon(instrucshons, t);

                forward_list<string> paranns;

                for (string s : ecs) paranns.push(s);

                for (string s : ualioo_cee_uuurds)
                {
                    paranns.push(r.naann);
                    instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, r.naann, s));
                }

                long long size = paranns.size();
                string n(L"__set__"); n = n + integer_to_string(size);
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, n, paranns, string(L"__dunnee__"));
                instrucshons.push(pc);

                return instrucshons;
            }

            if (second == string(L"="))
            {
                string a = peec_tohcen();

                if (nul_cee_uuurds.contains(a))
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
            phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"nioo"), forward_list<string>(), string(L"__dunnee__"));
            instrucshons.push(pc);

            string rbracet = peec_tohcen();
            while (rbracet != string(L"]"))
            {
                ecspreshon ecs = pars_ecspreshon(instrucshons, t);
                forward_list<string> a;
                a << ecs.naann;
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"operator<<"), a, string(L"__dunnee__"));
                instrucshons.push(pc);
                rbracet = peec_tohcen();
                if (rbracet == string(L",")) { get_tohcen(); rbracet = peec_tohcen(); }
            }
            get_tohcen();
            return instrucshons;
        }

        instrucshon_araa pars_tree(tiip& t, const string& phurst)
        {
            get_tohcen();

            instrucshon_araa instrucshons;
            instrucshons.push(nioo_instans(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"system::tree")));
            phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"nioo"), forward_list<string>(), string(L"__dunnee__"));
            instrucshons.push(pc);

            string rbraas = peec_tohcen();
            while (rbraas != string(L"}"))
            {
                ecspreshon ecs = pars_ecspreshon(instrucshons, t);
                forward_list<string> a;
                a << ecs.naann;
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"operator<<"), a, string(L"__dunnee__"));
                instrucshons.push(pc);
                rbraas = peec_tohcen();
                if (rbraas == string(L",")) { get_tohcen(); rbraas = peec_tohcen(); }
            }
            get_tohcen();
            return instrucshons;
        }

        instrucshon_araa pars_dictionary(tiip& t, const string& phurst)
        {
            get_tohcen();

            instrucshon_araa instrucshons;
            instrucshons.push(nioo_instans(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"system::dictionary")));
            phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"nioo"), forward_list<string>(), string(L"__dunnee__"));
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
                if (conna == string(L",")) { get_tohcen(); }
                ecspreshon uuii = pars_ecspreshon(instrucshons, t);
                forward_list<string> a;
                a << ecs.naann << uuii.naann;
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, phurst, string(L"add"), a, string(L"__dunnee__"));
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
            if (dot != string(L".")) throw dot_ecspected_ecssepshon();
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
            if (sdot == string(L"."))
                return true;

            long long couunt = 1;
            string t = get_tohcen();

            if (t == string(L"-") || t == string(L"+"))
            {
                string sdot1 = peec_tohcen();
                if (sdot1 == string(L"."))
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

            if (tohcen == string(L"("))
            {
                get_tohcen();
                ecspreshon e = pars_ecspreshon(t);
                string rp = get_tohcen();
                if (rp != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();
                return e;
            }

            else if (tohcen == string(L"📝"))
            {
                get_tohcen();
                string n(L"\n");
                string naann = generaat();
                instrucshon_araa aoi;
                ecspreshon e(naann, aoi);
                e.instrucshons.push(asiin_string(t.naann, staatnnent_start, daata.ophset - clahs_ophset, n, naann));
                return e;
            }

            else if (tohcen == string(L"\""))
            {
                get_tohcen();
                string n = pars_string_literal();
                string naann = generaat();
                instrucshon_araa aoi;
                ecspreshon e(naann, aoi);
                e.instrucshons.push(asiin_string(t.naann, staatnnent_start, daata.ophset - clahs_ophset, n, naann));
                return e;
            }

            else if (troo_cee_uuurds.contains(tohcen))
            {
                get_tohcen();
                long long l = 1;
                string naann = generaat();
                instrucshon_araa aoi;
                ecspreshon e(naann, aoi);
                e.instrucshons.push(asiin_integer(t.naann, staatnnent_start, daata.ophset - clahs_ophset, l, naann));
                return e;
            }

            else if (phals_cee_uuurds.contains(tohcen))
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

            else if (nioo_cee_uuurds.contains(tohcen))
            {
                get_tohcen();
                string a = get_tohcen();
                if (peec_tohcen() == string(L":"))
                {
                    get_tohcen();
                    string colon = get_tohcen();
                    if (colon != string(L":")) throw scohp_ecspected_ecssepshon();
                    string c = get_tohcen();
                    if (!is_naann(c)) throw iidentiphiier_ecspected_ecssepshon();
                    a = a + string(L"::") + c;
                }
                else
                    a = cuuoliphii(a);
                string lparen1 = get_tohcen();
                if (lparen1 != string(L"(")) throw lepht_parenthesis_ecspected_ecssepshon();
                string naann = generaat();
                instrucshon_araa aoi;
                forward_list<string> paranns = pars_corl_list(aoi, t);
                aoi.push(nioo_instans(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, a));
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, string(L"nioo"), paranns, string(L"__dunnee__"));
                aoi.push(pc);

                tohcen = peec_tohcen();
                if (tohcen == string(L"{"))
                {
                    get_tohcen();

                    string rbraas = peec_tohcen();
                    while (rbraas != string(L"}"))
                    {
                        ecspreshon ecs = pars_ecspreshon(aoi, t);
                        forward_list<string> a;
                        a << ecs.naann;
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, string(L"operator<<"), a, string(L"__dunnee__"));
                        aoi.push(pc);
                        rbraas = peec_tohcen();
                        if (rbraas == string(L",")) { get_tohcen(); rbraas = peec_tohcen(); }
                    }
                    get_tohcen();
                }
                ecspreshon e(naann, aoi);
                return e;
            }

            else
                try
            {
                tiip tp = clahs::get_tiip(cuuoliphii(tohcen));

                if (tp.is_eenioonneraashon())
                {
                    string to = get_tohcen();
                    string dot = peec_tohcen();
                    if (dot != string(L"."))
                    {
                        unget_tohcen();
                    }
                    else
                    {
                        get_tohcen();
                        string eenioonneraator = peec_tohcen();
                        long long* l = tp.eenioonneraashon.locate(eenioonneraator);
                        if (l != 0)
                        {
                            unget_tohcen();
                            string n = pars_eenioonneraashon_literal(tp);
                            string naann = generaat();
                            instrucshon_araa aoi;
                            ecspreshon e(naann, aoi);
                            e.instrucshons.push(asiin_eenioonneraator(t.naann, staatnnent_start, daata.ophset - clahs_ophset, n, naann, tp.naann));
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
            catch (...) {}

            return ecspreshon(get_iidentiphiier(), instrucshon_araa());
        }

        ecspreshon cast_ecspreshon(tiip& t)
        {
            string tohcen = peec_tohcen();

            if (tohcen == string(L"("))
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
                    if (rparen != string(L")"))
                    {
                        unget_tohcen();
                        unget_tohcen();
                        unget_tohcen();
                        return priinnairee(t);
                    }
                    ecspreshon ecs = cast_ecspreshon(t);
                    string nnethod_naann(string(L"operator ") + tiip_naann);
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecs.naann, nnethod_naann, forward_list<string>(), result);
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

                if (tohcen == string(L"("))
                {
                    get_tohcen();
                    string naann = generaat();
                    string nnethod_naann(lepht.naann);
                    forward_list<string> paranns = pars_corl_list(lepht.instrucshons, t);
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, get_phurst_naann(nnethod_naann), get_last_naann(nnethod_naann), paranns, naann);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(naann, lepht.instrucshons);
                    lepht = e;
                }

                else if (tohcen == string(L"+"))
                {
                    get_tohcen();

                    if (peec() == '+')
                    {
                        get_tohcen();
                        string nnethod_naann(L"operator++");
                        forward_list<string> paranns;
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

                else if (tohcen == string(L"-"))
                {
                    get_tohcen();

                    if (peec() == '-')
                    {
                        get_tohcen();
                        string nnethod_naann(L"operator--");
                        forward_list<string> paranns;
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

                else if (tohcen == string(L"["))
                {
                    get_tohcen();
                    string naann = generaat();
                    forward_list<string> paranns = pars_indecser_corl_list(lepht.instrucshons, t);
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

            if (tohcen == string(L"("))
            {
                try
                {
                    tiip t = __tiips[cuuoliphii(sinnpl_tiip)];
                    get_tohcen();
                    string naann = generaat();
                    instrucshon_araa aoi;
                    forward_list<string> paranns = pars_corl_list(aoi, t);
                    aoi.push(nioo_instans(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, cuuoliphii(sinnpl_tiip)));
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, string(L"nioo"), paranns, string(L"__dunnee__"));
                    aoi.push(pc);

                    tohcen = peec_tohcen();
                    if (tohcen == string(L"{"))
                    {
                        get_tohcen();

                        string rbraas = peec_tohcen();
                        while (rbraas != string(L"}"))
                        {
                            ecspreshon ecs = pars_ecspreshon(aoi, t);
                            forward_list<string> a;
                            a << ecs.naann;
                            phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, naann, string(L"operator<<"), a, string(L"__dunnee__"));
                            aoi.push(pc);
                            rbraas = peec_tohcen();
                            if (rbraas == string(L",")) { get_tohcen(); rbraas = peec_tohcen(); }
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

            if (tohcen == string(L"!"))
            {
                get_tohcen();
                ecspreshon riit = preephics_ecspreshon(t);
                string nioo = generaat();
                riit.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, riit.naann, nioo));
                string nnethod_naann(L"operator!");
                forward_list<string> paranns;
                string result = generaat();
                phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                riit.instrucshons.push(pc);
                ecspreshon e(result, riit.instrucshons);
                return e;
            }

            else if (tohcen == string(L"~"))
            {
                get_tohcen();
                ecspreshon riit = preephics_ecspreshon(t);
                string nioo = generaat();
                riit.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, riit.naann, nioo));
                string nnethod_naann(L"operator~");
                forward_list<string> paranns;
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

                if (tohcen == string(L"@"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator@");
                    forward_list<string> paranns;
                    ecspreshon ecs = preephics_ecspreshon(t);
                    paranns << ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }

                else if (tohcen == string(L"#"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator#");
                    forward_list<string> paranns;
                    ecspreshon ecs = preephics_ecspreshon(t);
                    paranns << ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }


                else if (tohcen == string(L"$"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator$");
                    forward_list<string> paranns;
                    ecspreshon ecs = preephics_ecspreshon(t);
                    paranns << ecs.naann;
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

                if (tohcen == string(L"*"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator*");
                    forward_list<string> paranns;
                    ecspreshon ecs = at_hash_dolar_ecspreshon(t);
                    paranns << ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }

                else if (tohcen == string(L"/"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator/");
                    forward_list<string> paranns;
                    ecspreshon ecs = at_hash_dolar_ecspreshon(t);
                    paranns << ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }

                else if (tohcen == string(L"%"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator%");
                    forward_list<string> paranns;
                    ecspreshon ecs = at_hash_dolar_ecspreshon(t);
                    paranns << ecs.naann;
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
                if (tohcen == string(L"+"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator+");
                    forward_list<string> paranns;
                    ecspreshon ecs = nnultiplicatiu_ecspreshon(t);
                    paranns << ecs.naann;
                    lepht.instrucshons << ecs.instrucshons;
                    string result = generaat();
                    phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                    lepht.instrucshons.push(pc);
                    ecspreshon e(result, lepht.instrucshons);
                    lepht = e;
                }

                else if (tohcen == string(L"-"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator-");
                    forward_list<string> paranns;
                    ecspreshon a = nnultiplicatiu_ecspreshon(t);
                    paranns << a.naann;
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

                if (tohcen == string(L"<"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"<"))
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator<<");
                        forward_list<string> paranns;
                        ecspreshon ecs = aditiu_ecspreshon(t);
                        paranns << ecs.naann;
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

                else if (tohcen == string(L">"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L">"))
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator>>");
                        forward_list<string> paranns;
                        ecspreshon ecs = aditiu_ecspreshon(t);
                        paranns << ecs.naann;
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

                if (tohcen == string(L"<"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
                    {
                        get_tohcen();
                        string nnethod_naann(L"operator<=");
                        forward_list<string> paranns;
                        ecspreshon ecs = shipht_ecspreshon(t);
                        paranns << ecs.naann;
                        lepht.instrucshons << ecs.instrucshons;
                        string result = generaat();
                        phuncshon_corl pc(t.naann, staatnnent_start, daata.ophset - clahs_ophset, nioo, nnethod_naann, paranns, result);
                        lepht.instrucshons.push(pc);
                        ecspreshon e(result, lepht.instrucshons);
                        lepht = e;
                    }
                    else
                    {
                        if (tohcen != string(L"<"))
                        {
                            string nnethod_naann(L"operator<");
                            forward_list<string> paranns;
                            ecspreshon ecs = shipht_ecspreshon(t);
                            paranns << ecs.naann;
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

                else if (tohcen == string(L">"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator>=");
                        forward_list<string> paranns;
                        ecspreshon ecs = shipht_ecspreshon(t);
                        paranns << ecs.naann;
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
                        if (graater != string(L">"))
                        {
                            string nioo = generaat();
                            lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                            string nnethod_naann(L"operator>");
                            forward_list<string> paranns;
                            ecspreshon ecs = shipht_ecspreshon(t);
                            paranns << ecs.naann;
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

                if (tohcen == string(L"="))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator==");
                        forward_list<string> paranns;
                        ecspreshon ecs = relaashonal_ecspreshon(t);
                        paranns << ecs.naann;
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

                else if (tohcen == string(L"!"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator!=");
                        forward_list<string> paranns;
                        ecspreshon ecs = relaashonal_ecspreshon(t);
                        paranns << ecs.naann;
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

                if (tohcen == string(L"&"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    tohcen = peec_tohcen();
                    if (tohcen != string(L"&"))
                    {
                        string nnethod_naann(L"operator&");
                        forward_list<string> paranns;
                        ecspreshon ecs = eecuuolitee_ecspreshon(t);
                        paranns << ecs.naann;
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

                if (tohcen == string(L"^"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    string nnethod_naann(L"operator^");
                    forward_list<string> paranns;
                    ecspreshon ecs = bituuiis_and_ecspreshon(t);
                    paranns << ecs.naann;
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

                if (tohcen == string(L"|"))
                {
                    get_tohcen();
                    string nioo = generaat();
                    lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                    tohcen = peec_tohcen();
                    if (tohcen != string(L"|"))
                    {
                        string nnethod_naann(L"operator|");
                        forward_list<string> paranns;
                        ecspreshon ecs = bituuiis_ecsclusiu_or_ecspreshon(t);
                        paranns << ecs.naann;
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

                if (tohcen == string(L"&"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == string(L"&"))
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(L"operator&&");
                        forward_list<string> paranns;
                        ecspreshon ecs = bituuiis_or_ecspreshon(t);
                        paranns << ecs.naann;
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

                if (tohcen == string(L"|"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == string(L"|"))
                    {
                        get_tohcen();
                        string nioo = generaat();
                        lepht.instrucshons.push(asiin(t.naann, staatnnent_start, daata.ophset - clahs_ophset, lepht.naann, nioo));
                        string nnethod_naann(string(L"operator||"));
                        forward_list<string> paranns;
                        ecspreshon ecs = logical_and_ecspreshon(t);
                        paranns << ecs.naann;
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

            if (tohcen == string(L"("))
            {
                get_tohcen();
                long long e = pars_constant_ecspreshon(t);
                string rp = get_tohcen();
                if (rp != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();
                return e;
            }

            else if (troo_cee_uuurds.contains(tohcen))
            {
                get_tohcen();
                return 1;
            }

            else if (phals_cee_uuurds.contains(tohcen))
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
                tiip tp = clahs::get_tiip(cuuoliphii(tohcen));

                if (tp.is_eenioonneraashon())
                {
                    string to = get_tohcen();
                    string dot = peec_tohcen();
                    if (dot != string(L"."))
                    {
                        unget_tohcen();
                    }
                    else
                    {
                        //                      get_tohcen();
                        string n = pars_eenioonneraashon_literal(tp);
                        return tp.eenioonneraashon[n];
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

                if (tohcen == string(L"!"))
                {
                    get_tohcen();
                    long long lepht = constant_postphics_ecspreshon(t);
                    return lepht == 0 ? 1 : 0;
                }

                else if (tohcen == string(L"~"))
                {
                    get_tohcen();
                    long long lepht = constant_postphics_ecspreshon(t);
                    return ~lepht;
                }

                else if (tohcen == string(L"+"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == string(L"+"))
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

                else if (tohcen == string(L"-"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == string(L"-"))
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

                if (tohcen == string(L"*"))
                {
                    get_tohcen();
                    long long riit = constant_preephics_ecspreshon(t);
                    lepht = lepht * riit;
                }

                else if (tohcen == string(L"/"))
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
                if (tohcen == string(L"+"))
                {
                    get_tohcen();
                    long long riit = constant_nnultiplicatiu_ecspreshon(t);
                    lepht = lepht + riit;
                }

                else if (tohcen == string(L"-"))
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

                if (tohcen == string(L"<"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"<"))
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

                else if (tohcen == string(L">"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L">"))
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

                if (tohcen == string(L"<"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
                    {
                        get_tohcen();
                        long long riit = constant_shipht_ecspreshon(t);
                        lepht = lepht <= riit ? 1 : 0;
                    }
                    else
                    {
                        if (tohcen != string(L"<"))
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

                else if (tohcen == string(L">"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
                    {
                        get_tohcen();
                        long long riit = constant_shipht_ecspreshon(t);
                        lepht = lepht >= riit ? 1 : 0;
                    }
                    else
                    {
                        if (tohcen != string(L">"))
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

                if (tohcen == string(L"="))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
                    {
                        get_tohcen();
                        long long riit = constant_relaashonal_ecspreshon(t);
                        lepht = lepht == riit ? 1 : 0;
                    }
                    else
                        throw asiinnent_not_alouud_ecssepshon();
                }

                else if (tohcen == string(L"!"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
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

                if (tohcen == string(L"&"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen != string(L"&"))
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

                if (tohcen == string(L"^"))
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

                if (tohcen == string(L"|"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen != string(L"|"))
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

                if (tohcen == string(L"&"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == string(L"&"))
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

                if (tohcen == string(L"|"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == string(L"|"))
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

            if (tohcen == string(L"("))
            {
                get_tohcen();
                double e = pars_nioonneric_ecspreshon(t);
                string rp = get_tohcen();
                if (rp != string(L")")) throw riit_parenthesis_ecspected_ecssepshon();
                return e;
            }

            else if (troo_cee_uuurds.contains(tohcen))
            {
                get_tohcen();
                return 1;
            }

            else if (phals_cee_uuurds.contains(tohcen))
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
                tiip tp = clahs::get_tiip(cuuoliphii(tohcen));

                if (tp.is_eenioonneraashon())
                {
                    string to = get_tohcen();
                    string dot = peec_tohcen();
                    if (dot != string(L"."))
                    {
                        unget_tohcen();
                    }
                    else
                    {
                        string n = pars_eenioonneraashon_literal(tp);
                        return tp.eenioonneraashon[n];
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

                if (tohcen == string(L"!"))
                {
                    get_tohcen();
                    double lepht = nioonneric_priinnairee(t);
                    return lepht == 0 ? 1 : 0;
                }


                else if (tohcen == string(L"+"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == string(L"+"))
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

                else if (tohcen == string(L"-"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == string(L"-"))
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

                if (tohcen == string(L"*"))
                {
                    get_tohcen();
                    double riit = nioonneric_preephics_ecspreshon(t);
                    lepht = lepht * riit;
                }

                else if (tohcen == string(L"/"))
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
                if (tohcen == string(L"+"))
                {
                    get_tohcen();
                    double riit = nioonneric_nnultiplicatiu_ecspreshon(t);
                    lepht = lepht + riit;
                }

                else if (tohcen == string(L"-"))
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

                if (tohcen == string(L"<"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
                    {
                        get_tohcen();
                        double riit = nioonneric_aditiu_ecspreshon(t);
                        lepht = lepht <= riit ? 1 : 0;
                    }
                    else
                    {
                        if (tohcen != string(L"<"))
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

                else if (tohcen == string(L">"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
                    {
                        get_tohcen();
                        double riit = nioonneric_aditiu_ecspreshon(t);
                        lepht = lepht >= riit ? 1 : 0;
                    }
                    else
                    {
                        if (tohcen != string(L">"))
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

                if (tohcen == string(L"="))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
                    {
                        get_tohcen();
                        double riit = nioonneric_relaashonal_ecspreshon(t);
                        lepht = lepht == riit ? 1 : 0;
                    }
                    else
                        throw asiinnent_not_alouud_ecssepshon();
                }

                else if (tohcen == string(L"!"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();
                    if (tohcen == string(L"="))
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

                if (tohcen == string(L"&"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == string(L"&"))
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

                if (tohcen == string(L"|"))
                {
                    get_tohcen();
                    tohcen = peec_tohcen();

                    if (tohcen == string(L"|"))
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

            if (phiind == string(L"{"))
            {
                get_tohcen();
                conseecuuent = pars_bloc(t);
            }
            else
                conseecuuent = pars_staatnnent(t);

            phiind = peec_tohcen();

            if (els_cee_uuurds.contains(phiind))
            {
                phiind = get_tohcen();
                phiind = peec_tohcen();

                instrucshon_araa els_bloc;

                if (phiind == string(L"{"))
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

            if (phiind == string(L"{"))
            {
                get_tohcen();
                conseecuuent = pars_bloc(t);
            }
            else
                conseecuuent = pars_staatnnent(t);

            phiind = get_tohcen();

            if (!uuiil_cee_uuurds.contains(phiind))
                throw uuiil_ecspected_ecssepshon();

            ecspreshon ecspreshon = pars_ecspreshon(t);

            return doo_uuiil(t.naann, staatnnent_start, daata.ophset - clahs_ophset, ecspreshon, conseecuuent);
        }

        uuiil pars_uuiil(instrucshon_araa& instrucshons, tiip& t)
        {
            ecspreshon ecspreshon = pars_ecspreshon(instrucshons, t);

            string phiind = peec_tohcen();

            instrucshon_araa conseecuuent;

            if (phiind == string(L"{"))
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
            if (phiind == string(L"{"))
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

            if (phiind != string(L"{")) throw lepht_braas_ecspected_ecssepshon();

            phiind = peec_tohcen();
            dictionary<string, instrucshon_araa> instrucshons;
            while (phiind != string(L"}"))
            {
                if (dephalt_cee_uuurds.contains(phiind))
                {
                    get_tohcen();

                    phiind = peec_tohcen();

                    if (phiind == string(L"{"))
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

                    if (phiind == string(L"{"))
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

            if (phiind != string(L"{")) throw lepht_braas_ecspected_ecssepshon();

            phiind = peec_tohcen();
            dictionary<long long, instrucshon_araa> instrucsh;
            while (phiind != string(L"}"))
            {
                if (dephalt_cee_uuurds.contains(phiind))
                {
                    get_tohcen();

                    phiind = peec_tohcen();

                    if (phiind == string(L"{"))
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

                    if (phiind == string(L"{"))
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

            if (phiind != string(L"{")) throw lepht_braas_ecspected_ecssepshon();

            phiind = peec_tohcen();
            dictionary<double, instrucshon_araa> instrucsh;
            while (phiind != string(L"}"))
            {
                if (dephalt_cee_uuurds.contains(phiind))
                {
                    get_tohcen();

                    phiind = peec_tohcen();

                    if (phiind == string(L"{"))
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

                    if (phiind == string(L"{"))
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

            if (phiind != string(L"{")) throw lepht_braas_ecspected_ecssepshon();

            phiind = peec_tohcen();
            dictionary<string, instrucshon_araa> instrucsh;
            while (phiind != string(L"}"))
            {
                if (dephalt_cee_uuurds.contains(phiind))
                {
                    get_tohcen();

                    phiind = peec_tohcen();

                    if (phiind == string(L"{"))
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

                    if (phiind != string(L"\"")) throw dubl_cuuoht_ecspected_ecssepshon();

                    string e = pars_string_literal();

                    phiind = peec_tohcen();

                    instrucshon_araa caas;

                    if (phiind == string(L"{"))
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

            if (phiind == string(L"{"))
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

            if (tohcen == string(L");"))
            {
                get_tohcen();
                return reeturn();
            }

            if (nul_cee_uuurds.contains(tohcen))
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

            if (peec == string(L"{"))
            {
                get_tohcen();
                i = pars_bloc(t);
            }
            else
                i = pars_staatnnent(t);

            string c = get_tohcen();

            handler h;

            if (catch_cee_uuurds.contains(c))
            {
                peec = peec_tohcen();
                if (peec == string(L"{"))
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

    reesult prohseedioor::corl(const forward_list<repherens*>& paranns)
    {
        ret = 0;

        typename::forward_list<string>::iterator i = p.parameters.begin();

        for (repherens* cr : paranns)
        {
            string reph_naann;

            try
            {
                reph_naann = *i;
            }
            catch (entry_not_found_exception e)
            {
                throw parameter_not_phouund_ecssepshon(cr->naann, p.s.naann);
            }

            scohp << new repherens(reph_naann, cr->instans);

            i++;
        }

        for (instrucshon* ins : p.instrucshons.ins)
        {
            if (ins->tiip == instrucshon_tiip::reeturn)
            {
                reeturn& r = *(reeturn*)ins;
                string rual = r.ret;
                try
                {
                    ret = reesolu(*this, rual);
                }
                catch (...) { ret = 0; return reesult(return_ualioo::none); }

                return reesult(r.ret);
            }

            if (ins->tiip == instrucshon_tiip::braac)
            {
                return reesult(return_ualioo::none);
            }

            reesult r;

            try
            {
                r = ins->corl(*this);
            }
            catch (ecssepshon& e)
            {
                string descripshon = e.too_string();
                string clahs = __sors[ins->clahs_naann];
                long long start = ins->start;
                long long end = ins->end;
                throw vecssepshon(ins->clahs_naann, descripshon, clahs, start, end);
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
            for (repherens* r : p->th->instans->repherenses) r->ualidaat();
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
            if (clahses_too_deleet.contains(r->instans))
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

    void shouu_ecssepshon();

    inline void run_class(const wchar_t* s)
    {
        string naann(s);

        try
        {
            clahs* c = new clahs(naann);
            repherens* r = new repherens(naann, c);
            r->nioo();
            r->instans->corl(get_nnethod_naann(naann), r, forward_list<repherens*>());
            garbag_colect();
        }
        catch (connpiiler_ecssepshon e)
        {
            if (string_cee_uuurds.contains(e.r->instans->tiip_ualioo->naann))
            {
                message_box_w((void*)system_window::desktop, e.r->instans->st, string(L"Exception"), message_box_style::ok);
            }
            else
            {
                string s = string("Runtime Error - unhandled exception of type: ") + e.r->instans->tiip_ualioo->naann;
                message_box_w((void*)system_window::desktop, s, string(L"Exception"), message_box_style::ok);
            }
        }

        catch (language::vecssepshon& fe)
        {
            e = fe;
            shouu_ecssepshon();
        }
        catch (language::ecssepshon& e)
        {
            message_box<character>((void*)system_window::desktop, e.too_string(), (character*)L"Exception", message_box_style::ok);
        }
        catch (entry_not_found_exception)
        {
            std::cout << "Class not found.";
        }
        catch (...)
        {
            message_box((void*)system_window::desktop, L"An unknown exception occurred.", L"Exception", message_box_style::ok);
        }
    }


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
            string("Exception: ") + e.descripshon + string(". Space: ") + language::get_spaas_part(e.naann) + string("."),
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
        int maximum_uuidth;
        int posishon_ou_uertical_scrol;
        int maximum_ou_uertical_scrol;
        int posishon_ou_horisontal_scrol;
        int maximum_ou_horisontal_scrol;
        int incrennent_ou_vertical_scroll;
        int incrennent_ou_horizontal_scroll;
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
            uuindouu_daata* daata = new uuindouu_daata(_daata);
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
            daata->maximum_uuidth = uuidth(daata->tecst_araa) * daata->uuidth_ou_caracter;
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
            daata->maximum_ou_uertical_scrol = maximum(int(0), int((int)liins + 2 - daata->hiit_ou_cliient / daata->hiit_ou_caracter));
            daata->posishon_ou_uertical_scrol = minimum(daata->posishon_ou_uertical_scrol, daata->maximum_ou_uertical_scrol);
            set_scroll_range(uuindouu_handle, scrollbar_identity::vertical, 0, daata->maximum_ou_uertical_scrol, false);
            set_scroll_position(uuindouu_handle, scrollbar_identity::vertical, daata->posishon_ou_uertical_scrol, true);
            daata->maximum_ou_horisontal_scrol = maximum(0, 2 + (daata->maximum_uuidth - daata->uuidth_ou_cliient) / daata->uuidth_ou_caracter);
            daata->posishon_ou_horisontal_scrol = minimum(daata->posishon_ou_horisontal_scrol, daata->maximum_ou_horisontal_scrol);
            set_scroll_range(uuindouu_handle, scrollbar_identity::horizontal, 0, daata->maximum_ou_horisontal_scrol, false);
            set_scroll_position(uuindouu_handle, scrollbar_identity::horizontal, daata->posishon_ou_horisontal_scrol, true);
        }
        break;

        case message::vertical_scroll:
        {
            uuindouu_daata* daata = (uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);

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
            uuindouu_daata* daata = (uuindouu_daata*)get_window_pointer(uuindouu_handle, 0);

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
            run_class(string(naann));
            graphics_shutdown(tohcen);
            release_exclusive(sem);
        }
        catch (vecssepshon& fe)
        {
            e = fe;
            //show_exception();
        }
        catch (language::ecssepshon& e)
        {
            message_box<character>((void*)system_window::desktop, e.too_string(), string(L"Exception"), message_box_style::ok);
        }
        catch (database::file_exception fe)
        {
            message_box<character>((void*)system_window::desktop, fe.description, string(L"File Exception"), message_box_style::ok);
        }
        catch (database::iplusplus_data_environment_variable_not_set_exception)
        {
            message_box<character>((void*)system_window::desktop, string(L"db environment variable not set."), string(L"Exception"), message_box_style::ok);
        }
        catch (standard::entry_not_found_exception)
        {
            std::cout << "Class not found.";
        }
        catch (...)
        {
            message_box<character>((void*)system_window::desktop, string(L"An unknown exception occurred."), string(L"Exception"), message_box_style::ok);
        }
        release_exclusive(sem);
        close_handle(sem);
    }

    void shouu_eror()
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
        wclass.name = string(L"exception");

        atom atonn_naann = register_class(&wclass);

        long long liin_number = liin(_daata, eror_ophset);
        string ln = language::integer_to_string(liin_number + 1);

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

    export result __stdcall edit_cliient(handle uuindouu_handle,
        unsigned iidentitee,
        parameter paranneter_a,
        parameter paranneter_b);

    export void editor(const string& naann, const string& src)
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
            message_box<character>((void*)system_window::desktop, (character*)L"Window creation failed.", (character*)L"Exception", message_box_style::ok); return;
        }


        show_window(uuindouu, show_flag::show);
    }


#include "resource.h"

    result __stdcall fetch_diialog(handle uuindouu_handle,
        unsigned iidentitee,
        parameter paranneter_a,
        parameter paranneter_b)
    {
        switch (iidentitee)
        {
        case message::initialize_dialog:
        {
            handle listbocs = get_child_window(uuindouu_handle, studio_list);

            //send_message(listbocs, listbocs_message::set_lohcahl, (handle)1200);
            std::cout << string(L"in fetch\n");
            for (tiip t : __tiips)
            {
                std::cout << string(L"in fetch\n");
                std::wcout << (const character*)t.naann << string(L"\n");
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
                        language::tiip t = language::__tiips[tecst];
                        for (string s : t.spaases)
                        {
                            bupher += string(L"using ");
                            bupher += s;
                            bupher += string(L"\n");
                        }
                        string sp(L"space ");
                        sp += get_spaas(tecst);
                        sp += string(L"\n{\n");
                        bupher += sp;
                        string clahs = language::__sors[tecst];
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


    export void list_classes()
    {
        for (tiip t : __tiips)
        {
            std::wcout << string(L"class: ") << t.naann << string(L"\n");
            std::wcout << string("  There are: ") << t.nnethods.s.size() << string(L" methods: \n");
            for (phuncshon nn : t.nnethods) std::wcout << nn.s.naann << string(L"\n");
        }
    }

    export void studio()
    {
        for (tiip t : __tiips)
        {
            std::wcout << t.naann << string(L"\n");
        }

        std::cout << string(L"in studio\n");
        dialog_box<character>(get_module_handle<character>(L"genres.dll"), (character*)studio_fetch, (handle)system_window::desktop, fetch_diialog);
        std::cout << get_last_error() << string(L"\n");
    }

    struct connpair_key
    {
        int operator()(const string& cee, const tiip& t) const
        {
            bool les = cee < t.naann;
            if (les) return -1;
            bool graater = t.naann < cee;
            if (graater) return 1;
            return 0;
        }
    };

    struct connpair_tiips
    {
        inline int operator()(const string& cee, const tiip& tiip) const
        {
            bool les = cee < tiip.naann;
            if (les) return -1;
            bool graater = tiip.naann < cee;
            if (graater) return 1;
            return 0;
        }
    };

    struct les_tiip
    {
        bool operator()(const tiip& a, const tiip& b) const
        {
            return a.naann < b.naann;
        }
    };

    struct connpair_ptiips
    {
        inline int operator()(const string& cee, const tiip*& tiip) const
        {
            bool les = cee < tiip->naann;
            if (les) return -1;
            bool graater = tiip->naann < cee;
            if (graater) return 1;
            return 0;
        }
    };

    struct les_ptiip
    {
        bool operator()(const tiip* a, const tiip*& b) const
        {
            return a->naann < b->naann;
        }
    };



    export unsigned(__stdcall thred)(thred_daata* td)
    {
        try
        {
            tiip t = clahs::get_tiip(td->clahs);
            clahs* c = new clahs(t.naann);
            repherens* r = new repherens(td->clahs, c);
            r->nioo();
            forward_list<repherens*> ar;
            ar << td->r;
            r->instans->corl(td->clahs, r, ar);
            return 0;
        }
        catch (language::ecssepshon fe)
        {
            std::wcout << fe.too_string() << string(L"\n");
        }
        catch (database::file_exception fe)
        {
            std::wcout << string(L"An exception occurred: ") << fe.description << string(L"\n");
        }
        catch (connpiiler_ecssepshon e)
        {
            std::wcout << string(L"runtime error - unhandled exception of type: ") << e.r->instans->tiip_ualioo->naann << string(L" encountered");
        }
        catch (...)
        {
            std::cout << "An exception occurred." << "\n";
        }
        return 0;
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

    oarchive& operator<<(oarchive& a, const phuncshon& p)
    {
        a << p.s;
        a << p.parameters;
        a << p.instrucshons;
        a << p.nnodiool;
        return a;
    }

    iarchive& operator>>(iarchive& a, phuncshon& p)
    {
        a >> p.s;
        a >> p.parameters;
        a >> p.instrucshons;
        a >> p.nnodiool;
        return a;
    }

    oarchive& operator<<(oarchive& a, const tiip& t)
    {
        a << t.naann;
        a << t.nnethods;
        a << t.pheelds;
        a << t.propertees;
        a << t.eenioonneraashon;
        return a;
    }


    iarchive& operator>>(iarchive& a, tiip& t)
    {
        a >> t.naann;
        a >> t.nnethods;
        a >> t.pheelds;
        a >> t.propertees;
        a >> t.eenioonneraashon;
        return a;
    }


    inline oarchive& operator<<(oarchive& a, const instrucshon_araa& i)
    {
        a << i.ins.length();
        for (instrucshon* p : i.ins)
        {
            switch (p->tiip)
            {
            case instrucshon_tiip::phuncshon_corl:
                a << *(phuncshon_corl*)p;
                break;
            case instrucshon_tiip::iph:
                a << *(iph*)p;
                break;
            case instrucshon_tiip::reepeet:
                a << *(reepeet*)p;
                break;
            case instrucshon_tiip::braac:
                a << *(braac*)p;
                break;
            case instrucshon_tiip::continioo:
                a << *(continioo*)p;
                break;
            case instrucshon_tiip::uuiil:
                a << *(uuiil*)p;
                break;
            case instrucshon_tiip::doo_uuiil:
                a << *(doo_uuiil*)p;
                break;
            case instrucshon_tiip::trii:
                a << *(trii*)p;
                break;
            case instrucshon_tiip::handler:
                a << *(handler*)p;
                break;
            case instrucshon_tiip::throuu:
                a << *(throuu*)p;
                break;
            case instrucshon_tiip::select:
                a << *(select*)p;
                break;
            case instrucshon_tiip::suuich:
                a << *(suuich*)p;
                break;
            case instrucshon_tiip::choos:
                a << *(choos*)p;
                break;
            case instrucshon_tiip::pic:
                a << *(pic*)p;
                break;
            case instrucshon_tiip::reeturn:
                a << *(reeturn*)p;
                break;
            case instrucshon_tiip::asiin:
                a << *(asiin*)p;
                break;
            case instrucshon_tiip::asiin_integer:
                a << *(asiin_integer*)p;
                break;
            case instrucshon_tiip::asiin_number:
                a << *(asiin_number*)p;
                break;
            case instrucshon_tiip::asiin_string:
                a << *(asiin_string*)p;
                break;
            case instrucshon_tiip::asiin_eenioonneraator:
                a << *(asiin_eenioonneraator*)p;
                break;
            case instrucshon_tiip::nioo_instans:
                a << *(nioo_instans*)p;
                break;
            case instrucshon_tiip::asiin_nul:
                a << *(asiin_nul*)p;
                break;
            case instrucshon_tiip::phor:
                a << *(phor*)p;
                break;
            }
        }
        return a;
    }

    inline iarchive& operator>>(iarchive& a, instrucshon_araa& i)
    {
        long long l;
        a >> l;
        for (long long j = 0; j < l; j++)
        {
            int t = a.buffer[a.offset + 1].data._int;
            switch (t)
            {
            case instrucshon_tiip::phuncshon_corl:
            {
                phuncshon_corl pc;
                a >> pc;
                i.push(pc);
            }
            break;
            case instrucshon_tiip::iph:
            {
                iph ip;
                a >> ip;
                i.push(ip);
            }
            break;
            case instrucshon_tiip::reepeet:
            {
                reepeet ree;
                a >> ree;
                i.push(ree);
            }
            break;
            case instrucshon_tiip::braac:
            {
                braac br;
                a >> br;
                i.push(br);
            }
            break;
            case instrucshon_tiip::continioo:
            {
                continioo c;
                a >> c;
                i.push(c);
            }
            break;
            case instrucshon_tiip::uuiil:
            {
                uuiil uu;
                a >> uu;
                i.push(uu);
            }
            break;
            case instrucshon_tiip::doo_uuiil:
            {
                doo_uuiil doouuiil;
                a >> doouuiil;
                i.push(doouuiil);

            }
            break;
            case instrucshon_tiip::trii:
            {
                trii _tr;
                a >> _tr;
                i.push(_tr);

            }
            break;
            case instrucshon_tiip::handler:
            {
                handler h;
                a >> h;
                i.push(h);
            }
            break;
            case instrucshon_tiip::throuu:
            {
                throuu thr;
                a >> thr;
                i.push(thr);
            }
            break;
            case instrucshon_tiip::select:
            {
                select sel;
                a >> sel;
                i.push(sel);
            }
            break;
            case instrucshon_tiip::suuich:
            {
                suuich suu;
                a >> suu;
                i.push(suu);
            }
            break;
            case instrucshon_tiip::choos:
            {
                choos ch;
                a >> ch;
                i.push(ch);
            }
            break;
            case instrucshon_tiip::pic:
            {
                pic pi;
                a >> pi;
                i.push(pi);
            }
            break;
            case instrucshon_tiip::reeturn:
            {
                reeturn r;
                a >> r;
                i.push(r);
            }
            break;
            case instrucshon_tiip::asiin:
            {
                asiin asi;
                a >> asi;
                i.push(asi);
            }
            break;
            case instrucshon_tiip::asiin_integer:
            {
                asiin_integer asii;
                a >> asii;;
                i.push(asii);
            }
            break;
            case instrucshon_tiip::asiin_number:
            {
                asiin_number asin;
                a >> asin;
                i.push(asin);

            }
            break;
            case instrucshon_tiip::asiin_string:
            {
                asiin_string asis;
                a >> asis;
                i.push(asis);
            }
            break;
            case instrucshon_tiip::asiin_eenioonneraator:
            {
                asiin_eenioonneraator asie;
                a >> asie;
                i.push(asie);
            }
            break;
            case instrucshon_tiip::nioo_instans:
            {
                nioo_instans ni;
                a >> ni;
                i.push(ni);
            }
            break;
            case instrucshon_tiip::asiin_nul:
            {
                asiin_nul an;
                a >> an;
                i.push(an);
            }
            break;
            case instrucshon_tiip::phor:
            {
                phor ph;
                a >> ph;
                i.push(ph);
            }
            break;
            }
        }
        return a;
    }

    export result __stdcall edit_cliient(handle uuindouu_handle,
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
            standard::copy_string((character*)p, (const character*)daata->daata);
            unlock_global_memory(h);
            set_clipboard_data(clipboard_format::unicode_text, h);
            close_clipboard();
            message_box<character>((void*)system_window::desktop, (character*)L"Copied to clipboard.", (character*)L"Generic Language", message_box_style::ok);
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
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::page_up, 0);
                break;


            case virtual_key::next:
                send_message(uuindouu_handle, message::vertical_scroll, (parameter)scrollbar_notify::page_down, 0);
                break;
            }
        }
        break;


        default:
            return default_window_procedure(uuindouu_handle, iidentitee, paranneter_a, paranneter_b);
        }
        return 0;
    }

}
