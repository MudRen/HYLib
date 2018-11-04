// Last Modified by Winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/daku.c

#include "da.h"
#include "ansi.h"
inherit NPC;
inherit F_MASTER;
string ask_me();
int do_zhongcai(string arg);

void create()
{
	set_name("����ʦ", ({ "daku dashi", "daku", "dashi"}));
	set("long",
		"����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 12000);
	set("max_jing", 11200);
	set("neili", 13000);
	set("max_neili", 13000);
	set("jiali",200);
	set("combat_exp", 8000000);
	set("score", 5000);
	set_skill("zhanzhuang-gong", 220);
	set_skill("shaolin-cuff", 220);
	set_skill("shaolin-leg", 220);
	set_skill("yiwei-dujiang", 220);
	set_skill("boluomi-hand", 220);
	set_skill("jingang-strike", 220);
	set_skill("wuxiang-finger", 220);
	set_skill("ruying-leg", 280);
	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 150);
	set_skill("force", 150);
	set_skill("yijinjing", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 220);
// basic skill begin
	set_skill("hunyuan-yiqi", 220);
	set_skill("luohan-quan", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("ranmu-daofa", 220);
	set_skill("weituo-gun", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("banruo-zhang", 220);
// basic skill end
// �޺�ȭ
	set_skill("cuff", 150);
	set_skill("jingang-quan", 220);
	set_skill("whip", 150);
	set_skill("riyue-bian", 220);
	set_skill("riyue-bian", 220);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("whip", "riyue-bian");
	map_skill("parry", "riyue-bian");

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 660);
	set_temp("apply/armor", 660);

	

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
  map_skill("parry","ruying-leg");
  map_skill("unarmed","ruying-leg");
  map_skill("leg","ruying-leg");
	prepare_skill("leg", "ruying-leg");
	
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({		
		 (: perform_action, "leg.ruying" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("��������", 19, "ɮ��");
	set("inquiry", 
	([
		"��ֵ" : (: ask_me :),
	]));
	setup();
	carry_object(__DIR__"whip")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	add_action("do_lunzhi","lunzhi");
	add_action("do_zhongcai","zhongcai");
}
string ask_me()
{
	mapping fam; 
	object me;
	object ob;
	ob=this_player();
	me=this_object();
	if(!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��������")
		return RANK_D->query_respect(ob)+"���㲻�Ǳ��µ��ӣ�������ֵ��";
	if((string)ob->query("class")!="bonze")
		return ("�׼ҵ��Ӳ�����ֵ��");

	if(me->query_temp("lunzhi"))
		return ("������������ֵ�ˣ���͵���һ�ΰɡ�\n");
	me->set("lunzhi_name",ob->query("name"));
	me->set_temp("lunzhi",1);
	ob->set_temp("lunzhi",1);
	ob=new(__DIR__"obj/lunzhi-ling");
	ob->move(this_player());
	write("����ʦ����һ����ֵ�\n");
	return "�ðɣ���͵�ӭ��ͤ�������ͨ�ɣ���ֵʱӦ��С�ķ�������ֹ���͵�����С�";
}
int do_lunzhi(string arg)
{
	object ob,me;
	int i1,i2;
	ob=this_player();
	me=this_object();
	if(!(arg)) return 0;
	if(!(arg=="ok")) return 0;
	if(!ob->query_temp("lunzhi")) return 0;
	if(!ob->query_temp("lunzhied")) return 0;
	if(ob->query("name")==me->query("lunzhi_name")) 
	{
		if (interactive(ob) && (int)ob->query_condition("sl_lunzhi"))
		{
			command("angry"+ob->query("id"));
			command("slap"+ob->query("id"));
			return notify_fail( "����ʦ��ŭ����"RED"��͵��������ҹ���ȥ��\n"NOR);
		}
		command("pat "+ob->query("id"));
		command("say ����������Ϊ���ˣ�"+RANK_D->query_respect(ob)+"���ɵúã�");
		i1=(int)(ob->query_skill("buddhism",1)/12);
		i2=(int)(ob->query_skill("buddhism",1)/10);
		if (i1>80) i1=80;
		if (i2>120) i2=120;	
		ob->add("potential",i1+50);
		ob->add("combat_exp",i2+60);
		me->delete("lunzhi_name");
		me->delete_temp("lunzhi");
		ob->delete_temp("lunzhi");
		ob->delete_temp("lunzhied");
		return 1;
	}
	return notify_fail("����ʦ������˵���ұ�ɱ�ˣ�����ֵ�ļ�¼û���ˣ�\n");
}

int do_zhongcai(string arg)
{
	int i1,i2;
	object ob=this_player(), me=this_object();

	if(!arg || arg != "ok") return 0;
	if(!ob->query_temp("mark/����")) return 0;
	{
		command("pat "+ob->query("id"));
		command("say �����ˣ�");
		i1=(int)(ob->query_skill("buddhism",1)/12);
		i2=(int)(ob->query_skill("buddhism",1)/10);
		if (i1>80) i1=80;
		if (i2>100) i2=100;	
		ob->add("potential",i1+20);
		ob->add("combat_exp",i2+50);
		ob->delete_temp("job_name");
		ob->delete_temp("mark/����");
		return 1;
	}
	return notify_fail("�����ʵ�����ղŽ�ȥ���̷����ˣ�\n");
}

