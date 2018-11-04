// ����˫����

//weishi.c �����ʿ

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�����ʿ", ({ "wei shi", "shi", "wei" }) );
        set("gender", "����");
        set("age", 35);
        set("long",
"���Ǹ����ʹ����ع��ŵ���ʿ,��������,���øֵ���
��˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
        set("combat_exp", 300000+random(40000));
        set("attitude", "heroism");

        set("str", 30);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("max_mana", 700);
        set("neili", 400);
        set("max_neili", 500);
        set("force_factor", 25);
        set_skill("blade", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);

        setup();

        carry_object("/d/gaoli/obj/gangdao")->wield();
        carry_object("/d/gaoli/obj/armor")->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

int accept_fight(object me)
{
        message_vision("�����ʿ��$N���һ�������ò��ͷ��ˣ��ʹ�ǰҲ�Һ��֣�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

