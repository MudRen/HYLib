#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
���Ų����У��ٲ�̤���ľ��ǰ������ݣ�����û��·,ÿ��һ����������
���̵�С��,����������塣
LONG
        );
        set("outdoors", "dali");

        set("exits", ([
           "south" : __DIR__"shanlu11",
           "north" : __DIR__"shanlu11",
           "west" : __DIR__"shanlu11",
           "east" : __DIR__"shanlu11",
        ]));

        setup();
}


void init()
{    
  object me = this_player();
     if (random(me->query("kar")) <10 && me->query_con() < 30)
            {
     me->set_temp("last_damage_from", "��ɭ�����ƣ������");
             me->add("qi", -30);
             me->add("jing", -10);
             me->receive_wound("jing", 20);
             }else{
             me->add("qi", -20);
             }    
 add_action("do_look", "look");               
}

int do_look()
{
        object me = this_player();
        mixed *local;
        local = localtime(time() * 60);
        if((local[2] < 3 || local[2] >= 21)&&random(6)<2) {
        message("vision",BLU"�����,���������һƬ�����ֲ�����ָ,���Ĵ�������,��������־�.\n"
                           "ͻȻ��������Ұ�޵ĺ���,���ŵĿ�������.\n"NOR, me);
        }
}

int valid_leave(object me, string dir)
{
        mixed *local;
        local = localtime(time() * 60);
        if (dir == "west")
          me->add_temp("mark/steps",1);
        if (dir == "south")
          me->add_temp("mark/step",-1);
       if (dir == "east")
          me->add_temp("mark/steps",-1); 
        if (dir == "north")
          me->add_temp("mark/step",1);

/**for Ӫ�ȶ��� ***/
         if (me->query_temp("duanyu/steps") 
           && me->query_temp("duanyu/step")  
           && random(me->query("kar")) > 20
           && me->query_temp("duanyu/find2")
            ){
	call_out("kicking1", 0, me);
//            me->move(__DIR__"gaoshan");
            me->set("dali/pass", 1);
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
              return notify_fail("���ߵ���һ����ɽ�ϡ�\n");
         }
// Modify By River ���ڲ���̫�򵥻�� lbwb ��ֻ���Ĵλ��� 
         if (me->query_temp("mark/steps") < -8 || me->query_temp("mark/step") < -8 ){
           if(me->query_temp("duanyu/find2")){
             if(!me->query("dali/fail"))
               me->set("dali/fail", 1);
             else {
               me->add("dali/fail", 1);
               if( me->query("dali/fail") > 8)
                me->set("dali/fail", 8);
             }
           }
	call_out("kicking", 0, me);
//           me->move(__DIR__"xiaoxi");
           me->delete_temp("mark/steps");
           me->delete_temp("mark/step");
           if(me->query_temp("duanyu/find2") && me->query("dali/fail") > 3){
//           me->delete_temp("duanyu/find2");
              return notify_fail(HIW"\n���ƣ�������߳����ɽ·����ɥ�ط����Լ���ôҲ�Ҳ����Ĵ���˵����١�\n"NOR);
           }
           else 
              return notify_fail("���ƣ�����������߳������ɽ·��\n");
        }           
        return ::valid_leave(me, dir);
}
void kicking(object me)
{
           me->move(__DIR__"xiaoxi");
}
void kicking1(object me)
{
            me->move(__DIR__"gaoshan");
}