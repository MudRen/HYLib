// box.c ����
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(RED "������" NOR, ({ "da tiehe", "tiehe", "box" }) );
        set_weight(30000000);
        if( clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���⼣�߰ߵĴ������ӣ������ܾ�û���˶����ˡ�\n");
                set("value", 1000);
                set("material", "steel");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
        setup();
}

void init()
{
      add_action("do_xian","xian");
}

int do_xian(string arg)
{
      object me,suo,ob;
      me=this_player();
      ob=this_object();
      if (me->is_busy() || me->is_fighting())
           return notify_fail("����æ���ģ�\n");
      if (!me->query_temp("marks/����")) return 0;
      if ( arg =="box" || arg=="da tiehe" || arg =="tiehe") {   
//        if(!objectp( present("silver key", me)))        
//           return notify_fail("��û��Կ�ף���ʲô������\n");
        suo=new(__DIR__"yinsuo");
        if(!clonep(suo))
         return notify_fail("���ƿ����У����������ˣ��������һ�\n");         
if (this_object()->query("aget"))
{
           destruct(suo);
           return notify_fail("���ƿ����У����������ˣ��������һ�\n");
           } 
        if(clonep(suo) && ob->violate_unique()){
           destruct(suo);
           return notify_fail("���ƿ����У����������ˣ��������һ�\n");
           } 
        message_vision(HIY"$N�ƿ����У������������һ�ű�篰�����¡�\n"NOR,me);
        me->delete_temp("marks/����");
        suo->move(me); 
this_object()->set("aget",1);
//        destruct(ob);               
        return 1;
        }
       return notify_fail("��Ҫ�ƿ�ʲô��\n");
}
