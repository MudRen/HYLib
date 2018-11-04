// worker.c

inherit NPC;

void create()
{
	set_name("������",({"tangzi shou","shou"}));
        set("shen_type",-1);
        set("gender", "����" );
        set("age", 52);
        set("combat_exp", 20000);
        set("attitude", "heroism");
        set_skill("unarmed", 80);
        set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("blade",80);
	setup();
	add_money("silver", 2);
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
        
}
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
message_vision("�����ִ�������:����-----����-------\n",ob);
			break;
		case 1:
message_vision("�����ڲ�Ҫ��ʲô�²ź�,ϣ��ƽƽ����,��ȥ��С����.\n",ob);
			break;
                           }
}
