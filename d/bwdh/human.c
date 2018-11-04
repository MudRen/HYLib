//Cracked by Kafei
// human.c
// From ES2
// Modified by Xiang@XKX

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
	([      "action":               "$N��ȭ����$n��$l",
		"damage_type":  "����",
	]),
	([      "action":               "$N��$n��$lһץ",
		"damage_type":  "����",
	]),
	([      "action":               "$N��$n��$l�ݺݵ�����һ��",
		"damage_type":  "����",
	]),
	([      "action":               "$N����ȭͷ��$n��$l��ȥ",
		"damage_type":  "����",
	]),
	([      "action":               "$N��׼$n��$l�����ӳ�һȭ",
		"damage_type":  "����",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "λ");
	set("gender", "����");
	set("can_speak", 1);
	set("attitude", "peaceful");

	set("limbs", ({
		"ͷ��", "����", "�ؿ�", "����", "���", "�Ҽ�", "���",
		"�ұ�", "����", "����", "����", "����", "����", "С��", 
		"����", "����", "����", "���", "�ҽ�", "���", "�Ҷ�" 
	}) );

	set("dead_message",           "\n$N���ڵ��ϣ������˼��¾����ˡ�\n\n"      );
	set("unconcious_message",     "\n$N����һ�����ȣ����ڵ��ϻ��˹�ȥ��\n\n"  );
	set("revive_message",         "\n$N���������۾��������˹�����\n\n"        );
//      set("comeout_message_outdoor","�첽��$d�뿪��\n"                          );
//      set("comein_message_outdoor", "�첽���˹�����\n"                          );
//      set("comeout_message_indoor", "��$d���˳�ȥ��\n"                          );
//      set("comein_message_indoor",  "���˹�����\n"                              );
//      set("fleeout_message",        "��$d��Ķ����ˡ�\n"                        );
//      set("fleein_message",         "����ײײ�����˹�����ģ����Щ�Ǳ���\n"      );
}

