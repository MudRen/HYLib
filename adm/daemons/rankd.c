// rankd.c
// 1996-02-15 dts ranking related to "shen"

#include <ansi.h>

string query_rank(object ob)
{
        mapping fam;

        int exp;
        int shen;
        int budd;
        int age;
string family;
        if( ob->is_ghost() )
                return HIB "���»�Ұ��" NOR;

        shen = ob->query("shen");
        exp = ob->query("combat_exp");
        age = ob->query("age");
        family = ob->query("family/family_name");
        if ( (fam = ob->query("family")) && (fam["family_name"] == "������"
                || fam["family_name"] == "������"
                || fam["family_name"] == "������"
                || fam["family_name"] == "ѩɽ��"
                || fam["family_name"] == "��ɽ��"
                ))
                budd = ob->query_skill("buddhism",1);
//        if(exp >=2500000 && shen >=200000)
//                return HIW "����˵�еĴ�����" NOR;
//        if(exp >=2500000 && shen <=-200000)
//                return HIW "����˵�е�ħ����" NOR;
//        if(exp >=1500000)
//                return HIW "�����ִ��桿" NOR;


        switch(ob->query("gender")) {
        case "Ů��":
                switch(wizhood(ob)) {
                case "(admin)":
                        return HIM "��������Ů��" NOR;
                case "(arch)":
                        return HIY "������Ů��" NOR;
                case "(wizard)":
                        return HIG "��������Ů��" NOR;
                case "(apprentice)":
                        return HIC "�� ��  �� ��" NOR;
                case "(immortal)":
                        return HIC "������ʹ�ߡ�" NOR;
                default:
/*if (!ob->query("class") || !family) {
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "����ѪŮħ��" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "��Ů �� �ԡ�" NOR;
                       if (shen >= 1000000) return HIC "�������콿��" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIC "������Ů����" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIC "�� ��Ů�� ��" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIC "�� Ů  �� ��" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return HIC "�� Ů���� ��" NOR;
                        if (shen <= -1000000) return HIR "��������ɲ��" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return HIC "������Ůħ��" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return HIC "�� ��Ůħ ��" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIC "�� Ů  ħ ��" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return HIC "�� Ů��ħ ��" NOR;
}
                        else*/
if (family=="�������")
 {
                       if (exp>= 1000000 ) return HIW "�� ʥ  �� ��" NOR;
                       else if (exp>= 800000 ) return HIW "�� �󻤷� ��" NOR;
                       else if (exp>= 700000) return HIY "�� ��  �� ��" NOR;
                       else if (exp>= 600000)  return HIY "�� ̳  �� ��" NOR;
                       else if (exp>= 50000) return YEL "�� ��  �� ��" NOR;
                       else if (exp>= 30000 || age >= 20) return CYN "�� Ů���� ��" NOR;
                       else return CYN "�� Ů��ͽ ��" NOR;
 }else
 if (family=="��ң��" || family=="�һ���")
 {
                       if (exp>= 1000000 ) return HIW "�� ��  �� ��" NOR;
                       else if (exp>= 800000 ) return HIW "�� ��  �� ��" NOR;
                       else if (exp>= 700000) return HIY "�� ��  ʿ ��" NOR;
                       else if (exp>= 600000)  return HIY "�� ��  ʿ ��" NOR;
                       else if (exp>= 50000) return YEL "�� ��  ʿ ��" NOR;
                       else if (exp>= 30000 || age >= 20) return CYN "�� ��  �� ��" NOR;
                       else return CYN "��Ů �� �ڡ�" NOR;
 }else
if (family=="ѩɽ��")
 {
                       if (exp>= 1000000 && shen >= 0) return HIW "�� ��ϲ�� ��" NOR;
                       else if (exp>= 1000000 && shen < 0) return HIW "�� ��ϲħ ��" NOR;
                       else if (exp>= 700000) return HIY "�� ʥ  Ů ��" NOR;
                       else if (exp>= 600000)  return HIY "�� ��  �� ��" NOR;
                       else if (exp>= 50000) return YEL "�� Ǭ���� ��" NOR;
                       else if (exp>= 30000 || age >= 20) return CYN "�� ����Ů ��" NOR;
                       else return CYN "�� ��  �� ��" NOR;
 }else
 if (family=="��Ĺ��" || family=="��ɽ��" || family=="������")
 {
                       if (exp>= 2000000 && shen > 0) return HIW "������һ����" NOR;
                       else if (exp>= 2000000 && shen < 0) return HIW "����ħһ����" NOR;
                        else if (exp>= 1000000) return HIR "�� ��  ʥ ��" NOR;
                        else if (exp>= 800000) return HIY "�� ��  �� ��" NOR;
                        else if (exp>= 700000) return HIC "�� Ů���� ��" NOR;
                        else if (exp>= 500000 )  return YEL "�� Ů���� ��" NOR; 
                        else return "�� Ů��ʿ ��";
 }else
 if (family=="����Ľ��" || family=="����μ�")
 {
                        if (exp>= 1000000) return HIR "�� ��  �� ��" NOR;
                        else if (exp>= 800000) return HIY "�� ھ������ ��" NOR;
                        else if (exp>= 700000) return HIC "�� Ů  �� ��" NOR;
                        else if (exp>= 500000 )  return YEL "�� Ů  �� ��" NOR; 
                        else if ( age >= 18)  return CYN "�� Ů  �� ��" NOR; 
                        else return "�� Ů  �� ��";
 }else
  if (family=="���չ�")
 {
                        if (exp>= 1000000) return HIR "�� ��  Ů ��" NOR;
                        else if (exp>= 800000) return HIY "�� ��  �� ��" NOR;
                        else if (exp>= 700000) return HIC "�� ��  Ů ��" NOR;
                        else if (exp>= 500000 )  return YEL "����ңŮ�ɡ�" NOR; 
                        else if ( age >= 18)  return CYN "�� ��  �� ��" NOR; 
                        else return "�� ��  �� ��";
 }else
  if (family=="����")
 {
						if (exp>10000000)
								return NOR "��"HIR"Ů������"NOR"��";
						if (exp>5000000)
								return NOR "��"HIM" ��  �� "NOR"��";
						if (exp>1000000)
								return NOR "��"GRN"Ů�ܻ���"NOR"��";
						if (exp>500000)
								return NOR "��"YEL"Ů �� ��"NOR"��";
						if (exp>300000)
								return NOR "��"YEL"Ů������"NOR"��";
						if (exp>100000)
								return NOR "��"CYN"Ů������"NOR"��";
						if (exp>25000)
								return NOR "��"CYN"Ů �� ��"NOR"��";
						if (exp>10000)
								return NOR "��"MAG"Ů������"NOR"��";
						if (exp>5000)
								return NOR "��"MAG"Ů �� ��"NOR"��";
						return "��  ��  ��  ��" ;
 }else
  if (family=="������")
 {
                        return HIG"��Ů �� ʿ��"NOR;
 }else
  if (family=="������")
 {
						if (exp>10000000)
								return NOR "��"HIR"��   ��"NOR"��";
						if (exp>5000000)
								return NOR "��"HIM"��   ��"NOR"��";
						if (exp>1000000)
								return NOR "��"GRN"��   ��"NOR"��";
						if (exp>500000)
								return NOR "��"YEL" ����ɲ "NOR"��";
						if (exp>300000)
								return NOR "��"YEL" ����ɲ "NOR"��";
						if (exp>100000)
								return NOR "��"CYN" ����ɲ "NOR"��";
						if (exp>25000)
								return NOR "��"CYN" ����ɲ "NOR"��";
						if (exp>10000)
								return NOR "��"MAG" ����ɲ "NOR"��";
						if (exp>5000)
								return NOR "��"MAG"��    ��"NOR"��";
						return "��  ��ƨ��  ��" ;
 }else
  if (family=="�嶾��")
 {
						if (exp>10000000)
								return NOR "��"HIR"��   ��"NOR"��";
						if (exp>5000000)
								return NOR "��"HIM"��   ��"NOR"��";
						if (exp>1000000)
								return NOR "��"GRN"��   ��"NOR"��";
						if (exp>500000)
								return NOR "��"YEL" ����ɲ "NOR"��";
						if (exp>300000)
								return NOR "��"YEL" ����ɲ "NOR"��";
						if (exp>100000)
								return NOR "��"CYN" ����ɲ "NOR"��";
						if (exp>25000)
								return NOR "��"CYN" ����ɲ "NOR"��";
						if (exp>10000)
								return NOR "��"MAG" ����ɲ "NOR"��";
						if (exp>5000)
								return NOR "��"MAG"��    ��"NOR"��";
						return "��  Ů����  ��" ;
 }else

  if (family=="����ɽ��")
 {
	if (shen >= 0)
	return NOR "��"HIR"ħ �� ��"NOR"��";
	else
	return NOR "��"HIR" ��  ħ "NOR"��";
 }else

                        switch(ob->query("class")) {
                        case "bonze":
  
                             if (budd >= 150)
                                return HIY "�� ��  �� ��" NOR;
                             else if (budd >= 120)
                                return HIY "�� ʥ  �� ��" NOR;
                             else if (budd >= 90)
                                return HIY "�� ��  �� ��" NOR;
                             else if (budd >= 60)
                                return HIC "�� ��  �� ��" NOR;
                             else if (budd >= 30)
                                return HIG "�� ������ ��" NOR;
                             else if (age <= 16)
                                return HIW "�� ɳ���� ��" NOR;
                             else
                                return HIW "�� ѧ��Ů ��" NOR;
                        case "taoist":
                        if (budd >= 180) return HIW "�� ��  Ů ��" NOR;
                        else if (budd >= 140) return HIY "�� ��  �� ��" NOR;
                        else if (budd >= 100) return YEL "�� ɢ  �� ��" NOR;
                        else if (budd >= 50 || age >= 20) return YEL "�� ��  �� ��" NOR;
                        else return "�� С���� ��"; 
                        case "bandit":
                                return HIW "�� Ů���� ��" NOR;
                        case "dancer":
                                return HIW "����ɫ�輧��" NOR;
                        case "scholar":
                             if (age <= 16)
                                return HIW "�� Ůѧͯ ��" NOR;
                             else if (age <= 30)
                                return HIW "��ңң���ˡ�" NOR;
                             else
                                return HIW "�� Ůѧʿ ��" NOR;
                        case "officer":
                                return HIW "�� Ů  �� ��" NOR;
                        case "fighter":
                                return HIW "�� Ů���� ��" NOR;
                        case "swordsman":
                        if (exp>= 1000000) return HIR "�� ��  ʥ ��" NOR;
                        else if (exp>= 800000) return HIY "�� ��  �� ��" NOR;
                        else if (exp>= 700000) return HIC "�� Ů���� ��" NOR;
                        else if (exp>= 500000 )  return YEL "�� Ů���� ��" NOR; 
                        else return "�� Ů��ʿ ��";
                        case "alchemist":
                                return HIW "�� Ů��ʿ ��" NOR;
                        case "shaman":
                                return HIW "�� Ů��ҽ ��" NOR;
                        case "beggar":
                                return HIW "�� Ů�л� ��" NOR;
                        case "prostitute":
                                return HIW "�� ��  Ů ��" NOR;
			    case "mr":
                                return HIB "�� Ľ������ ��" NOR;
			    case "tiezhang":
                                return HIY "�� ���Ƶ��� ��" NOR;
                        default:
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "����ѪŮħ��" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "��Ů �� �ԡ�" NOR;
                       if (shen >= 1000000) return HIC "�������콿��" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIM "������Ů����" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIG "������Ӣ�ۡ�" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIY "��Ů�к��ܡ�" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return CYN "���糾��Ů��" NOR;
                        if (shen <= -1000000) return HIR "��������ɲ��" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return HIG "������Ůħ��" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return CYN "����ѪŮħ��" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIY "����ѪħŮ��" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return CYN "��������Ů��" NOR;
                                if (age <= 16)
                                    return HIC "��������Ů��" NOR;
                                else
                                    return HIM "��ܷܷ��Ů��" NOR;
                        }
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "����ѪŮħ��" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "��Ů �� �ԡ�" NOR;
                       if (shen >= 1000000) return HIC "�������콿��" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIM "������Ů����" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIG "������Ӣ�ۡ�" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIY "��Ů�к��ܡ�" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return CYN "���糾��Ů��" NOR;
                        if (shen <= -1000000) return HIR "��������ɲ��" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return HIG "������Ůħ��" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return CYN "����ѪŮħ��" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIY "����ѪħŮ��" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return CYN "��������Ů��" NOR;
                }
        default:
                switch(wizhood(ob)) {
                case "(admin)":
                        return HIM "�� ��  �� ��" NOR;
                case "(arch)":
                        return HIY "�� ��  �� ��" NOR;
                case "(wizard)":
                        return HIG "�� ��  �� ��" NOR;
                case "(apprentice)":
                        return HIC "�� ɢ  �� ��" NOR;
                case "(immortal)":
                        return HIC "�� ��  �� ��" NOR;
                default:
/*if (!ob->query("class") || !family){
                        if (shen >= 1000000) return HIC "������������" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIC "������������" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIC "���������ܡ�" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIC "���������㡿" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return HIC "��С�����塿" NOR;
                        else if (shen <= -1000000) return HIR "��������ħ��" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return HIC "������ħ����" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return HIC "�����һ����" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIC "������Զ�" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return HIC "��С�ж�����" NOR;
                        else
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "�� ɱ��ħ ��" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "�� ��  �� ��" NOR;
}
                        else*/
 if (family=="�������")
 {
                       if (exp>= 1000000) return HIW "�� ������ ��" NOR;
                       if (exp>= 800000 ) return HIW "�� �󻤷� ��" NOR;
                       if (exp>= 700000) return HIY "�� ��  �� ��" NOR;
                       if (exp>= 600000)  return HIY "�� ̳  �� ��" NOR;
                       if (exp>= 50000) return YEL "�� ��  �� ��" NOR;
                       if (exp>= 30000 || age >= 20) return CYN "�� ��  �� ��" NOR;
                       return CYN "�� ��  ͽ ��" NOR;
 }else
 if (family=="��ң��" || family=="�һ���")
 {
                       if (exp>= 1000000 && shen >= 0) return HIW "�� ��  ʥ ��" NOR;
                       if (exp>= 1000000 && shen < 0) return HIW "�� ��  �� ��" NOR;
                       if (exp>= 700000) return HIY "�� ��  �� ��" NOR;
                       if (exp>= 600000)  return HIY "�� ��  ʿ ��" NOR;
                       if (exp>= 50000) return YEL "�� ��  ʿ ��" NOR;
                       if (exp>= 30000 || age >= 20) return CYN "�� ��  �� ��" NOR;
                       return CYN "�����齣�͡�" NOR;
 }else
 if (family=="���ư�")
 {
                       if (exp>= 1000000 && shen >= 0) return HIW "�� ɽ���� ��" NOR;
                       if (exp>= 1000000 && shen < 0) return HIW "�� կ  �� ��" NOR;
                       if (exp>= 700000) return HIY "�� կ  �� ��" NOR;
                       if (exp>= 600000)  return HIY "�� ��  �� ��" NOR;
                       if (exp>= 50000) return YEL "�� ��  �� ��" NOR;
                       if (exp>= 30000 || age >= 20) return CYN "�� ͷ  Ŀ ��" NOR;
                       return CYN "�� С��� ��" NOR;
 }else
 if (family=="��Ĺ��" || family=="��ɽ��" || family=="������")
 {
                       if (exp>= 2000000 && shen > 0) return HIW "������һ����" NOR;
                       else if (exp>= 2000000 && shen < 0) return HIW "����ħһ����" NOR;
                        else 
                        if (exp>= 1000000) return HIR "�� ��  �� ��" NOR;
                        else if (exp>= 800000) return HIY "�� ��  �� ��" NOR;
                        else if (exp>= 700000) return HIC "�� ��  �� ��" NOR;
                        else if (exp>= 500000 )  return YEL "�� ��  �� ��" NOR; 
                        else return "�� ��  ʿ ��";
 }else
 if (family=="ѩɽ��")
 {
                       if (exp>= 1000000 && shen >= 0) return HIW "�� ��ϲ�� ��" NOR;
                       if (exp>= 1000000 && shen < 0) return HIW "�� ��ϲħ ��" NOR;
                       if (exp>= 700000) return HIY "�� ��  �� ��" NOR;
                       if (exp>= 600000)  return HIY "�� �󻤷� ��" NOR;
                       if (exp>= 50000) return YEL "�� ��  �� ��" NOR;
                       if (exp>= 30000 || age >= 20) return CYN "�� ��  ʿ ��" NOR;
                       return CYN "�� ��  �� ��" NOR;
 }else
 if (family=="����Ľ��" || family=="����μ�")
 {
                        if (exp>= 1000000) return HIR "�� ��  �� ��" NOR;
                        else if (exp>= 800000) return HIY "�� ��  ү ��" NOR;
                        else if (exp>= 700000) return HIC "�� ��  �� ��" NOR;
                        else if (exp>= 500000 )  return YEL "�� ��  �� ��" NOR; 
                        else if ( age >= 18)  return CYN "�� У  ξ ��" NOR; 
                        else return "�� ��  ʿ ��";
 }
 else
  if (family=="����")
 {
 						if (exp>10000000)
								return NOR "��"HIR"�� �� ��"NOR"��";
						if (exp>5000000)
								return NOR "��"HIM" ��  �� "NOR"��";
						if (exp>1000000)
								return NOR "��"GRN"�� �� ��"NOR"��";
						if (exp>500000)
								return NOR "��"YEL" ��  �� "NOR"��";
						if (exp>300000)
								return NOR "��"YEL"�� �� ��"NOR"��";
						if (exp>100000)
								return NOR "��"CYN"�� �� ��"NOR"��";
						if (exp>25000)
								return NOR "��"CYN" ��  �� "NOR"��";
						if (exp>10000)
								return NOR "��"GRN"�� �� ��"NOR"��";
						if (exp>5000)
								return NOR "��"HIB" ��  �� "NOR"��";
						return "�� ��  �� ��" ;

 }else
  if (family=="������")
 {
                        return HIG"��������ʿ��"NOR;
 }
 else
  if (family=="������")
 {
						if (exp>10000000)
								return NOR "��"HIR"��   ��"NOR"��";
						if (exp>5000000)
								return NOR "��"HIM"��   ��"NOR"��";
						if (exp>1000000)
								return NOR "��"GRN"��   ��"NOR"��";
						if (exp>500000)
								return NOR "��"YEL"��  �� "NOR"��";
						if (exp>300000)
								return NOR "��"YEL"��  ħ "NOR"��";
						if (exp>100000)
								return NOR "��"CYN"��   ħ"NOR"��";
						if (exp>25000)
								return NOR "��"CYN"��   ħ"NOR"��";
						if (exp>10000)
								return NOR "��"MAG"��   ħ"NOR"��";
						if (exp>5000)
								return NOR "��"MAG"��   ħ"NOR"��";
						return "��  ������  ��" ;
 }else
  if (family=="�嶾��")
 {
						if (exp>10000000)
								return NOR "��"HIR"��   ��"NOR"��";
						if (exp>5000000)
								return NOR "��"HIM"��   ��"NOR"��";
						if (exp>1000000)
								return NOR "��"GRN"��   ��"NOR"��";
						if (exp>500000)
								return NOR "��"YEL"��  �� "NOR"��";
						if (exp>300000)
								return NOR "��"YEL"��  ħ "NOR"��";
						if (exp>100000)
								return NOR "��"CYN"��   ħ"NOR"��";
						if (exp>25000)
								return NOR "��"CYN"��   ħ"NOR"��";
						if (exp>10000)
								return NOR "��"MAG"��   ħ"NOR"��";
						if (exp>5000)
								return NOR "��"MAG"��   ħ"NOR"��";						return "��  Ů����  ��" ;
						return "��  �н���  ��" ;
 }else
  if (family=="����ɽ��")
 {
	if (shen >= 0)
	return NOR "��"HIR"ħ �� ��"NOR"��";
	else
	return NOR "��"HIR" ��  ħ "NOR"��";
 }else
                                 switch(ob->query("class")) {
                                case "bonze":
                       if (budd >= 180) return HIW "�� ��  ɮ ��" NOR;
                      else if (budd >= 150) return WHT "�� ��  �� ��" NOR;
                      else if (budd >= 120) return HIY "�� ʥ  ɮ ��" NOR;
                      else if (budd >= 80) return HIY "�� ��  �� ��" NOR;
                      else if (budd >= 60) return YEL "�� ��  �� ��" NOR;
                      else if (budd >= 40) return YEL "�� ��  ʦ ��" NOR;
                      else if (budd >= 30) return YEL "�� ��  �� ��" NOR;
                      return "�� ɮ  �� ��";
                                 case "taoist":
                                        if (ob->query_skill("taoism",1) >= 180) return HIW "�� ��  �� ��" NOR;
                                        else if (ob->query_skill("taoism",1) >= 140) return HIY "�� ��  ʦ ��" NOR;
                                        else if (ob->query_skill("taoism",1)>100)
                                           return HIW "�� ��  �� ��" NOR;
                                        else if (age <= 16)
                                           return HIW "�� С��ʿ ��" NOR;
                                        else if (age <= 30)
                                           return HIW "�� ��  ʿ ��" NOR;
                                        else
                                           return HIW "�� ��  �� ��" NOR;
                                case "bandit":
                                 if (exp>= 1000000) return HIC "�� կ  �� ��" NOR;
                                 if (exp>= 600000) return CYN "�� ��  �� ��" NOR;
                                 if (exp>= 100000 || age >= 18)  return CYN "�� ͷ  Ŀ ��" NOR; 
                                 return "�� С��� ��"; 
                                case "scholar":
                                     if (age <= 16)
                                        return HIW "�� ѧ  ͯ ��" NOR;
                                     else if (age <= 45)
                                        return HIW "�� ��  �� ��" NOR;
                                     else
                                        return HIW "�� ����� ��" NOR;
                                case "officer":
                                        return HIW "�� ��  �� ��" NOR;
                                case "fighter":
                                        return HIW "�� ��  �� ��" NOR;
                                case "swordsman":
                                if (exp>= 1000000) return HIR "�� ��  �� ��" NOR;
                                if (exp>= 800000) return HIY "�� ��  �� ��" NOR;
                                if (exp>= 500000) return HIC "�� ��  �� ��" NOR;
                                if (exp>= 100000 || age >= 18) return YEL "�� ��  �� ��" NOR;
                                return "�� ��  ʿ ��";
                                case "alchemist":
                                        return HIW "�� ��  ʿ ��" NOR;
                                case "shaman":
                                        return HIW "�� ��  ҽ ��" NOR;
                                case "mr":
                                return HIB "�� Ľ������ ��" NOR;
			            case "tiezhang":
                                return HIY "�� ���Ƶ��� ��" NOR;
			        	case "beggar":
                                if (exp>= 2000000) return HIW "�� ��  ؤ ��" NOR;
                                else if (exp>= 1000000 && ob->query("shen") >= 0 ) return HIC "�� ��  ؤ ��" NOR;
                                else if (exp>= 1000000 && ob->query("shen") < 0 ) return HIR "�� ��  ؤ ��" NOR;
                                else if (exp>= 600000) return HIC "�� ��  �� ��" NOR;
                                else if (exp>= 200000) return CYN "�� ��  ͷ ��" NOR;
                                else if ( age >= 18)  return CYN "�� �л��� ��" NOR; 
                                else return "�� С��ؤ ��";
                                case "eunach":
                                        budd = ob->query_skill("pixie-jian",1);
                                        if (budd >= 110)
                                                return HIY "�����ڸ��֡�" NOR;
                                        else if (budd >= 100)
                                                return HIY "�������򻧡�" NOR;
                                        else if (budd >= 90)
                                                return HIY "������ǧ����" NOR;
                                        else if (budd >= 80)
                                                return HIY "�������ٻ���" NOR;
                                        else if (budd >= 70)
                                                return HIY "������ʮ����" NOR;
                                        else if (budd >= 60)
                                                return HIY "������������" NOR;
                                        else return HIW "�� ��  �� ��" NOR;
                                case "prostitute":
                                        return HIM "�� ��  �� ��" NOR;
                                default:
                        if (shen >= 1000000) return HIC "������������" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIC "������������" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIG "���������ܡ�" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIY "���������㡿" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return CYN "��С�����塿" NOR;
                        else if (shen <= -1000000) return HIR "��������ħ��" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return RED "������ħ����" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return HIG "�����һ����" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIY "������Զ�" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return BLU "��С�ж�����" NOR;
                        else
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "�� ɱ��ħ ��" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "�� ��  �� ��" NOR;
                                        if (age < 18) return HIC"��������꡿"NOR;
                                        else if (age < 30) return HIG"��������ӡ�"NOR;
                                        else if (age < 50) return HIB"�����ֺ��ܡ�"NOR;
                                        else
                                            return HIM "���������ܡ�" NOR;
                                }
                        if (shen >= 1000000) return HIC "������������" NOR;
                        else if (shen >= 100000 && exp >=800000)
                                return HIC "������������" NOR;
                        else if (shen >= 10000 && exp >=400000)
                                return HIG "���������ܡ�" NOR;
                        else if (shen >= 1000 && exp >=200000)
                                return HIY "���������㡿" NOR;
                        else if (shen >= 100 && exp >=50000)
                                return CYN "��С�����塿" NOR;
                        else if (shen <= -1000000) return HIR "��������ħ��" NOR;
                        else if (shen <= -100000 && exp >=800000)
                                return RED "������ħ����" NOR;
                        else if (shen <= -10000 && exp >=400000)
                                return HIG "�����һ����" NOR;
                        else if (shen <= -1000 && exp >=200000)
                                return HIY "������Զ�" NOR;
                        else if (shen <= -100 && exp >=50000)
                                return BLU "��С�ж�����" NOR;
                        else
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return HIR "�� ɱ��ħ ��" NOR;
                        if ((int)ob->query("thief") > 10 )
                                return HIC "�� ��  �� ��" NOR;
                }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

	if(ob->query("race") != "����") return ob->name();

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ̫";
                                else return "ʦ̫";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С�ɹ�";
                                else return "�ɹ�";
                                break;
                        default:
                                if( age < 18 ) return "С����";
                                else if( age < 30 ) return "����";
                                else if( age < 40 ) return "����";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ��";
                                else return "��ʦ";
                                break;
                        case "taoist":
                                if( age < 18 ) return "����";
                                else return "����";
                                break;
                        case "scholar":
                                if( age < 18 ) return "С�๫";
                                else if( age < 50 ) return "�๫";
                                else return "������";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "С�ϵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ǰ��";
                                break;
                        default:
                                if( age < 20 ) return "С�ֵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ү��";
                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "С����";
                                if( age < 30 ) return "����";
                                else return "������";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С��Ů";
                                if( age < 30 ) return "��Ů";
                                else return "������";
                                break;
                        default:
                                if( age < 18 ) return "С��Ƥ";
                                if( age < 25 ) return "С����";
                                if( age < 40 ) return "������";
                                else return "����̫��";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "С��ͺ";
                                if( age < 50 ) return "��ͺ¿";
                                else return "��ͺ¿";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С��ë";
                                if( age < 30 ) return "��ţ����";
                                else return "����ë";
                                break;
                        case "scholar":
                                if( age < 18 ) return "С�����";
                                else if( age < 50 ) return "�������";
                                else return "��ͯ��";
                                break;
                        default:
                                if( age < 20 ) return "С���˵�";
                                if( age < 30 ) return "ֱ����";
                                if( age < 50 ) return "����";
                                if( age < 80 ) return "��ƥ��";
                                else return "�ϲ���";
                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        case "taoist":
                                return "ƶ��";
                                break;
                        default:
                                if( age < 20 ) return "СŮ��";
                                if( age > 50 ) return "����";
                                else return "���";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "С��";
                                if( age < 40 ) return "ƶɮ";
                                else return "����";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С��";
                                if( age < 30 ) return "ƶ��";
                                else return "�ϵ�";
                                break;
                        case "scholar":
                                if( age < 30 ) return "����";
                                else return "����";
                                break;
                        default:
                                if( age < 50 ) return "����";
                                else return "��ͷ��";
                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        case "taoist":
                                return "���ɹ�";
                                break;
                        default:
                                if( age < 20 ) return "������";
                                if( age < 30 ) return "��������";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "�������";
                                else return "�Ϻ�����";
                                break;
                        case "taoist":
                                if( age < 30 ) return "��ɽ��";
                                return "�ϵ���";
                                break;
                        case "scholar":
                                if( age < 50 ) return "���๫";
                                else return "�Ϸ�����";
                                break;
                        default:
                                if( age < 20 ) return "����ү��";
                                if( age < 40 ) return "��ү��";
                                else return "����";
                                break;
                        }
        }
}
string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (ob->query("gender")) {
        case "Ů��" :

                if (a2 - a1 >= 24) return "�ù�";
                else if (a1 - a2 >= 24) return "ֶŮ";
                else if (a1 >= a2) return "����";
                else  return "���";
                break;
        default :
                if (a2 - a1 >= 24) return "����";
                else if (a1 - a2 >= 24) return "��ֶ";
                else if (a1 >= a2) return "�͵�";
                else  return "���";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (this_player()->query("gender")) {
        case "Ů��" :
                if (a1 - a2 >= 24) return "�ù���";
                else if (a2 - a1 >= 24) return "ֶŮ��";
                else if (a1 >= a2) return "�����";
                else return "С����";
                break;
        default :
                if (a1 - a2 >= 240) return "������";
                else if (a2 - a1 >= 240) return "Сֶ��";
                else if (a1 >= a2) return "������";
                else return "С����";
        }
}

