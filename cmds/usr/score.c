// score.c
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

string bar_string = "��������������������������������������������������";
string blank_string = "��������������������������������������������������";
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob, obt;
	mapping my;
	string line, str, skill_type,zs,zs1,zs2;
	object weapon;
        int attack_points, dodge_points, parry_points, btmp, t, d, r,money,i,zs3,zs4;
        int a,b,c;
	seteuid(getuid(me));
        btmp=1;
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
                obt = find_player(arg);
                if ( !obt ) btmp=0;
                if (!ob) ob = obt;
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
        my = ob->query_entire_dbase();

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
	if( ob->query("mud_age") > 86400){
	t = ob->query("t");
	d = ob->query("d");
	r = ob->query("r");
	}
write(HIC"��"+HIY"��������������������������������������������������������������"HIC"��\n"NOR);
write(NOR+RANK_D->query_rank(ob)+""+ob->short(1)+"\n");
write(HIY"����������������������������������������������������������������\n"NOR);
write(HIW"��"HIM"����"HIW"��"HIY+chinese_number(ob->query("age"))+"��"+chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200 + 1 )+"��"+"\n");
write(HIW"��"HIM"����"HIW"��"HIY+CHINESE_D->chinese_date((ob->query("birthday") - 14*365*24*60) * 60-890000000)+"\n");
write(HIW"��"HIM"�Ա�"HIW"��"HIY+ob->query("gender")+"\n");
 if( ob->query("couple/couple_name") ){
write(HIW"��"HIM"����"HIW"��"HIY+ob->query("couple/couple_name")+"\n");
	}
else write(HIW"��"HIM"����"HIW"��"HIY+"��\n");
	if( mapp(my["family"]) ) {
		if( my["family"]["master_name"] ){
write(HIW"��"HIM"ʦ��"HIW"��"HIY+my["family"]["master_name"]+"\n");
		}
else write(HIW"��"HIM"ʦ��"HIW"��"HIY+"��\n");
	}
if( mapp(my["family"]) ) {
		if( my["family"]["family_name"] ){
write(HIW"��"HIM"ʦ��"HIW"��"HIY+my["family"]["family_name"]+"");
write(HIW"��"HIM"ʦ�Ź���"HIW"��"HIY+chinese_number(my["mpgx"])+"\n");
		}
else write(HIW"��"HIM"ʦ��"HIW"��"HIY+"��\n");
}
       
