// jingbing.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("Ѳ�ǹٱ�", ({ "xunbing", "bing" }) );
        set("long",
                
"���Ǹ�����ִ�й����Ѱ�ǹٱ�����Ȼ���������������������ٱ�\n"
                
"�ǵ��书ʵ��ϡ��ƽ������������������֯���м��ɵ�սʿ��˭Ҳ��\n"
                "���׵��������ǡ�\n");

        set("attitude", "heroism");
        set("pursuer", 1);    // ׷����  1=yes 0=no
        set("vendetta_mark", "authority");  // �ǳ���=��authority�� (�ٸ�)

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 100000);

        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "Ѱ�ǹٱ��ȵ�������������������־͸���\n",
                "Ѱ�ǹٱ��ȵ����󵨵��񾹸Ҿܲ������ˣ����ˣ�\n"
        }) );

        set_skill("unarmed", 70);
        set_skill("sword", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 100);

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/g_cloth")->wear();
        carry_object(__DIR__"obj/longsword")->wield();
}

 
