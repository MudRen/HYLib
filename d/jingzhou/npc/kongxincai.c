// Room: /d/jingzhou/npc/kongxincai.c
// Date: 99/06/01 by Byt

inherit NPC;
void create()
{
	set_name("���Ĳ�", ({ "kong xincai","kong","xincai"}) );
	set("gender", "Ů��" );
	set("age", 4);
	set("long", "�ݷ���Ů����һ�����ÿɰ���СŮ����\n");
	set("shen_type", 1);
	set("combat_exp", 5000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
        set("per", random(12)+20);
	set("attitude", "friendly");
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("score", 1000);

         set("chat_chance", 10);
         set("chat_msg", ({
		"���Ĳ˵���ص��������Ĳ��ڻ�԰�����Ĳ˿����ϣ���\n",
	}));        
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

