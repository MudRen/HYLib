// feizei.c
//����(lywin)2000/5/30Ϊһ������ϵͳд��npc

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����",({ "fei zei","fei" }) );
	set("title",HIY"����ݵ�"NOR);
        set("gender", "����" );
        set("age", 33);
        set("long", 
"�����޶����ķ�����������һ��СС�������������ǲ�͵��ʲô�������֡�\n");

	set("int", 30);
	set("str", 30);
	set("con", 30);
	set("dex", 30);
        set("attitude", "aggressive");
        set("shen_type", -1);

	set("qi", 1000+random(5000));
	set("max_qi", 1000+random(5000));
	set("jing", 1000+random(5000));
	set("max_jing", 800+random(5000));
	set("neili", 1800+random(5000));
	set("max_neili", 1800+random(5000));
	set("jiali", 20);
	set("combat_exp", 500000+random(3000000));
	set("score", 15000);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 140);
	set_skill("unarmed",90+random(200));
	set_skill("force", 90+random(200));
	set_skill("dodge", 90+random(200));
	set_skill("parry", 90+random(200));
	set_skill("sword", 100+random(200));
	set_skill("staff", 100+random(200));
	set_skill("literate", 80+random(200));
	set_skill("huashan-zhangfa", 120+random(200));
	set_skill("huashan-shenfa",120+random(200));
	set_skill("huashan-jianfa", 120+random(200));
	set_skill("zixia-shengong", 120+random(200));
	set_skill("shenlong-xinfa", 120+random(200));
	set_skill("shedao-qigong", 120+random(200));

	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.feilong" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
        setup();
        carry_object("clone/cloth/cloth")->wear();
        carry_object( __DIR__ "changjian")->wield();
        carry_object( __DIR__ "lingzhi");
	add_money("gold",1);

}

void init()
{
        remove_call_out("leave");
        call_out("leave",300);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