zs="��";
zs1="��";
zs2="";
if (ob->query("zhuanshen"))
zs="һת";
if (ob->query("guard/flag"))
zs="��ת";
if (ob->query("zhuanbest"))
zs="��ת";
if (ob->query("4zhuan"))
zs="��ת";
if (ob->query("5zhuan"))
zs="��ת";
if (ob->query("zhuanfinal/7"))
zs1="������ʮ�����졿";
if (ob->query("zhuanfinal/8"))
zs1=zs1+" �������񹦡�";
if (ob->query("zhuanfinal/1"))
zs2="��Ԫ�����";
if (ob->query("zhuanfinal/2"))
zs2=zs2+" ����Ӱ���١�";
if (ob->query("zhuanfinal/3"))
zs2=zs2+" ����ħ����";
if (ob->query("zhuanfinal/4"))
zs2=zs2+" �����ǲ���";
if (ob->query("zhuanfinal/5"))
zs2=zs2+" ����Ԫ�󷨡�";
if (ob->query("zhuanfinal/6"))
zs2=zs2+" ����ʿ��˫��";
zs3=6000000+(ob->query("expmax",1)*500000);
zs4=ob->query_temp("menpaijob",1);
write(HIW"��"HIM"ת��"HIW"��"HIY+zs+"");
if (!ob->query("4zhuan"))
{
write("\n");


}
if (ob->query("4zhuan"))
{
write(HIW"��"HIM"��������"HIW"��"HIY+zs4+"");write(HIW"��"HIM"�书����"HIW"��"HIY+zs3+"\n");
write(HIW"��"HIM"ת���书"HIW"��"HIY+zs1+"\n");
write(HIW"��"HIM"ת����"HIW"��"HIY+zs2+"\n");


}
write(HIY"����������������������������������������������������������������\n"NOR);
write(HIW"��"HIM"����"HIW"��"HIY+display_attr(my["str"], ob->query_str())+HIW"��"HIM"��������"HIW"��"NOR+HIC+"(+"+ob->query_temp("apply/damage")+")\n"NOR);
write(HIW"��"HIM"����"HIW"��"HIY+display_attr(my["int"], ob->query_int())+HIW"��"HIM"���߷���"HIW"��"NOR+HIC+"(+"+ob->query_temp("apply/armor")+")\n"NOR);
write(HIW"��"HIM"����"HIW"��"HIY+display_attr(my["con"], ob->query_con())+HIW"��"HIM"ɱ������"HIW"��"NOR+HIR+chinese_number(my["MKS"] + my["PKS"])+NOR+"\n"NOR);
write(HIW"��"HIM"��"HIW"��"HIY+display_attr(my["dex"], ob->query_dex())+HIW"��"HIM"ɱ�����"HIW"��"NOR+HIR+chinese_number(my["PKS"])+NOR+"\n"NOR);
if (wizardp(me))
{
write(HIW"��"HIM"��Ե"HIW"��"HIY+display_attr(my["kar"], ob->query_kar())+HIW"��"HIM"��������"HIW"��"NOR+HIR+chinese_number(my["dietimes"])+"\n"NOR);
}
else write(HIW"��"HIM"��Ե"HIW"��"HIY+"???"+HIW"��"HIM"��������"HIW"��"NOR+HIR+chinese_number(my["dietimes"])+"\n"NOR);
if (wizardp(me))
{
write(HIW"��"HIM"��ò"HIW"��"HIY+display_attr(my["per"], ob->query_per())+HIW"��"HIM"��������"HIW"��"NOR+HIR+chinese_number(my["dietimes"] - my["normal_die"])+"\n"NOR);
} else write(HIW"��"HIM"��ò"HIW"��"HIY+"???"+HIW"��"HIM"��������"HIW"��"NOR+HIR+chinese_number(my["dietimes"] - my["normal_die"])+"\n"NOR);
write(HIY"����������������������������������������������������������������\n"NOR);
write(HIW"��"HIM"����"HIW"��"HIY+tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], HIC) + HIW"��"HIM"��ʦ����"HIW"��"NOR+HIB+chinese_number(ob->query("betrayer"))+NOR+"\n");
write(HIW"��"HIM"��Ѫ"HIW"��"HIY+tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR) + HIW"��"HIM"�������"HIW"��"HIC+chinese_number(ob->query("meili"))+"\n");
write(HIW"��"HIM"��ˮ"HIW"��"HIY+tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN) + HIW"��"HIM"��������"HIW"��"HIC+chinese_number(ob->query("weiwang"))+"\n");
write(HIW"��"HIM"ʳ��"HIW"��"HIY+tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL) + HIW"��"HIM"��������"HIW"��"HIC+ob->query("score")+"\n");
write(HIW"��"HIM"����"HIW"��"NOR+HIY+"/cmds/std/looksj.c"->getatt(ob,1)+NOR+"\n");
write(HIW"��"HIM"����"HIW"��"NOR+HIY+"/cmds/std/looksj.c"->getdef(ob,1)+NOR+"\n");
write(HIW"��"HIM"����"HIW"��"NOR+HIY+"/cmds/std/looksj.c"->getdog(ob,1)+NOR+"\n");
if (wizardp(me))write(HIW"��"HIM"������"HIW"��"NOR+HIC+attack_points/100 + 1+"(+"+ob->query_temp("apply/damage")+")\n"NOR);
if (wizardp(me))write(HIW"��"HIM"������"HIW"��"NOR+HIC+(dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1+"(+"+ob->query_temp("apply/armor")+")\n"NOR);
write(HIY"����������������������������������������������������������������\n"NOR);
write(HIW"��"HIM"��������"HIW"��"NOR+RED+ob->query("shen")+NOR"\n");
write(HIW"��"HIM"ѧϰǱ��"HIW"��"NOR+HIY+(ob->query("potential") - ob->query("learned_points"))+NOR+"\n");
write(HIW"��"HIM"ʵս����"HIW"��"NOR+HIY+ob->query("combat_exp")+NOR+"\n");
        if( ob->query("killbyname") && ob->query("killbyname")!="������"){
write(HIW"��"HIM"�ϴ�����"HIW"��"HIY+"��"+ob->query("killbyname")+"ɱ��\n");
	}
        if( ob->query("killbyname") && ob->query("killbyname")=="������"){
write(HIW"��"HIM"�ϴ�����"HIW"��"HIY+"������\n");
	}
	if (me->query("age")==14) money = 100;
	if (me->query("age")>14) money = 100 + (me->query("age")-15) * 20;
	if (me->query("age")>20) money = 200 + (me->query("age")-20) * 20;
	if (me->query("age")>30) money = 400 + (me->query("age")-30) * 30;
	if (me->query("age")>40) money = 800 + (me->query("age")-40) * 40;
write(HIW"��"HIM"�������"HIW"��"NOR+HIY+money+HIY+"���ƽ�"+"\n"NOR);
        if( !ob->query("killbyname")){
write(HIW"��"HIM"�ϴ�����"HIW"��"HIY+"��\n");
	}
if (ob->query_temp("temp_exp"))
{
if (ob->query("mud_age") - ob->query_temp("mud_age") > 1)
{
if (ob->query("combat_exp") > ob->query_temp("temp_exp"))
{
if ((i = (ob->query("combat_exp") - ob->query_temp("temp_exp")) * 60
/ (ob->query("mud_age") - ob->query_temp("mud_age"))) > 100)
i = i*60;
write(HIW"��"HIM"�ɳ��ٶ�"HIW"��"HIY+i+"/Сʱ\n");
}
}
}
if (me->query_temp("apply/strength") > 800)
me->set_temp("apply/strength",800);
if (me->query_temp("apply/intelligence") > 800)
me->set_temp("apply/intelligence",800);
if (me->query_temp("apply/constitution") > 800)
me->set_temp("apply/constitution",800);
if (me->query_temp("apply/dexerity") > 800)
me->set_temp("apply/dexerity",800);
if (me->query_temp("apply/attack") > 800)
me->set_temp("apply/attack",800);
if (me->query_temp("apply/defense") > 800)
me->set("apply/defense",800);
if (me->query_temp("apply/damage") > 4000)
me->set_temp("apply/damage",4000);
if (me->query_temp("apply/armor") > 4000)
me->set_temp("apply/armor",4000);
if (me->query_temp("apply/dodge") > 800)
me->set_temp("apply/dodge",800);

write(HIC"��"+HIY"�������������������������������������������� �� II����������"HIC"��\n"NOR);
	return 1;
        
}
string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d" NOR, value );
	else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
	else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}
string tribar_graph(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*10/max)*2-1]
		+ ((eff > val) ? blank_string[(val*10/max)*2..(eff*10/max)*2-1] : "") + NOR;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��

see also : hp
HELP
    );
    return 1;
}
