inherit NPC;

void create()
{
        set_name("�񱴿ǵ�СŮ��", ({"girl","kid","xiaohai"}));
        set("gender", "Ů��" );
        set("age", 9);
        set("long", "�����˸߲��ҵ�����,�����ջ�С��\n");
        set("combat_exp", 500);
        set("attitude", "peaceful");
        set_skill("dodge", 10);
        set_skill("unarmed", 20);
        set_skill("literate", 30);
        set("per", 25);
        set("max_kee", 200);
        set("max_gin", 100);
        set("max_sen", 100);
        setup();
        carry_object("/d/hainan/obj/hua-cloth")->wear();
        carry_object("/d/hainan/obj/beike2");
}


