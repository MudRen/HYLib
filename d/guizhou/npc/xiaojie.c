inherit NPC;
void create()
{
   set_name("С��",({ "xiao jie","xiao","jie" }) );
   set("gender", "����" );
   set("age", 22);
   set("long", "����һλС�㡣\n");
   set("combat_exp", 20000);
   set("attitude", "friendly");
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set_temp("apply/armor",30);
   set("chat_chance",20);
   set("chat_msg",({
   	"С��΢΢һЦ�����ڴ��̣�����ûʲô����ģ���ǰ�ɲ���������ӡ�\n",
   	"С��̾����ʲôʱ����ܹ��Ϻ����ӣ��ҵķ����֪����ս���������ǻ\n",
   	"С��̾������˵ɱ���һ���ʲô���š�����ҷ������ߣ�˭���������ҥ��\n",
   	(:random_move:),
   	}));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   if(!userp(ob)) return ::die();
   
   if(random(100)>95){
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"ɱ�����򣬻����"+
      "������Ѫ�֡��ĳƺţ�\n");
     ob->set_temp("rank/class","����Ѫ��");
   }
   
   return ::die();
   
}