// yayi.c  �ٸ�����
inherit NPC;

void create()
{
	set_name("����", ({ "ya yi", "ya" }));
	set("gender", "����");
	set("age", 25);

	set("long", "һ���ߴ����͵ĺ��ӣ���Ϊ���ڹٸ����£������Ѿ�ĥ���ú��ޱ��顣\n");
        set("no_quest",1);
        set("no_bark",1);
	set("combat_exp", 17500);
	set("shen_type", 1);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
	setup();
	carry_object("/d/city/npc/obj/yayifu")->wear();
}
	
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && living(this_object()) &&
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
}
