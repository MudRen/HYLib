
inherit NPC;
void create()
{
   
   set_name("���",({ "huo ji","huo","ji"}) );
        set("gender", "����" );
        set("age",22);
   set("long", "����һ���򹤵�С��ơ�\n");
   set("combat_exp",80000);
   set("str", 30);  
   set("chat_chance",50);
   set("chat_msg",({
   "С��������⿴�˿����ϰ�ʲôʱ������أ�\n",
   "С������ĵش��˸���Ƿ��\n",
   }));   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
