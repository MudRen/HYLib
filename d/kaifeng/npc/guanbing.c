#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ٱ�", ({ "guan bing", "bing" }));
        set("age", 22);
        set("gender", "����");
        set("long", "��Ȼ�ٱ������ղ��ܺ�������ʿ��ȣ��������ǽ��������˶�������\n");
        set("attitude", "peaceful");

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 510000);
        set("shen_type", 1);

        set_skill("unarmed", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
        set_skill("blade", 140);
        set_skill("force", 140);
        set_temp("apply/attack", 140);
        set_temp("apply/defense", 140);
        set_temp("apply/damage", 120);
        set_temp("apply/armor", 140);

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                CYN "�ٱ��ȵ����󵨵��񣬾����췴���ɣ�\n" NOR,
                CYN "�ٱ��ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n" NOR,
        }));
        setup();
        carry_object("/d/city/npc/obj/gangdao")->wield();
        carry_object("/d/city/npc/obj/junfu")->wear();
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
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        kill_ob(me);
        return 1;
}
