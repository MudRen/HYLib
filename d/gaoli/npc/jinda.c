// ����˫����
//cui.c 
 
inherit NPC;

void create()
{
        set_name("�������", ({ "jin dashanren", "jin", "dashanren" }));
        set("age", 50);
        set("gender", "����");
        set("long","���Ǹ��������Ĵ����ˣ�������˵����һ��������,/n");
        set("attitude", "peaceful");
   set("str", 20);
        set("combat_exp", 800000);
   set("max_qi", 2400);
   set("max_mana", 2200);
   set("max_jing", 2400);
   set("max_neili", 2200);
   set("neili", 2200);
   set("force_factor", 100);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("force", 150);

        setup();
        carry_object("/d/gaoli/obj/pao1")->wear();
}
