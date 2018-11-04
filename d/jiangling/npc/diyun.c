//Edited by fandog, 02/13/2000

inherit NPC;
string ask_me();

void create ()
{
	object weapon;
	set_name("����", ({"di yun","di"}));
	set("long", "��������ڣ�ȧ��΢�ߣ����ִ�ţ������������³�����ׯ�ں��ӡ�\n");
	set("gender", "����");
	set("age", 24);

	set("combat_exp", 20000000);
	set("str", 125);
	set("int", 125);
	set("con", 125);
	set("dex", 125);
	set("per", 26);
	set_skill("force", 320);
	set_skill("dodge", 320);
	set_skill("sword", 220);
	set_skill("parry", 320);
	set_skill("feixian-steps", 320);
	set("max_qi",20000);
	set("max_jing",20000);
	set("max_neili",30000);
	set("qi",20000);
	set("jing",20000);
	set("neili",30000);

	set_skill("liancheng-jian", 320);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.gan" :),
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.qu" :),
                (: perform_action, "sword.zhai" :),
                (: perform_action, "sword.zhu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
        
        }) );
 

	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("blade", 300);
	set_skill("feixian-steps", 300);
	set_skill("shenzhao-jing", 300);
	set_skill("xue-dao", 300);
	map_skill("force", "shenzhao-jing");
	map_skill("blade", "xue-dao");
	map_skill("parry", "xue-dao");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "feixian-steps");
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");  
	set("inquiry", ([
		"ˮ��" : (: ask_me :),
	]));
	set("wucan_count", 1);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	if (clonep())
	{
		weapon = new( __DIR__"xblade" );	
		if ( weapon->violate_unique() )
		{
			destruct( weapon );
			weapon = new( "/clone/weapon/changjian" );
		}
		weapon->move(this_object());
		weapon->wield();
	}
} 

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (query("wucan_count") < 1)
		return "ˮ�Ϲ������ѩ������ң�";

	add("wucan_count", -1);
	this_player()->set_temp("marks/wucan", 1);
	return "ˮ�Ϲ������ѩ������ң�����ʲô�����Ӹ���ô��";
}
int accept_object(object who, object ob)
{
	object obj;
	if (ob->query("id") != "da chang")
		return notify_fail("�����ⶫ����ʲô�ã�");
	message_vision("����Ц��˵������лл�㣡��λ" + RANK_D->query_respect(ob) +"���������ˡ���\n", who);
	if (!who->query_temp("marks/wucan"))
	{
		return 1;
	}
	obj = new(__DIR__"wucanyi");
	this_player()->delete_temp("marks/wucan");
	if ( obj->violate_unique() || uptime() < 300)
	{
		destruct( obj );
		return 1;
	}
	message_vision("���ƶ�$N˵����������ڲ���Ҳ������ʲô�������ı�����ɣ������ƴӻ����ͳ�һ�Ų����۵Ķ������ݵ�$N�����ϡ�\n", who);
	obj->move(this_player());
	return 1;
}
