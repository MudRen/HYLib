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
        set("long", "����һ��ר�������Ÿ��ֱ����ļ��ӡ�
�����У�
       ��(bian)��        ��(dao)�� 
       ��(gun)��         ��(bang)��
       ��(zhang)��       ��(jian)��
       ��(axe)��       ذ��(dagger)�� 

���������ߡ�\n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
    add_action("do_get",({"get","na"}));
}

int do_get(string arg)
{
  object me,ob;
  string arg1,arg2;
  me=this_player();
  if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
   return notify_fail("�����ʽ: get <��������> from jia��\n");
  if (arg2!="jia")
     return notify_fail("�����ʽ: get <��������> from jia��\n");
  if(present(arg1, me) || present(arg1, environment()))
     return notify_fail("�Ѿ������������ˡ�\n");
    switch (arg1){
          case "jian": ob=new("/clone/weapon/changjian"); break;             
          case "dao": ob=new("/clone/weapon/gangdao"); break;   
          case "bian": ob=new("/clone/weapon/changbian"); break;         
          case "axe": ob=new("/clone/weapon/axe"); break;
          case "zhang": ob=new("/clone/weapon/gangzhang"); break;
          case "gun": ob=new("clone/weapon/qimeigun"); break;           
          case "dagger": ob=new("clone/weapon/dagger"); break;
          case "bang": ob=new("clone/weapon/zhubang"); break; 
          default :
                 return notify_fail("û�����ֱ�����\n");
          }
     if(ob) ob->move(me);
       message_vision("$N�ӱ��������ó�һ��$n��\n",me, ob);  
       return 1;
}
