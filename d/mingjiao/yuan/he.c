#include <ansi.h>


inherit NPC;


void create()
{
        set_name("�ױ���", ({ "hebi weng", "hebi", "weng" }));
	set("gender", "����");
	set("title", HIB"��ڤ����"NOR);
        set("shen_type", -1);
        set("age", 50);
        set("str", 30);
        set("con", 38);
        set("int", 20);
        set("dex", 26);
        set("max_qi", 14400);
        set("max_jing", 12200);
        set("qi", 14400);
        set("jing", 12200);
        set("neili", 15500);
        set("max_neili", 15500);
        set("jiali", 135);
        set("combat_exp", 3200000);

        set_skill("force", 250);
	set_skill("shenlong-xinfa", 380);
        set_skill("dodge", 200);
	set_skill("yixingbu", 380);
        set_skill("hand", 250);
	set_skill("shenlong-bashi", 380);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 380);
        set_skill("parry", 250);
set_skill("claw", 300);
set_skill("strike", 300);
        set_skill("staff", 200);
        set_skill("sword", 200);
        set_skill("zhaosheshu", 380);
        set_skill("yangsheshu", 380);
	set_skill("shedao-qigong", 380);
	set_skill("literate", 200);
	set_skill("dulong-shenzhua", 380);
	set_skill("xuanming-zhang", 380);
        
        set_skill("leg",200);
        set_skill("shenlong-tuifa",380);
        

        map_skill("strike", "xuanming-zhang");
        map_skill("force",  "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
        map_skill("parry",  "dulong-shenzhua");
        map_skill("unarmed",  "dulong-shenzhua");
        map_skill("claw",  "dulong-shenzhua");
	map_skill("hand", "shenlong-bashi");
        prepare_skill("claw", "dulong-shenzhua");

             
        create_family("��ڤ��", 2, "����");



        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({               
                (: perform_action, "claw.bao" :),
                (: perform_action, "claw.ju" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("inquiry", ([
                "���޼�"    :   "�ߣ���С���Ŵλ��Ҵ��£��ҷ�ɱ�������ɣ�\n",
                "����"      :   "��Ѿͷ��ƶ�ˣ��������壬�����ֵ�Ϊ������������\n",
                "�������"  :   "�����Ҷ�ʦ���������ʲô��\n",
                "¹�ȿ�"    :   "������ʦ�֣����Ǵ�С����ʦ��ѧ�գ���ͬ���㡣\n", 
        ]));

        set_temp("apply/attack", 180);
        set_temp("apply/damage", 180);
        set_temp("apply/armor", 180);



        setup();

        carry_object("/clone/cloth/baipao")->wear();
}

void init()
{	
	object ob;

	::init();
	add_action("do_qiecuo","qiecuo");
	add_action("do_killing", "kill");
	add_action("do_killing", "touxi");
	add_action("do_killing", "hit");
	add_action("do_killing", "ansuan");
	add_action("do_killing", "qiangjian");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "����" && !userp(victim))
		{
		message_vision("$N��Цһ������������\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		victim->kill_ob(player);
		return 1;
		}
	}
	return 0;		
}

void greeting(object ob)
{
        object obj;
        if( objectp(obj = present("zhao min", environment(ob))) )
        {
                this_object()->set_leader(obj);
        }
}
