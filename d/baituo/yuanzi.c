// yuanzi.c

inherit ROOM;

void init();
string look_gate();
int do_open(string);
int do_lock(string);

void create()
{
        set("short", "Ժ��");
        set("long",
             "����һ����Ժ�ӣ���ɨ��һ����Ⱦ������װ����������񣬴���\n"
         "���¡������������⡣������һ�䴢���ң�����(door)�ر��š�����\n"
         "�ǡ�����ɽׯ���Ĵ������ϱ߾��Ǵ����ˡ�\n"
         "���ﻹ��һ���Ļ�԰���м�һ�Ѽ�ɽ��һ��СϪ���Ա������˸��໨�ݣ�\n"
         "�������ˡ�������һ�����ŵ�����(tiemen)������ͨ����һ��Ժ�ӡ�\n"
        );
        set("exits", ([
                "northup" : __DIR__"dating",
                "west" : __DIR__"wuqiku",
                "south" : __DIR__"damen",
        ]));

        set("outdoors", "baituo");
        set("no_clean_up", 0);

        set("item_desc", ([
            "door" : (: look_gate :),
                "tiemen": "\n������ż�����أ�����û�м��ٽ���������������������Ϊ
�λ�����������ڴˣ�����һ���˶����Է�Խ(climb)�Աߵİ�ǽ��\n",
        ]));

        set_temp("lock",1);

        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_open", "open");
	add_action("do_lock", "lock");
        add_action("do_fan", "fan");
        add_action("do_fan", "pa");
        add_action("do_fan", "climb");
        add_action("do_push", "push");
        add_action("do_push", "tui");
        add_action("do_push", "strike");
        add_action("do_wen", "wen");
        add_action("do_wen", "smell");                  

}

string look_gate()
{
	if (query_temp("lock") == 0)
		return "���ϵ����������ˡ�\n";
	return "�����ű�����������ס��\n";
}

int do_open(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="door")
		return notify_fail("��Ҫ��ʲô��\n");

	if( query_temp("lock") == 1 && !present("key", me) )
		return notify_fail("Կ�׶�û�У���ô���ţ�\n");

	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");

	if(query_temp("lock") == 1 && present("key", me))
	{
		set_temp("lock", 0);
		message_vision("$N��Կ�ײ�����ף�ֻ��������ડ�һ���������ˡ�\n", me);
		message("vision", "���洫��һ������������ֻ��������ડ�һ���������ˡ�
  \n",room);
}
   message_vision("$N�����ƿ��ţ����˽�ȥ�����ְ�������������\n",me);
   message("vision", "�������˽��������ְ��������ˡ�\n",room);
   me->move(room);
   return 1;
}

int do_lock(string arg)
{
	object me=this_player();
	object room;

	if(!arg ||  arg!="door")
		return notify_fail("��Ҫ��ʲô��\n");
	if( !present("key",me))
		return notify_fail("Կ�׶�û�У���ô���ţ�\n");
	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");

	if(query_temp("lock") == 1)
		return notify_fail("���Ѿ������ˡ�\n");
	set_temp("lock",1);
	message_vision("$N��Կ�ײ�����ף�ֻ��������ડ�һ�����������ϡ�\n",me);
	message("vision", "���洫��һ����������������ֻ��������ડ�һ�������������ˡ�
  \n",room);

	return 1;
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
        me->delete_temp("baituo_climb");
        if ((!myfam || myfam["family_name"] != "����ɽ��") && dir == "west")
           return notify_fail("�˴��˱��ɽ��أ���ֹ����\n");

        return ::valid_leave(me, dir);
}
int do_fan(string arg)
{
        int dex, i = 0;
        object me = this_player();    
            
        dex = me->query_dex();     
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
       	if( (int)me->query("hamagong") ) 
        	return notify_fail("�����뷭��ǽȥ��ͻȻ����һ�����ƿ����ŵĳ嶯��\n");
       	if (dex < 18 )
        	return notify_fail("�Ⱛǽ�䰫����ȴ��ôҲ������ȥ��\n");
       	
       	if (dex > 17 && dex < 25){  
           	message_vision("$N˫���ڰ�ǽ��һ����һ��������˹�ȥ��\n", me);
           	i = 1;
        	}
        
       	if (dex > 24 && dex < 36){  
           	message_vision("$N�˹���������һ�ݣ���Ծ�˹�ȥ��\n", me);
           	i = 2;
        	}
        
       	if (dex > 35){  
           	message_vision("$N�ż�����һ�㣬�߸�Ծ��Ʈ�˽�ȥ��\n", me);
           	i = 3;
        }    
        me->set_temp("baituo_climb", i);
        me->move(__DIR__"shetan");
        me->start_busy(2);
        return 1;   	    
}

int do_push(string arg)
{
        int str;
        object me = this_player();
        
        str = me->query_str();

        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
        if( !arg || arg=="" ) return 0;
        
       	if (arg == "tiemen" ){
        	if( (int)me->query_skill("hamagong", 1)){
           		message_vision("$N�������ӣ���������������˫��ƽ���������š�\n", me);
           		message_vision("����ͻȻ�򿪣�$Nһû������˽�ȥ������ȴ�ֺ����ˡ�\n", me);
//           		me->receive_damage("neili", 100);
           		me->receive_damage("jing", 50);
           		me->move(__DIR__"yuanzi1");
           		message("vision", "ֻ��ž��һ����һ����Ӱ�����ų����˹�����\n",environment(me), ({me}));
           		return 1;
           		}
       		if (str < 21 )
               		return notify_fail("��ʹ���˳��̵��������ɾ����Ʋ��������š�\n");
               		
       		if (str > 20 && str < 38){  
       			if(str < 30)
           			message_vision("$Nʹ��ȫ�������������ţ�������ֻ���ᶯ��һ�¡�\n", me);
           		else message_vision("$N�˹������͵��������ţ����ŷ����˺����������������ϾͿ����ƿ��ˡ�����ʱ$N�������պ�ʹ�ֻ꣬�����ա�\n", me);
//           		me->receive_damage("neili", 400);
           		me->receive_damage("jing", 200);
           		return 1;
           		}

       		if (str > 37){  
           		message_vision("$N�ھ���ת��˫��ƽ���������š�\n", me);
           		message_vision("����ͻȻ�򿪣�$Nһû������˽�ȥ������ȴ�ֺ����ˡ�\n", me);
//           		me->receive_damage("neili", 400);
           		me->receive_damage("jing", 200);
           		me->move(__DIR__"yuanzi1");
           		message("vision", "ֻ��ž��һ����һ����Ӱ�����ų����˹�����\n",environment(me), ({me}));
           		return 1;
           		} 
       		}
       	else return 0;        
}

int do_wen(string arg)
{
        int con = this_player()->query_con();

      	if ( con > 29 && con < 37)
         	write("����������������ͻȻ�о����������������й���ζ�����Ų����Ǵ��Ķ����ġ�\n");      
      	if ( con > 36 )
         	write("����������������ͻȻ�о����������������й���ζ�������Ǵ������Ǳߵ�Ժ��Ʈ���ġ�\n");       
      	if ( con < 30 )
         	write("����������������ȫ�Ƿҷ��Ļ��㣬�㶼�����ˡ�\n");                     
       	return 1;        
}

