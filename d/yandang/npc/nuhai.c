
// musix yangzhou's Ů��
inherit NPC;

void create()
{
	set_name("Ů��",({ "nuhai","nvhai","girl" }) );
        set("gender", "Ů��" );
        set("age", 12);
        set("long", 
"��֪˭�ҵ�СŮ����\n");
        set_temp("apply/defense", 10);
	set("combat_exp", 100);
	set("mingwang", 1);
        set("str", 14);
        set("int", 15);
        set("attitude", "friendly");
        setup();
carry_object("/clone/misc/cloth")->wear();
}

