 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "������");
        set("long", @LONG
��������һ������ͩq�����հ���һһ�����괴���ġ���Ժ��ɽ��ˮ���羰��
�������ڴ���һ�������հ����ܵ���һ�𣬴�ʦ��ǰ���µ��ּ�����Ѫ�һ�������
Ȼ�𾴡���������ɣ�Ѻ��У������Ⱥ������ɮ�˳����ָ����㱳��ι�����Ρ�
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"wild5",
                "north" : "/d/zangbei/sela",
        ]));
        set("item_desc", ([
                "��Ѫ�һ�":     "�����հ���ǰ���µ��ּ���\n",
                "picture":      "�����հ���ǰ���µ��ּ���\n",
                "�һ�":         "�����հ���ǰ���µ��ּ���\n",
        ]));
        
        set("objects", ([
                __DIR__"obj/statue4":   1,
                __DIR__"obj/river":     1,
                __DIR__"npc/monk4":     1,
        ]) );
         set("resource/water", 1);
        set("liquid/container", "ɣ�Ѻ�");  
        set("coor/x",-1070);
        set("coor/y",170);
        set("coor/z",0);
        setup(); 
}  
void reset()
{
        object statue,incense;
               
        ::reset();
        statue = present("statue", this_object());
        if (!present("incense",statue)) {
           incense=new(__DIR__"obj/incense");
                incense->move(statue);
        }
} 
void fish_notify(object obj){
        object me, room, fish, *inv, bait;
        int i;
        
        me = this_player();
        inv = all_inventory(obj);
        if(sizeof(inv) == 0){
                message("vision",me->name() + "�ͳ���" + obj->name() + "�ַ��˻�ȥ��\n", environment(me), me);
                tell_object(me, obj->name() + "��û�ж���ô���Ե����� ? \n");           
                return;
        }               
        for(i=0; i<sizeof(inv); i++) {
                if(inv[i]->query("fish_bait")) {
                        bait = inv[i];
                        message_vision("$N�Ӷ���һ��," + obj->name() + "�ڿ��л���һ��Ư���Ļ���, �㹳������ˮ��. \n" , me);
                        me->start_busy(5);
                        remove_call_out("do_fishing");              
                        call_out("do_fishing", 5, me, bait);                    
                        return;
                } 
        }
        tell_object(me, "���õĶ���̫�԰� ? \n");                       
        return;
} 
void do_fishing(object me, object bait){
        object  fish; 
        if(me && environment(me) == this_object()) {
                message_vision("$N�ܿ��ֳ�����һ�����, " , me);
                switch (random(10)) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:         message_vision("ȴʲô��û������ ! \n", me);
                                        break;
                        case 4:
                        case 5:
                           case 6:         message_vision("ʲô��û������ , ���ȴ������� !!  \n", me);
                                        destruct(bait);                         
                                        break;
                        case 7:
                        case 8:
                        case 9:         if (!bait->query("fish_bait_zanba")){        
                                                message_vision("ʲô��û������ , ���ȴ������� !!  \n", me);
                                                destruct(bait);                         
                                                break;
                                        }       
                                        if (random(5)) {                                
                                                message_vision("�㹳�ϵ�����һ�����㣡����  \n", me);
                                                fish = new(__DIR__"obj/fish");
                                                fish->move(me);
                                        } else {      
                                                message_vision("��������һ�����ƺ�������ʲô���� ����  \n", me);
                                                message_vision("$N�Ѿ��ذ��������������\n",me);
                                                fish = new(__DIR__"obj/item");
                                                fish->move(me);
                                        }
                                        destruct(bait);
                                        break;
                }
        }
        return;
}       