void setup_human(object ob)
{
	mapping my;
	int xism_age, qi_age, jing_age;
	int lvl, skill1, skill2, skill3, skill4;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if (undefinedp(my["age"])) my["age"] = 14;
	if (undefinedp(my["str"])) my["str"] = 10 + random(21);
	if (undefinedp(my["con"])) my["con"] = 10 + random(21);
	if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
	if (undefinedp(my["int"])) my["int"] = 10 + random(21);
	if (undefinedp(my["per"])) my["per"] = 10 + random(21);
	if (undefinedp(my["kar"])) my["kar"] = 10 + random(21);

	if( userp(ob) || undefinedp(my["max_potential"]) )
		my["max_potential"] = 100 + to_int(sqrt(to_float(my["combat_exp"]))) / 10;

	if( userp(ob) || undefinedp(my["max_jing"]) ) {

		if( my["age"] <= 14 ) my["max_jing"] = 100;
		else if( my["age"] <= 30 )
			my["max_jing"] = 100 + (my["age"] - 14) * (my["int"] + my["con"])/2;
		else my["max_jing"] = (my["int"] + my["con"]) * 8 + 100;

		//jing start drop after 70 years old:
		if( my["age"] > 70 )
		{
			my["max_jing"] -= (my["age"] - 70) * (my["int"] + my["con"])/7;

		// ���ұ�����
			if ( mapp(my["family"]) && (my["family"]["family_name"] == "�䵱��"
			|| my["family"]["family_name"] == "ȫ���")
			&& (lvl = (int)ob->query_skill("taoism", 1)) >= 100 )
				my["max_jing"] += (my["age"] - 70) * lvl/20 ;

		}

		// ���������������ǰ������������󳤾�
		if ( mapp(my["family"]) ) {
			if ( my["family"]["family_name"] == "������" )
				xism_age = (int)ob->query_skill("mahayana", 1);
			else if ( my["family"]["family_name"] == "������" )
				xism_age = (int)ob->query_skill("buddhism", 1);
			else if ( my["family"]["family_name"] == "����μ�" )
				xism_age = (int)ob->query_skill("buddhism", 1);
			else if ( my["family"]["family_name"] == "ѩɽ��" || my["family"]["family_name"] == "Ѫ����" )
				xism_age = (int)ob->query_skill("lamaism", 1);
		}
		else xism_age = 0;

		if(xism_age > 39) {
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;
			
			skill1 = ob->query_skill("hunyuan-yiqi",1);
			skill2 = ob->query_skill("linji-zhuang",1);
			skill3 = ob->query_skill("longxiang-banruo",1);
			skill4 = ob->query_skill("kurong-changong", 1);
			if (xism_age > 0) {
				skill1 = xism_age * (skill1/10);
				skill2 = xism_age * (skill2/10);
				skill3 = xism_age * (skill3/10);
				skill4 = xism_age * (skill4/10);
				if ( my["family"]["family_name"] == "������" )
					my["max_jing"] += skill1;
				else if ( my["family"]["family_name"] == "������" )
					my["max_jing"] += skill2;
				else if ( my["family"]["family_name"] == "����μ�" )
					my["max_jing"] += skill4;
				else
					my["max_jing"] += skill3;
			} 
		}

		// ��ɲ���꣺ÿ��һ�Σ�ؤ�ﾫ������ֵ
		if( mapp(my["family"]) && my["family"]["family_name"] == "ؤ��" )
			my["max_jing"] += my["con"] * my["death_times"];

		// ��ɽ�������������ǰ������������󳤾�
		if( mapp(my["family"]) && my["family"]["family_name"] == "��ɽ��"
		&& (jing_age =(int)ob->query_skill("ziyin-yin", 1)) > 39 )
		{
			jing_age = jing_age/2;
			if (my["age"] <= 30) jing_age -= my["age"];
			else jing_age -= 30;

			skill1 = (int)ob->query_skill("zixia-gong",1);

			if ( jing_age > 0 && ob->query("huashan/yin-jue") > 1 )
			      my["max_jing"] += jing_age * (skill1/10);
			if ( jing_age > 0 )
				my["max_jing"] += jing_age * (skill1/15);
		}

		if( my["eff_jingli"] > 0 ) my["max_jing"] += my["eff_jingli"] / 4;
	}
	if( userp(ob) || undefinedp(my["max_qi"]) ) {
		
		if( my["age"] <= 14 ) my["max_qi"] = 100;
		else if( my["age"] <= 30 )
			my["max_qi"] = 100 + (my["age"] - 14) * (my["con"] + my["str"])/2;
		else my["max_qi"] = 100 + (my["con"] + my["str"]) * 8;
			
		// drop qi after 70 years old:          
		if( my["age"] > 70 ) 
		{
			my["max_qi"] -= (my["age"] - 70) * (my["con"] + my["str"])/7;
		
		// ��ұ�����
			if ( mapp(my["family"]) ) {
			   if ( my["family"]["family_name"] == "������" )
				lvl = (int)ob->query_skill("buddhism", 1);
			   else if ( my["family"]["family_name"] == "������" )
				lvl = (int)ob->query_skill("mahayana", 1);
			    else if ( my["family"]["family_name"] == "����μ�" )
				lvl = (int)ob->query_skill("buddhism", 1);
				else if ( my["family"]["family_name"] == "ѩɽ��"
				|| my["family"]["family_name"] == "Ѫ����" )
				lvl = (int)ob->query_skill("lamaism", 1);
		}

		if(lvl >= 100)
			my["max_qi"] += (my["age"] - 70) * lvl/20;
		}

		// ����������������ǰ���������������
		if ( mapp(my["family"]) && my["family"]["family_name"] == "�䵱��"
		&& (xism_age=(int)ob->query_skill("taoism", 1)) > 39 )
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			skill1 = ob->query_skill("force");

			if (xism_age > 0 )
				my["max_qi"] += xism_age * (skill1/10);
		}

		if ( mapp(my["family"]) && my["family"]["family_name"] == "ȫ���"
		&& (xism_age=(int)ob->query_skill("taoism", 1)) > 39 )
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;

			skill1 = ob->query_skill("force");

			if (xism_age > 0 )
				my["max_qi"] += xism_age * (skill1/10);
		}

		// ���޾۶�������������ǰ���������������
		  if ( mapp(my["family"]) && my["family"]["family_name"] == "������"
		  && (xism_age=(int)ob->query_skill("poison", 1)) > 39 )
		  {
			  xism_age = xism_age/2;
			  if (my["age"] <= 30) xism_age -= my["age"];
			  else xism_age -= 30;

			  skill1 = (int)ob->query_skill("huagong-dafa",1);

			  if (xism_age > 0 )
				  my["max_qi"] += xism_age * (skill1/10);
		  }

		// ��ħ���壺ÿ��һ�Σ�ؤ����������ֵ֮��
		if( mapp(my["family"]) && my["family"]["family_name"] == "ؤ��" )
			my["max_qi"] += my["con"] * my["death_times"];

		// ��ɽ��������������ǰ���������������
		if( mapp(my["family"]) && my["family"]["family_name"] == "��ɽ��"
		&& (qi_age =(int)ob->query_skill("zhengqi-jue", 1)) > 39 )
		{
			qi_age = qi_age/2;
			if (my["age"] <= 30) qi_age -= my["age"];
			else qi_age -= 30;

			skill1 = (int)ob->query_skill("zixia-gong",1);

			if ( qi_age > 0 && ob->query("huashan/yin-jue") > 1 )
				my["max_qi"] += qi_age * (skill1/10);
			else if ( qi_age > 0 )
				my["max_qi"] += qi_age * (skill1/15);
		}

		// �һ������Ŷܼף�������ǰ���������������
			if ( mapp(my["family"]) && my["family"]["family_name"] == "�һ���"
			&& (xism_age=(int)ob->query_skill("qimen-dunjia", 1)) > 39 )
			{
				xism_age = xism_age/2;
				if (my["age"] <= 30) xism_age -= my["age"];
				else xism_age -= 30;

			skill1 = (int)ob->query_skill("bitao-xuangong",1);

			if (xism_age > 0 )
			my["max_qi"] += xism_age * (skill1/10);
			  }

		if( my["max_neili"] > 0 ) my["max_qi"] += my["max_neili"] / 4;
	}

	if( userp(ob) || undefinedp(my["max_jingli"]) ) {

		if( my["age"] <= 14 ) my["max_jingli"] = 100;
		else if( my["age"] <= my["con"] )
		my["max_jingli"] = 100 + (my["age"] - 14) * (my["str"] + my["dex"]);
		else my["max_jingli"] = 100 + (my["str"] + my["dex"]) * (my["con"] - 14);

		// drop jingli after 70 years old:
		if( my["age"] > 70 ) 
			my["max_jingli"] -= (my["age"] - 70) * my["con"]/5;

		if( !userp(ob)
		 && (my["max_jingli"] < my["max_qi"] || my["max_jingli"] < my["max_jing"]) )
			my["max_jingli"] = my["max_qi"] > my["max_jing"] ? my["max_qi"] : my["max_jing"];

		if( userp(ob) && my["max_jingli"] < 100 ) my["max_jingli"] = 100;

		if( my["eff_jingli"] > 0 ) my["max_jingli"] += my["eff_jingli"];
		if( (int)ob->query_skill("force") > (int)ob->query_skill("force", 1) 
		 && my["eff_jingli"] > (int)ob->query_skill("force") * ob->query("con") / 2 ) {
			my["eff_jingli"] = (int)ob->query_skill("force") * ob->query("con") / 2;
			my["max_jingli"] = (int)ob->query_skill("force") * ob->query("con") / 2;
		}

		if( ob->is_character() && !userp(ob) && my["max_jingli"] <= 0)
			my["max_jingli"] = 100 + my["age"] * 5;
	
	}
	if (undefinedp(my["max_jingli"]))
		my["max_jingli"] = 1;
	if (undefinedp(my["max_neili"]))
		my["max_neili"] = 1;

	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
