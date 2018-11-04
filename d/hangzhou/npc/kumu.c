//Cracked by Kafei
// /d/hangzhou/npc/kumu.c
// by aln  2 / 98

inherit NPC;
inherit F_MASTER;

string day_event() { return NATURE_D->outdoor_room_event(); }

string ask_job();

void create()
{
	set_name("��ľ��ʦ", ({
		"kumu chanshi",
		"kumu",
		"chanshi",
	}));
	set("long",
		"����Ǳ��µ�ס�֣�һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 650);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 80000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("finger", 70);
	set_skill("nianhua-zhi", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "nianhua-zhi");
	map_skill("finger", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");

        set("inquiry", ([
                "����" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

	setup();

//        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

string ask_job()
{
        object obj, place, *inv, me = this_player();

        if( is_fighting() || is_busy() )
                return "����æ�š�";

//        if( (string)me->query("gender") != "����" )
//                return "�����ӷ����գ����գ�Ůʩ��Ī�����ɵ���Ц��";

        if( (string)me->query("class") != "bonze" )
                return "�����ӷ����գ����գ�ʩ�����Ƿ��ŵ��ӣ�������ذɡ�";

        if( (int)me->query_skill("buddhism", 1) < 120 )
                return "����ֻ�����ɮǰ������˵��";

//        if( day_event() != "event_dawn" )
//                return "����ײ���о�ʱ���ѹ���" + RANK_D->query_respect(me) + "�´������ɡ�";

        if( me->query_condition("lyjob") )
                return RANK_D->query_respect(me) + "�Ѿ��ڽ���˵���ˡ�";
        if( me->query_condition("lyjob2") )
                return RANK_D->query_respect(me) + "�ոս������ˣ���Ϣһ�������ɡ�";

        command("nod");
        me->apply_condition("lyjob", 3 + random(3));

//        if( random((int)me->query_temp("lypoint")) > 1
//        && !(present("jiasha", me)) ) {
//                obj = new(__DIR__"obj/jiasha");
//                obj->move(me);
//                message_vision("�Ա�һɮ��һ��������������$N���ϡ�\n", me);
//        }

        return "̫���ˣ���������һ�����¸�ɮǰ������˵��";
}

