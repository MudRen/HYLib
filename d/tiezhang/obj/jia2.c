#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW "������" NOR, ({ "bingqi jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
        set("long", "����һ��ר�������ű����ļ��ӡ�
�����У�\n\n"
                   HIY"������"NOR"(duo) \n\n" 
                   HIM"�����ĸ��"NOR"(huan)\n\n" 
                   HIW"����÷����"NOR"(huan2)
\n");
//                   HIY"�����ĸ��"NOR(huan)\n\n" 
//                   HIY"����÷����"NOR(huan2)

        set("material","wood");
        set("weapon",3);
set("no_drop",1);
        set("no_get",1);
        }
        setup();
}
void init()
{
    add_action("do_get","na");
}

int do_get(string arg)
{
  object me,ob;
  string arg1,arg2;
  me=this_player();
  if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
   return notify_fail("�����ʽ: na <��������> from jia��\n");
  if (arg2!="jia")
     return notify_fail("�����ʽ: na <��������> from jia��\n");
  if(me->query_temp("tz_marks/��2"))
       return notify_fail("���Ѿ��ù��ˡ�\n");
    switch (arg1){
          case "duo":      ob=new(__DIR__"jinlong-duo"); break;             
          case "huan":       ob=new(__DIR__"zimu-huan"); break;
          case "huan2":       ob=new(__DIR__"wanzi-duo"); break;
          default :
                 return notify_fail("û�����ֱ�����\n");
          }
if (this_object()->query("weapon") <1)
return notify_fail("�����Ѿ����������ˡ�\n");
     if(!ob)
       return notify_fail("�����Ѿ����������ˡ�\n");
     if(ob) ob->move(me);
       message_vision("$N�ӱ��������ó�һ��$n��\n",me, ob); 
       this_object()->add("weapon",-1);
       me->set_temp("tz_marks/��2",1);
       return 1;


}


