
inherit NPC;
void create()
{
   
   set_name("С��",({ "xiaofeng"}) );
        set("gender", "Ů��" );
        set("age",18);
   set("long", "����һ�����ޱ��µķ糾Ů�ӡ�\n");
   set("combat_exp", 2000);
   set("str", 10);
   set("per", 23);
   set("chat_chance",60);
   set("chat_msg",({
   	"С�ｿЦ�����͹ٽ����������������ܺõģ�\n",
   	"С������Ц�˼�����\n",
   	}));
     
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
