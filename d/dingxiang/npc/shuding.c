
#include <room.h>
#include <ansi.h>


inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǵ����Ķ�����������һ��ӥ�ˡ������￴�����ܲ�ԭ�ľ�ɫ��
ֻ��һ��������Х��Զ��������������������ӥҪ�����ˣ����ǸϽ���
ȥ�ĺá�
LONG);
        set("exits", ([
            "down" : __DIR__"caoyuan1",                        
        ]));
        set("objects",([
          __DIR__"xiaoying":3,
          ]));
        set("outdoors", "caoyuan");
        setup();
        
}

void reset()
{
   object *ob;
   int i;
   
   ob=all_inventory(this_object());
   
   for(i=0;i<sizeof(ob);i++){
     if(userp(ob[i])){
     	tell_object(ob[i],"��������ӥ�����ˣ��Ͻ������ˣ�\n");
     	ob[i]->move(__DIR__"caoyuan1");
     }
   }
   ::reset();
}
    