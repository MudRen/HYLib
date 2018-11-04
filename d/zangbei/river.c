 inherit ROOM;
#include <ansi.h> 
string look_house(); 
void create() 
{
        set("short", "С����");
        set("long", @LONG
΢���д���Ȫˮ�������������㲻֪�������߹�ȥ������ˮ������������ˮҲ
���ɿݣ�ȴ��Զ����ͣ����,�·���Զ��֪����룬�����ֻ��õ��������㲻�䡣
̸��������Ӻ�ˮ�����𣬿�������ô���ᣬ��ô���������������һԾԾ�����
��ķ��պ�ʹ�����Ҳ�ܿ�ؾͻ�������������ʧ��
LONG
        );
        set("exits", ([ 
                "eastup":  __DIR__"spring",
        ]));
        set("item_desc",([
                "red house":    (: look_house() :),
                "house":        (: look_house() :),
                "С��¥":       (: look_house() :),
                "��¥":         (: look_house() :),
                "river":        "һ������������СϪ��ˮ��������������\n",
                "��ˮ":         "һ������������СϪ��ˮ��������������\n",
                "С��":         "һ������������СϪ��ˮ��������������\n",
                "��ˮ":         "һ������������СϪ��ˮ��������������\n",
                "stream":       "һ������������СϪ��ˮ��������������\n",
                "Ȫˮ":         "һ������������СϪ��ˮ��������������\n",
        ]) );
        set("objects", ([
                __DIR__"npc/xiaodie2": 1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
void init(){
        add_action("do_walk","walkto");
}  
int walkto(string arg){
        
        object me=this_player();
        object room;
        
        if (!me->query("zangbei/����¥")) return 0;
        if (arg == "building" || arg == "house" || arg == "С��¥" || arg == "��¥") {
                message_vision("$N��Ӷ԰�һԾ����Ӱ��ʧ�������С�\n",me);
                room=find_object(__DIR__"star_room2");
                if (!objectp(room)) room=load_object(__DIR__"star_room2");
                me->move(room);
                return 1;
        }
        return 0;
}
                
                
                
string look_house(){
        
        object me=this_player();
        if (!me->query("zangbei/����¥")) return "ˮ����������ʲôҲ���������\n";
        return "ˮ���У��԰���һ��С��¥�������֣�����������߹�ȥ(walkto house)��\n";
}   
