
inherit ITEM;

string *vision=({
"$N��ˮ���ȵ÷ɿ�,",
"$N����û���زȶ�ˮ��,",
"ˮ����$N�Ĳȶ���ת������,",
"$Nһ�Ÿ�,һ�ŵ͵ز���ˮ����,",
"$N������ͨ��,���µ�ˮ��ȴת��Խ��Խ��,",
"ˮ����$N�Ĳȶ���ת�÷ɿ�,",
"$N֨֨ŤŤ�زȶ�ˮ��,",
"$NĨ�������ϵĺ�ˮ,����ˮ��,"
});
void create()
{
        set_name("ˮ��", ({"watercart"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "��ˮ����,һ�����ˮ��,һ����������
�������̤��(tread watercart)�Ļ�,�Ϳ��Գ�ˮ�����У�\n"),
   set("no_get", 1);
   }
   setup();
}
void init()
{
  add_action("do_tread","tread");
}
int do_tread(string arg)
{
  object player,obj;
  string str;
 player=this_player();
 obj=this_object();
if (!arg||arg!="watercart") return 0;
if (living(player)&&environment(player)==environment())
    {
      if (player->query_skill("dodge",1)>30)
     {    tell_object(player,"���Ѿ����ܴӲ�ˮ����ѧ��ʲô��!\n");
          return 1;
     }
       str=vision[random(sizeof(vision))];
  message_vision(str+"��ˮ���뵾��.\n",player);
      player->improve_skill("dodge",random(3));
      player->receive_damage("qi",random(20));
      player->receive_damage("jing",random(3));
   return 1;
  }
return 1;
}
       