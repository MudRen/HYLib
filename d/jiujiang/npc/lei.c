
inherit NPC;

void create()
{
   set_name("�׾�ָ",({ "lei jiuzhi","lei" }) );
        set("gender", "����" );
		set("title","����");
        set("age", 32);
   set("long", "��������ڶĲ����׾�ָ��\n");
       
   set("combat_exp", 300000);
   set("str", 10);
   set("per", 22);
   set("unarmed",80);
   set("parry",80);
   set("dodge",80);
   set("force",300);
   set("max_neili",300);
   set_skill("force",80);
   set("attitude", "peaceful");
   set("inquiry",([
	   "³����":"�����ҵĶ�ʦ������Ȼ������û����Ϊͽ�ܣ�\n",
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

