inherit NPC;
void create()
{
  set_name("��ؤ",({ "qi gai","qi","gai"}) );
        set("gender", "����" );
        set("age", 35);
   set("long", "����һ����������ؤ��\n");
   set("combat_exp",3000+random(3000));
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("chat_chance",20);
   set("chat_msg",({
    "��ؤ�����������кã�����Ǯ�ɣ�\n",
    "��ؤ�޵����Ҽ��а�ʮ��ĸ������һ�����ӣ��������ӣ����кðɣ�\n",
    "��ؤ������˵�������Ѿ�����û�Է��ˣ�\n",
    "��ؤ�޵�����˵˭ɱ���һ���ʲô�ƺţ�����ô��ô���డ����\n",
    }));
  setup();
  
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   if(!userp(ob)) return ::die();
   
   if(random(100)>95){
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"ɱ����ؤ�������"+
      "��ɥ���������ĳƺţ�\n");
     ob->set_temp("rank/class","ɥ������");
   }
   
   return ::die();
   
}
