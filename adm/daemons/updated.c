// updated.c
#include <ansi.h>;
void create() { seteuid(getuid()); }

void check_user(object ob)
{
	int v1, i, level; 
	mapping my, skill_status;
	string *sname, m;
	float exper;
	string name,id,or,type,time;
	int value,make,lv,money_limit;

	my = ob->query_entire_dbase();

	if( (v1=ob->query_skill("xingxiu-duzhang", 1)) > 0 )
	{
		ob->set_skill("chousui-zhang", v1);
		ob->map_skill("unarmed", "chousui-zhang");
		ob->delete_skill("xingxiu-duzhang");
	}

	if( (v1=ob->query_skill("mizong-xinfa", 1)) > 0 )
	{
		ob->set_skill("lamaism", v1);
		ob->delete_skill("mizong-xinfa");
	}
	if( ob->query("family/generation")==0)
		ob->delete("family");
	if( ob->query("gender")=="����")
		ob->set("class", "eunach");
	if( ob->query("new_mail") == 1 )
	{
		tell_object(ob, HIG "�����ʲ��ܲ������ݸ���һ���ţ�ת������ˡ�\n" NOR );
//		write(GRN+"\n�����ʲ���������˵�������˼����������ţ�\n\n"+NOR);
		ob->set("new_mail", 0);
	}
	if( ob->query("linji/jing") )
	{
		ob->apply_condition("linji_daxiao", 1);
	}
	if( ob->query("linji/per") )
	{
		ob->apply_condition("linji_tiandi", 1);
	}
	if( ob->query("linji/dex") )
	{
		ob->apply_condition("linji_fengyun", 1);
	}
	if( ob->query("linji/con") )
	{
		ob->apply_condition("linji_longhe", 1);
	}
	if( ob->query("linji/int") )
	{
		ob->apply_condition("linji_zhixin", 1);
	}

//	if (!wizardp(ob))
//	ob->set("channels", ({ "chat", "rumor", "party", "xkx", "sing" }) );

	if (ob->query("age")==14) money_limit = 100;
	if (ob->query("age")>14) money_limit = 100 + (ob->query("age")-15) * 20;
	if (ob->query("age")>20) money_limit = 200 + (ob->query("age")-20) * 20;
	if (ob->query("age")>30) money_limit = 400 + (ob->query("age")-30) * 30;
	if (ob->query("age")>40) money_limit = 800 + (ob->query("age")-40) * 40;
	money_limit = money_limit*10000;

	if (ob->query("balance") > money_limit)
	{
		ob->set("old_balance",ob->query("balance"));
		ob->set("balance",money_limit);
	}

	if( (ob->query("weapon/����")==1) )
	{
		name = ob->query("weapon/����");
		id = ob->query("weapon/����");
		or = ob->query("weapon/ԭ��");
		type=ob->query("weapon/����");
		time=ob->query("weapon/ʱ��");
		value=ob->query("weapon/ֵ");
		lv = ob->query("weapon/�ȼ�");
		ob->delete("weapon");
		ob->set("weapon/make",1);
		ob->set("weapon/name",name);
		ob->set("weapon/id",id);
		ob->set("weapon/or",or);
		ob->set("weapon/type",type);
		ob->set("weapon/value",value);
		ob->set("weapon/lv",lv);
		ob->set("weapon/time",time);
	}

/*
	if( (v1=ob->query_skill("unarmed", 1)) > 0 && my["family/family_name"] == "��ɽ��")
	{
		ob->set_skill("strike", v1);
		if( stringp(m=ob->query_skill_mapped("unarmed")) )
			ob->map_skill("strike", "hunyuan-zhang");
		ob->delete_skill("huashan-zhangfa");
		ob->delete_skill("unarmed");
	}
*/
	if (wizardp(ob)) return;

	if( undefinedp(my["eff_jing"]) ) my["eff_jing"] = my["max_jing"];
	if( undefinedp(my["eff_qi"]) ) my["eff_qi"] = my["max_qi"];
	if( my["eff_jing"] > my["max_jing"] ) my["eff_jing"] = my["max_jing"];
	if( my["eff_qi"] > my["max_qi"] ) my["eff_qi"] = my["max_qi"];
	if( my["jing"] > my["eff_jing"] ) my["jing"] = my["eff_jing"];
	if( my["jing"] > my["eff_jing"] ) my["jing"] = my["eff_jing"];
//	if( my["max_neili"] > ob->query_skill("force",1)*20 ) my["max_neili"] = ob->query_skill("force")*10;
	if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];

	exper = to_float(ob->query("combat_exp"));

	if ( !(skill_status = ob->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper 
//		&& exper > 100.0
		&& sname[i] != "buddhism"
		&& sname[i] != "mahayana"
		&& sname[i] != "lamaism"
		&& sname[i] != "literate"
		&& sname[i] != "taoism" 
		&& sname[i] != "qimen-wuxing" 
		&& sname[i] != "poison" ) 
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			ob->set_skill(sname[i], level);
		}
	}
}
