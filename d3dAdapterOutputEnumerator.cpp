#include "d3dAdapterOutputEnumerator.h"

HRESULT DXGI_getAdapters(std::vector<IDXGIAdapter*>& adaptersVec)
{
	IDXGIFactory1* factory = NULL;
	HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)&factory);
	if(FAILED(hr))
		return hr;
	UINT adptIndex = 0;
	IDXGIAdapter1* pAdapter = NULL;
	while( SUCCEEDED(factory->EnumAdapters1(adptIndex, &pAdapter)) )
	{
		adaptersVec.push_back(pAdapter);
		adptIndex++;
	}
	factory->Release();
	return S_OK;
}

HRESULT DXGI_getOutputs(IDXGIAdapter* adapter, std::vector<IDXGIOutput*>& outputVec)
{
	if(adapter==NULL)
		return S_FALSE;
	UINT outputIndex = 0;
	IDXGIOutput* pOutput = NULL;
	while( SUCCEEDED(adapter->EnumOutputs(outputIndex, &pOutput)) )
	{
		outputVec.push_back(pOutput);
		++outputIndex;
	}
	return S_OK;
}

HRESULT DXGI_releaseAdaptersObjs(std::vector<IDXGIAdapter*>& adptVec)
{
	for(int i=0; i<adptVec.size(); i++)
	{
		if(adptVec[i]!=NULL)
			adptVec[i]->Release();
	}
	adptVec.clear();
	return S_OK;
}

HRESULT DXGI_releaseOutputObjs(std::vector<IDXGIOutput*>& outputVec)
{
	for(int i=0; i<outputVec.size(); i++)
	{
		if(outputVec[i]!=NULL)
			outputVec[i]->Release();
	}
	outputVec.clear();
	return S_OK;
}