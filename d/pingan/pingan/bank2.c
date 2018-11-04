// bank.c

inherit ROOM;

int do_apply(string);
int do_cancel(string);
int confirm(string,int,object,object);


void create()
{
        set("short", "���Ǯׯ");
        set("long", @LONG
        
����һ�����ֺŵ�Ǯׯ�����ϰ���ɽ���ˣ����Ǯׯ������үү��ү
ү��үү��үү�Ǳ���ʼ����һֱ��������������ǳ��ã���ȫ
�����ض��зֵꡣ�����е���Ʊͨ��ȫ����Ǯׯ���ſڹ���һ������
(paizi)��
LONG);
        set("item_desc", ([
                "paizi": @TEXT
                
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

        apply  card      �������ÿ�
        
        cancel card         ע�����ÿ�
        
TEXT]) );
//      cancel bag       ע��Ǭ����

        set("exits", 
        ([ //sizeof() == 4
           "down" : __DIR__"bank1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tiesuanpan" : 1,
        ]));

//      set("outdoors", "changan");
       set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_apply","apply");
        add_action("do_cancel","cancel");  
/*      add_action("do_upgrade","upgrade"); */
}

int do_apply(string arg)
{
        object bag,me=this_player();
        if (!arg) return notify_fail("��������ʲô?\n");
        if(arg=="card"){
                if (present("credit card",me))        tell_object(me,"�������ɻ�ؿ����㣺�������ÿ������Ѿ������������!\n");
                else{
                        bag=new("/clone/money/account.c");
                        bag->move(me);
                        tell_object(me,"Ǯׯ�ϰ����һ����ɫ��Ƭ����õ������ÿ���\n");
                        tell_room(this_object(),"Ǯׯ�ϰ��һ����ɫ��Ƭ�ݸ�"+me->query("name")+".\n",me);
                }
                return 1;
        }
        else         if(arg=="bag"){
                if (present("big bag",me))tell_object(me,"������а��ؿ����㣺����Ǭ�������㻹��Ҫ���ڣ�\n");
                else{
                        }
                        /* bag=new("/obj/bigbag");
                  bag->move(me);
                        tell_object(me,"Ǯׯ�ϰ����һ���ش�Ĵ��ӣ���õ���Ǭ������\n");
                        tell_room(this_object(),"Ǯׯ�ϰ��һ���ش�Ĵ��ӵݸ�"+me->query("name")+"��\n",me);
                }*/
                return 1;
        }
        else  return notify_fail("�����̺���һ��������Ҫʲô?\n");
}

int do_cancel(string arg)
{
        object bag,me=this_player();
        if (!arg) return notify_fail("����ע��ʲô?\n");
        if(arg=="card"){
                if (!(bag=present("credit card",me)))        tell_object(me,"�������ɻ�ؿ����㣺ע�����ÿ����㲻�����Լ�Ū���˰�?\n");
                else{
                        destruct(bag);
                        tell_object(me,"�㽫���ÿ�������Ǯׯ�ϰ塣\n");
                        tell_room(this_object(),me->query("name")+"��һ����ɫ��Ƭ�ݸ�Ǯׯ�ϰ塣\n",me);
                }
                return 1;
        }
/*      
        else         if(arg=="bag"){
                if (!(bag=present("big bag",me)))tell_object(me,"�������ɻ�ؿ����㣺ע��Ǭ�������㲻�����Լ�Ū���˰�?\n");
                else{
                        destruct(bag);
                        tell_object(me,"�㽫Ǭ����������Ǯׯ�ϰ塣\n");
                        tell_room(this_object(),me->query("name")+"��һ���ش�Ĵ��ӵݸ�Ǯׯ�ϰ塣\n",me);
                }
                return 1;
        }
*/      
        else  return notify_fail("�����̺���һ��������ע��ʲô?\n");
}

/* int do_upgrade(string arg)
{
        int upgrade_value=25;        //25 golds
        object bag,me=this_player();
        int i,max_bag_items=me->query("maxbagitems");
        
        if (!arg) return notify_fail("��������ʲô?\n");
        if(arg=="bag"){
                if (!(bag=present("big bag",me)))return notify_fail("������а���һЦ���㰾�˼���ͨ����?�Լ���û��Ǭ��������֪��!\n");
                 if(!max_bag_items){
                max_bag_items=MAX_BIGBAG_ITEMS;
                        me->set("maxbagitems",MAX_BIGBAG_ITEMS);
                };
                for(i=5 ;i<max_bag_items;i++) upgrade_value *=2;
                write("Ǭ���������������壬����һ����������һ��\n");
                write("���������ɽ����Ǭ������������"+chinese_number(max_bag_items)+"����"
                        +chinese_number(max_bag_items+1)+"����Ҫ"+chinese_number(upgrade_value)+"���ƽ�\n");
                upgrade_value*=10000;
                i=me->can_afford(upgrade_value);
                if( !i )return notify_fail("������û���㹻��Ǯ��\n");
                if(i==2)return notify_fail("������û�н��������޷����ʡ�\n");

                write("\n�����Ҫ������(y/n)?\n");
             return input_to( (: confirm :) ,1,upgrade_value,me,bag);
        }
        else  return notify_fail("�����̺���һ��������Ϊ�Ǹ�������������?\n");
}
*/
int confirm(string arg,int upgrade_value,object me,object bag)
{
        if(arg == "y" || arg == "Y"){
             if(me->pay_money(upgrade_value)){
                  me->add("maxbagitems",1);
                  bag->set_max_items(me->query("maxbagitems"));
                  tell_object(me,"Ǯׯ�ϰ������Ǭ�����������ģ��ۿ���Ǭ��������һȦ��\n");
                        tell_room(this_object(),"Ǯׯ�ϰ�������"+me->query("name")+"���ϵĴ��ӣ��Ǵ��Ӿ��ƺ�����һȦ��\n",me);
                }
                else write("error");
                return 1;
        }
        else{
                write("���������Ǭ������\n");
                return 0;
        }
}
