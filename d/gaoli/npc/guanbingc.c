// ����˫����

//�ٱ�


inherit NPC;

#include <ansi.h>

void create()
{
        set_name(HIY"�ٱ�"NOR, ({ "guan bing", "bing"}) );
        set("gender", "����");
        set("age", 35);
        set("long","���Ǹ������ŵĹٱ����ܹܸ������ΰ���\n");
        set("combat_exp", 300000+random(40000));
        set("attitude", "heroism");
        set("str", 30);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("max_gin", 700);
        set("neili", 400);
        set("max_neili", 500);
        set("force_factor", 25);
        set_skill("blade", 300);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);

        setup();

        carry_object("/d/gaoli/obj/gangdao")->wield();
        carry_object("/d/gaoli/obj/armor")->wear();
}

