// npc: ҩ���ϰ�

inherit NPC;

void create()
{
        set_name("ҩ���ϰ�", ({ "lao ban", "lao", "boss" }) );
        set("gender", "����" );
	set("title", "������ҽ");
        set("age", 50);
        set("long",
	    "��������һ��ҩ���ڿ���\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
	set_skill("force", 20);
        set_skill("dodge", 35);

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "��ҽ" : "�Ϸ�һ����ҽ��������Ҳ�����˼������¡�",
       ]) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();

}

