#include <ansi.h>
int main()
{
	string info,name,id,file,infoa,infob;
		info = read_file("/data/npc/champion.o");
infoa = read_file("/data/npc/menpai.o");
infob = read_file("/data/npc/menpai1.o");
	printf(HIY"\n\n    ����= "HIM" �������֪����ʿ�б�"HIY"  =����\n"HIW"----------------------------------------------\n"NOR);
printf(HIM"	�������ƽ١�"+RED" %s"+HIC"����ս��"NOR+RED" %s\n"NOR,infoa,infob);
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIC"	��������        "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIC"	��������        "+HIB" ��ȱ\n"NOR);
	info = read_file("/data/npc/champion1.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIR"	а������        "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIR"	а������        "+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_sl.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	���������Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	���������Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_gm.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	��Ĺ�����Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	��Ĺ�����Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_gb.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	ؤ�����Ŵ����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"   	ؤ�����Ŵ����  "+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_hs.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	��ɽ�����Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	��ɽ�����Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_yl.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	���������Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	���������Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_lj.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	���չ����Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	���չ����Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_xx.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	���������Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	���������Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_wd.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�䵱�����Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�䵱�����Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_em.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	��ü�����Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	��ü�����Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_xs.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	ѩɽ�����Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	ѩɽ�����Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_dl.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	����μҴ����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	����μҴ����  "+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_bt.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	����ɽ���Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	����ɽ���Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_mj.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�������Ŵ����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�������Ŵ����  "+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_qz.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	ȫ�������Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	ȫ�������Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_ry.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	���½����Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	���½����Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_mr.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	Ľ�����Ҵ����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	Ľ�����Ҵ����  "+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_slj.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	���������Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	���������Ŵ����"+HIB" ��ȱ\n"NOR);
info = read_file("/data/npc/champion_th.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�һ������Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�һ������Ŵ����"+HIB" ��ȱ\n"NOR);
	info = read_file("/data/npc/champion_tz.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	���ư����Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	���ư����Ŵ����"+HIB" ��ȱ\n"NOR);
	info = read_file("/data/npc/champion_xy.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	��ң�����Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	��ң�����Ŵ����"+HIB" ��ȱ\n"NOR);
	info = read_file("/data/npc/champion_kl.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	���������Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	���������Ŵ����"+HIB" ��ȱ\n"NOR);
	info = read_file("/data/npc/champion_wdj.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�嶾�����Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�嶾�����Ŵ����"+HIB" ��ȱ\n"NOR);
	info = read_file("/data/npc/champion_lx.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	���������Ŵ����"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	���������Ŵ����"+HIB" ��ȱ\n"NOR);
	info = read_file("/data/npc/champion_tm.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�������Ÿ�����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�������Ÿ�����  "+HIB" ��ȱ\n"NOR);
	info = read_file("/data/npc/champion_feitian.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	��������������  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	��������������  "+HIB" ��ȱ\n"NOR);


	info = read_file("/data/npc/champion_nsl.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�������ɸ�����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�������ɸ�����  "+HIB" ��ȱ\n"NOR);


	info = read_file("/data/npc/champion_hua.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�컨�ḱ�ܶ���  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�컨�ḱ�ܶ���  "+HIB" ��ȱ\n"NOR);


	info = read_file("/data/npc/champion_ss.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�� ɽ �ɸ�����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�� ɽ �ɸ�����  "+HIB" ��ȱ\n"NOR);


	info = read_file("/data/npc/champion_ts.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	̩ ɽ �ɸ�����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	̩ ɽ �ɸ�����  "+HIB" ��ȱ\n"NOR);
		
	info = read_file("/data/npc/champion_qc.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�� �� �ɸ�����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�� �� �ɸ�����  "+HIB" ��ȱ\n"NOR);		

	info = read_file("/data/npc/champion_henshan.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�� ɽ �ɸ�����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�� ɽ �ɸ�����  "+HIB" ��ȱ\n"NOR);		
		

	info = read_file("/data/npc/champion_hengshan.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	�� ɽ �ɸ�����  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	�� ɽ �ɸ�����  "+HIB" ��ȱ\n"NOR);				

	info = read_file("/data/npc/champion_hj.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	������Ҹ��ܹ�  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	������Ҹ��ܹ�  "+HIB" ��ȱ\n"NOR);			
		

	info = read_file("/data/npc/champion_mz.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	÷  ׯ  ��ׯ��  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	÷  ׯ  ��ׯ��  "+HIB" ��ȱ\n"NOR);					

	printf(HIW"------------------------------"HIM" �� ����II �� "HIW"---\n"NOR);

return 1;
}
int help(object me)
{  
write(@HELP
ָ���ʽ: topp����쿴�����и���������ʿ��
HELP
   );   
return 1;
}