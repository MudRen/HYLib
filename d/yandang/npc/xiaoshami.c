// music   yangzhou's ��С��

inherit NPC;
void create()
{
	set_name("Сɳ��",({"xiao shami","xiao","shami"}));
	set("gender", "����" );
	set("age",10);
	set("long",
	"ͷð����Ĵ���С���С�\n");
	set("mingwang",1);
	set("combat_exp",150);
	set("attitude", "friendly");
	setup();
	carry_object(__DIR__"obj/hui_jiasha.c")->wear();
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
	say("Сɳ�ֺ���:��~��~��~����\n");
			break;
		case 1:
	say("Сɳ��һƨ����������:������.....��\n");
			break;
                           }
}
