inherit NPC;

void create()
{
   set_name("����",({ "yayi"}) );
        set("gender", "����" );
        set("age",30+random(10));
   set("long", "����һ���Ž����ŵ����ۡ�\n");       
   set("combat_exp",10000);
   set("str",28);
   set_skill("parry",40);
   set_skill("unarmed",40);
   set_skill("dodge",40);
   set_skill("staff",40);

   set("attitude", "peaceful");
   set("chat_chance",10);
   set("chat_msg",({
       "����̾�˿�����\n",
   }));
  
   setup();
   carry_object(__DIR__"obj/yayi-fu")->wear();
   carry_object(__DIR__"obj/yayi-mao")->wear();
   carry_object(__DIR__"obj/shuihuo-bang")->wield();
  
}

