inherit NPC;
void create()
{
  set_name("������ʿ",({ "gaoli yongshi","yongshi"}) );
        set("gender", "����" );
        set("age", 35);
   set("long", "���Ǹ�������ʿ���ڸ������е��֡�\n");
   set("combat_exp",1500000+random(3000));
   set_skill("dodge",680);
   set_skill("parry",680);
   set_skill("unarmed",680);
   set("attitude", "peaceful");
   set("chat_chance",20);
   set("chat_msg",({
    "������ʿһЦ��˭�Һ�����ս�����ǻ�ò��ͷ��ˣ�\n",
    "������ʿ�������һ����С��ɫ���Ժ�����Ҽ����㣡\n",
    "������ʿ��ͷһ��������ؿ�����һ�ۡ�\n",
    "������ʿһɹ����˵˭ɱ���һ�õ�ʲô�ƺţ��ҿ��������˻�û�����أ�\n",
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
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"ɱ��������ʿ�������"+
      "���������ߡ��ĳƺţ�\n");
     ob->set_temp("rank/class","��������");
   }
   
   return ::die();
   
}
