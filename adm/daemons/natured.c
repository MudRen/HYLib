//������100����II
//����(lywin)��ǰ�˵�natured.cΪ����������ҹ����ֵķ�����ͨ�档2000/5/30

// natured.c
#include <ansi.h>
#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60)
//#define TIME_TICK (time()*60-890000000)
//#define TIME_TICK1 (time()*60-900000000)
//#define TIME_TICK ((time()-900000000)*24)
//#define TIME_TICK1 ((time()-900000000)*24)
static int current_day_phase, current_month;
static string ppl;
mapping *day_phase;

string *month_desc = ({
	"��¡����:",
	"��������:",
	"��������:",
	"���紺��:",
	"��������:",
	"�����ġ�:",
	"��ʢ�ġ�:",
	"�����ġ�:",
	"�����:",
	"�����:",
	"�����:",
	"��������:",
});

string *weather_msg = ({
        "�������������",
        "���䵭�����Ʋ�ױ�������ʵ����",
        "�����������Ʈ��Ʈȥ",
        "�����Ʋ�ѻ������",
        "����������ܲ�",
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
//        day_phase = read_table("/adm/etc/nature/day_phase");
//        init_day_phase();
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
        get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "��":
		case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "��":
		case "��":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		case "һ":
		        if(get_day=="һ")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		        
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


	init_day_phase();
}
/*
void init_day_phase()
{
        mixed *local;
        int i, t;

        // Get minutes of today.
        local = localtime(TIME_TICK1);
        t = local[2] * 60 + local[1];           // hour * 60 + minutes

        // Find the day phase for now.
        for( i=0; i < sizeof(day_phase); i++)
                if( t >= day_phase[i]["length"] )
                        t -= (int)day_phase[i]["length"];
                else
                        break;

        current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

        // Since in our time scale, 1 minute == 1 second in RL, so we don't need
        // any conversion before using this number as call_out dalay, if you
        // changed the time scale, be sure to convert it.

        call_out("update_day_phase",
      (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}*/
void init_day_phase()
{
	mixed *local;
	int i, t;


	local = localtime(TIME_TICK1);
	t = local[2] * 60 + local[1];      


	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_month = local[4];


	remove_call_out("init_day_phase");
	call_out("init_day_phase", 180);


	remove_call_out("update_day_phase");	



	call_out("update_day_phase",
	(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
        remove_call_out("update_day_phase");

        current_day_phase = (++current_day_phase) % sizeof(day_phase);
        switch (day_phase[current_day_phase]["outcolor"])
        {
              case "BLK":
                   message("channel:chat", HIG"�����⡿"BLK + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "RED":
                   message("channel:chat", HIG"�����⡿"RED + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIR":
                   message("channel:chat", HIG"�����⡿"HIR + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "GRN":
                   message("channel:chat", HIG"�����⡿"GRN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIG":
                   message("channel:chat", HIG"�����⡿"HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "YEL":
                   message("channel:chat", HIG"�����⡿"YEL + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIY":
                   message("channel:chat", HIG"�����⡿"HIY + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "BLU":
                   message("channel:chat", HIG"�����⡿"BLU + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIB":
                   message("channel:chat", HIG"�����⡿"HIB + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "MAG":
                   message("channel:chat", HIG"�����⡿"MAG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIM":
                   message("channel:chat", HIG"�����⡿"HIM + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "CYN":
                   message("channel:chat", HIG"�����⡿"CYN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIC":
                   message("channel:chat", HIG"�����⡿"HIC + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "WHT":
                   message("channel:chat", HIG"�����⡿"WHT + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIW":
                   message("channel:chat", HIG"�����⡿"HIW + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              default:
                   message("channel:chat", HIG"�����⡿"HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
        }
//        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
        if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
            call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

        call_out("update_day_phase", day_phase[current_day_phase]["length"]);
//	call_out("test_robot", 5+random(20));
}

void test_robot()
{
	object *obs = users(), ob, robot;
    int i = sizeof(obs), j = 10;

	if (i < 1) return;
	while (j--) {
		ob = obs[random(i)];
		if (wiz_level(ob)) continue;
		if (!living(ob)) continue;
		if (!interactive(ob)) continue;
                if (query_idle(ob) > 30) continue;
		if (!environment(ob)) continue;
		break;
	}
	if (j < 0) return;
	ppl = ob->query("id");
        if (!ob->is_fighting() 
        && interactive(ob) && living(ob)
        || ob->query("combat_exp")> 1000000 )
        ob->set_temp("testrobot",1);
        call_out("ok_robot", 1, ob);
}

void ok_robot(object ob)
{
if (ob)
{
ob->set_temp("testrobot",0);
ob->delete_temp("testrobot");
}
}

void event_morning()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIY"����͢������"HIR + "�����ݳ��з����ձ���ϸ��\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("channel:chat", HIY"����͢������"HIM + "�ڱ������з����ձ���ϸ��\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/city3/guangchang")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
 message("channel:chat", HIY"����͢������"HIM + "�ڳɶ����з����ձ���ϸ��\n"NOR,users() );
	}
        if (random(12) == 4)
        {
		if(objectp(room=load_object("/d/quanzhen/zhongxin")) && 
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
  message("channel:chat", HIB"����͢������"GRN + "���书���з��ֽ����ϸ��\n"NOR,users() );
	}
        if (random(12) == 5)
        {
		if(objectp(room=load_object("/d/dali/taihejiekou")) && 
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
message("channel:chat", HIB"����͢������"GRN + "�ڴ�����з��ֽ����ϸ��\n"NOR,users() );
	}
        if (random(12) == 6)
        {
		if(objectp(room=load_object("/d/foshan/street3")) && 
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
message("channel:chat", HIB"����͢������"GRN + "�ڷ�ɽ���з��ֽ����ϸ��\n"NOR,users() );
	}
        if (random(12) == 7)
        {
		if(objectp(room=load_object("/d/fuzhou/dongjiekou")) && 
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
  message("channel:chat", HIG"����͢������"CYN + "�ڸ��ݳ��з����ɹż�ϸ��\n"NOR,users() );
	}
        if (random(12) == 8)
        {
		if(objectp(room=load_object("/d/hangzhou/road13")) && 
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
  message("channel:chat", HIG"����͢������"CYN + "�ں��ݳ����з����ɹż�ϸ��\n"NOR,users() );
	}
        if (random(12) == 9)
        {
		if(objectp(room=load_object("/d/lingzhou/center")) && 
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
  message("channel:chat", HIG"����͢������"CYN + "�����ݳ����з����ɹż�ϸ��\n"NOR,users() );
	}
        if (random(12) == 10)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) && 
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("channel:chat", HIR"����͢������"BLU + "��Ȫ�ݳ��з������ļ�ϸ��\n"NOR,users() );
	}
        if (random(12) == 11)
        {
		if(objectp(room=load_object("/d/suzhou/baodaiqiao")) && 
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("channel:chat", HIR"����͢������"BLU + "�����ݳ��з������ļ�ϸ��\n"NOR,users() );
	}
        if (random(12) == 12)
        {
		if(objectp(room=load_object("/d/xiangyang/guangchang")) && 
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("channel:chat", HIR"����͢������"BLU + "���������з������ļ�ϸ��\n"NOR,users() );
	}
        if (random(16) == 1)
        {
		if(objectp(room=load_object("/d/huanghe/yongdeng")) && 
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                message("channel:chat", HIR"��ǰ�߸漱��"HIW + "���Ĵ�����������ľ����������ǣ�\n"NOR,users() );
	}
        if (random(16) == 2)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) && 
		objectp(badguy = new("/quest/weiguo/japan/japan3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
  message("channel:chat", HIR"��ǰ�߸漱��"HIW + "���ܴ����Ȫ�ݸ�����½��ɱ�Ұ���!!\n"NOR,users() );
	}
        if (random(16) == 4)
        {
		if(objectp(room=load_object("/d/xiangyang/eastgate1")) && 
		objectp(badguy = new("/quest/weiguo/menggu/mengu3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
               message("channel:chat", HIR"��ǰ�߸漱��"HIW + "�ɹŴ�����������������������漱!!\n"NOR,users() );
	}
        if (random(16) == 7)
        {
		if(objectp(room=load_object("/d/city2/di_anmen.")) && 
		objectp(badguy = new("/quest/weiguo/jinbing/jin3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
  message("channel:chat", HIR"��ǰ�߸漱��"HIW + "��������ϵĲ���ɱ���˾��ǣ����Ǹ�Σ!!\n"NOR,users() );
	}
}

void event_night()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/city3/guangchang")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�ɶ����н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 4)
        {
		if(objectp(room=load_object("/d/quanzhen/zhongxin")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 5)
        {
		if(objectp(room=load_object("/d/dali/taihejiekou")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 6)
        {
		if(objectp(room=load_object("/d/foshan/street3")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "��ɽ���н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 7)
        {
		if(objectp(room=load_object("/d/fuzhou/dongjiekou")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 8)
        {
		if(objectp(room=load_object("/d/hangzhou/road13")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 9)
        {
		if(objectp(room=load_object("/d/lingzhou/center")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 10)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "Ȫ�ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 11)
        {
		if(objectp(room=load_object("/d/suzhou/baodaiqiao")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "���ݳ��н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}
        if (random(12) == 12)
        {
		if(objectp(room=load_object("/d/xiangyang/guangchang")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"���ٸ�ͨ�桿"HIR + "�������н�ҹ�з������У������������Ų�������Ī����\n"NOR,users() );
	}

}

void event_afternoon()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/weiguo/japan/japan1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia2");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia3");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia4");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N˵������Ҫ���ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}

void event_dawn()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/feizei/feizei");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$NЦ���������ˣ�����Ҳ�����ˣ�������\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}

void event_midnight()
{
        string get_month, get_day;
        get_day = CHINESE_D->chinese_monthday(TIME_TICK1);
        get_month = CHINESE_D->chinese_month(TIME_TICK1);
        switch(get_month)
        {
                //spring weather
                case "��":
                case "��":
                case "��":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/spring_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/spring_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/spring_wind");
                           break;
                     }
                     break;
                //summer weather
                case "��":
                case "��":
                case "��":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/summer_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/summer_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/summer_wind");
                           break;
                     }
                     break;
                //autumn weather
                case "��":
                case "ʮ":
                case "ʮһ":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/autumn_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/autumn_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/autumn_wind");
                           break;
                     }
                     break;
                //winter weather
                case "ʮ��":
                case "һ":
                case "��":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/winter_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/winter_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/winter_wind");
                           break;
                     }
                     break;
                default:
                     day_phase = read_table("/adm/etc/nature/day_phase");
        }
//        switch(get_day)
//        {
//                case "һ��һ��":
//                     day_phase = read_table("/adm/etc/nature/spring");
//                     break;
//                case "��������":
//                case "��������":
//                case "����ʮ����":
//                case "���¾���":
//                case "ʮ���°���":
//        }
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
        object *ob;
        int i, skill,con,con1,con2,con3;
        string get_month,ill,msg;
        get_month = CHINESE_D->chinese_month(TIME_TICK1);
        switch(get_month)
        {
                case "��":
                case "��":
                case "��":
                     ill = "ill_kesou";
                     msg = HIG + "��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n" + NOR;
                     break;
                case "��":
                case "��":
                case "��":
                     ill = "ill_zhongshu";
                     msg = HIG+"ͻȻ������֮��һ���ڣ��������ˡ�\n" + NOR;
                     break;
                case "��":
                case "ʮ":
                case "ʮһ":
                     ill = "ill_shanghan";
                     msg = HIG+"��������˸���ս��ͷ������ģ�����˺����ˡ�\n"+NOR;
                     break;
                case "ʮ��":
                case "һ":
                case "��":
                     ill = "ill_dongshang";
                     msg = HIG+"��֫��ĩ��һ��ֱ�������㱻�����ˡ�\n"+NOR;
                     break;
        }
        if(random(2))
        {
                ill = "ill_fashao";msg = HIG+"��ż�з纮����������������\n"+NOR;
        }
        ob = users();
        for(i=0; i<sizeof(ob); i++)
        {
                if( !environment(ob[i]) ) continue;
                if( !environment(ob[i])->query("outdoors") ) continue;
                if( ob[i]->query("age")==14 ) continue;
                con1 = ob[i]->query("qi");
                con2 = ob[i]->query("max_qi");
                (int)con = con1/con2*50;//�γɵ�һ�������ж�����
                con3 = ob[i]->query("neili");
                con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
                (int)con1 = con3/con2*50;//�γɵڶ��������ж�����
                if(random(con)+random(50)+random(con1)<25)
                {
                        ob[i]->apply_condition(ill, 10);
                        tell_object(ob[i], msg);
                }
        }
}

string outdoor_room_description()
{
	return "    " + sprintf(
		day_phase[current_day_phase]["desc_msg"],
		month_desc[current_month]) + "��\n";
}
string outdoor_room_outcolor()
{
        return day_phase[current_day_phase]["outcolor"];
}

string game_time()
{
        return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;

        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        }

        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}

mapping *query_day_phase() { return day_phase; }

