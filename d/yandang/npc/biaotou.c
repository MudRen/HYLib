// biaotou.c �����ܼ�

inherit NPC;

void create()
{
	set_name("��ͷ", ({ "biao tou", "biao" }));
	set("gender", "����");
	set("age", 35);

	set("combat_exp", 50000);
	set("shen_type", 1);

	set_skill("unarmed", 100);
	set_skill("blade", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	::init();
	add_action("do_get","get");
	add_action("do_steal","steal");
}
int do_get(string arg)
{
	object me,obj;
	string from,item;
	me=this_player();
	if(!arg)	return 0;
	if(sscanf(arg, "%s from %s", arg, from)==2)
	{
		if(from=="biaoche"||from=="che"||from=="biao")	{
		command("say ��ǿ��,���컯��֮��,������·���٣�\n");
                      call_out("kill_ob", 1, me); 
		return 1;
		}
	return 0;
  }
return 0;
}
int do_steal(string arg)
{
	object me;
	string from;
	me=this_player();
	if(!arg)	return 0;
	if(sscanf(arg,"%s from %s",arg,from)==2)	{
		if(from=="biaoche"||from=="che"||from=="biao")	{
		command("say �󵨶���,��Ȼ�ϻ���߰�ë,�ҿ����ò��ͷ��ˣ�\n");
        call_out("kill_ob", 1, me); 
return 1;
	}
return 0;
   }
	return 0;
}
	
