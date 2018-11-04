// dating.c ����
// Modify By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short",HIW"����"NOR);
            set("long",@LONG
�����Ǿ���ȵĴ������ǹ��������͵ĵط���������ǰ�����Ϲ���һ��
����(bian)����������ĸ����ɷ���Ľ��֣��쳣���ɡ��������ص��ڴ���֮
�¹���һ�����׺����졹֮ͼ��hua)������������ó������������е��Ը�
LONG
       );
            
           set("item_desc",([ "bian": HIY"    
          ����������������������������������������
          ����������������������������������������
          ��������                          ������
          ������   ��        ��        ��   ������
          ��������                          ������    
          ����������������������������������������
          ����������������������������������������\n"NOR,
             "dao": "����һ���ص���\n",   
             "hua": "����һ�����׺����졹ͼ������ͼ���ǽ���ƺ�����ͨ����\n",
            ]));

            set("exits",([
               "out": __DIR__"shiwu",
            ]));
            set("objects",([
                 __DIR__"npc/gsz" : 1,
            ]));
            set("valid_startroom", 1);
            setup();
}

void init()
{
            add_action("do_xian","xian");
            add_action("do_enter","zuan");
            add_action("do_wa","jie");
}

int do_xian(string arg)
{
            object me = this_player();
            if(me->is_busy() || me->is_fighting())
                   return notify_fail("����æ���أ�\n");
            if(!arg) return 0;
            if(arg =="hua"){
            message("vision",me->name() +"�ҿ�ͼ��������ǽ����һ���ܵ���\n", environment(me), ({me}));
            write("�����ͼ��������ǽ����һ���ܵ�(dao)��\n");
            me->set_temp("mark/��",1);   
            return 1;
            }
            return notify_fail("�����ʲô? \n");                    
}

int do_enter(string arg)
{
        object me = this_player();
        if(!arg || arg !="dao")
                return notify_fail("���������ꣿ\n");
        if(me->is_busy() || me->is_fighting())
                return notify_fail("����æ���أ�\n");
        if(!me->query_temp("gsz_agree"))
                return notify_fail("�����Ǿ���ȵĽ��أ�û��ׯ��������������Ӳ��ܽ��룡��\n");
        if((int)me->query_temp("mark/��")){
          message("vision", me->name() + "��������ܵ���\n", environment(me), ({me}));
          tell_object(me,"�㹭������ܵ���\n");
          me->move(__DIR__"houtang");
          message("vision",me->name() +"������ܵ������˹�����\n", environment(me), ({me}));
          me->delete_temp("mark/��");
          return 1;
          }
      return notify_fail("û��������ʲô�� \n");
}

int do_wa(string arg,object ob)
{
        object weapon,me=this_player();
        if(!me->query_temp("jqg/chi")) return 0;
        if( !arg || arg !="zhuan")
               return notify_fail("���ҽ�ʲô����\n");
        if(!weapon=(me->query_temp("weapon")))
               return notify_fail("��׼�����ֽҽӿ���שô��\n");        
        if(me->is_busy() || me->is_fighting())
                return notify_fail("����æ���أ�\n");
        ob=new(__DIR__"obj/jqdan");
        if(!clonep(ob))
           return notify_fail("�������ˣ����鵤�Ѹ����������ˡ�\n");  
if (this_object()->query("aget")>2)
{
           destruct(ob);
           return notify_fail("�������ˣ����鵤�Ѹ�����ȡ���ˡ�\n");
           }
        if(clonep(ob) && ob->violate_unique()){
           destruct(ob);
           return notify_fail("�������ˣ����鵤�Ѹ�����ȡ���ˡ�\n");
           }
        tell_object(me,"�������������ש���γ�����"+weapon->name()+"����ש���в��룬����ש�飬��������ľ��鵤��\n");
        message("vision", me->name() + "�γ�����"+weapon->name()+"����ש���в��룬����ש�顣\n", environment(me), ({me}));
        me->delete_temp("jqg/chi");
        this_object()->add("aget",1);
        ob->move(me);
        return 1;
}

