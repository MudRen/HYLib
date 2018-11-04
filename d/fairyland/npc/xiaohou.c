// xiaohou.c
// By jpei

inherit NPC;

void wander_about();

void create()
{
        set_name("С��", ({ "xiao hou", "xiao", "hou", "monkey" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻ���Ű�ë��С�\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 100);
    
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
	if (clonep()) call_out("wander_about", 10);
}

void init()
{
	object ob = this_player();

	if (base_name(environment())[<6..] == "shanbi") {
		if ( random(300)) {
			set("get_wound", 1);
			say("һ��С���Ȼ�Ӷ��͵�ɽ����ʧ��������������ȱ�һ��ʯͷѹס�ˣ��������á�\n");
		}
	}
	if (ob->query_temp("help_monkey") && !present("jiuyang zhenjing", ob) && !query("get_wound") && !random(3)) {
		tell_object(ob, "��ֻ��ȹ���С���Ȼ���˹�����֨֨�������и���ͣ��\n");
		tell_object(ob, "˳��������ָ��ȥ��ֻ��һ����ɫ��Գ�����������ʹ�ࡣ\n");
		new("/d/fairyland/npc/dabaiyuan")->move(environment(ob));
		ob->delete_temp("help_monkey");
	}
	else if (!query("get_wound"))
		::init();;
}

int return_home(object home)
{
	if (query("get_wound")) return 1;
	return ::return_home(home);
}

void wander_about()
{
	if (!is_fighting()) {
		if (!query("get_wound")) {
                call_out("dis", 0);
//                  destruct(this_object());
//			random_move();
		}
		else {
			add("get_wound", 1);
			if (query("get_wound") > 15) {
				say("С�﷢��һ�������ĲҽУ�����һ�����ˡ�\n");
				destruct(this_object());
				return;
			}
			say("С�﷢����֨֨���Ĳҽ�����\n");
		}
	}
	call_out("wander_about", 10);
}

void dis()
{
	destruct(this_object());
}
