 inherit NPC;
void create()
{
        set_name("����", ({ "city guard", "guard" }) );
        set("gender", "����" );
        set("age", 25);
        set("str", 30);
        set("long", @LONG
һ������Ĳ�ɮ��
LONG
);
        set("attitude", "heroism"); 
        set("neili", 300);
        set("max_neili", 300);
        set("force_factor", 2);  
        set("combat_exp", 20000); 
        set_skill("staff", 50);
        set_skill("cloudstaff", 20);
        set_skill("force", 40);
        set_skill("parry", 50);
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        set_skill("iron-cloth", 80);
        set_skill("jin-gang", 20);
        map_skill("iron-cloth", "jin-gang");
        setup(); 
        carry_object(__DIR__"obj/3staff")->wield();
        carry_object(__DIR__"obj/redcloth")->wear();
}  
