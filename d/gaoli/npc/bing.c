// ����˫����
//bing.c С��
 
inherit NPC;

void create()
{
        set_name("С��", ({ "xiao bing", "bing" }));
        set("age", 18+random(10));
        set("gender", "����");
        set("long","����һ������ʿ������Щʿ���������־�����ʿ���еľ���\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("combat_exp", 80000);
        set("max_qi", 400);
        set("max_mana", 200);
        set("max_jing", 400);
        set("max_neili", 200);
        set("neili", 200);
        set("force_factor", 10);
        
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
        
        setup();
        
}
