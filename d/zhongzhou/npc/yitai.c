inherit NPC;

void create()
{
        set_name("��̫̫", ({ "yi taitai", "yi", "taitai"}) );
        set("gender", "Ů��" );
        set("age", 22);
        set("shen_type", -1);
        set("long", "�������������̫̫�����÷ǳ������ޡ�\n");

        set("combat_exp", 100);
        set("attitude", "peaceful");
        set_skill("unarmed", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);

        setup();
        add_money("silver", 1);
        carry_object("clone/misc/cloth")->wear();
        
}
