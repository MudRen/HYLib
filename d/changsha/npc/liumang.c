inherit NPC;
void create()
{
  set_name("��å",({ "liu mang","liu","mang"}) );
  set("gender", "����" );
  set("age", 35);
   set("long", "����һ���������å��\n");
   set("combat_exp",3000+random(3000));
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   
   set("chat_chance",20);
   set("chat_msg",({
    "��å�ߵ�������������ӹ�������·����\n",
    "��å�������ү���ڳ����Զٷ�������Ǯ�������ﻹ�ҳ�����ҪǮ����\n",
    "��åһ��ţ���û��������ɳһ�������Ǿ��������ң���\n",
    "��ؤɹ������˵˭ɱ���һ���ʲô�ƺţ�˭�Ұ�������\n",
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
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"ɱ����å�������"+
      "���������͡��ĳƺţ�\n");
     ob->set_temp("rank/class","��������");
   }
   
   return ::die();
   
}
