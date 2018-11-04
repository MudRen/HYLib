
inherit NPC;

void create()
{
   set_name("С��",({ "xiao jie","xiao","jie"}) );
   set("gender", "Ů��" );
   set("age",20+random(2));
   set("long", "����һλ��ҹ��㡣\n");
       
   set("combat_exp", 100000);
   set("per",25);
   set("chat_chance",20);
   set("chat_msg",({
    "С�㽿���������ս�𲻶ϣ��ҿ����Ǻ������ˣ�\n",
    "С�����ĵ���������˵���١�����������˵ã��ҿ����뿴һ�����ǰ���\n",
    "С�����������������кܶ���˴��ҵ����⣬�Ҹ���ô�죿\n",
    "С�����������˵˭ɱ���Ҿ��л�����ĳ���ƺţ����ǵ��������ˣ�\n",
   }));
   
   set("inquiry",([
    "����":"�ҿ��������������ܼ޸�������Ҳ����������ô�����ˣ�\n",
    "������":"��˵����Ʒ�ܺã������ʶһ�¡�\n",
    ]));
   
   
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
  
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   if(!userp(ob)) return ::die();
   
   if(random(100)>95){
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"ɱ����Ů�������"+
      "��������å���ĳƺţ�\n");
     ob->set_temp("rank/class","������å");
   }
   
   return ::die();
   
}